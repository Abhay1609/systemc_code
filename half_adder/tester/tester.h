#pragma once 

#include  "half_adder.h"
SC_MODULE(tester)
{
    
    SC_CTOR(tester){
        
        a.bind(a_sig);
        h.a.bind(a_sig);
        b.bind(b_sig);
        h.b.bind(b_sig);
        sum.bind(sum_sig);
        h.sum.bind(sum_sig);
        carry.bind(carry_sig);
        h.carry.bind(carry_sig);

        SC_THREAD(tests);

    
    }

    sc_out<bool> a, b;
    sc_in<bool> sum, carry;

    sc_signal<bool> a_sig, b_sig, sum_sig, carry_sig;

    half_adder h{"half_adder_name"};

    void tests()
    {
        a = true;
        b = true;

        wait(sum.value_changed_event() | carry.value_changed_event() );

        if ( sum == false && carry == true)
        {
            std::cout << "Test Passed" << std::endl;
        }
        else
        {

            std::cout << "Test failed" << std::endl;
        }
    }


};