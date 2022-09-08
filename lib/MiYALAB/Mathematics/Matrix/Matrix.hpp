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


#ifndef __MIYALAB_CPP_MATHEMATICS_MATRIX_HPP__
#define __MIYALAB_CPP_MATHEMATICS_MATRIX_HPP__

//-----------------------------
// include
//-----------------------------
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB {
namespace Cpp{
namespace Mathematics{
/**
 * @brief Matrix class
 * 
 * @tparam NumericType 
 */
template<class NumericType>
struct Matrix{
public:
    // コンストラクタ
    Matrix(){}
    Matrix(const size_t &n): data(n, std::vector<NumericType>(n,0)){}
    Matrix(const size_t &rows, const size_t &cols): data(rows, std::vector<NumericType>(cols,0)){}
    
    // デストラクタ
    virtual ~Matrix(){}

    // 添字演算子
    const std::vector<NumericType> &operator[](const size_t &row) const {return data[row];};
    std::vector<NumericType> &operator[](const size_t &row) {return data[row];};

    // 算術演算子
    Matrix &operator +=(const Matrix &matrix);
    Matrix &operator -=(const Matrix &matrix);
    Matrix &operator *=(const Matrix &matrix) {return (*this = (*this)*matrix);}
    Matrix &operator *=(const NumericType &num);
    Matrix &operator /=(const NumericType &num);
    Matrix operator +(const Matrix &matrix) const {return Matrix(*this)+=matrix;};
    Matrix operator -(const Matrix &matrix) const {return Matrix(*this)-=matrix;};
    Matrix operator *(const Matrix &matrix) const;
    Matrix operator *(const NumericType &num) const {return Matrix(*this)*=num;};
    Matrix operator /(const NumericType &num) const {return Matrix(*this)/=num;};

    // 比較演算子
    bool operator ==(const Matrix &matrix) const;
    bool operator !=(const Matrix &matrix) const {return !(*this==matrix);}
    
    // 文字列化メソッド
    std::string ToString() const;

    // 行列計算計算メソッド
    Matrix Inverse() const;
    Matrix Transpose() const;
    NumericType Determinant() const;

    // 単位行列生成メソッド
    static Matrix I(size_t n){Matrix ret(n); for(size_t i=0; i<n; i++) ret[i][i]=1; return ret;}
    static inline Matrix E(size_t n) {return I(n);}

    // 行列要素関連メソッド
    size_t Height() const {return data.size();}
    size_t Rows()   const {return data.size();}
    size_t Width()  const {return data.size() ? data[0].size() : 0;}
    size_t Cols()   const {return data.size() ? data[0].size() : 0;}
    const NumericType &At(const size_t &row, const size_t &col) const {if(this->Cols()<=col || this->Rows()<=row) throw std::out_of_range("out_of_range"); return (*this)[row][col];}
    NumericType &At(const size_t &row, const size_t &col) {if(this->Cols()<=col || this->Rows()<=row) throw std::out_of_range("out_of_range"); return (*this)[row][col];}

private:
    std::vector<std::vector<NumericType>> data;
};
}
}
}

#endif

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------