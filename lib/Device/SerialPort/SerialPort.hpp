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

#ifndef __MIYALAB_CPP_DEVICE_SERIALPORT_SERIALPORT_HPP__
#define __MIYALAB_CPP_DEVICE_SERIALPORT_SERIALPORT_HPP__

#include <thread>
#include <mutex>
#include <termios.h>

namespace MiYALAB{
namespace Cpp{
namespace Device{
    /**
     * @brief ストップビット列挙型
     * 
     */
    enum StopBits
    {
        ONE,
        ONE_POINT_FIVE,
        TWO
    };

    enum Parity
    {
        NONE,
        ODD,
        EVEN
    };

    class SerialPort{
    public:
        SerialPort();
        virtual ~SerialPort();
        bool Open();
        bool Close();
        int Available();
        uint8_t Read();
        void Write(const std::string &sendData);

    private:
        int hPort;
        int baudrate;
        int databits;
        StopBits stopbits = StopBits::ONE;
        Parity parity = Parity::NONE;
        termios tio;
    };
}
}
}

#endif //__MIYALAB_CPP_DEVICE_SERIALPORT_SERIALPORT_HPP__