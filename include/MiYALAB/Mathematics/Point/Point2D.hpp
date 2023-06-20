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
struct Point2DType{
    // フィールド
    Numeric x;
    Numeric y;

    // コンストラクタ
    Point2DType() : x(0), y(0){}
    Point2DType(const Numeric &_x, const Numeric &_y) : x(_x), y(_y){}

    // デストラクタ
    virtual ~Point2DType(){}

    // 算術演算子
    Point2DType &operator+=(const Point2DType &point)  {this->x+=point.x; this->y+=point.y; return *this;}
    Point2DType &operator-=(const Point2DType &point)  {this->x-=point.x; this->y-=point.y; return *this;}
    Point2DType &operator*=(const Numeric &num){this->x*=num; this->y*=num; return *this;}
    Point2DType &operator/=(const Numeric &num){this->x/=num; this->y/=num; return *this;}
    Point2DType operator+ (const Point2DType &point)   const {return (Point2DType(*this)+=point);}
    Point2DType operator- (const Point2DType &point)   const {return (Point2DType(*this)-=point);}
    Point2DType operator* (const Numeric &num) const {return (Point2DType(*this)*=num);}
    Point2DType operator/ (const Numeric &num) const {return (Point2DType(*this)/=num);}
    
    // 比較演算子
    bool operator==(const Point2DType &point) const {return (this->x == point.x && this->y == point.y);}
    bool operator!=(const Point2DType &point) const {return (this->x != point.x || this->y != point.y);}

    // 文字列化メソッド
    std::string toString() const {return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";}

    // 2次元ベクトル計算メソッド
    Numeric dot(const Point2DType &point) const {return this->x*point.x + this->y*point.y;}
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
using Point2D32 = Point2DType<float>;
using Point2D = Point2DType<double>;
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_POINT_POINT_2D_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------