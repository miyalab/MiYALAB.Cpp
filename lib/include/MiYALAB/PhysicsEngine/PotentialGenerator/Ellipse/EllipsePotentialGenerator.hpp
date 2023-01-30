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

#ifndef __MIYALAB_CPP_PHYSICS_ENGINE_ROTATE_POTENTIAL_GENERATOR_HPP__
#define __MIYALAB_CPP_PHYSICS_ENGINE_ROTATE_POTENTIAL_GENERATOR_HPP__

//-----------------------------
// include
//-----------------------------
#include "../PotentialGenerator.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace PhysicsEngine{
class EllipsePotentialGenerator: public PotentialGenerator{
public:
    EllipsePotentialGenerator(){}
    virtual ~EllipsePotentialGenerator(){}
    Mathematics::Point2D<double> CalcPotential(const Mathematics::Point2D<double> &point) const override;
    void SetAspectRatio(const double &aspect){m_aspect_ratio = aspect;}
    void SetAngle(const double &angle){m_angle = angle;}
private:
    double m_aspect_ratio = 1.0;
    double m_angle;
protected:
    const double &GetAspectRatio() const {return m_aspect_ratio;}
    const double &GetAngle() const {return m_angle;}
};
}
}

#endif // __MIYALAB_CPP_POTENTIAL_GENERATOR_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------