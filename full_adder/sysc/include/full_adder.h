#include "systemc.h"

SC_MODULE(full_adder){

    sc_in<bool> a, b, c_in;
    sc_out<bool> sum, c_out;
    sc_signal<bool> c1, s1, c2;


    SC_CTOR(full_adder){
        h1 = new half_adder("half_adder"); 
        h1->a(a);
        h1->b(b);
        h1->carry(c1);
        h1->sum(s1);
        


        h2 = new half_adder("half_adder");
        //Position association
        (*h2)(s1, c_in, sum, c2);

        SC_METHOD(prc_or);
        sensitive << c1 << c2;
        dont_initialize();
    }
    half_adder* h1;
    half_adder* h2;

    void prc_or();

    ~half_adder();
}