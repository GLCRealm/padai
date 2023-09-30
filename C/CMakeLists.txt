cmake_minimum_required(VERSION 3.23)
project(C)

set(CMAKE_CXX_STANDARD 23)

add_executable(C main.cpp codes/linkdelist.c )

add_executable(linkdelist codes/linkdelist.c )
add_executable(ansh ansh.c "Anshdeep Rawat/G1/Roll No -10/DSA.c")
add_executable(f codes/f.cpp)
add_executable(hello codes/hello.cpp)
add_executable(fghjk codes/fghjk.c)

add_executable(learnlinkedlist codes/learnlinkedlist.c)
add_executable(DSA "Anshdeep Rawat/G1/Roll No -10/DSA.c")
add_executable(code "Anshdeep Rawat/G1/Roll No -10/code.c")
add_executable(work "Anshdeep Rawat/G1/Roll No -10/work.c")