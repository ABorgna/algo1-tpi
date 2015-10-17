#include "aux.h"

void trimIS(std::istream & is){
    while(is.peek() == ' ')
        is.ignore();
}

