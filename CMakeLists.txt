#
cmake_minimum_required(VERSION 3.5)
project(lib_test)

# Add definitions
if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "C:/local" CACHE PATH "Installation directory" FORCE)
endif()
if(MSVC)
  add_definitions(-D_WIN32_WINNT=0x0501)
  set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs")
else()
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build")
  set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS} -Wunused-variable")
endif()

#各ディレクトリ
set(SRC_DIR src)
set(INC_DIR lib)

#インクルードディレクトリ
include_directories(lib)

#ソースコード
set(SRC 
  matrix_test
  potential_test
)

set(LIBS
  MiYALAB.Cpp
)
#ソースコードのコンパイル
foreach(target IN LISTS SRC)
    add_executable(${target} ${SRC_DIR}/${target}.cpp)
    target_link_libraries(${target} ${LIBS})
endforeach()
