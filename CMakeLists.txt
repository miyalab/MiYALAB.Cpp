#
cmake_minimum_required(VERSION 3.5)
project(MiYALAB.Cpp)

# OpenMP使用
find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

#各ディレクトリ
set(SRC_DIR src)
set(INC_DIR lib)

#インクルードディレクトリ
include_directories(lib)

#ソースコード
set(SRC main)

#ライブラリ
add_library(MiYALAB STATIC
    lib/Mathematics/Matrix/Matrix.cpp;
)

#ソースコードのコンパイル
foreach(target IN LISTS SRC)
    add_executable(${target} ${SRC_DIR}/${target}.cpp)
    target_link_libraries(${target} MiYALAB)
endforeach()
