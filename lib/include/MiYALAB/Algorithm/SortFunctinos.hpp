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

#ifndef __MIYALAB_CPP_ALGORITHM_SORT_FUNCTIONS__
#define __MIYALAB_CPP_ALGORITHM_SORT_FUNCTIONS__

namespace MiYALAB{
namespace Cpp{
namespace Algorithm{
/**
 * @brief 選択ソート
 * 
 * @tparam type 
 * @param array ソートする配列
 * @param length 配列長
 * @param compFunc 比較関数(-1:n1が小さい 1:n2が大きい 0:等しい)
 */
template<typename type> void SelectSort(type *array, int length, int (*cmpFunc)(type n1 , type n2))
{
    int i, j, calc, sel;
    type max;

    for(i=0; i<length-1; i++) {
        max = array[i];
        sel = i;
        for(j=i+1; j<length; j++){
            calc = cmpFunc(max, array[j]);
            
            // 第2引数の方が大きい
            if(calc == 1){
                sel = j;
                max = array[j];
            }
        }
        Swap(&array[i], &array[sel]);
    }
}

}
}
}

#endif