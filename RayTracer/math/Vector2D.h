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
 * Name:	Vector2D
 * Author:	Colin Barré-Brisebois
 * Created: 2004-07-02
 * Version: $Revision: 1.16 $
 */

#ifndef __MATHLIB3D_VECTOR2D__
#define __MATHLIB3D_VECTOR2D__

#include "MathLib3D.h"
#include "Vector3D.h"
#include "MathUtils.h"
using namespace MATHLIB3D;

namespace MATHLIB3D {

	/**
	 * Vector2D Class.
	 * Contains all the mathematical operations for a 2D vector
	 */
	class Vector2D {
	public:

		/* Constructors */
		Vector2D();
		Vector2D(const float& x, const float& y);
		Vector2D(const Vector2D* pVector);
		Vector2D(const Vector2D& pVector);

		/* Get Methods - Original Vector Not Modified */
		inline const float GetMagnitude() const;
		inline const float GetDot(const Vector2D& vector) const;
		inline const float GetAngle(const Vector2D& vector) const;
		inline const float GetPolarAngle() const;
		inline const float GetDistance(Vector2D& vector) const;
		inline Vector2D GetNormalized() const;
		inline Vector2D GetInverted() const;
		inline Vector3D GetCross(const Vector2D& vector) const;
		inline Vector2D GetProjected(Vector2D& vector) const;

		/* Set Methods - Original Vector Modified */
		inline Vector2D& SetMagnitude(const float& magnitude);
		inline Vector2D& SetNormalized();
		inline Vector2D& SetInverted();
		inline Vector2D& SetProjected(const Vector2D& vector1);
		inline Vector2D& SetProjected(const Vector2D& vector1, const Vector2D& vector2);

		/* Operator replacements */
		inline Vector2D GetAdd(const Vector2D& vector) const;
		inline Vector2D& SetAdd(const Vector2D& vector);
		inline Vector2D& SetAdd(const Vector2D& vector1, const Vector2D& vector2);

		inline Vector2D GetSub(const Vector2D& vector) const;
		inline Vector2D& SetSub(const Vector2D& vector);
		inline Vector2D& SetSub(const Vector2D& vector1, const Vector2D& vector2);

		inline Vector2D GetMul(const float& scalar) const;
		inline Vector2D& SetMul(const float& scalar);
		inline Vector2D& SetMul(const Vector2D& vector, const float& scalar);

		inline Vector2D GetDiv(const float& scalar) const;
		inline Vector2D& SetDiv(const float& scalar);
		inline Vector2D& SetDiv(const Vector2D& vector, const float& scalar);

		inline const bool equals(const Vector2D& vector) const;
		inline const bool notEquals(const Vector2D& vector) const;

		/* Operators */
		inline Vector2D operator + (const Vector2D& vector) const;
		inline Vector2D operator - (const Vector2D& vector) const;      
		inline Vector2D operator * (const float& scalar) const;      
		inline Vector2D operator / (const float& scalar) const;   
		inline Vector2D& operator += (const Vector2D& vector);
		inline Vector2D& operator -= (const Vector2D& vector);
		inline Vector2D& operator *= (const float& scalar);
		inline Vector2D& operator /= (const float& scalar);
		inline Vector2D operator - () const;
		inline const bool operator == (Vector2D& vector) const;
		inline const bool operator != (Vector2D& vector) const;

	public:
		float x;
		float y;
	};
}

//-------------------------------------------------------------------------------------------------
// INLINED SOURCE
//-------------------------------------------------------------------------------------------------

/**
 *  Default constructor of the Vector2D class
 */
Vector2D::Vector2D() : x(0), y(0) {
}

/**
 * Default constructor of the Vector2D class
 * @param x x coordinate value
 * @param y y coordinate value
 */
Vector2D::Vector2D(const float& x, const float& y) : x(x), y(y) {}

/**
 * Copy constructor of the Vector2D class
 * @param vector vector to copy
 */
Vector2D::Vector2D(const Vector2D* pVector) : x(pVector->x), y(pVector->y) {}

/**
 * Copy constructor of the Vector2D class
 * @param vector vector to copy
 */
Vector2D::Vector2D(const Vector2D& vector) : x(vector.x), y(vector.y) {}

/**
 * Magnitude of the vector
 * @return magnitude of the vector
 */
inline const float Vector2D::GetMagnitude() const {
	return static_cast<float>(sqrt(x*x + y*y));
}

/**
 * Dot product of the two vectors
 * @param vector second vector on which the dot product is applied
 * @return dot product value
 */
inline const float Vector2D::GetDot(const Vector2D& vector) const {
	return (x * vector.x + y * vector.y);
}

/**
 * Angle between the two vectors
 * @param vector second vector of the pair, where the angle is calculated
 * @return angle between the two vectors
 */
inline const float Vector2D::GetAngle(const Vector2D& vector) const {
	const float magnitudesProduct = GetMagnitude() * vector.GetMagnitude();

	if (magnitudesProduct != 0.0f)
		return static_cast<float>(MathUtils::ArcCos(GetDot(vector) / magnitudesProduct));
	else
		return 0.0f;
}

/**
 * Calculates the polar angle of the vector
 * @return angle value
 */
inline const float Vector2D::GetPolarAngle() const {
	const Vector2D reference (1,0);

	return static_cast<float>(GetAngle(reference));
}

/**
 * Calculates the distance between two vectors
 * @param vector vector to calculate the distance to
 * @return distance between the two vectors
 */
inline const float Vector2D::GetDistance(Vector2D& vector) const {
	Vector2D tmp = *this;
	tmp -= vector;
	return tmp.GetMagnitude();
}

/**
 * Normalizes an INSTANCE of the vector
 * @return reference to a new normalized Vector2D
 */
inline Vector2D Vector2D::GetNormalized() const {
	const float magnitude = GetMagnitude();
   
	if (magnitude != 0.0f)
		return Vector2D(x / magnitude, y / magnitude);
	else
		return (*this);
}

/**
 * Inverts an INSTANCE of the vector
 * @return reference to a new inverted Vector2D
 */
inline Vector2D Vector2D::GetInverted() const {
	return Vector2D(-x, -y);
}

/**
 * Cross product of the two Vector2D, outputs a Vector3D
 * @param vector second vector of the pair
 * @return new perpendicular Vector3D
 */
inline Vector3D Vector2D::GetCross(const Vector2D& vector) const {
	return Vector3D(0, 0, x * vector.y - y * vector.x);
}

/**
 * Projects an INSTANCE of the vector onto another
 * @param vector vector on which the projection is done
 * @return reference to a new normalized Vector2D
 */
inline Vector2D Vector2D::GetProjected(Vector2D& vector) const {
	const float selfDot = vector.GetDot(vector);

	if (selfDot != 0.0f)
		return ((GetDot(vector) / (selfDot)) * vector);
	else
		return (*this);
}

/**
 * Changes the magnitude of the vector
 * @param new magnitude value
 * @return new vector
 */
inline Vector2D& Vector2D::SetMagnitude(const float& magnitude) {
	const float currentMagnitude = GetMagnitude();

	if (currentMagnitude != 0.0f) {
		const float magnitudeRatio = magnitude / currentMagnitude;	//Faster, but not nice.
		x *= magnitudeRatio;
		y *= magnitudeRatio;
	}

	return (*this);
}

/**
 * Normalizes the vector
 * @return reference to THIS normalized Vector2D
 */
inline Vector2D& Vector2D::SetNormalized() {
	const float magnitude = GetMagnitude();
   
	if (magnitude != 0.0f) {
		x /= magnitude;
		y /= magnitude;
	}
	
	return (*this);
}

/**
 * Inverts the vector
 * @return reference to THIS inverted Vector2D
 */
inline Vector2D& Vector2D::SetInverted() {
	x = -x;
	y = -y;
	return (*this);
}

/**
 * Sets the current vector as the projection on the param vector
 * @param vector vector to project the first one on
 * @return reference to THIS projected Vector2D
 */
inline Vector2D& Vector2D::SetProjected(const Vector2D& vector) {
	return SetProjected(*this, vector);
}

/**
 * Sets the current vector as the projection of the two vectors
 * @param vector1 first vector to project onto, reference vector
 * @param vector2 second vector, projected vector
 * @return reference to THIS Vector2D
 */
inline Vector2D& Vector2D::SetProjected(const Vector2D& vector1, const Vector2D& vector2) {
	const float selfDot = vector2.GetDot(vector2);

	if (selfDot != 0.0f)
		*this = (((vector1.GetDot(vector2)) / (selfDot)) * vector2);

	return (*this);
}

/**
 * ADD operator replacement
 * @param vector vector to sum
 * @return summation result
 */
inline Vector2D Vector2D::GetAdd(const Vector2D& vector) const {
	return Vector2D(this->x + vector.x, this->y + vector.y);
}

/**
 * ADD_EQUAL operator replacement
 * @param vector vector to add to the current vector
 * @return summation result
 */
inline Vector2D& Vector2D::SetAdd(const Vector2D& vector) {
	this->x += vector.x;
	this->y += vector.y;

	return (*this);
}

/**
 * ADD_EQUAL operator replacement
 * @param vector1 first vector to add 
 * @param vector2 second vector to add
 * @return summation result
 */
inline Vector2D& Vector2D::SetAdd(const Vector2D& vector1, const Vector2D& vector2) {
	this->x = vector1.x + vector2.x;
	this->y = vector1.y + vector2.y;

	return (*this);
}

/**
 * SUB operator replacement
 * @param vector vector to sub
 * @return substraction result
 */
inline Vector2D Vector2D::GetSub(const Vector2D& vector) const {
	return Vector2D(this->x - vector.x, this->y - vector.y);
}

/**
 * SUB_EQUAL operator replacement
 * @param vector vector to sub to the current vector
 * @return substraction result
 */
inline Vector2D& Vector2D::SetSub(const Vector2D& vector) {
	this->x -= vector.x;
	this->y -= vector.y;

	return (*this);
}

/**
 * SUB_EQUAL operator replacement
 * @param vector1 first vector to sub 
 * @param vector2 second vector to sub
 * @return substraction result
 */
inline Vector2D& Vector2D::SetSub(const Vector2D& vector1, const Vector2D& vector2) {
	this->x = vector1.x - vector2.x;
	this->y = vector1.y - vector2.y;

	return (*this);
}

/**
 * MULTIPLY operator replacement
 * @param scalar scalar value multiplied by the vector
 * @return scaled vector
 */
inline Vector2D Vector2D::GetMul(const float& scalar) const {
	return Vector2D(this->x * scalar, this->y * scalar);
}

/**
 * MULTIPLY_EQUAL operator replacement
 * @param scalar scalar multiplied by the current vector
 * @return scaled vector
 */
inline Vector2D& Vector2D::SetMul(const float& scalar) {
	this->x *= scalar;
	this->y *= scalar;

	return (*this);
}

/**
 * MULTIPLY_EQUAL operator replacement
 * @param vector1 first vector to multiply 
 * @param scalar scalar to multiply to the first vector
 * @return scaled vector
 */
inline Vector2D& Vector2D::SetMul(const Vector2D& vector, const float& scalar) {
	this->x = vector.x * scalar;
	this->y = vector.y * scalar;

	return (*this);
}

/**
 * DIVIDE operator replacement
 * @param scalar scalar value that divides the vector
 * @return scaled vector
 */
inline Vector2D Vector2D::GetDiv(const float& scalar) const {
	return Vector2D(this->x / scalar, this->y / scalar);
}

/**
 * DIVIDE_EQUAL operator replacement
 * @param scalar scalar multiplied by the current vector
 * @return scaled vector
 */
inline Vector2D& Vector2D::SetDiv(const float& scalar) {
	this->x /= scalar;
	this->y /= scalar;

	return (*this);
}

/**
 * MULTIPLY_EQUAL operator replacement
 * @param vector1 first vector to multiply 
 * @param scalar scalar to multiply to the first vector
 * @return scaled vector
 */
inline Vector2D& Vector2D::SetDiv(const Vector2D& vector, const float& scalar) {
	this->x = vector.x / scalar;
	this->y = vector.y / scalar;

	return (*this);
}

/**
 * EQUAL_EQUAL operator
 * @param vector vector to compare
 * @return equal value
 */
inline const bool Vector2D::equals(const Vector2D& vector) const {
	return ((this->x == vector.x) && (this->y == vector.y));
}

/**
 * NOT_EQUAL operator
 * @param vector vector to compare
 * @return not equal value
 */
inline const bool Vector2D::notEquals(const Vector2D& vector) const {
	return ((this->x != vector.x) && (this->y != vector.y));
}

/**
 * ADD operator
 * @param vector vector to sum
 * @return summation result
 */
inline Vector2D Vector2D::operator + (const Vector2D& vector) const {
	return Vector2D(x + vector.x, y + vector.y);
}

/**
 * SUB operator
 * @param vector vector to sub
 * @return substraction result
 */
inline Vector2D Vector2D::operator - (const Vector2D& vector) const {
	return Vector2D(x - vector.x, y - vector.y);
}

/**
 * MULTIPLY operator
 * @param scalar scalar value multiplied by the vector
 * @return scaled vector
 */
inline Vector2D Vector2D::operator * (const float& scalar) const {
	return Vector2D(x * scalar, y * scalar);
}      

/**
 * DIVIDE operator
 * @param scalar scalar value divided by the vector
 * @return scaled vector
 */
inline Vector2D Vector2D::operator / (const float& scalar) const {
	if (scalar != 0.0f)
		return Vector2D(x / scalar, y / scalar);
	else
		return (*this);
}       

/**
 * ADD_EQUAL operator
 * @param vector vector to add to the current vector
 * @return summation result
 */
inline Vector2D& Vector2D::operator += (const Vector2D& vector) {
	x += vector.x;
	y += vector.y;
	return (*this);
}

/**
 * SUB_EQUAL operator
 * @param vector vector to sub to the current vector
 * @return substraction result
 */
inline Vector2D& Vector2D::operator -= (const Vector2D& vector) {
	x -= vector.x;
	y -= vector.y;
	return *this;
}

/**
 * MULTIPLY_EQUAL operator
 * @param scalar scalar multiplied by the current vector
 * @return scaled result
 */
inline Vector2D& Vector2D::operator *= (const float& scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}

/**
 * DIVIDE_EQUAL operator
 * @param scalar scalar divided by the current vector
 * @return scaled result
 */
inline Vector2D& Vector2D::operator /= (const float& scalar) {
	if (scalar != 0.0f) {
		x /= scalar;
		y /= scalar;
	}
	
	return (*this);
}

/**
 * SIGN operator
 * @return signed result
 */
inline Vector2D Vector2D::operator - () const { 
	return Vector2D(-x, -y);
}

/**
 * EQUAL_EQUAL operator
 * @param vector vector to compare
 * @return equal value
 */
inline const bool Vector2D::operator == (Vector2D &vector) const {
	return ((x == vector.x) && (y == vector.y)) ? true : false;
}

/**
 * NOT_EQUAL operator
 * @param vector vector to compare
 * @return not equal value
 */
inline const bool Vector2D::operator != (Vector2D &vector) const {
	return ((x != vector.x) && (y != vector.y)) ? true : false;
}

/**
 * Global MULTIPLY operator
 * @param scalar scalar value to multiply with the second parameter
 * @param vector vector to multiply the scalar value with
 * @return scaled vector instance
 */
inline Vector2D operator * (float scalar, Vector2D& vector) {
	return Vector2D(vector.x * scalar, vector.y * scalar);
}

/**
 * Global DIVIDE operator
 * @param scalar scalar value to divide with the second parameter
 * @param vector vector to divide the scalar value with
 * @return scaled vector instance
 */
inline Vector2D operator / (float scalar, Vector2D& vector) {
	return Vector2D(vector.x / scalar, vector.y / scalar);
}

/**
 * Global MULTIPLY operator
 * @param scalar scalar value to multiply with the second parameter
 * @param vector const vector to multiply the scalar value with
 * @return scaled vector instance
 */
inline Vector2D operator * (float scalar, const MATHLIB3D::Vector2D& vector) {
	return Vector2D(vector.x * scalar, vector.y * scalar);
}

#endif