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

#include <iostream>
#include <string>
#include <vector>
#include "Mathematics/Matrix/Matrix.hpp"
#include "Mathematics/Mathematics.hpp"
#include "Algorithm/Swap.hpp"
#include "Exception.hpp"

namespace MiYALAB{
namespace Cpp{
namespace Mathematics{
    /**
     * @brief 行列クラス: コンストラクタ
     * 
     */
    Matrix::Matrix()
    {

    }

    /**
     * @brief 行列クラス: コンストラクタ
     * 
     * @param rows 行数
     * @param cols 列数
     */
    Matrix::Matrix(const int &rows, const int &cols)
    {
        int i;
        data.resize(rows);
        for(i=0; i<rows; i++) data[i].resize(cols);
    }

    /**
     * @brief 行列クラス: コピーコンストラクタ
     * 
     * @param mat 
     */
    Matrix::Matrix(const Matrix &mat)
    {
        this->data = mat.data;
    }

    /**
     * @brief 行列クラス: デストラクタ
     * 
     */
    Matrix::~Matrix()
    {
        
    }

    /**
     * @brief 行列クラス: 加算オペレーター
     * 
     * @param mat 
     * @return Matrix& 
     */
    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        // サイズが異なる場合はExceptionをthrow
        if(this->cols() != mat.cols() || this->rows() != mat.rows()){
            throw Exception("Input a matrix of the same size.");
        }

        // 計算
        int i,j;
        for(i=0; i<this->rows(); i++){
            for(j=0; j<this->cols(); j++){
                (*this)[i][j] += mat[i][j];
            }
        }
        return (*this);
    }
    
    /**
     * @brief 行列クラス: 減算オペレーター
     * 
     * @param mat 
     * @return Matrix& 
     */
    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        // サイズが異なる場合はExceptionをthrow
        if(this->cols() != mat.cols() || this->rows() != mat.rows()){
            throw Exception("Input a matrix of the same size.");
        }

        // 計算
        int i,j;
        for(i=0; i<this->rows(); i++){
            for(j=0; j<this->cols(); j++){
                (*this)[i][j] -= mat[i][j];
            }
        }
        return (*this);
    }

    /**
     * @brief 行列: 乗算オペレーター
     * 
     * @param mat 
     * @return Matrix& 
     */
    Matrix &Matrix::operator*=(const Matrix &mat)
    {
        // サイズが異なる場合はExceptionをthrow
        if(this->cols() != mat.rows()){
            throw Exception("Input a matrix of the same size.");
        }

        // 計算
        Matrix *ret = new Matrix(this->rows(), mat.cols());
        int i,j,k;
        for(i=0; i<this->rows(); i++){
            for(j=0; j<mat.cols(); j++){
                for(k=0; k<this->cols(); k++){
                    (*ret)[i][j] += (*this)[i][k] * mat[k][j];
                }
            }
        }
        return (*ret);
    }

    /**
     * @brief 行列クラス: 乗算オペレーター
     * 
     * @param k 
     * @return Matrix& 
     */
    Matrix &Matrix::operator*=(const double &k)
    {
        // 計算
        int i,j;
        for(i=0; i<this->rows(); i++){
            for(j=0; j<this->cols(); j++){
                (*this)[i][j] *= k;
            }
        }
        return (*this);
    }

    /**
     * @brief 行列クラス: 減算オペレーター
     * 
     * @param k 
     * @return Matrix& 
     */
    Matrix &Matrix::operator/=(const double &k)
    {
        // 計算
        int i,j;
        for(i=0; i<this->rows(); i++){
            for(j=0; j<this->cols(); j++){
                (*this)[i][j] /= k;
            }
        }
        return (*this);
    }

    /**
     * @brief 行列クラス: 等価オペレーター
     * 
     * @param mat 
     * @return true 
     * @return false 
     */
    bool Matrix::operator==(const Matrix &mat)
    {
        // サイズが異なるときはfalse
        if(this->cols() != mat.cols() || this->rows() != mat.rows()){
            return false;
        }

        // 計算
        int i,j;
        for(i=0; i<this->rows(); i++){
            for(j=0; j<this->cols(); j++){
                if((*this)[i][j] != mat[i][j]) return false;
            }
        }
        // すべての値が一致
        return true;
    }

    struct LUP{
    public:
        Matrix mat;
        std::vector<double> perm;
        int toggle;
    private:
    };

    /**
     * @brief 
     * 
     * @param mat 
     * @param ret 
     */
    void DecomposeLUP(const Matrix &mat, LUP &ret)
    {
        int i,j,k,pRow;
        double colMax;
        ret.toggle = 1;
        ret.mat = mat;
        ret.perm.resize(mat.height());
        for(i=0; i<ret.perm.size(); i++) ret.perm[i] = i;
        
        for(j=0; j<mat.height() - 1; j++){
            colMax = Mathematics::Abs(ret.mat[j][j]);
            pRow = j;
            for(i=j+1; i<mat.height(); i++){
                if(ret.mat[i][j] > colMax){
                    colMax = ret.mat[i][j];
                    pRow = i;
                }
            }
            if(pRow != j){
                Algorithm::Swap(&ret.mat[pRow], &ret.mat[j]);
                Algorithm::Swap(&ret.perm[pRow], &ret.perm[j]);
                ret.toggle = -ret.toggle;
            }
            if(Mathematics::Abs(ret.mat[j][j]) < 1.0E-10){
                ret.toggle = 0;
                return;
            }
            for(i=j+1; i<mat.height(); i++){
                ret.mat[i][j] /= ret.mat[j][j];
                for(k=j+1; k<mat.height(); k++) ret.mat[i][k] -= ret.mat[i][j] * ret.mat[j][k];
            }
        }
    }

    /**
     * @brief 
     * 
     * @param luMat 
     * @param b 
     * @param x 
     */
    void HelperSolve(const Matrix &luMat, 
                        const std::vector<double> &b, 
                        std::vector<double> &x)
    {
        int i,j,n = luMat.height();
        double sum;
        x.resize(n);
        for(i=0; i<b.size(); i++) x[i] = b[i];
        
        for(i=1; i<n; i++){
            sum = x[i];
            for(j=0; j<i; j++) sum -= luMat[i][j] * x[j];
            x[i] = sum;
        }
        x[n-1] /= luMat[n-1][n-1];
        for(i=n-2; i>=0; i--)
        {
            sum = x[i];
            for(j=i+1; j<n; j++) sum-= luMat[i][j] * x[j];
            x[i] = sum / luMat[i][i];
        }
    }

    /**
     * @brief 行列クラス: 逆行列計算
     * 
     * @param mat 行列
     * @return Matrix = mat^{-1}
     */
    Matrix &Matrix::Inv()
    {
        int i,j,n = this->height();
        Matrix *ret = new Matrix(*this);

        LUP lum;
        DecomposeLUP(*this, lum);
        if(lum.toggle == 0) throw Exception("Unable to compute inversed matrix.");
        
        std::vector<double> b(n);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(i == lum.perm[j]) b[j] = 1.0;
                else b[j] = 0.0;
            }
            std::vector<double> x;
            HelperSolve(lum.mat, b, x);
            for(j=0; j<n; j++) (*ret)[j][i] = x[j];
        }
        return *ret;
    }

    /**
     * @brief 行列クラス: 行列式計算関数
     * 
     * @param mat 行列
     * @return double 行列式値
     */
    double Matrix::Det()
    {
        LUP lum;
        DecomposeLUP(*this, lum);
        if(lum.toggle == 0) throw Exception("Unable to compute matrix determinate.");
        int i;
        double ret;
        ret = lum.toggle;
        for(i=0; i<lum.mat.height(); i++){
            ret *= lum.mat[i][i];
        }
        return ret; 
    }

    /**
     * @brief 行列クラス: 文字列化
     * 
     * @return std::string 
     */
    std::string Matrix::ToString()
    {
        std::string ret;
        ret = "[";

        int i,j;
        for(i=0; i<this->rows(); i++){
            ret += "[";
            for(j=0; j<this->cols(); j++){
                ret += std::to_string((*this)[i][j]) + ", ";
            }
            ret[ret.length() - 2] = ']';
            ret[ret.length() - 1] = '\n';
        }
        ret[ret.length() - 1] = ']';
        return ret;
    }
}
}
}