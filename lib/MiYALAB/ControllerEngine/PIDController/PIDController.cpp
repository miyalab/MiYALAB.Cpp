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
// STL
#include <chrono>

#include "PIDController.hpp"

//-----------------------------
// Namespace & using
//-----------------------------

//-----------------------------
// Methods
//-----------------------------
namespace MiYALAB{
namespace Cpp{
namespace ControllerEngine{

/**
 * @brief Construct a new class object
 * 
 */
PIDController::PIDController()
{
    this->Reset();
    this->SetGain(0, 0, 0);
    this->SetAccelerateLimit(0);
    this->SetManipulateLimit(0);
    this->SetBrakeLimit(0);
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
    this->Reset();
    this->SetGain(kp, ki, kd);
    this->SetManipulateLimit(-1);
    this->SetAccelerateLimit(-1);
    this->SetBrakeLimit(-1);
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
    this->Reset();
    this->SetGain(kp, ki, kd);
    this->SetManipulateLimit(manipulate);
    this->SetAccelerateLimit(accelerate);
    this->SetBrakeLimit(brake);
}

/**
 * @brief PIDコントローラーリセットメソッド
 * 
 */
void PIDController::Reset()
{
    this->manipulateBefore = 0;
    this->errorBefore = 0;
    this->errorInt = 0;
    this->timeBefore = std::chrono::high_resolution_clock::now();
}

/**
 * @brief 制御量計算メソッド
 * 
 * @param error 偏差
 * @return double 制御量
 */
double PIDController::CalcManipulateVal(const double &error)
{
    double ret;

    // 時間変化
    const auto &time_now = std::chrono::high_resolution_clock::now();
    const double &dt = (double)std::chrono::duration_cast<std::chrono::microseconds>(time_now - timeBefore).count() / 1000000.0;
    
    // 積分計算(台形面積)
    this->errorInt += (error + errorBefore) / 2 * dt;

    // PID制御量計算
    ret =  gainP * error;
    ret += gainI * errorInt;
    ret += gainD * (error - errorBefore) / dt;
    
    // 制御量 上昇量制限
    if(ret >= 0){
        if(accelerateLimit > 0 && (ret - manipulateBefore)/dt > accelerateLimit) ret = manipulateBefore + accelerateLimit * dt;
        else if(brakeLimit > 0 && (ret - manipulateBefore)/dt < -brakeLimit)     ret = manipulateBefore - brakeLimit * dt;
    }
    else{
        if(accelerateLimit > 0 && (ret - manipulateBefore)/dt < accelerateLimit) ret = manipulateBefore - accelerateLimit * dt;
        else if(brakeLimit > 0 && (ret - manipulateBefore)/dt > -brakeLimit)     ret = manipulateBefore + brakeLimit * dt;
    }

    // 制御量 制限
    if(manipulateLimit >= 0.0){
        if(ret > manipulateLimit)       ret = manipulateLimit;
        else if(ret < -manipulateLimit) ret = -manipulateLimit;
    }

    // 次の呼び出し時用
    this->manipulateBefore = ret;
    this->errorBefore = error;
    this->timeBefore = time_now;

    return ret;
}
}
}
}

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------