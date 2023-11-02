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

//-----------------------------
// include
//-----------------------------
#include "MiYALAB/System/Clock/Stopwatch.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Methods
//-----------------------------
namespace MiYALAB {
namespace System{
Stopwatch::Stopwatch()
{
    m_is_active = false;
}

Stopwatch::~Stopwatch()
{

}

void Stopwatch::start()
{
    m_is_active = true;
    m_start_point = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop()
{
    m_is_active = false;
    m_time_span += TimeSpan(m_start_point, std::chrono::high_resolution_clock::now());
}

void Stopwatch::restart()
{
    this->start();
    m_time_span = TimeSpan(m_start_point, m_start_point);
}

TimeSpan Stopwatch::elapsedTime()
{
    if(m_is_active){
        return m_time_span + TimeSpan(m_start_point, std::chrono::high_resolution_clock::now());
    }
    return m_time_span;
}
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------