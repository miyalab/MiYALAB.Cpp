#ifndef __MIYALAB_CPP_MATHEMATICS_FUNCTINOS_HPP__
#define __MIYALAB_CPP_MATHEMATICS_FUNCTINOS_HPP__

#include "MathematicsValue.hpp"

namespace MiYALAB{
namespace Mathematics{
/**
 * @brief degree to radian
 * 
 * @tparam Numeric 
 * @param deg 
 * @return Numeric 
 */
template<typename Numeric> inline Numeric DegToRad(const Numeric &deg){return deg * ConstantValue::M_PI / 180;}

/**
 * @brief radian to degree
 * 
 * @tparam Numeric 
 * @param rad 
 * @return Numeric degree
 */
template<typename Numeric> inline Numeric RadToDeg(const Numeric &rad){return rad * 180 / ConstantValue::M_PI;}


}
}


#endif

//-----------------------------------------------------------------------------------
// end of file
//-----------------------------------------------------------------------------------