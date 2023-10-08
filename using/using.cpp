#include <yaml-cpp/yaml.h>
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <vector>
#include <string>
#include <memory>
#include <iterator>
#include <iostream>
#include <opencv2/core/eigen.hpp>

using namespace std;
using namespace cv;

const string id="KE0200020184";
const string path="/home/aiit/Desktop/camera_check/using/param.yaml";

template<typename T>
bool init(Eigen::MatrixXd &matrix,std::vector<T> &vector)
{
    int cnt=0;
    for (int row = 0; row < matrix.rows(); row++)
    {
        for (int col = 0; col < matrix.cols(); col++)
        {
            matrix(row,col)=vector[cnt];
            cnt++;

        }
    }
    return true;
}


int main()
{
    Mat intrinsic;
    Mat coeff;
    Eigen::MatrixXd Intrinsic(3,3);
    Eigen::MatrixXd Coeff(1,5);
    YAML::Node param=YAML::LoadFile(path);

    auto read=param[id]["Intrinsic"].as<vector<float>>();
    init(Intrinsic,read);
    eigen2cv(Intrinsic,intrinsic);
    cout<<"Intrinsic:"<<intrinsic<< endl;

    read=param[id]["Coeff"].as<vector<float>>();
    init(Coeff,read);
    eigen2cv(Coeff,coeff);
    cout<<"Coeff:"<<coeff<< endl;

    return 0;



}