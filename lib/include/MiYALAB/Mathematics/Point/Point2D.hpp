/*
 * MIT License
 * 
 * Copyright (c) 2022-2023 MiYA LAB(K.Miyauchi)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef __MIYALAB_CPP_MATHEMATICS_POINT_2D_HPP__
#define __MIYALAB_CPP_MATHEMATICS_POINT_2D_HPP__

//-----------------------------
// include
//-----------------------------
#include <string>
#include <cmath>

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Cpp{
namespace Mathematics{
/**
 * @brief x-y NumericType
 * 
 * @tparam NumericType 
 */
template<class NumericType>
struct Point2D{
    // フィールド
    NumericType x;
    NumericType y;

    // コンストラクタ
    Point2D(){this->x=0; this->y=0;}
    Point2D(const NumericType &_x, const NumericType &_y){this->x = _x; this->y = _y;}

    // デストラクタ
    virtual ~Point2D(){}

    // 算術演算子
    Point2D &operator+=(const Point2D &point)  {this->x+=point.x; this->y+=point.y; return *this;}
    Point2D &operator-=(const Point2D &point)  {this->x-=point.x; this->y-=point.y; return *this;}
    Point2D &operator*=(const NumericType &num){this->x*=num; this->y*=num; return *this;}
    Point2D &operator/=(const NumericType &num){this->x/=num; this->y/=num; return *this;}
    Point2D operator+ (const Point2D &point)   const {return (Point2D(*this)+=point);}
    Point2D operator- (const Point2D &point)   const {return (Point2D(*this)-=point);}
    Point2D operator* (const NumericType &num) const {return (Point2D(*this)*=num);}
    Point2D operator/ (const NumericType &num) const {return (Point2D(*this)/=num);}
    
    // 比較演算子
    bool operator==(const Point2D &point) const {return (this->x == point.x && this->y == point.y);}
    bool operator!=(const Point2D &point) const {return (this->x != point.x || this->y != point.y);}

    // 文字列化メソッド
    std::string ToString() const {return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";}

    // 2次元ベクトル計算メソッド
    NumericType Dot(const Point2D &point) const {return this->x*point.x + this->y*point.y;}
    NumericType Magnitude()     const {return std::sqrt(this->x*this->x + this->y*this->y);}
    NumericType MagnitudePow2() const {return (this->x*this->x + this->y*this->y);}
};
}
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_POINT_2D_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------