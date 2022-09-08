#ifndef __MIYALAB_CPP_MATHEMATICS_FUNCTINOS_HPP__
#define __MIYALAB_CPP_MATHEMATICS_FUNCTINOS_HPP__

#include "MathematicsValue.hpp"

namespace MiYALAB{
namespace Cpp{
namespace Mathematics{
/**
 * @brief degree to radian
 * 
 * @tparam NumericType 
 * @param deg 
 * @return NumericType 
 */
template<typename NumericType> inline NumericType DegToRad(const NumericType &deg){return deg * ConstantValue::M_PI / 180;}

/**
 * @brief radian to degree
 * 
 * @tparam NumericType 
 * @param rad 
 * @return NumericType degree
 */
template<typename NumericType> inline NumericType RadToDeg(const NumericType &rad){return rad * 180 / ConstantValue::M_PI;}


}
}
}

#endif

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------