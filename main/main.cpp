#include <stdio.h>

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

return 0;
}
