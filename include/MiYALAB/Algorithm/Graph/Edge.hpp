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

#ifndef __MIYALAB_CPP_ALGORITHM_GRAPH_EDGE__
#define __MIYALAB_CPP_ALGORITHM_GRAPH_EDGE__

//-----------------------------
// include
//-----------------------------
#include <vector>

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB{
namespace Algorithm{
template<typename Numeric>
struct Edge{
public:
    int src;        // 始点
    int to;         // 終点
    Numeric cost;   // コスト

    Edge(int _to, Numeric _cost) : src(-1), to(_to), cost(_cost){}
    Edge(int _src, int _to, Numeric _cost) : src(_src), to(_to), cost(_cost){}
};
}
}

//-----------------------------
// template
//-----------------------------
namespace MiYALAB{
namespace Algorithm{
template struct Edge<char>;
template struct Edge<short>;
template struct Edge<int>;
template struct Edge<long>;
template struct Edge<long long>;
template struct Edge<float>;
template struct Edge<double>;
template struct Edge<long double>;

using Edge32f = Edge<float>;
using Edge64f = Edge<double>;

template<typename Numeric> using Edges = std::vector<Numeric>;
template<typename Numeric> using WeightGraph = std::vector<Edges<Numeric>>;
template<typename Numeric> using UnWeightGraph = std::vector<Edges<int>>;
}
}

#endif // __MIYALAB_CPP_ALGORITHM_GRAPH_EDGE__