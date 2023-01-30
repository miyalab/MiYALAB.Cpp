

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

#ifndef __MIYALAB_CPP_MATHEMATICS_QUATERNION_HPP__
#define __MIYALAB_CPP_MATHEMATICS_QUATERNION_HPP__

//-----------------------------
// include
//-----------------------------
#include <string>
#include <cmath>

#include "../Point/Point3D.hpp"

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
struct Quaternion{
    NumericType w;
    NumericType x;
    NumericType y;
    NumericType z;

    // コンストラクタ
    Quaternion(){this->w=0; this->x = 0; this->y = 0; this->z = 0;}
    Quaternion(const NumericType &_w, const NumericType &_x, const NumericType &_y, const NumericType &_z){this->w = _w; this->x = _x; this->y = _y; this->z = _z;}

    // デストラクタ
    virtual ~Quaternion(){}

    // 比較演算子
    bool operator==(const Quaternion &quaternion) const {return (this->w == quaternion.w && this->x == quaternion.x && this->y == quaternion.y && this->z == quaternion.z);}
    bool operator!=(const Quaternion &quaternion) const {return (this->w != quaternion.w || this->x != quaternion.x || this->y != quaternion.y || this->z != quaternion.z);}

    std::string toString() const {return "("+ std::to_string(this->w) + ", " + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " << std::to_string(this->z) + ")";}

};
}
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_QUATERNION_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------