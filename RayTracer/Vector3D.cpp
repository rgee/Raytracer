#include "Vector3D.h"

Vector3 operator*(float k, const Vector3& rhs)
{
	return rhs * k;
}

std::ostream& operator<<(std::ostream& os, Vector3 output) 
{
    os << "(X: ";
    os << output.m_data[0];
    os << " Y: ";
    os << output.m_data[1];
    os << " Z: ";
    os << output.m_data[2];
    os << ")";

    return os;
}

Vector3::Vector3() {
  m_data[0] = 0.0f;
  m_data[1] = 0.0f;
  m_data[2] = 0.0f;
}

Vector3::Vector3(float x, float y, float z) {
  m_data[0] = x;
  m_data[1] = y;
  m_data[2] = z;
}

Vector3::Vector3(const float data[3]) {
  m_data[0] = data[0];
  m_data[1] = data[1];
  m_data[2] = data[2];
}

Vector3& Vector3::operator=(const Vector3& rhs) {
  if(&rhs != this)
  {
      m_data[0] = rhs.m_data[0];
      m_data[1] = rhs.m_data[1];
      m_data[2] = rhs.m_data[2];
  }
  return *this;
}

Vector3& Vector3::operator+=(const Vector3& rhs){
    m_data[0] += rhs.m_data[0];
    m_data[1] += rhs.m_data[1];
    m_data[2] += rhs.m_data[2];
    
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs){
    m_data[0] -= rhs.m_data[0];
    m_data[1] -= rhs.m_data[1];
    m_data[2] -= rhs.m_data[2];
    
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& rhs){
    m_data[0] /= rhs.m_data[0];
    m_data[1] /= rhs.m_data[1];
    m_data[2] /= rhs.m_data[2];
    
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& rhs){
    m_data[0] *= rhs.m_data[0];
    m_data[1] *= rhs.m_data[1];
    m_data[2] *= rhs.m_data[2];
    
    return *this;
}

float Vector3::Length() const {
  return sqrt(
          (m_data[0] * m_data[0]) +
          (m_data[1] * m_data[1]) +
          (m_data[2] * m_data[2])
        );
}


float Vector3::Distance(const Vector3& rhs) const {
  float dx = m_data[0] - rhs.m_data[0];
  float dy = m_data[1] - rhs.m_data[1];
  float dz = m_data[2] - rhs.m_data[2];
  
  return (dx + dy + dz);
}

float Vector3::SqDistance(const Vector3& rhs) const {
  return pow(this->Distance(rhs), 2);
}

Vector3 Vector3::Normalize() const {
  float length = this->Length();
  float scalar = (length == 0.0f) ? 0.0f : (1.0f / length);
  
  return Vector3(m_data[0] * scalar, m_data[1] * scalar, m_data[2] * scalar);
}

Vector3 Vector3::Cross(const Vector3& rhs) const {
  /*
   * U x V = ( (Uy * Vz) - (Uz * Vy),
   *           (Uz * Vx) - (Ux * Vz),
   *           (Ux * Vy) - (Uy * Vx) )
   */
  return Vector3(
    (m_data[1] * rhs.m_data[2]) - (m_data[2] * rhs.m_data[1]),
    (m_data[2] * rhs.m_data[0]) - (m_data[0] * rhs.m_data[2]),
    (m_data[0] * rhs.m_data[1]) - (m_data[1] * rhs.m_data[0])
  );
}

float Vector3::Dot(const Vector3& rhs) const {
  return (
    (m_data[0] * rhs.m_data[0]) +
    (m_data[1] * rhs.m_data[1]) +
    (m_data[2] * rhs.m_data[2])
  );
}

bool Vector3::operator==(const Vector3& rhs) const {
  return (
    (m_data[0] == rhs.m_data[0]) &&
    (m_data[1] == rhs.m_data[1]) &&
    (m_data[2] == rhs.m_data[2])
  );
}

bool Vector3::operator!=(const Vector3& rhs) const {
  return (
    (m_data[0] != rhs.m_data[0]) ||
    (m_data[1] != rhs.m_data[1]) ||
    (m_data[2] != rhs.m_data[2])
  );
}

Vector3 Vector3::operator-() const{
  return Vector3(-m_data[0], -m_data[1], -m_data[2]);
}

Vector3 Vector3::operator*(float scalar) const {
  return Vector3(
    (m_data[0] * scalar),
    (m_data[1] * scalar),
    (m_data[2] * scalar)
  );
}
Vector3 Vector3::operator/(float scalar) const {
  return Vector3(
    (m_data[0] / scalar),
    (m_data[1] / scalar),
    (m_data[2] / scalar)
  );
}

Vector3 Vector3::operator+(const Vector3& rhs) const {
  return Vector3(
    (m_data[0] + rhs.m_data[0]),
    (m_data[1] + rhs.m_data[1]),
    (m_data[2] + rhs.m_data[2])
  );
}

Vector3 Vector3::operator-(const Vector3& rhs) const {
  return Vector3(
    (m_data[0] - rhs.m_data[0]),
    (m_data[1] - rhs.m_data[1]),
    (m_data[2] - rhs.m_data[2])
  );
}

float Vector3::X() const {
	return m_data[0];
}

float Vector3::Y() const {
	return m_data[1];
}

float Vector3::Z() const {
	return m_data[2];
}