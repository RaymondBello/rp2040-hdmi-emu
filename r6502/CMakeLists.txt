add_library(r6502 Bus.h Bus.cpp R6502.h R6502.cpp)
target_link_libraries(r6502 pico_stdlib )
target_include_directories(r6502 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


