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

#ifndef __MIYALAB_CPP_MATHEMATICS_POSE_POSE_3D_HPP__
#define __MIYALAB_CPP_MATHEMATICS_POSE_POSE_3D_HPP__

//-----------------------------
// include
//-----------------------------
#include <string>

#include "../Point/Point3D.hpp"
#include "../Quaternion/Quaternion.hpp"

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
template<class NumericType>
struct Pose3DType{
    Point3DType<NumericType> position;
    QuaternionType<NumericType> orientation;

    std::string toString() const {return "(" + std::to_string(position.x) + ", "
                                             + std::to_string(position.y) + ", " 
                                             + std::to_string(position.z) + ", "
                                             + std::to_string(orientation.w) + ", "
                                             + std::to_string(orientation.x) + ", "
                                             + std::to_string(orientation.y) + ", " 
                                             + std::to_string(orientation.z) + ")";}
};
}
}

//-----------------------------
// using
//-----------------------------
namespace MiYALAB{
namespace Mathematics{
using Pose32 = Pose3DType<float>;
using Pose = Pose3DType<double>;
}
}


#endif // __MIYALAB_CPP_MATHEMATICS_POSE_POSE_3D_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------