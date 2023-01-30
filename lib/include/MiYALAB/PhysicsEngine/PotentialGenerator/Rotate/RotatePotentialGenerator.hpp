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

#ifndef __MIYALAB_CPP_PHYSICS_ENGINE_ELLIPSE_POTENTIAL_GENERATOR_HPP__
#define __MIYALAB_CPP_PHYSICS_ENGINE_ELLIPSE_POTENTIAL_GENERATOR_HPP__

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
class RotatePotentialGenerator: public PotentialGenerator{
public:
    RotatePotentialGenerator(){}
    virtual ~RotatePotentialGenerator(){}
    Mathematics::Point2D<double> CalcPotential(const Mathematics::Point2D<double> &point) const override;
private:

protected:
};
}
}

#endif // __MIYALAB_CPP_POTENTIAL_GENERATOR_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------