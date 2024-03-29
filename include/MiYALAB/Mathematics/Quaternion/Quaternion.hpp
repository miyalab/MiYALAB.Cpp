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

#ifndef __MIYALAB_CPP_MATHEMATICS_QUATERNION_QUATERNION_HPP__
#define __MIYALAB_CPP_MATHEMATICS_QUATERNION_QUATERNION_HPP__

//-----------------------------
// include
//-----------------------------
#include <string>

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
struct QuaternionType{
    Numeric w;
    Numeric x;
    Numeric y;
    Numeric z;

    // コンストラクタ
    QuaternionType() : w(0), x(0), y(0), z(0){}
    QuaternionType(const Numeric &_w, const Numeric &_x, const Numeric &_y, const Numeric &_z) :  w(_w), x(_x), y(_y), z(_z){}

    // デストラクタ
    virtual ~QuaternionType(){}

    // 比較演算子
    bool operator==(const QuaternionType &quaternion) const {return (this->w == quaternion.w && this->x == quaternion.x && this->y == quaternion.y && this->z == quaternion.z);}
    bool operator!=(const QuaternionType &quaternion) const {return (this->w != quaternion.w || this->x != quaternion.x || this->y != quaternion.y || this->z != quaternion.z);}

    std::string toString() const {return "(" + std::to_string(this->w) + ", " + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")";}

};
}
}

//-----------------------------
// using
//-----------------------------
namespace MiYALAB{
namespace Mathematics{
using Quaternion32 = QuaternionType<float>;
using Quaternion = QuaternionType<double>;
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_QUATERNION_QUATERNION_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------