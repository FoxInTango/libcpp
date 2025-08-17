#include "instrument.h"

/**
 * http://allinone.vm:8080/#/chat/conv-1755451583437
 * __builtin_function_name __builtin_frame_address __builtin_return_address
 * gcc -finstrument-functions
 *     -finstrument-functions-exclude-file-list="crtbegin.o crtend.o" 
 *     -o example example.c 
 *     -Wl,--wrap=__cyg_profile_func_enter -Wl,--wrap=__cyg_profile_func_exit -ldl
 */
