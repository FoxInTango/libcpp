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

#ifndef _LIBCPP_STRING_H_
#define _LIBCPP_STRING_H_
#include "define.h"
namespaceBegin(foxintango)
/**  UTF-8, a transformation format of ISO 10646
 * https://www.ietf.org/rfc/rfc3629.txt
 */

 /**
  * 赋值运算符 与 拷贝运算符
  *
  * 数值的科学计数法
  */
    template <typename T>
Size string_length(const T* s) {
    Size l = 0;
    while (s[l]) {
        l++;
    }

    return l;
}
/*
template <typename T>
Size string_copy(T* const t, const T* const s, const Size& length = 0) {
    if (!t || !s) return 0;
    Index index = 0;
    Size l = length > 0 ? length : string_length<T>(s);
    while (index < l && s[index] != 0) {
        t[index] = s[index];
        index++;
    }
    return index + 1;
}
*/
template <typename T>
bool string_compare(const T* t, const T* s, const Size& length = 0) {
    Index index = 0;
    Size l = length > 0 ? length : UNSIGNED_LONG_MAX;
    while (s[index] && t[index] && index < l) {
        if (s[index] != t[index]) return false;
        index++;
    }

    return true;
}

Size unicode_swap_endian(Unicode* unicode);
namespaceEnd
#endif
