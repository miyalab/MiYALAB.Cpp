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
// Function
//-----------------------------
namespace MiYALAB {
namespace Mathematics{
template<typename Numeric> void convertToQuaternion(const Vector3Type<Numeric> &euler, QuaternionType<Numeric> &quaternion)
{
    Numeric cosRoll = std::cos(euler.x / 2.0);
    Numeric sinRoll = std::sin(euler.x / 2.0);
    Numeric cosPitch = std::cos(euler.y / 2.0);
    Numeric sinPitch = std::sin(euler.y / 2.0);
    Numeric cosYaw = std::cos(euler.z / 2.0);
    Numeric sinYaw = std::sin(euler.z / 2.0);

    quaternion.w = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
    quaternion.x = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
    quaternion.y = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
    quaternion.z = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
}
template void convertToQuaternion<char>(const Vector3Type<char>&, QuaternionType<char>&);
template void convertToQuaternion<short>(const Vector3Type<short>&, QuaternionType<short>&);
template void convertToQuaternion<int>(const Vector3Type<int>&, QuaternionType<int>&);
template void convertToQuaternion<long>(const Vector3Type<long>&, QuaternionType<long>&);
template void convertToQuaternion<long long>(const Vector3Type<long long>&, QuaternionType<long long>&);
template void convertToQuaternion<float>(const Vector3Type<float>&, QuaternionType<float>&);
template void convertToQuaternion<double>(const Vector3Type<double>&, QuaternionType<double>&);
template void convertToQuaternion<long double>(const Vector3Type<long double>&, QuaternionType<long double>&);

template<typename Numeric> QuaternionType<Numeric> convertToQuaternion(const Vector3Type<Numeric> &euler)
{
    QuaternionType<Numeric> ret;
    convertToQuaternion(euler, ret);
    return ret;
}
template QuaternionType<char> convertToQuaternion<char>(const Vector3Type<char>&);
template QuaternionType<short> convertToQuaternion<short>(const Vector3Type<short>&);
template QuaternionType<int> convertToQuaternion<int>(const Vector3Type<int>&);
template QuaternionType<long> convertToQuaternion<long>(const Vector3Type<long>&);
template QuaternionType<long long> convertToQuaternion<long long>(const Vector3Type<long long>&);
template QuaternionType<float> convertToQuaternion<float>(const Vector3Type<float>&);
template QuaternionType<double> convertToQuaternion<double>(const Vector3Type<double>&);
template QuaternionType<long double> convertToQuaternion<long double>(const Vector3Type<long double>&);

}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------