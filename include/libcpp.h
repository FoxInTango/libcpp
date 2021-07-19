#ifndef _LIB_CPP_H_
#define _LIB_CPP_H_
namespace foxintango {

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
 *  __FILE__
 *  __LINE__
 *  __FUNCTION__
 *  __PRETTY_FUNCTION__  namespace::classname::functionname
 * */
}
#endif
