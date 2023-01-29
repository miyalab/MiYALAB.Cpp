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

#ifndef __MIYALAB_CPP_MATHEMATICS_POINT_HPP__
#define __MIYALAB_CPP_MATHEMATICS_POINT_HPP__

//-----------------------------
// include
//-----------------------------
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "../Matrix/Matrix.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Cpp{
namespace Mathematics{
template <class NumericType> Matrix<NumericType> ToMatrix(const Point2D<NumericType> &point, bool columnVector = true)
{
    if(columnVector) {
        Matrix<NumericType> ret(2,1);
        ret[0][0] = point.x;
        ret[1][0] = point.y;
        return ret;
    }
    else{
        Matrix<NumericType> ret(1,2);
        ret[0][0] = point.x;
        ret[0][1] = point.y;
        return ret;
    }
}
template <class NumericType> Matrix<NumericType> ToMatrix(const Point3D<NumericType> &point, bool columnVector = true)
{
    if(columnVector) {
        Matrix<NumericType> ret(3,1);
        ret[0][0] = point.x;
        ret[1][0] = point.y;
        ret[2][0] = point.z;
        return ret;
    }
    else{
        Matrix<NumericType> ret(1,3);
        ret[0][0] = point.x;
        ret[0][1] = point.y;
        ret[0][2] = point.z;
        return ret;
    }
}

}
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_POINT_2D_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------