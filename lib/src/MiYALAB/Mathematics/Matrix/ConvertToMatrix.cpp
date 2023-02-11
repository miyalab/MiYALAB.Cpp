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
#include "MiYALAB/Mathematics/Matrix/ConvertToMatrix.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Mathematics{
template <typename Numeric> Matrix<Numeric> convertToMatrix(const Point2D<Numeric> &point, bool column_vector)
{
    Matrix<Numeric> ret(1+column_vector,1+!column_vector);
    ret[0][0] = point.x;
    ret[column_vector][!column_vector] = point.y;
    return ret;
}

template <typename Numeric> Matrix<Numeric> convertToMatrix(const Point3D<Numeric> &point, bool column_vector)
{
    Matrix<Numeric> ret(1+2*column_vector, 1+2*!column_vector);
    ret[0][0] = point.x;
    ret[column_vector][!column_vector] = point.y;
    ret[2*column_vector][2*!column_vector] = point.z;
    return ret;
}

}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------