/*
   This file is part of mathlib3d-cpp.
   mathlib3d-cpp is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   mathlib3d-cpp is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with j2dcg; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
 * MATHLIB3D - 3D Math Library
 * C++ v1.0
 * http://mathlib3d.sf.net
 *
 * Name:	MathUtils
 * Author:	Colin Barré-Brisebois
 * Created: 2004-07-02
 * Version: $Revision: 1.6 $
 */

#ifndef __MATHLIB3D_MATHUTILS__
#define __MATHLIB3D_MATHUTILS__
#pragma once

#include "MathLib3D.h"
using namespace MATHLIB3D;

namespace MATHLIB3D {

	class MathUtils {
	public:
		static const float PI;
		static const float PI_DOUBLE;
		static const float PI_HALF;
		static const float PI_SQUARE;
		static const float E;
		static const float RAD_PER_DEG;
		static const float DEG_PER_RAD;

		static inline float Cos(const float& value);
		static inline float Sin(const float& value);
		static inline float Tan(const float& value);
		static inline float ArcCos(const float& value);
		static inline float ArcSin(const float& value);
		static inline float ArcTan(const float& value);
		static inline float DegToRad(const float& value);
		static inline float RadToDeg(const float& value);
		static inline float Abs(const float& value);
		static inline int Floor(const float& value);
		static inline int Ceiling(const float& value);
		static inline int Round(const float& value);
		static inline float FloatRound1000(const float& value);
		static inline int Sign(const float& value);
		static inline float Min(const float& value1, const float& value2);
		static inline float Max(const float& value1, const float& value2);
		static inline void Swap(int& value1, int& value2);
		static inline bool Odd(const int& value);
	};

	const float MathUtils::PI = 3.1415926535897932f;
	const float MathUtils::PI_DOUBLE = 6.2831853071795865f;
	const float MathUtils::PI_HALF = 1.5707963267948966f;
	const float MathUtils::PI_SQUARE = 9.8696044010893586f;
	const float MathUtils::E = 2.7182818284590452f;
	const float MathUtils::RAD_PER_DEG = 0.0174532925199433f;
	const float MathUtils::DEG_PER_RAD = 57.2957795130823069f;
}

//-------------------------------------------------------------------------------------------------
// INLINED SOURCE
//-------------------------------------------------------------------------------------------------

/**
 * Calculates the cos of a value
 * @param value value to calculate from
 * @return calculated cos value
 * @todo numerical approximation
 */
inline float MathUtils::Cos(const float& value) {
	return static_cast<float>(cos(value));
}
	
/**
 * Calculates the sin of a value
 * @param value value to calculate from
 * @return calculated sin value
 * @todo numerical approximation
 */
inline float MathUtils::Sin(const float& value) {
	return static_cast<float>(sin(value));
}

/**
 * Calculates the tan of a value
 * @param value value to calculate from
 * @return calculated tan value
 * @todo numerical approximation
 */	
inline float MathUtils::Tan(const float& value) {
	return static_cast<float>(tan(value));
}

/**
 * Calculates the arccos of a value
 * @param value value to calculate from
 * @return calculated arccos value
 * @todo numerical approximation
 */
inline float MathUtils::ArcCos(const float& value) {
	return static_cast<float>(acos(value));	
}

/**
 * Calculates the arcsin of a value
 * @param value value to calculate from
 * @return calculated arcsin value
 * @todo numerical approximation
 */
inline float MathUtils::ArcSin(const float& value) {
	return static_cast<float>(asin(value));
}

/**
 * Calculates the arctan of a value
 * @param value value to calculate from
 * @return calculated arctan value
 * @todo numerical approximation
 */
inline float MathUtils::ArcTan(const float& value) {
	return static_cast<float>(atan(value));
}

/**
 * Converts a degree value to a rad value
 * @param value value to convert
 * @return converted rad value
 */
inline float MathUtils::DegToRad(const float& value) {
	return (value * MathUtils::RAD_PER_DEG);
}
	
/**
 * Converts a rad value to a degree value
 * @param value value to convert
 * @return converted deg value
 */
inline float MathUtils::RadToDeg(const float& value) {
	return (value * MathUtils::DEG_PER_RAD);
}

/**
 * Calculates the absolute value
 * @param value value to calculate from
 * @return absolute value
 */
inline float MathUtils::Abs(const float& value) {
	return (((value) < 0) ? -(value) : (value));
}
	
/**
 * Calculates the floor value
 * @param value value to calculate from
 * @return floor value
 */
inline int MathUtils::Floor(const float& value) {
	return static_cast<int>(floor(value));
}

/**
 * Calculates the ceiling value
 * @param value value to calculate from
 * @return ceiling value
 */	
inline int MathUtils::Ceiling(const float& value) {
	return static_cast<int>(ceilf(value));
}

/**
 * Calculates the round value
 * @param value value to calculate from
 * @return round value
 */
inline int MathUtils::Round(const float& value) {
	return ((value) > 0 ? static_cast<int>(value + 0.5f) : -static_cast<int>(0.5f - value));
}

inline float MathUtils::FloatRound1000(const float& value) {
	return static_cast<float>(Round(value*10000)/10000.0);
}

/**
 * Calculates the signed value
 * @param value value to calculate from
 * @return signed value (-1 = signed, 0 = not signed)
 */
inline int MathUtils::Sign(const float& value) {
	return (((value) < 0) ? -1 : 1);
}

/**
 * Calculates the minimum value between 2 values
 * @param value1 first value to calculate from 
 * @param value2 second value to calculate from 
 * @return minimum value
 */
inline float MathUtils::Min(const float& value1, const float& value2) {
	return (((value1) < (value2)) ? (value1) : (value2));
}

/**
 * Calculates the maximum value between 2 values
 * @param value1 first value to calculate from 
 * @param value2 second value to calculate from 
 * @return maximum value
 */
inline float MathUtils::Max(const float& value1, const float& value2) {
	return (((value1) > (value2)) ? (value1) : (value2));
}

/**
 * Swaps two int values rapidly using masks
 * @param value1 first value to switch
 * @param value2 second value to switch
 */
inline void MathUtils::Swap(int& value1, int& value2) {
	value1 ^= value2; 
	value2 ^= value1; 
	value1 ^= value2;
}
	
/**
 * Identifies if a value is odd
 * @param value value to check if odd or not
 * @return odd (true) or not (false)
 */
inline bool MathUtils::Odd(const int& value) {
	return (((value) & 1) ? true : false);
}

#endif