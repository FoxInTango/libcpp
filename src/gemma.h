/** MIT License

Copyright(c) 2022 FoxInTango <foxintango@yeah.net>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _LIBCPP_GEMMA_H_
#define _LIBCPP_GEMMA_H_
#include "define.h"
EXTERN_C_BEGIN
namespaceBegin(foxintango)

/** 数据分布
 */
class foxintangoAPI Gemma { //改名为 class 或 type ? 或者整一个prototype?

public:
    class ModelLoader;// 从序列化数据里加载类模型 XML,JSON,YAML,MARKDOWN
    class ModelLayout;// 类数据分布格式
public:
    void setLoader(ModelLoader* loader,int LOADER_TYPE);
protected:
    char** descriptions;
    Size   description_number;

    char* classname;// 层级
    char* spacename;// 层级
public:
    Gemma();
    ~Gemma();
public:
    const char* error(const int& code);
};
namespaceEnd
EXTERN_C_END
#endif