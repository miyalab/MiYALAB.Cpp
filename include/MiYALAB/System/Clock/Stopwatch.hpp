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

#ifndef __MIYALAB_CPP_SYSTEM_STOPWATCH_STOPWATCH_HPP__
#define __MIYALAB_CPP_SYSTEM_STOPWATCH_STOPWATCH_HPP__

//-----------------------------
// include
//-----------------------------
#include <chrono>
#include "TimeSpan.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Struct
//-----------------------------
namespace MiYALAB {
namespace System{
class Stopwatch{
public:
    Stopwatch();
    virtual ~Stopwatch();
    void start();
    void stop();
    void restart();
    TimeSpan elapsedTime();
private:
    bool m_is_active;
    std::chrono::high_resolution_clock::time_point m_start_point;
    TimeSpan m_time_span;
};
}
}

#endif // __MIYALAB_CPP_SYSTEM_STOPWATCH_STOPWATCH_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------