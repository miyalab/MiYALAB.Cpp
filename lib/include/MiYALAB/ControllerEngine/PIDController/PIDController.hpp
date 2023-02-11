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
    void setGain(const double &kp, const double &ki, const double &kd){gain_p = kp; gain_i = ki; gain_d = kd;}
    void setManipulateLimit(const double &limit){manipulate_limit = limit;}
    void setAccelerateLimit(const double &limit){accelerate_limit = limit;}
    void setBrakeLimit(const double &limit)     {brake_limit = limit;}
    void reset();
    double calcManipulateVal(const double &error);
    double getManipulateVal(){return manipulate_before;}
private:
    // PIDゲイン関連
    double gain_p;
    double gain_i;
    double gain_d;

    // PID操作量計算用
    std::chrono::_V2::system_clock::time_point time_before;
    double error_before;
    double error_int;

    // 制御量制限
    double manipulate_limit;

    // 制御量変化制限
    double manipulate_before;
    double accelerate_limit;
    double brake_limit;
};
 
}
}

#endif // _MIYALAB_CPP_CONTROLLER_ENGINE_PID_CONTROLLER_HPP_

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------