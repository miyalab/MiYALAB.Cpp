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

#ifndef __MIYALAB_CPP_PHYSICS_ENGINE_POTENTIAL_GENERATOR_HPP__
#define __MIYALAB_CPP_PHYSICS_ENGINE_POTENTIAL_GENERATOR_HPP__

//-----------------------------
// include
//-----------------------------
#include "../../Mathematics/Point/Point.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Cpp{
namespace PhysicsEngine{
class PotentialGenerator{
public:
    PotentialGenerator(){}
    virtual ~PotentialGenerator(){}
    void SetGain(const double &_gain){gain = _gain;}
    void SetOfset(const Mathematics::Point2D<double> &_ofset){ofset = _ofset;}
    void SetOfset(const double &x, const double &y){ofset.x = x; ofset.y = y;}
    virtual double CalcPotential(const double &x, const double &y) const;
    virtual Mathematics::Point2D<double> CalcPotential(const Mathematics::Point2D<double> &point) const;
private:
    double gain = 1.0;
    Mathematics::Point2D<double> ofset;
protected:
    const double &GetGain() const {return gain;}
    const Mathematics::Point2D<double> &GetOfset() const {return ofset;}
};
}
}
}

#endif // __MIYALAB_CPP_POTENTIAL_GENERATOR_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------