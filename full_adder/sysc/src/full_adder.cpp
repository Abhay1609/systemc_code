#include "full_adder.h"

full_adder::full_addition()
{
    c_out = c1 | c1;
}

full_adder::~full_adder(){
    delete h1;
    delete h2;
}