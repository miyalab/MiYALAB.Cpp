cmake_minimum_required(VERSION 2.8)
project(MiYALAB.Cpp)
# Add definitions
if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "C:/local" CACHE PATH "Installation directory" FORCE)
endif()
if(MSVC)
	add_definitions(-D_WIN32_WINNT=0x0501)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs")
else()
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build")
	set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")
endif() 
 
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
set(DEPENDENT_LIBS opencv_core)
 
# Build library
add_library(${PROJECT_NAME} SHARED
	src/MiYALAB/Mathematics/Matrix/Matrix.cpp
	src/MiYALAB/ControllerEngine/PIDController/PIDController.cpp
	src/MiYALAB/PhysicsEngine/PotentialGenerator/PotentialGenerator.cpp
	src/MiYALAB/PhysicsEngine/PotentialGenerator/Rotate/RotatePotentialGenerator.cpp
	src/MiYALAB/PhysicsEngine/PotentialGenerator/Ellipse/EllipsePotentialGenerator.cpp
)
target_link_libraries(${PROJECT_NAME} ${DEPENDENT_LIBS})
 
# Set installation
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
install(DIRECTORY include DESTINATION include)