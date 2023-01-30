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
#include "MiYALAB/Mathematics/EulerAngles/EulerAnglesConverter.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Mathematics{
template<typename Numeric> void ConvertToEulerAngles(const Quaternion<Numeric> &quaternion, EulerAngles<Numeric> &euler)
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
    
    euler.roll  = std::atan2(2.0 * (q2q3 + q0q1), q0q0 - q1q1 - q2q2 + q3q3);
    euler.pitch = std::asin(2.0 * (q0q2 - q1q3));
    euler.yaw   = std::atan2(2.0 * (q1q2 + q0q3), q0q0 + q1q1 - q2q2 - q3q3);
}
template void ConvertToEulerAngles<char>(const Quaternion<char>&, EulerAngles<char>&);
template void ConvertToEulerAngles<short>(const Quaternion<short>&, EulerAngles<short>&);
template void ConvertToEulerAngles<int>(const Quaternion<int>&, EulerAngles<int>&);
template void ConvertToEulerAngles<long>(const Quaternion<long>&, EulerAngles<long>&);
template void ConvertToEulerAngles<long long>(const Quaternion<long long>&, EulerAngles<long long>&);
template void ConvertToEulerAngles<float>(const Quaternion<float>&, EulerAngles<float>&);
template void ConvertToEulerAngles<double>(const Quaternion<double>&, EulerAngles<double>&);
template void ConvertToEulerAngles<long double>(const Quaternion<long double>&, EulerAngles<long double>&);

template<typename Numeric> EulerAngles<Numeric> ConvertToEulerAngles(const Quaternion<Numeric> &quaternion)
{
    EulerAngles<Numeric> ret;
    ConvertToEulerAngles(quaternion, ret);
    return ret;
}
template EulerAngles<char> ConvertToEulerAngles<char>(const Quaternion<char>&);
template EulerAngles<short> ConvertToEulerAngles<short>(const Quaternion<short>&);
template EulerAngles<int> ConvertToEulerAngles<int>(const Quaternion<int>&);
template EulerAngles<long> ConvertToEulerAngles<long>(const Quaternion<long>&);
template EulerAngles<long long> ConvertToEulerAngles<long long>(const Quaternion<long long>&);
template EulerAngles<float> ConvertToEulerAngles<float>(const Quaternion<float>&);
template EulerAngles<double> ConvertToEulerAngles<double>(const Quaternion<double>&);
template EulerAngles<long double> ConvertToEulerAngles<long double>(const Quaternion<long double>&);

}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------