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

#ifndef __MIYALAB_CPP_SYSTEM_STOPWATCH_TIME_SPAN_HPP__
#define __MIYALAB_CPP_SYSTEM_STOPWATCH_TIME_SPAN_HPP__

//-----------------------------
// include
//-----------------------------
#include <chrono>

//-----------------------------
// Namespace & using
//-----------------------------
constexpr long long UNIT_NANO = 1000000000LL;

//-----------------------------
// Struct
//-----------------------------
namespace MiYALAB {
namespace System{
class TimeSpan{
private:
    long long m_nanosec = 0;
    long long m_sec = 0;
public:
    TimeSpan(){}
    TimeSpan(std::chrono::high_resolution_clock::time_point tp1, std::chrono::high_resolution_clock::time_point tp2){
        auto nanosec = std::chrono::duration_cast<std::chrono::nanoseconds>(tp2 - tp1).count();
        m_nanosec = nanosec % UNIT_NANO;
        m_sec     = nanosec / UNIT_NANO;

    }
    virtual ~TimeSpan(){}

    double totalSeconds()     {return (double)m_sec + (double)m_nanosec / UNIT_NANO;}
    double totalMilliseconds(){return (double)m_sec * UNIT_NANO + (double)m_nanosec / 1000000.0;}
    double totalMicroseconds(){return (double)m_sec * UNIT_NANO + (double)m_nanosec / 1000.0;}
    double totalNanoseconds() {return (double)m_sec * UNIT_NANO + (double)m_nanosec;}
    
    TimeSpan operator+=(const TimeSpan &ts){
        m_nanosec += ts.m_nanosec;
        m_sec += ts.m_sec + (m_nanosec / UNIT_NANO);
        m_nanosec %= UNIT_NANO;
        return *this;
    } 
    TimeSpan operator+ (const TimeSpan &ts){return TimeSpan(*this)+=ts;}
    
    long long nanoseconds(){return m_nanosec % 1000;} 
    long long microseconds(){return (m_nanosec / 1000) % 1000;} 
    long long milliseconds(){return m_nanosec / 1000000;} 
    long long seconds(){return m_sec % 60;}
    long long minutes(){return (m_sec / 60) % 60;}
    long long hours(){return m_sec / 3600;}
};
}
}

#endif // __MIYALAB_CPP_SYSTEM_STOPWATCH_TIME_SPAN_HPP__

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------