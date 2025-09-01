/** 源码宏
 *  1,编译器识别
 *  2,编译平台识别
 *  3,标准库识别
 *  4,目标平台识别 目标平台版本识别
 *
 *  条件输出 放在libecho 中
 *     #define debug
 *
 *     #ifdef debug
 *         #define echo(x) print
 *     #else
 *         #define echo(x)
 *     #endif
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
        //const char* name = __PRETTY_FUNCTION__;
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
        //const char* name = __PRETTY_FUNCTION__;
        //printf("    __PRETTY_FUNCTION__:%s\n", name);
    }
};

template <class T>
class C :public T {
public:
    C() {
        this->print();
        //const char* name = __PRETTY_FUNCTION__;
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