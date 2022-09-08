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
#include "EllipsePotentialGenerator.hpp"

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
math::Point2D<double> EllipsePotentialGenerator::CalcPotential(const math::Point2D<double> &point) const
{
    math::Point2D<double> ret;
    math::Point2D<double> pt = point - this->GetOfset();

    // 楕円ポテンシャル場の回転
    const double &cos = std::cos(this->GetAngle());
    const double &sin = std::sin(this->GetAngle());
    math::Point2D<double> pt2;
    pt2.x =  cos * pt.x + sin * pt.y;
    pt2.y = -sin * pt.x + cos * pt.y;
    pt = pt2;

    // ポテンシャル計算
    const double &aspect_pow2 = this->GetAspectRatio()*this->GetAspectRatio();
    const double &theta = std::atan2(m_aspect_ratio * pt.y, pt.x);
    const double &r = std::sqrt((1+aspect_pow2)*pt.x*pt.x + (1+1/aspect_pow2)*pt.y*pt.y);
    ret.x = this->GetGain() * std::cos(theta + this->GetAngle()) / r;
    ret.y = this->GetGain() * std::sin(theta + this->GetAngle()) / r;
    
    return ret;
}
}
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------