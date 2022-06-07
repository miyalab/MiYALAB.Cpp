#include <iostream>
#include <iomanip> 
#include <ctime>
#include <random>
#include "Algorithm/Sort.hpp"
#include "Mathematics/Matrix/Matrix.hpp"

using namespace std;
using namespace MiYALAB::Cpp;

class test{
public:
    const int &getVal(){return val;}
    void show(){std::cout << val << std::endl;}
    void showA(){cout << &val << endl;}
private:
    int val= 0;
};

int main()
{
    std::cout << fixed << std::setprecision(10);
    std::srand(std::time(nullptr));

    Mathematics::Matrix mat1(100,100), mat2(3,3);

    for(int i=0; i<mat1.rows(); i++){
        for(int j=0; j<mat1.cols(); j++){
            mat1[i][j] = rand() % 10;
        }
    }
    mat1[0][2] = 1;
    //std::cout << mat1.ToString() << std::endl;

    std::clock_t start, end;
    start = std::clock();
    double det = mat1.Det();
    auto inv = mat1.Inv();
    end = std::clock();
    std::cout << (long double)(end-start)/CLOCKS_PER_SEC << "[s]"<< std::endl;
}
    
    