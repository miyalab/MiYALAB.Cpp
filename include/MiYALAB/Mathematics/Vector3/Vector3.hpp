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

#ifndef __MIYALAB_CPP_MATHEMATICS_EULER_ANGLES_EULER_ANGLES_HPP__
#define __MIYALAB_CPP_MATHEMATICS_EULER_ANGLES_EULER_ANGLES_HPP__

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
 * @brief x-y-z Numeric
 * 
 * @tparam Numeric 
 */
template<typename Numeric>
struct Vector3Type{
    // フィールド
    Numeric x;
    Numeric y;
    Numeric z;

    // コンストラクタ
    Vector3Type() : x(0), y(0), z(0){}
    Vector3Type(const Numeric &_roll, const Numeric &_pitch, const Numeric &_yaw) : x(_roll), y(_pitch), z(_yaw){}

    // デストラクタ
    virtual ~Vector3Type(){}

    // 算術演算子
    Vector3Type &operator+=(const Vector3Type &point)  {this->x+=point.x; this->y+=point.y; this->z+=point.z; return *this;}
    Vector3Type &operator-=(const Vector3Type &point)  {this->x-=point.x; this->y-=point.y; this->z-=point.z; return *this;}
    Vector3Type &operator*=(const Vector3Type &point)  {*this=*this*point; return *this;}
    Vector3Type &operator*=(const Numeric &num){this->x*=num; this->y*=num; this->z*=num; return *this;}
    Vector3Type &operator/=(const Numeric &num){this->x/=num; this->y/=num; this->z/=num; return *this;}
    Vector3Type operator+ (const Vector3Type &point)   const {return (Vector3Type(*this)+=point);}
    Vector3Type operator- (const Vector3Type &point)   const {return (Vector3Type(*this)-=point);}
    Vector3Type operator* (const Vector3Type &point)   const {return (Vector3Type(this->y*point.z-point.y*this->z, this->z*point.x-point.z*this->x, this->x*point.y-point.x*this->y));}
    Vector3Type operator* (const Numeric &num) const {return (Vector3Type(*this)*=num);}
    Vector3Type operator/ (const Numeric &num) const {return (Vector3Type(*this)/=num);}    
    
    // 比較演算子
    bool operator==(const Vector3Type &angles) const {return (this->x == angles.x && this->y == angles.y && this->z == angles.z);}
    bool operator!=(const Vector3Type &angles) const {return (this->x != angles.x || this->y != angles.y || this->z != angles.z);}

    // 文字列化メソッド
    std::string toString() const {return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")";}

    // 3次元ベクトル計算メソッド
    Numeric dot(const Vector3Type &point) const {return (this->x*point.x + this->y*point.y + this->z*point.z);}
    Numeric magnitude()     const {return std::sqrt(this->x*this->x + this->y*this->y + this->z*this->z);}
    Numeric magnitudePow2() const {return (this->x*this->x + this->y*this->y + this->z*this->z);}
};
}
}

//-----------------------------
// using
//-----------------------------
namespace MiYALAB{
namespace Mathematics{
using Vector3_32 = Vector3Type<float>;
using Vector3 = Vector3Type<double>;
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_EULER_ANGLES_EULER_ANGLES_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------