#include <iostream>
#include <iomanip> 
#include <chrono>
#include <random>
#include "MiYALAB/PhysicsEngine/PotentialGenerator/PotentialGenerator.hpp"
#include "MiYALAB/PhysicsEngine/PotentialGenerator/Ellipse/EllipsePotentialGenerator.hpp"

constexpr size_t MAT_SIZE = 1000;

namespace math = MiYALAB::Mathematics;
namespace physics = MiYALAB::PhysicsEngine;

int main()
{
    math::Point2D point(1,1.4);
    physics::PotentialGenerator circleP;
    physics::EllipsePotentialGenerator ellipseP;
    circleP.setOffset(0, 0);
    circleP.setGain(2);
    ellipseP.setOffset(0, 0);
    ellipseP.setAspectRatio(2.0);
    ellipseP.setGain(2);
    std::cout << circleP.calcPotential(point).toString() << std::endl;
    std::cout << ellipseP.calcPotential(point).toString() << std::endl;
    
}