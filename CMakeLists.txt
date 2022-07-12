cmake_minimum_required(VERSION 3.10)
project(CAOE)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")
include_directories("include/")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

file(GLOB SRC 
    "src/*.cpp"
)

add_executable(CAOE ${SRC})
target_link_libraries(CAOE sfml-graphics sfml-audio)