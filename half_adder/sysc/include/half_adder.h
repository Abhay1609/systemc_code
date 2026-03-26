#pragma once
#include "systemc.h"

SC_MODULE(half_adder){
    
    public:
    sc_in<bool> a;
    sc_in<bool> b;

    void addition();

    sc_out<bool> sum;
    sc_out<bool> carry;

    SC_CTOR(half_adder){

        SC_METHOD(addition);
        sensitive(a);
        sensitive(b);
    }
};