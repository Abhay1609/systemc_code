#include "tester.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

class ModuleTest : public Test
{
    public:
    ModuleTest()
    {
        auto tester = module_tester::instance();
        auto& module_inst = tester->module_inst;
    }
};

TEST_F(ModuleTest, TestProcess)
{
    

    // Here you can add expectations and assertions for the module's behavior
    // For example, you can check if the process is running or if certain outputs are produced
    // However, since the process runs indefinitely, you may want to use a timeout or mock the behavior for testing
}