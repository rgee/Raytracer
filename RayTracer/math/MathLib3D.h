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
 * Name:	MathLib3D
 * Author:	Colin Barré-Brisebois
 * Created: 2004-07-02
 * Version: $Revision: 1.8 $
 */

#ifndef __MATHLIB3D__
#define __MATHLIB3D__

#include <math.h>

namespace MATHLIB3D {
	class Vector2D;
	class Vector3D;
	class Vector4D;
	class Matrix3;
	class Matrix4;
	class Quaternion;
	class MathUtils;
	class Matrix3x3;
	class Matrix4x4;
	class Plane;
	class Polynomial;
}

inline MATHLIB3D::Vector2D operator * (float scalar, MATHLIB3D::Vector2D& vector);
inline MATHLIB3D::Vector2D operator * (float scalar, const MATHLIB3D::Vector2D& vector);
inline MATHLIB3D::Vector3D operator * (float scalar, MATHLIB3D::Vector3D& vector);
inline MATHLIB3D::Vector4D operator * (float scalar, MATHLIB3D::Vector4D& vector);

inline MATHLIB3D::Vector2D operator / (float scalar, MATHLIB3D::Vector2D& vector);
inline MATHLIB3D::Vector3D operator / (float scalar, MATHLIB3D::Vector3D& vector);
inline MATHLIB3D::Vector4D operator / (float scalar, MATHLIB3D::Vector4D& vector);

#endif