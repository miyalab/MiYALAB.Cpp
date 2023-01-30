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
#include "MiYALAB/Mathematics/Quaternion/ConvertToQuaternion.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Mathematics{
template<typename Numeric> void ConvertToQuaternion(const EulerAngles<Numeric> &euler, Quaternion<Numeric> &quaternion)
{
    Numeric cosRoll = std::cos(euler.roll / 2.0);
    Numeric sinRoll = std::sin(euler.roll / 2.0);
    Numeric cosPitch = std::cos(euler.pitch / 2.0);
    Numeric sinPitch = std::sin(euler.pitch / 2.0);
    Numeric cosYaw = std::cos(euler.yaw / 2.0);
    Numeric sinYaw = std::sin(euler.yaw / 2.0);

    quaternion.w = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
    quaternion.x = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
    quaternion.y = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
    quaternion.z = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
}
template void ConvertToQuaternion<char>(const EulerAngles<char>&, Quaternion<char>&);
template void ConvertToQuaternion<short>(const EulerAngles<short>&, Quaternion<short>&);
template void ConvertToQuaternion<int>(const EulerAngles<int>&, Quaternion<int>&);
template void ConvertToQuaternion<long>(const EulerAngles<long>&, Quaternion<long>&);
template void ConvertToQuaternion<long long>(const EulerAngles<long long>&, Quaternion<long long>&);
template void ConvertToQuaternion<float>(const EulerAngles<float>&, Quaternion<float>&);
template void ConvertToQuaternion<double>(const EulerAngles<double>&, Quaternion<double>&);
template void ConvertToQuaternion<long double>(const EulerAngles<long double>&, Quaternion<long double>&);

template<typename Numeric> Quaternion<Numeric> ConvertToQuaternion(const EulerAngles<Numeric> &euler)
{
    Quaternion<Numeric> ret;
    ConvertToQuaternion(euler, ret);
    return ret;
}
template Quaternion<char> ConvertToQuaternion<char>(const EulerAngles<char>&);
template Quaternion<short> ConvertToQuaternion<short>(const EulerAngles<short>&);
template Quaternion<int> ConvertToQuaternion<int>(const EulerAngles<int>&);
template Quaternion<long> ConvertToQuaternion<long>(const EulerAngles<long>&);
template Quaternion<long long> ConvertToQuaternion<long long>(const EulerAngles<long long>&);
template Quaternion<float> ConvertToQuaternion<float>(const EulerAngles<float>&);
template Quaternion<double> ConvertToQuaternion<double>(const EulerAngles<double>&);
template Quaternion<long double> ConvertToQuaternion<long double>(const EulerAngles<long double>&);

}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------