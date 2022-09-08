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

//-----------------------------
// include
//-----------------------------
#include <cmath>
#include "RotatePotentialGenerator.hpp"

//-----------------------------
// Namespace & using
//-----------------------------
namespace math = MiYALAB::Cpp::Mathematics;

//-----------------------------
// Methods
//-----------------------------
namespace MiYALAB {
namespace Cpp{
namespace PhysicsEngine{
/**
 * @brief x-y
 * 
 * @param point 
 * @return math::Point2D<double> 
 */
math::Point2D<double> RotatePotentialGenerator::CalcPotential(const math::Point2D<double> &point) const 
{
    math::Point2D<double> ret;
    math::Point2D<double> pt = point - this->GetOfset();

    const double &r2 = pt.x * pt.x + pt.y * pt.y;
    ret.x =   this->GetGain() * pt.y / r2;             // x = Gain * sin(theta) / r
    ret.y = - this->GetGain() * pt.x / r2;             // y = Gain * cos(theta) / r
    
    return ret;
}
}
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------