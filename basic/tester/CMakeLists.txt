cmake_minimum_required(VERSION 3.0)
project(tester)
set(CMAKE_CXX_STANDARD 17)
set( MODULE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../sysc )
file(GLOB MODULE_SRC ${MODULE_DIR}/src/*.cpp)
set(LIBS pthread dl rt m)
add_executable(tester 
${MODULE_SRC}
tests.cpp
main.cpp)

target_include_directories(tester PUBLIC 
    /home/ratap/tools/systemc-2.3.4/include
    /home/ratap/tools/googletest/include
    
    ${MODULE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/


)

# target_compile_definitions(${TEST_NAME} PUBLIC 
# )

target_link_directories(tester PUBLIC  
    /home/ratap/tools/systemc-2.3.4/lib/Debug
    /home/ratap/tools/googletest/lib/Debug
)

target_link_libraries(tester PUBLIC 
    systemc
    gtest
    ${LIBS}
)