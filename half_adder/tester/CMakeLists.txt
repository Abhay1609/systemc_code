cmake_minimum_required(VERSION 3.10)
project(half_adder)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(MODULE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../sysc )
set(SYSTEMC_HOME /home/abhay/tools/systemc-2.3.3)

include_directories(
    ${MODULE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${SYSTEMC_HOME}/include
    )

link_directories(${SYSTEMC_HOME}/lib)

add_executable( adder_test
    main.cpp
    ${MODULE_DIR}/src/half_adder.cpp
)



target_link_libraries(adder_test systemc)
