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

#ifndef __MIYALAB_CPP_MATHEMATICS_POINT_POINT_2D_HPP__
#define __MIYALAB_CPP_MATHEMATICS_POINT_POINT_2D_HPP__

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
namespace Mathematics{
/**
 * @brief x-y Numeric
 * 
 * @tparam Numeric 
 */
template<typename Numeric>
struct Point2D{
    // フィールド
    Numeric x;
    Numeric y;

    // コンストラクタ
    Point2D() : x(0), y(0){}
    Point2D(const Numeric &_x, const Numeric &_y) : x(_x), y(_y){}

    // デストラクタ
    virtual ~Point2D(){}

    // 算術演算子
    Point2D &operator+=(const Point2D &point)  {this->x+=point.x; this->y+=point.y; return *this;}
    Point2D &operator-=(const Point2D &point)  {this->x-=point.x; this->y-=point.y; return *this;}
    Point2D &operator*=(const Numeric &num){this->x*=num; this->y*=num; return *this;}
    Point2D &operator/=(const Numeric &num){this->x/=num; this->y/=num; return *this;}
    Point2D operator+ (const Point2D &point)   const {return (Point2D(*this)+=point);}
    Point2D operator- (const Point2D &point)   const {return (Point2D(*this)-=point);}
    Point2D operator* (const Numeric &num) const {return (Point2D(*this)*=num);}
    Point2D operator/ (const Numeric &num) const {return (Point2D(*this)/=num);}
    
    // 比較演算子
    bool operator==(const Point2D &point) const {return (this->x == point.x && this->y == point.y);}
    bool operator!=(const Point2D &point) const {return (this->x != point.x || this->y != point.y);}

    // 文字列化メソッド
    std::string toString() const {return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";}

    // 2次元ベクトル計算メソッド
    Numeric dot(const Point2D &point) const {return this->x*point.x + this->y*point.y;}
    Numeric magnitude()     const {return std::sqrt(this->x*this->x + this->y*this->y);}
    Numeric magnitudePow2() const {return (this->x*this->x + this->y*this->y);}
};
}
}

//-----------------------------
// using
//-----------------------------
namespace MiYALAB{
namespace Mathematics{
using Point2d32f = Point2D<float>;
using Point2d64f = Point2D<double>;
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_POINT_POINT_2D_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------