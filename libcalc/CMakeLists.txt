set(LIBCALC_VERSION_MAJOR 1)
set(LIBCALC_VERSION_MINOR 0)

file(GLOB_RECURSE libcalc_SRC
        "*.h"
        "*.cpp")
add_library(calc modes/comp.cpp modes/comp.h modes/cmplx.cpp modes/cmplx.h ${libcalc_SRC})

target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
