macro (add_executable _name)
    # invoke built-in add_executable
    _add_executable(${ARGV})
    if (TARGET ${_name})
        target_link_libraries(${_name} LINK_PUBLIC calc)
    endif()
endmacro()

add_executable(quadratic quadratic.cpp)
target_link_libraries(quadratic LINK_PUBLIC calc)
