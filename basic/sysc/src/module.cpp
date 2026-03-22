#include "module.h"

module::module(sc_core::sc_module_name name) : sc_core::sc_module(name)
{
    SC_METHOD(process);
}

void module::process()
{

    std::cout << "Hello, SystemC!" << std::endl;

  
}