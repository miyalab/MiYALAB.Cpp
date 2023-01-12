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

#ifndef __MIYALAB_CPP_MATHEMATICS_CONST_HPP__
#define __MIYALAB_CPP_MATHEMATICS_CONST_HPP__

namespace MiYALAB{
namespace Cpp{
namespace Mathematics{
namespace ConstantValue{

constexpr double e = 2.718281828459045235360287471352;          // ネイピア数
constexpr double g = 9.80665;                                   // 重力加速度

constexpr double M_PI   = 3.141592653589793238462643;           // 円周率
constexpr double M_PI_1 = 3.141592653589793238462643 / 1;       // 円周率　π/1
constexpr double M_PI_2 = 3.141592653589793238462643 / 2;       // 円周率　π/2
constexpr double M_PI_3 = 3.141592653589793238462643 / 3;       // 円周率　π/3
constexpr double M_PI_4 = 3.141592653589793238462643 / 4;       // 円周率　π/4
constexpr double M_1_PI = 3.141592653589793238462643 * 1;       // 円周率　1π
constexpr double M_2_PI = 3.141592653589793238462643 * 2;       // 円周率　2π
constexpr double M_3_PI = 3.141592653589793238462643 * 3;       // 円周率　3π
constexpr double M_4_PI = 3.141592653589793238462643 * 4;       // 円周率　4π

constexpr double R = 8.31446262;                                // 気体定数
constexpr double k = 1.380649E-23;                              // ネイピア数
constexpr double Na = 6.02214076E23;                            // アボガドロ数
}
}
}
}

#endif

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------