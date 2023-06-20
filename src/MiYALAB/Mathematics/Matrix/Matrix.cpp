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
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include "MiYALAB/Mathematics/Matrix/Matrix.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Helper function
//-----------------------------
namespace MiYALAB {
namespace Mathematics{

template<typename Numeric>
struct LUP{
public:
    LUP(const MatrixType<Numeric> &matrix): mat(matrix), perm(matrix.height()){}
    MatrixType<Numeric> mat;
    std::vector<Numeric> perm;
    int toggle;
};

template<typename Numeric> 
void decomposeLUP(LUP<Numeric> &ret)
{
    const size_t &n = ret.mat.height();

    int p_row;
    Numeric col_max;
    ret.toggle = 1;
    for(size_t i=0; i<n; i++) ret.perm[i] = i;
    
    for(size_t j=0; j<n-1; j++){
        col_max = std::abs(ret.mat[j][j]);
        p_row = j;
        for(int i=j+1; i<n; i++){
            if(ret.mat[i][j] > col_max){
                col_max = ret.mat[i][j];
                p_row = i;
            }
        }
        if(p_row != j){
            std::swap(ret.mat[p_row], ret.mat[j]);
            std::swap(ret.perm[p_row],ret.perm[j]);
            ret.toggle = -ret.toggle;
        }
        if(std::abs(ret.mat[j][j]) < 1.0E-10){
            ret.toggle = 0;
            return;
        }
        for(size_t i=j+1; i<n; i++){
            ret.mat[i][j] /= ret.mat[j][j];
            for(size_t k=j+1; k<n; k++) ret.mat[i][k] -= ret.mat[i][j] * ret.mat[j][k];
        }
    }
}

/**
 * @brief 
 * 
 * @tparam Numeric 
 * @param luMat 
 * @param b 
 * @param x 
 */
template<typename Numeric>
void helperSolve(const MatrixType<Numeric> &lu_matrix, const std::vector<Numeric> &b, std::vector<Numeric> &x)
{
    const size_t &n = lu_matrix.height();
    Numeric sum;
    x.resize(n);
    for(size_t i=0; i<b.size(); i++) x[i] = b[i];
    
    for(size_t i=1; i<n; i++){
        sum = x[i];
        for(size_t j=0; j<i; j++) sum -= lu_matrix[i][j] * x[j];
        x[i] = sum;
    }
    x[n-1] /= lu_matrix[n-1][n-1];
    for(long i=n-2; 0<=i; i--){
        sum = x[i];
        for(size_t j=i+1; j<n; j++) sum-= lu_matrix[i][j] * x[j];
        x[i] = sum / lu_matrix[i][i];
    }
}
}
}

//-----------------------------
// Methods
//-----------------------------
namespace MiYALAB {
namespace Mathematics{
/**
 * @brief 加算代入メソッド
 * 
 * @tparam Numeric 
 * @param matrix 
 * @return MatrixType<Numeric>& 
 */
template<typename Numeric> MatrixType<Numeric> &MatrixType<Numeric>::operator+=(const MatrixType &matrix)
{
    if(this->cols() != matrix.cols() || this->rows() != matrix.rows()) throw "Input matrices have different sizes.";

    for(size_t i=0; i<this->rows(); i++){
        for(size_t j=0; j<this->cols(); j++){
            (*this)[i][j] += matrix[i][j];
        }
    }
    return *this;
}

/**
 * @brief 減算代入メソッド
 * 
 * @tparam Numeric 
 * @param matrix 
 * @return MatrixType<Numeric>& 
 */
template<typename Numeric> MatrixType<Numeric> &MatrixType<Numeric>::operator-=(const MatrixType &matrix)
{
    if(this->cols() != matrix.cols() || this->rows() != matrix.rows()) throw "Input matrices have different sizes.";

    for(size_t i=0; i<this->rows(); i++){
        for(size_t j=0; j<this->cols(); j++){
            (*this)[i][j] -= matrix[i][j];
        }
    }
    return *this;
}

/**
 * @brief 乗算メソッド
 * 
 * @tparam Numeric 
 * @param matrix 
 * @return MatrixType<Numeric> 
 * 
*/
template<typename Numeric> MatrixType<Numeric> MatrixType<Numeric>::operator*(const MatrixType &matrix) const 
{
    if(this->cols() != matrix.rows()) throw "Input matrices have different sizes.";

    MatrixType<Numeric> ret(this->rows(), matrix.cols());
    for(size_t i=0; i<this->rows(); i++){
        for(size_t k=0; k<this->cols(); k++){
            for(size_t j=0; j<matrix.cols(); j++){
                ret[i][j] += (*this)[i][k] * matrix[k][j];
            }
        }
    }
    return ret;
}

/**
 * @brief スカラ積メソッド
 * 
 * @tparam Numeric 
 * @param num 
 * @return MatrixType<Numeric>& 
 */
template<typename Numeric> MatrixType<Numeric> &MatrixType<Numeric>::operator*=(const Numeric &num)
{
    for(size_t i=0; i<this->rows(); i++){
        for(size_t j=0; j<this->cols(); j++){
            (*this)[i][j] *= num;
        }
    }
    return *this;
}

/**
 * @brief スカラ積メソッド（除算）
 * 
 * @tparam Numeric 
 * @param num 
 * @return MatrixType<Numeric>& 
 */
template<typename Numeric> MatrixType<Numeric> &MatrixType<Numeric>::operator/=(const Numeric &num)
{
    for(size_t i=0; i<this->rows(); i++){
        for(size_t j=0; j<this->cols(); j++){
            (*this)[i][j] /= num;
        }
    }
    return *this;
}

/**
 * @brief 等価判定メソッド
 * 
 * @tparam Numeric 
 * @param matrix 
 * @return true 
 * @return false 
 */
template<typename Numeric> bool MatrixType<Numeric>::operator==(const MatrixType &matrix) const 
{
    if(this->cols() != matrix.cols() || this->rows() != matrix.rows()) return false;

    for(size_t i=0; i<this->rows(); i++){
        for(size_t j=0; j<this->cols(); j++){
            if((*this)[i][j] != matrix[i][j]) return false;
        }
    }
    return true;
}

/**
 * @brief 文字列化メソッド
 * 
 * @tparam Numeric 
 * @return std::string 
 */
template<typename Numeric> std::string MatrixType<Numeric>::toString() const
{
    std::string ret = "[";

    for(size_t i=0; i<this->rows(); i++){
        ret += "[";
        for(size_t j=0; j<this->cols(); j++) ret += std::to_string((*this)[i][j]) + ", ";
        ret[ret.length() - 2] = ']';
        ret[ret.length() - 1] = '\n';
    }
    ret[ret.length() - 1] = ']';
    return ret;
}

/**
 * @brief 逆行列計算メソッド
 * 
 * @tparam Numeric 
 * @return MatrixType<Numeric> 
 */
template<typename Numeric> MatrixType<Numeric> MatrixType<Numeric>::inverse() const
{
    LUP<Numeric> lum(*this);
    decomposeLUP(lum);
    if(lum.toggle == 0) throw "Unable to compute inverse matrix.";

    MatrixType ret(*this);
    
    std::vector<Numeric> b(this->height());
    for(size_t i=0; i<this->height(); i++){
        for(size_t j=0; j<this->height(); j++){
            if(i == lum.perm[j]) b[j] = 1.0;
            else b[j] = 0.0;
        }
        std::vector<Numeric> x;
        helperSolve(lum.mat, b, x);
        for(size_t j=0; j<this->height(); j++) ret[j][i] = x[j];
    }
    return ret;
}

/**
 * @brief 行列式計算メソッド
 * 
 * @tparam Numeric 
 * @return double 
 */
template<typename Numeric> Numeric MatrixType<Numeric>::determinant() const
{
    LUP<Numeric> lum(*this);
    decomposeLUP(lum);
    if(lum.toggle == 0) throw "Unable to compute matrix determinate.";
    
    Numeric ret = lum.toggle;
    for(size_t i=0; i<lum.mat.height(); i++) ret *= lum.mat[i][i];
    return ret; 
}

/**
 * @brief 転置行列計算メソッド
 * 
 * @tparam Numeric 
 * @return MatrixType<Numeric> 
 */
template<typename Numeric> MatrixType<Numeric> MatrixType<Numeric>::transpose() const
{
    MatrixType ret(this->cols(), this->rows());
    for(size_t i=0; i<this->rows(); i++){
        for(size_t j=0; j<this->cols(); j++){
            ret[j][i] = (*this)[i][j];
        }
    }
    return ret;
}

}
}

//-----------------------------
// template
//-----------------------------
namespace MiYALAB{
namespace Mathematics{
template struct MatrixType<char>;
template struct MatrixType<short>;
template struct MatrixType<int>;
template struct MatrixType<long>;
template struct MatrixType<long long>;
template struct MatrixType<float>;
template struct MatrixType<double>;
template struct MatrixType<long double>;
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------