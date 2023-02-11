#include <iostream>
#include <iomanip> 
#include <chrono>
#include <random>
#include "MiYALAB/Mathematics/Matrix/Matrix.hpp"

// #define MAT_SHOW

constexpr size_t MAT_SIZE = 1000;

using namespace MiYALAB;

int main()
{
    std::cout << std::fixed << std::setprecision(10);
    std::srand(std::time(nullptr));

    Mathematics::Matrix mat1(MAT_SIZE, MAT_SIZE), mat2(MAT_SIZE, MAT_SIZE);
    
    for(size_t i=0; i<mat1.rows(); i++){
        for(size_t j=0; j<mat1.cols(); j++){
            mat1[i][j] = std::rand() % 10;
            mat2[i][j] = std::rand() % 10;
        }
    }

    // Mathematics::Matrix<double> dst;
    std::chrono::_V2::system_clock::time_point start, end;

#ifdef MAT_SHOW
    std::cout << mat1.ToString() << std::endl;
    std::cout << mat2.ToString() << std::endl;
#endif

    // atメソッドチェック
    // mat1.At(1000,1000) = 1;

    // 加算チェック
    start = std::chrono::high_resolution_clock::now();    
    const auto &dst1 = mat1 + mat2;
    end = std::chrono::high_resolution_clock::now();
#ifdef MAT_SHOW
    std::cout << dst1.ToString() << std::endl;
#endif
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()/1e9 << "[s]" << std::endl;

    // 減算チェック
    start = std::chrono::high_resolution_clock::now();    
    const auto &dst2 = mat1 - mat2;
    end = std::chrono::high_resolution_clock::now();
#ifdef MAT_SHOW
    std::cout << dst2.ToString() << std::endl;
#endif
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()/1e9 << "[s]" << std::endl;

    // 乗算チェック
    // start = std::chrono::high_resolution_clock::now();    
    // const auto &dst3 = mat1 * mat2;
    // end = std::chrono::high_resolution_clock::now();
#ifdef MAT_SHOW
    std::cout << dst3.ToString() << std::endl;
#endif
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()/1e9 << "[s]" << std::endl;

    // 逆行列チェック
    start = std::chrono::high_resolution_clock::now();    
    const auto &dst4 = mat1.inverse();
    end = std::chrono::high_resolution_clock::now();
#ifdef MAT_SHOW
    std::cout << dst4.ToString() << std::endl;
#endif
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()/1e9 << "[s]" << std::endl;

}