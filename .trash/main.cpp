#include <unistd.h>
#include <stdio.h>
// clang main/main.cpp -o hello -std=c++11 -lstdc++

namespace foxintango {
namespace macro {
class pretty {
public:
    pretty() {
        printf("FILE: %s   LINE: %d    METHOD: %s\n",__FILE__,__LINE__,__PRETTY_FUNCTION__);
    }

    ~pretty() {}
};

}
}
void function() {
    printf("FILE: %s   LINE: %d    METHOD: %s\n",__FILE__,__LINE__,__FUNCTION__);
}
int main(int argc,char** argv) {
foxintango::macro::pretty s;

function();

//execl("su sparrow && /usr/bin/ls","/usr/local/");

return 0;
}
