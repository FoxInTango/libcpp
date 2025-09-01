/** Դ���
 *  1,������ʶ��
 *  2,����ƽ̨ʶ��
 *  3,��׼��ʶ��
 *  4,Ŀ��ƽ̨ʶ�� Ŀ��ƽ̨�汾ʶ��
 *
 *  ������� ����libecho ��
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
/** ������
 *  Pre - defined C / C++ Compiler Macros https://sourceforge.net/p/predef/wiki/Home/
 *     from C/C++���޺�ָ�����ָʾ��ǰ��������λ���� - Pluto Hades�Ļش� - ֪�� https://www.zhihu.com/question/366578332/answer/977059288
 * https://stackoverflow.com/questions/48857887/pretty-function-in-visual-c
 *     EDG's C++ Front End documentation mentions that its supports some of the GCC pre-defines like __PRETTY_FUNCTION__ on page 71 - "1.13 Predefined Macros" together with Microsoft's __FUNCSIG__.
 * https://blog.csdn.net/fpcc/article/details/130896812 �µ�c++17�Ժ��ṩ�˱��ؿ�std::source_location && ��ʵ��VC�л���һ�����Ƶĺ�__FUNCDNAME__����Ҳ�������õ�������������
 */