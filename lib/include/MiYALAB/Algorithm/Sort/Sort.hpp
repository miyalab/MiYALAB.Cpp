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

#ifndef __MIYALAB_CPP_ALGORITHM_SORT_SELECT_SORT__
#define __MIYALAB_CPP_ALGORITHM_SORT_SELECT_SORT__

//-----------------------------
// include
//-----------------------------
#include <vector>
#include <functional>

//-----------------------------
// Function
//-----------------------------
namespace MiYALAB{
namespace Algorithm{
template<class T> void SelectSort(std::vector<T> &array);
template<class T> void SelectSort(std::vector<T> &array, std::function<int(T, T)> compFunctionPtr);

template<class T> void MergeSort(std::vector<T> &array);
template<class T> void MergeSort(std::vector<T> &array, std::function<int(T, T)> compFunctionPtr);

template<class T> void BubbleSort(std::vector<T> &array);
template<class T> void BubbleSort(std::vector<T> &array, std::function<int(T, T)> compFunctionPtr);

template<class T> void QuickSort(std::vector<T> &array);
template<class T> void QuickSort(std::vector<T> &array, std::function<int(T, T)> compFunctionPtr);
}
}

#endif // __MIYALAB_CPP_ALGORITHM_SORT_SELECT_SORT__