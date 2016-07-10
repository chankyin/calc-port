cmake_minimum_required(VERSION 3.3)
project(calc_port)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES prog/quadratic.cpp libcalc/modes/comp.h libcalc/modes/comp.cpp libcalc/objects/Scalar.h libcalc/objects/Scalar.cpp libcalc/objects/ComplexScalar.cpp libcalc/objects/ComplexScalar.h libcalc/modes/cmplx.cpp libcalc/modes/cmplx.h libcalc/global.h libcalc/func/ops.cpp libcalc/func/ops.h libcalc/internals.cpp libcalc/internals.h libcalc/objects/CalcErrors.h libcalc/setup/PrecisionSetup.cpp libcalc/setup/PrecisionSetup.h libcalc/setup/PrecisionType.h)
#add_executable(calc_port ${SOURCE_FILES})

add_subdirectory(libcalc)
add_subdirectory(prog)
