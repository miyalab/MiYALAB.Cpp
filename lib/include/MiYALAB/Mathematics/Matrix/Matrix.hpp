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


#ifndef __MIYALAB_CPP_MATHEMATICS_MATRIX_MATRIX_HPP__
#define __MIYALAB_CPP_MATHEMATICS_MATRIX_MATRIX_HPP__

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
namespace Mathematics{
/**
 * @brief MatrixType class
 * 
 * @tparam Numeric 
 */
template<typename Numeric>
struct MatrixType{
public:
    // コンストラクタ
    MatrixType(){}
    MatrixType(const size_t &n): data(n, std::vector<Numeric>(n,0)){}
    MatrixType(const size_t &rows, const size_t &cols): data(rows, std::vector<Numeric>(cols,0)){}
    
    // デストラクタ
    virtual ~MatrixType(){}

    // 添字演算子
    const std::vector<Numeric> &operator[](const size_t &row) const {return data[row];};
    std::vector<Numeric> &operator[](const size_t &row) {return data[row];};

    // 算術演算子
    MatrixType &operator +=(const MatrixType &matrix);
    MatrixType &operator -=(const MatrixType &matrix);
    MatrixType &operator *=(const MatrixType &matrix) {return (*this = (*this)*matrix);}
    MatrixType &operator *=(const Numeric &num);
    MatrixType &operator /=(const Numeric &num);
    MatrixType operator +(const MatrixType &matrix) const {return MatrixType(*this)+=matrix;};
    MatrixType operator -(const MatrixType &matrix) const {return MatrixType(*this)-=matrix;};
    MatrixType operator *(const MatrixType &matrix) const;
    MatrixType operator *(const Numeric &num) const {return MatrixType(*this)*=num;};
    MatrixType operator /(const Numeric &num) const {return MatrixType(*this)/=num;};

    // 比較演算子
    bool operator ==(const MatrixType &matrix) const;
    bool operator !=(const MatrixType &matrix) const {return !(*this==matrix);}
    
    // 文字列化メソッド
    std::string toString() const;

    // 行列計算計算メソッド
    MatrixType inverse() const;
    MatrixType transpose() const;
    Numeric determinant() const;

    // 単位行列生成メソッド
    static MatrixType I(size_t n){MatrixType ret(n); for(size_t i=0; i<n; i++) ret[i][i]=1; return ret;}
    static inline MatrixType E(size_t n) {return I(n);}

    // 行列要素関連メソッド
    size_t height() const {return data.size();}
    size_t rows()   const {return data.size();}
    size_t width()  const {return data.size() ? data[0].size() : 0;}
    size_t cols()   const {return data.size() ? data[0].size() : 0;}
    const Numeric &at(const size_t &row, const size_t &col) const {if(this->cols()<=col || this->rows()<=row) throw std::out_of_range("out_of_range"); return (*this)[row][col];}
    Numeric &at(const size_t &row, const size_t &col) {if(this->cols()<=col || this->rows()<=row) throw std::out_of_range("out_of_range"); return (*this)[row][col];}

private:
    std::vector<std::vector<Numeric>> data;
};
}
}

//-----------------------------
// using
//-----------------------------
namespace MiYALAB{
namespace Mathematics{
using Matrix32 = MatrixType<float>;
using Matrix = MatrixType<double>;
}
}

#endif // __MIYALAB_CPP_MATHEMATICS_MATRIX_MATRIX_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------