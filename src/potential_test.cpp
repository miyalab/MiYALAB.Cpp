#include <iostream>
#include <iomanip> 
#include <chrono>
#include <random>
#include "MiYALAB/PhysicsEngine/PotentialGenerator/PotentialGenerator.hpp"
#include "MiYALAB/PhysicsEngine/PotentialGenerator/Ellipse/EllipsePotentialGenerator.hpp"

constexpr size_t MAT_SIZE = 1000;

namespace math = MiYALAB::Cpp::Mathematics;
namespace physics = MiYALAB::Cpp::PhysicsEngine;

int main()
{
    math::Point2D<double> point(1,1.4);
    physics::PotentialGenerator circleP;
    physics::EllipsePotentialGenerator ellipseP;
    circleP.SetOffset(0, 0);
    circleP.SetGain(2);
    ellipseP.SetOffset(0, 0);
    ellipseP.SetAspectRatio(2.0);
    ellipseP.SetGain(2);
    std::cout << circleP.CalcPotential(point).ToString() << std::endl;
    std::cout << ellipseP.CalcPotential(point).ToString() << std::endl;
    
}