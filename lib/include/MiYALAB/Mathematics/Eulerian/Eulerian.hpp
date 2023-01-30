/*
 * MIT License
 * 
 * Copyright (c) 2022 MiYA LAB(K.Miyauchi)
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

#ifndef __MIYALAB_CPP_MATHEMATICS_EULERIAN_HPP__
#define __MIYALAB_CPP_MATHEMATICS_EULERIAN_HPP__

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
 * @brief roll-pitch-yaw Numeric
 * 
 * @tparam Numeric 
 */
template<typename Numeric>
struct EulerAngles{
    // フィールド
    Numeric roll;
    Numeric pitch;
    Numeric yaw;

    // コンストラクタ
    EulerAngles(){this->roll = 0; this->pitch = 0; this->yaw = 0;}
    EulerAngles(const Numeric &_roll, const Numeric &_pitch, const Numeric &_yaw){this->roll = _roll; this->pitch = _pitch; this->yaw = _yaw;}

    // デストラクタ
    virtual ~EulerAngles(){}

    // 算術演算子
    EulerAngles &operator+=(const EulerAngles &point)  {this->roll+=point.roll; this->pitch+=point.pitch; this->yaw+=point.yaw; return *this;}
    EulerAngles &operator-=(const EulerAngles &point)  {this->roll-=point.roll; this->pitch-=point.pitch; this->yaw-=point.yaw; return *this;}
    EulerAngles &operator*=(const EulerAngles &point)  {*this=*this*point; return *this;}
    EulerAngles &operator*=(const Numeric &num){this->roll*=num; this->pitch*=num; this->yaw*=num; return *this;}
    EulerAngles &operator/=(const Numeric &num){this->roll/=num; this->pitch/=num; this->yaw/=num; return *this;}
    EulerAngles operator+ (const EulerAngles &point)   const {return (EulerAngles(*this)+=point);}
    EulerAngles operator- (const EulerAngles &point)   const {return (EulerAngles(*this)-=point);}
    EulerAngles operator* (const EulerAngles &point)   const {return (EulerAngles(this->pitch*point.yaw-point.pitch*this->yaw, this->yaw*point.roll-point.yaw*this->roll, this->roll*point.pitch-point.roll*this->pitch));}
    EulerAngles operator* (const Numeric &num) const {return (EulerAngles(*this)*=num);}
    EulerAngles operator/ (const Numeric &num) const {return (EulerAngles(*this)/=num);}    
    
    // 比較演算子
    bool operator==(const EulerAngles &angles) const {return (this->roll == angles.roll && this->pitch == angles.pitch && this->yaw == angles.yaw);}
    bool operator!=(const EulerAngles &angles) const {return (this->roll != angles.roll || this->pitch != angles.pitch || this->yaw != angles.yaw);}

    // 文字列化メソッド
    std::string toString() const {return "(" + std::to_string(this->roll) + ", " + std::to_string(this->pitch) + ", " + std::to_string(this->yaw) + ")";}

    // 3次元ベクトル計算メソッド
    Numeric Dot(const EulerAngles &point) const {return (this->roll*point.roll + this->pitch*point.pitch + this->yaw*point.yaw);}
    Numeric Magnitude()     const {return std::sqrt(this->roll*this->roll + this->pitch*this->pitch + this->yaw*this->yaw);}
    Numeric MagnitudePow2() const {return (this->roll*this->roll + this->pitch*this->pitch + this->yaw*this->yaw);}
};
}
}
}

//-----------------------------
// template
//-----------------------------
namespace MiYALAB{
namespace Cpp{
namespace Mathematics{
template struct EulerAngles<char>;
template struct EulerAngles<short>;
template struct EulerAngles<int>;
template struct EulerAngles<long>;
template struct EulerAngles<long long>;
template struct EulerAngles<float>;
template struct EulerAngles<double>;
template struct EulerAngles<long double>;
}
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_POINT_3D_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------