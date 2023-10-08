# openCV标定

## 1.文件结构

```shell
├── camer_check  //标定程序
├── prepare		//准备材料
├── README.md    
└── using      //标定示例
```

## 2.使用方法

### camer_check

1. 修改图片角点

   ```c++
   int BOARDSIZE[2]{ 6,9 };//camer_check  8行  存放角点行列值
   /*
   
   ![pattern](/home/aiit/Desktop/camera_check/prepare/pattern.png)
   如图所示角点行列值为： 行：6 列：9
   */
   ```

2. 修改图片路径

   ```c++
   string image_path = "/home/aiit/Downloads/camra-111/*.bmp";//camera_check 17行待处理图路径
   src = imread("/home/aiit/Downloads/camra-111/2023-04-12_11_13_31_079.bmp"); //camera_check 86行
   //照片最好20--30张 
   ```

3. 编译

   ```shell
   mkdir build
   cd build
   cmake ..
   make -j2
   ./camer_check 
   //程序执行后会遍历所有照片后输出到终端上 需要等待一段时间 将输出来的值相对应的放入../using/param.yaml中
   ```

## using

1. 修改相机SN号和Yaml文件路径

   ```c++
   const string id="KE0200020184"; //using 15行 这个为相机SN号 可以在大恒驱动里面查询 注意Yaml文件开头应该与SN号一致
   const string path="/home/aiit/Desktop/camera_check/using/param.yaml"; //using 16行 这个为标定完相机后输出参数存储文件的路径
   ```

2. 修改Yaml文件

   ```yaml
   # 相机SN号 using/param.yaml
   KE0200020184:
       #内参矩阵
       Intrinsic: [1269.8510380773004727, 0.0000000000000000, 676.8259217405255868,
         0.0000000000000000, 1266.8336601375658574, 492.7451015999432116,
         0.0000000000000000, 0.0000000000000000, 1.0000000000000000 ]
       #畸变参数矩阵，k1,k2,k3,p1,p2。一定注意是k1,k2,k3,p1,p2!!!和标定标出来的k1,k2,p1,p2,k3不同！！！
       Coeff: [-0.1581579533096253, -2.5493384521746689, 0.0000000000000000, 0.0000000000000000, 32.1666228104754381]
   ```

3. 编译

   ```shell
   mkdir build
   cd build
   cmake ..
   make -j2
   ./using
   ```

   
