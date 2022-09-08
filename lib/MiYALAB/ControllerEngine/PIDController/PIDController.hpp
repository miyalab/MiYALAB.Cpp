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

#ifndef _MIYALAB_CPP_CONTROLLER_ENGINE_PID_CONTROLLER_HPP_
#define _MIYALAB_CPP_CONTROLLER_ENGINE_PID_CONTROLLER_HPP_

//-----------------------------
// include
//-----------------------------
#include <chrono>

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Class
//-----------------------------
namespace MiYALAB{
namespace Cpp{
namespace ControllerEngine{

/**
 * @brief PID Controller
 * 
 * @details 
 * 最大制御量制限，加速度制限，減速制限機能付きPIDコントローラ
 */
class PIDController {
public:
    PIDController();
    PIDController(const double &kp, const double &ki, const double &kd);
    PIDController(const double &kp, const double &ki, const double &kd, const double &manipulation, const double &acceleration, const double &brake);
    virtual ~PIDController(){}
    void SetGain(const double &kp, const double &ki, const double &kd){gainP = kp; gainI = ki; gainD = kd;}
    void SetManipulateLimit(const double &limit){manipulateLimit = limit;}
    void SetAccelerateLimit(const double &limit){accelerateLimit = limit;}
    void SetBrakeLimit(const double &limit)     {brakeLimit = limit;}
    void Reset();
    double CalcManipulateVal(const double &error);
    double GetManipulateVal(){return manipulateBefore;}
private:
    // PIDゲイン関連
    double gainP;
    double gainI;
    double gainD;

    // PID操作量計算用
    std::chrono::_V2::system_clock::time_point timeBefore;
    double errorBefore;
    double errorInt;

    // 制御量制限
    double manipulateLimit;

    // 制御量変化制限
    double manipulateBefore;
    double accelerateLimit;
    double brakeLimit;
};
 
}
}
}

#endif // _MIYALAB_CPP_CONTROLLER_ENGINE_PID_CONTROLLER_HPP_

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------