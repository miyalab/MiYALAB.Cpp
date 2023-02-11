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
// STL
#include <chrono>
#include "MiYALAB/ControllerEngine/PIDController/PIDController.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Methods
//-----------------------------
namespace MiYALAB{
namespace ControllerEngine{

/**
 * @brief Construct a new class object
 * 
 */
PIDController::PIDController()
{
    this->reset();
    this->setGain(0.0, 0.0, 0.0);
    this->setAccelerateLimit(0.0);
    this->setManipulateLimit(0.0);
    this->setBrakeLimit(0.0);
}

/**
 * @brief Construct a new PIDController::PIDController object
 * 
 * @param kp 比例ゲイン
 * @param ki 積分ゲイン
 * @param kd 微分ゲイン
 */
PIDController::PIDController(const double &kp, const double &ki, const double &kd)
{
    this->reset();
    this->setGain(kp, ki, kd);
    this->setManipulateLimit(-1.0);
    this->setAccelerateLimit(-1.0);
    this->setBrakeLimit(-1.0);
}

/**
 * @brief Construct a new PIDController::PIDController object
 * 
 * @param kp 比例ゲイン
 * @param ki 積分ゲイン
 * @param kd 微分ゲイン
 * @param manipulate 最大制御量
 * @param accelerate 最大上昇量
 * @param brake 最大下降量
 */
PIDController::PIDController(const double &kp, const double &ki, const double &kd, const double &manipulate, const double &accelerate, const double &brake)
{
    this->reset();
    this->setGain(kp, ki, kd);
    this->setManipulateLimit(manipulate);
    this->setAccelerateLimit(accelerate);
    this->setBrakeLimit(brake);
}

/**
 * @brief PIDコントローラーリセットメソッド
 * 
 */
void PIDController::reset()
{
    this->manipulate_before = 0.0;
    this->error_before = 0.0;
    this->error_int = 0.0;
    this->time_before = std::chrono::high_resolution_clock::now();
}

/**
 * @brief 制御量計算メソッド
 * 
 * @param error 偏差
 * @return double 制御量
 */
double PIDController::calcManipulateVal(const double &error)
{
    // 時間変化
    const auto &time_now = std::chrono::high_resolution_clock::now();
    const double &dt = (double)std::chrono::duration_cast<std::chrono::microseconds>(time_now - time_before).count() / 1000000.0;
    
    // 積分計算(台形面積)
    this->error_int += (error + error_before) / 2.0 * dt;

    // PID制御量計算
    double ret =  this->gain_p * error                         // 比例制御
                + this->gain_i * error_int                     // 積分制御
                + this->gain_d * (error - error_before) / dt;   // 微分制御
    
    // 制御量 変化量制限
    if(ret >= 0.0){
        if(accelerate_limit > 0.0 && (ret - manipulate_before)/dt > accelerate_limit) ret = manipulate_before + accelerate_limit * dt;
        else if(brake_limit > 0.0 && (ret - manipulate_before)/dt < -brake_limit)     ret = manipulate_before - brake_limit * dt;
    }
    else{
        if(accelerate_limit > 0.0 && (ret - manipulate_before)/dt < accelerate_limit) ret = manipulate_before - accelerate_limit * dt;
        else if(brake_limit > 0.0 && (ret - manipulate_before)/dt > -brake_limit)     ret = manipulate_before + brake_limit * dt;
    }

    // 制御量 制限
    if(manipulate_limit >= 0.0){
        if(ret > manipulate_limit)       ret = manipulate_limit;
        else if(ret < -manipulate_limit) ret = -manipulate_limit;
    }

    // 次の呼び出し時用
    this->manipulate_before = ret;
    this->error_before = error;
    this->time_before = time_now;

    return ret;
}
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------