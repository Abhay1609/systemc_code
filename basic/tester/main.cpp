
#include "tester.h"
#include <iostream>
#include "gtest/gtest.h"


int sc_main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    auto *tester = module_tester::instance();
    sc_core::sc_start();
    return 0;
}