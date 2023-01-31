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
#include <algorithm>
#include "MiYALAB/Algorithm/Sort/Sort.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Function
//-----------------------------
namespace MiYALAB {

namespace Algorithm{
template<class T> void SelectSort(std::vector<T> &array)
{
    for(int i=0, loop1 = array.size() - 1; i<loop1; i++){
        int index = i;
        for(int j=i+1, loop2 = loop1 + 1; j<loop2; j++){
            if(array[index] > array[j]) index = j;
        }
        std::swap(array[i], array[index]);
    }    
}
template void SelectSort<char>(std::vector<char>&);
template void SelectSort<unsigned char>(std::vector<unsigned char>&);
template void SelectSort<short>(std::vector<short>&);
template void SelectSort<unsigned short>(std::vector<unsigned short>&);
template void SelectSort<int>(std::vector<int>&);
template void SelectSort<unsigned int>(std::vector<unsigned int>&);
template void SelectSort<long>(std::vector<long>&);
template void SelectSort<unsigned long>(std::vector<unsigned long>&);
template void SelectSort<long long>(std::vector<long long>&);
template void SelectSort<unsigned long long>(std::vector<unsigned long long>&);
template void SelectSort<float>(std::vector<float>&);
template void SelectSort<double>(std::vector<double>&);
template void SelectSort<long double>(std::vector<long double>&);

template<class T> void SelectSort(std::vector<T> &array, std::function<int(T, T)> compareFunctionPtr)
{
    for(int i=0, loop1 = array.size() - 1; i<loop1; i++){
        int index = i;
        for(int j=i+1, loop2 = loop1 + 1; j<loop2; j++){
            if(compareFunctionPtr(array[index], array[j]) > 0) index = j;
        }
        std::swap(array[i], array[index]);
    }
}
template void SelectSort<char>(std::vector<char>&, std::function<int(char, char)> compareFunctionPtr);
template void SelectSort<unsigned char>(std::vector<unsigned char>&, std::function<int(unsigned char, unsigned char)> compareFunctionPtr);
template void SelectSort<short>(std::vector<short>&, std::function<int(short, short)> compareFunctionPtr);
template void SelectSort<unsigned short>(std::vector<unsigned short>&, std::function<int(unsigned short, unsigned short)> compareFunctionPtr);
template void SelectSort<int>(std::vector<int>&, std::function<int(int, int)> compareFunctionPtr);
template void SelectSort<unsigned int>(std::vector<unsigned int>&, std::function<int(unsigned int, unsigned int)> compareFunctionPtr);
template void SelectSort<long>(std::vector<long>&, std::function<int(long, long)> compareFunctionPtr);
template void SelectSort<unsigned long>(std::vector<unsigned long>&, std::function<int(unsigned long, unsigned long)> compareFunctionPtr);
template void SelectSort<long long>(std::vector<long long>&, std::function<int(long long, long long)> compareFunctionPtr);
template void SelectSort<unsigned long long>(std::vector<unsigned long long>&, std::function<int(unsigned long long, unsigned long long)> compareFunctionPtr);
template void SelectSort<float>(std::vector<float>&, std::function<int(float, float)> compareFunctionPtr);
template void SelectSort<double>(std::vector<double>&, std::function<int(double, double)> compareFunctionPtr);
template void SelectSort<long double>(std::vector<long double>&, std::function<int(long double, long double)> compareFunctionPtr);
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------