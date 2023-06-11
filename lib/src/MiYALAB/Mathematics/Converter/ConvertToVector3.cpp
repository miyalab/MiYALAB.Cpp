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

//-----------------------------
// include
//-----------------------------
#include <cmath>
#include "MiYALAB/Mathematics/Converter/ConvertToVector3.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Function
//-----------------------------
namespace MiYALAB {
namespace Mathematics{
template<typename Numeric> void convertToEulerAngles(const QuaternionType<Numeric> &quaternion, Vector3Type<Numeric> &euler)
{
    const Numeric &q0q0 = quaternion.w * quaternion.w;
    const Numeric &q0q1 = quaternion.w * quaternion.x;
    const Numeric &q0q2 = quaternion.w * quaternion.y;
    const Numeric &q0q3 = quaternion.w * quaternion.z;
    const Numeric &q1q1 = quaternion.x * quaternion.x;
    const Numeric &q1q2 = quaternion.x * quaternion.y;
    const Numeric &q1q3 = quaternion.x * quaternion.z;
    const Numeric &q2q2 = quaternion.y * quaternion.y;
    const Numeric &q2q3 = quaternion.y * quaternion.z;
    const Numeric &q3q3 = quaternion.z * quaternion.z;
    
    euler.x = std::atan2(2.0 * (q2q3 + q0q1), q0q0 - q1q1 - q2q2 + q3q3);
    euler.y = std::asin(2.0 * (q0q2 - q1q3));
    euler.z = std::atan2(2.0 * (q1q2 + q0q3), q0q0 + q1q1 - q2q2 - q3q3);
}
template void convertToEulerAngles<char>(const QuaternionType<char>&, Vector3Type<char>&);
template void convertToEulerAngles<short>(const QuaternionType<short>&, Vector3Type<short>&);
template void convertToEulerAngles<int>(const QuaternionType<int>&, Vector3Type<int>&);
template void convertToEulerAngles<long>(const QuaternionType<long>&, Vector3Type<long>&);
template void convertToEulerAngles<long long>(const QuaternionType<long long>&, Vector3Type<long long>&);
template void convertToEulerAngles<float>(const QuaternionType<float>&, Vector3Type<float>&);
template void convertToEulerAngles<double>(const QuaternionType<double>&, Vector3Type<double>&);
template void convertToEulerAngles<long double>(const QuaternionType<long double>&, Vector3Type<long double>&);

template<typename Numeric> Vector3Type<Numeric> convertToEulerAngles(const QuaternionType<Numeric> &quaternion)
{
    Vector3Type<Numeric> ret;
    convertToEulerAngles(quaternion, ret);
    return ret;
}
template Vector3Type<char> convertToEulerAngles<char>(const QuaternionType<char>&);
template Vector3Type<short> convertToEulerAngles<short>(const QuaternionType<short>&);
template Vector3Type<int> convertToEulerAngles<int>(const QuaternionType<int>&);
template Vector3Type<long> convertToEulerAngles<long>(const QuaternionType<long>&);
template Vector3Type<long long> convertToEulerAngles<long long>(const QuaternionType<long long>&);
template Vector3Type<float> convertToEulerAngles<float>(const QuaternionType<float>&);
template Vector3Type<double> convertToEulerAngles<double>(const QuaternionType<double>&);
template Vector3Type<long double> convertToEulerAngles<long double>(const QuaternionType<long double>&);

}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------