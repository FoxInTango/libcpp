/*
 * libcpp
 *
 * Copyright (C) 2021 FoxInTango <foxintango@yeah.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#ifndef _DEFINE_H_
#define _DEFINE_H_

#define namespaceBegin(name) namespace name {
#define namespaceEnd }

namespaceBegin(foxintango)

/** EXTERN C
 * */
#ifdef __cplusplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END   }

#define EXTERN_C extern "C"
#endif 

/** Platform 
 * */
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
    #ifdef foxintangoEXPORT
        #define foxintangoAPI __declspec(dllexport)
    #else
        #define foxintangoAPI __declspec(dllimport)
    #endif
#elif defined(ANDROID) || defined(_ANDROID_)
    #define foxintangoAPI __attribute__ ((visibility("default")))
#elif defined(__linux__)
    #define foxintangoAPI __attribute__ ((visibility("default")))
#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
    #define foxintangoAPI __attribute__ ((visibility("default")))
#else
    #define foxintangoAPI
#endif


/** 源码宏
 *  1,编译器识别
 *  2,编译平台识别
 *  3,标准库识别
 *  4,目标平台识别 目标平台版本识别
 * 
 *  __FILE__
 *  __LINE__
 *  __FUNCTION__
 *  __PRETTY_FUNCTION__  namespace::classname::functionname
 * */

 /** some thing funny.
 */
class C1 {
public:
    C1() {}
    ~C1() {};
public:
    void print() {
        //printf("Here C1 printing.");
        const char* name = __PRETTY_FUNCTION__;
        //printf("    __PRETTY_FUNCTION__:%s\n", name);
    }
};
class C2 {
public:
    C2() {}
    ~C2() {};
public:
    void print() {
        //printf("Here C2 printing.");
        const char* name = __PRETTY_FUNCTION__;
        //printf("    __PRETTY_FUNCTION__:%s\n", name);
    }
};

template <class T>
class C :public T {
public:
    C() {
        this->print();
        const char* name = __PRETTY_FUNCTION__;
        //printf("    __PRETTY_FUNCTION__:%s\n", name);
    }
    ~C() {}
};
 /** 环境宏
  *  Pre - defined C / C++ Compiler Macros https://sourceforge.net/p/predef/wiki/Home/ 
  *     from C/C++有无宏指令可以指示当前编译器的位数？ - Pluto Hades的回答 - 知乎 https://www.zhihu.com/question/366578332/answer/977059288
  * https://stackoverflow.com/questions/48857887/pretty-function-in-visual-c
  *     EDG's C++ Front End documentation mentions that its supports some of the GCC pre-defines like __PRETTY_FUNCTION__ on page 71 - "1.13 Predefined Macros" together with Microsoft's __FUNCSIG__.
  * https://blog.csdn.net/fpcc/article/details/130896812 新的c++17以后提供了本地库std::source_location && 其实在VC中还有一个类似的宏__FUNCDNAME__，它也是用来得到函数的修饰名
  */
typedef unsigned long int Size;
typedef unsigned long int Index;
typedef int               Status;
typedef void*             Address;
typedef bool              Bool;
typedef char32_t          Unicode;
typedef int               Error;

#define UNSIGNED_INT_MAX  0XFFFF
#define UNSIGNED_LONG_MAX 0xFFFFFFFF

namespaceEnd
#endif
