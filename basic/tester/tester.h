#pragma once
#include <systemc>
#include "gtest/gtest.h"
#include "module.h"

template<typename T>
class sc_tester : public sc_core::sc_module
{
    public:
    static T* instance()
    {
        static T obj("tester");
        return &obj;
    }

    virtual ~sc_tester() = default;

    int get_status()
    {
        return m_status;
    }

    void enable_log() { m_log = true; }
    void enable_trace() { m_trace = true; }
    bool is_log_enabled() { return m_log; }

    void call_sim_stop_after_tests() { m_stop_sim = true; }

    protected:
    SC_HAS_PROCESS(sc_tester);
    sc_tester(sc_core::sc_module_name a_name)
        : sc_core::sc_module(a_name)
    {
        SC_THREAD(run);
    }

    void run()
    {
        m_status = RUN_ALL_TESTS();
        if (m_stop_sim)
        {
            sc_core::sc_stop();
        }
    }

    int  m_status   = 0;
    bool m_stop_sim = false;
    bool m_log = false;
    bool m_trace = false;
};

class module_tester : public sc_tester<module_tester>
{
    public:
    module_tester(sc_core::sc_module_name a_name) : sc_tester(a_name) {}
    module module_inst{"module_inst"};
};