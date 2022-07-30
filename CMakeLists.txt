#
cmake_minimum_required(VERSION 3.5)
project(MiYALAB.Cpp)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")

# Add definitions
if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "C:/local" CACHE PATH "Installation directory" FORCE)
endif()
if(MSVC)
  add_definitions(-D_WIN32_WINNT=0x0501)
  set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs")
else()
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build")
  # set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif() 

# OpenMP使用
find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

#各ディレクトリ
set(SRC_DIR src)
set(INC_DIR lib)

# Set dependent libraries
set(HEADER_DIR "" CACHE PATH "The path to dependent headers")
set(LIBRARY_DIR "" CACHE PATH "The path to dependent libraries")
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${HEADER_DIR}
)
link_directories(
  ${LIBRARY_DIR}
)

#インクルードディレクトリ
include_directories(lib)

#ソースコード
set(SRC main)

#ライブラリ
add_library(${PROJECT_NAME} SHARED
    lib/Mathematics/Matrix/Matrix.cpp
)

#ソースコードのコンパイル
foreach(target IN LISTS SRC)
    add_executable(${target} ${SRC_DIR}/${target}.cpp)
    target_link_libraries(${target} ${PROJECT_NAME})
endforeach()

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY lib DESTINATION include)