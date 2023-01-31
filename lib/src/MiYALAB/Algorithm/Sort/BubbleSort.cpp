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
template<class T> void BubbleSort(std::vector<T> &array)
{
    for(int i=0, loop = array.size() - 1; i<loop; i++){
        for(int j=loop + 1; j>i; j++){
            if(array[j] > array[j+1]) std::swap(array[j], array[j+1]);
        }
    }  
}
template void BubbleSort<char>(std::vector<char>&);
template void BubbleSort<unsigned char>(std::vector<unsigned char>&);
template void BubbleSort<short>(std::vector<short>&);
template void BubbleSort<unsigned short>(std::vector<unsigned short>&);
template void BubbleSort<int>(std::vector<int>&);
template void BubbleSort<unsigned int>(std::vector<unsigned int>&);
template void BubbleSort<long>(std::vector<long>&);
template void BubbleSort<unsigned long>(std::vector<unsigned long>&);
template void BubbleSort<long long>(std::vector<long long>&);
template void BubbleSort<unsigned long long>(std::vector<unsigned long long>&);
template void BubbleSort<float>(std::vector<float>&);
template void BubbleSort<double>(std::vector<double>&);
template void BubbleSort<long double>(std::vector<long double>&);

template<class T> void BubbleSort(std::vector<T> &array, const std::function<int(T, T)> &compareFunctionPtr)
{
    for(int i=0, loop = array.size() - 1; i<loop; i++){
        for(int j=loop + 1; j>i; j++){
            if(compareFunctionPtr(array[j], array[j+1]) > 0) std::swap(array[j], array[j+1]);
        }
    }
}
template void BubbleSort<char>(std::vector<char>&, const std::function<int(char, char)>&);
template void BubbleSort<unsigned char>(std::vector<unsigned char>&, const std::function<int(unsigned char, unsigned char)>&);
template void BubbleSort<short>(std::vector<short>&, const std::function<int(short, short)>&);
template void BubbleSort<unsigned short>(std::vector<unsigned short>&, const std::function<int(unsigned short, unsigned short)>&);
template void BubbleSort<int>(std::vector<int>&, const std::function<int(int, int)>&);
template void BubbleSort<unsigned int>(std::vector<unsigned int>&, const std::function<int(unsigned int, unsigned int)>&);
template void BubbleSort<long>(std::vector<long>&, const std::function<int(long, long)>&);
template void BubbleSort<unsigned long>(std::vector<unsigned long>&, const std::function<int(unsigned long, unsigned long)>&);
template void BubbleSort<long long>(std::vector<long long>&, const std::function<int(long long, long long)>&);
template void BubbleSort<unsigned long long>(std::vector<unsigned long long>&, const std::function<int(unsigned long long, unsigned long long)>&);
template void BubbleSort<float>(std::vector<float>&, const std::function<int(float, float)>&);
template void BubbleSort<double>(std::vector<double>&, const std::function<int(double, double)>&);
template void BubbleSort<long double>(std::vector<long double>&, const std::function<int(long double, long double)>&);
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------