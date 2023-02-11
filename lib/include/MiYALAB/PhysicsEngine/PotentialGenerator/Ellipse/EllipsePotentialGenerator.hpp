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
    Mathematics::Point2D calcPotential(const Mathematics::Point2D &point) const override;
    void setAspectRatio(const double &aspect){aspect_ratio = aspect;}
    void setRotateAngle(const double &angle){rotate_angle = angle;}
private:
    double aspect_ratio = 1.0;
    double rotate_angle = 0.0;
protected:
    const double &getAspectRatio() const {return aspect_ratio;}
    const double &getAngle() const {return rotate_angle;}
};
}
}

#endif // __MIYALAB_CPP_POTENTIAL_GENERATOR_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------