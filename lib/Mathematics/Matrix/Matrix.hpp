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

#ifndef __MIYALAB_CPP_MATHEMATICS_MATRIX_MATRIX_HPP__
#define __MIYALAB_CPP_MATHEMATICS_MATRIX_MATRIX_HPP__

//----------------------------------
// include
//----------------------------------
#include <vector>
#include <string>

namespace MiYALAB{
namespace Cpp{
namespace Mathematics{
    class Matrix{
    public:
        //---------- constructor & destructor------------
        Matrix();
        Matrix(const int &cols, const int &rows);
        Matrix(const Matrix &mat);
        ~Matrix();

        //----------------- public setter --------------- 
        int rows() const {return data.size();}
        int height() const {return data.size();}
        int cols() const {return data[0].size();}
        int width() const {return data[0].size();}

        //----------------- public method ---------------
        double Det();
        Matrix &Inv();
        std::string ToString();

        //--------------- operator overload -------------
        Matrix &operator +=(const Matrix &mat);
        Matrix &operator -=(const Matrix &mat);
        Matrix &operator *=(const Matrix &mat);
        Matrix &operator *=(const double &k);
        Matrix &operator /=(const double &mat);
        bool operator ==(const Matrix &mat);
        std::vector<double> operator [](const int &row) const{return data[row];}
        std::vector<double> &operator [](const int &row) {return data[row];}
        Matrix operator +(const Matrix &mat) {Matrix ret(*this); ret+=mat; return ret;}
        Matrix operator -(const Matrix &mat) {Matrix ret(*this); ret-=mat; return ret;}
        Matrix operator *(const Matrix &mat) {Matrix ret(*this); ret*=mat; return ret;}
        Matrix operator *(const double &k) {Matrix ret(*this); ret*=k; return ret;}
        Matrix operator /(const double &k) {Matrix ret(*this); ret/=k; return ret;}
        bool operator !=(const Matrix &mat) {return !((*this)==mat);}
        
    private:
        //----------------- private value ---------------
        std::vector<std::vector<double>> data;
    };
}
}
}

#endif //__MIYALAB_CPP_MATHEMATICS_MATRIX_MATRIX_HPP__