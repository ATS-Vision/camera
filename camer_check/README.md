# 关于标定

## 理论基础

![camer_check](/home/aiit/Desktop/camera_check/camer_check/camer_check.jpg)![match](/home/aiit/Desktop/camera_check/camer_check/match.jpg)

## 代码解释

1. 获取图片

   ```c++
   string image_path = "/home/aiit/Downloads/camra-111/*.bmp"; // 待处理图路径
   glob(image_path, images_path); // 读取指定文件夹下的图像
   ```

2. 预处理

   ```c++
   image = imread(images_path[i]);
   cvtColor(image, img_gray, COLOR_BGR2GRAY);
   ```

3. 检测角点

   ```c++
   bool found_success = findChessboardCorners(img_gray, Size(BOARDSIZE[0], BOARDSIZE[1]), img_corner_points,
                                              CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FAST_CHECK | CALIB_CB_NORMALIZE_IMAGE);
   ```

4. 提取亚像素级别的焦点，绘制角点

   ```c++
   if (found_success) {
       // 迭代终止条件
       TermCriteria criteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.001);
   
       // 进一步提取亚像素角点
       cornerSubPix(img_gray, img_corner_points, Size(11, 11), Size(-1, -1), criteria);
   
       // 绘制角点
       drawChessboardCorners(image, Size(BOARDSIZE[0], BOARDSIZE[1]), img_corner_points, found_success);
   
       objpoints_img.push_back(obj_world_pts); // 从世界坐标系到相机坐标系
       images_points.push_back(img_corner_points);
   }
   ```

5. 进行标定，输出内参，畸变，旋转和平移向量

   ```c++
   Mat cameraMatrix, distCoeffs, R, T;
   calibrateCamera(objpoints_img, images_points, img_gray.size(), cameraMatrix, distCoeffs, R, T);
   ```

6. 校正图像

   ```c++
   Mat src, dst;
   src = imread("/home/aiit/Downloads/camra-111/2023-04-12_11_13_31_079.bmp"); // 读取校正前图像
   undistort(src, dst, cameraMatrix, distCoeffs);
   
   char texts[] = "image_dst";
   char *dst_output = texts;
   imshow(dst_output, dst);
   waitKey(100);
   imwrite("home/aiit/Downloads/camra-111/.jpg", dst); // 校正后图像
   ```

   