#ifndef VECTOR_3_H_
#define VECTOR_3_H_
#include <iostream>
#include <stdio.h>
#include <math.h>


  
class Vector3 {
  public:
    /**
     * Default constructor. Creates a vector at (0,0,0).
     */
    Vector3();
    
    /**
     * Constructor. Creates a vector at (x, y, z).
     * @param x The x position
     * @param y The y position
     * @param z The z position
     */
    Vector3(float x, float y, float z);
    
    /**
     * Constructor. Creates a vector at (data[0], data[1], data[2])
     * @param data An array of three floats
     */
    explicit Vector3(const float data[3]);

    
    /**
     * Destructor
     */
    ~Vector3() { };    
    
    /**
     * Assignment operator
     */
    Vector3& operator=(const Vector3&);
    
    
    Vector3& operator+=(const Vector3&);
    Vector3& operator-=(const Vector3&);
    Vector3& operator/=(const Vector3&);
    Vector3& operator*=(const Vector3&);
    Vector3& operator/=(float);
    Vector3& operator*=(float);
    
    /**
     * Normalization
     * @return Normalized form of this vector
     */
    Vector3 Normalize() const;
    
    /**
     * Length
     * @return Length of this vector
     */
    float Length() const;
    
    /**
     * Dot product
     * @param rhs The vector to compute the dot product with.
     * @return The dot product of this vector and the parameter.
     */
    float Dot(const Vector3& rhs) const;
    
    /**
     * Distance
     * @param rhs The vector to compute the distance to/from this vector
     * @return The distance between this vector and the parameter in
     *          3-dimensional space.
     */
    float Distance(const Vector3& rhs) const;
    
    /**
     * Squared distance
     * @see Distance
     * @return Squared distance from this vector to the parameter
     */
    float SqDistance(const Vector3&) const;
    
    /**
     * Cross product
     * @param rhs The vector to compute the cross product with.
     * @return The cross product of this vector and the parameter.
     */
    Vector3 Cross(const Vector3& rhs) const;
    
    /**
     * Negation operator
     */
    Vector3 operator-() const;
    
    Vector3 operator+(const Vector3&) const;
    Vector3 operator-(const Vector3&) const;
    Vector3 operator*(float) const;
    Vector3 operator/(float) const;
    
	/**
 	 * Equality / Inequality
 	 */
    bool operator==(const Vector3&) const;
    bool operator!=(const Vector3&) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector3 output);
   
	float X() const;
	float Y() const;
	float Z() const; 
  private:
    float m_data[3];
};


#endif