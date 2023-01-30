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

#ifndef __MIYALAB_CPP_MATHEMATICS_TWIST_TWIST_HPP__
#define __MIYALAB_CPP_MATHEMATICS_TWIST_TWIST_HPP__

//-----------------------------
// include
//-----------------------------
#include <string>

#include "../Point/Point3D.hpp"
#include "../EulerAngles/EulerAngles.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Mathematics{
/**
 * @brief x-y NumericType
 * 
 * @tparam NumericType 
 */
template<class Numeric>
struct Twist{
    Point3D<Numeric> position;
    EulerAngles<Numeric> orientation;

    std::string toString() const {return "(" + std::to_string(position.x) + ", "
                                             + std::to_string(position.y) + ", " 
                                             + std::to_string(position.z) + ", "
                                             + std::to_string(orientation.roll) + ", "
                                             + std::to_string(orientation.pitch) + ", " 
                                             + std::to_string(orientation.yaw) + ")";}
};
}
}

//-----------------------------
// template
//-----------------------------
namespace MiYALAB{
namespace Mathematics{
template struct Twist<char>;
template struct Twist<short>;
template struct Twist<int>;
template struct Twist<long>;
template struct Twist<long long>;
template struct Twist<float>;
template struct Twist<double>;
template struct Twist<long double>;

using Twist32f = Twist<float>;
using Twist64f = Twist<double>;
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_TWIST_TWIST_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------