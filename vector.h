#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <ostream>
#include <cmath>

class Vector
{
public:

    Vector();
    Vector(float x, float y, float z);
    Vector(const Vector &v);

    // classic op
    Vector operator+ (const Vector &v) const;
    Vector operator- (const Vector &v) const;
    Vector operator- () const;
    // scalar multiplication
    Vector operator* (float k) const;
    friend Vector operator*(float k, const Vector &v);
    // scalar division
    Vector operator/ (float k) const;
    friend Vector operator/(float k, const Vector &v);

    // classic assignment op
    Vector& operator=(const Vector &v);
    Vector& operator+=(const Vector &v);
    Vector& operator-=(const Vector &v);
    Vector& operator*=(float k);
    Vector& operator/=(float k);
    
    // vector op
    // dot product
    float operator*(const Vector &v) const;
    // cross product
    Vector operator^(const Vector &v) const;

    friend std::ostream &operator<<(std::ostream &o, const Vector &v);

    float length() const;
    float length2() const;
    Vector& normalize();
    Vector normalized() const;

public:
    float x, y, z;
};

float distance2(const Vector &a, const Vector &b);
float distance(const Vector &a, const Vector &b);

Vector::Vector() : x(0.0), y(0.0), z(0.0)
{}
Vector::Vector(float _x, float _y, float _z): x(_x), y(_y), z(_z)
{}
Vector::Vector(const Vector &v) : x(v.x), y(v.y), z(v.z)
{}

Vector Vector::operator+ (const Vector &v) const
{
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator- (const Vector &v) const
{
    return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator- () const
{
    return Vector(-x, -y, -z);
}

Vector Vector::operator* (float k) const
{
    return Vector(x * k, y * k, z * k);
}

Vector operator*(float k, const Vector &v)
{
    return Vector(v.x * k, v.y * k, v.z * k);
}

Vector Vector::operator/ (float k) const
{
    float d = 1.0f/k;
    return Vector(x * d, y * d, z * d);
}

Vector operator/ (float k, const Vector &v)
{
    float d = 1.0f/k;
    return Vector(v.x * d, v.y * d, v.z * d);
}

Vector& Vector::operator=(const Vector &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector& Vector::operator+=(const Vector &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector& Vector::operator-=(const Vector &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector& Vector::operator*=(float k)
{
    x *= k;
    y *= k;
    z *= k;
    return *this;
}

Vector& Vector::operator/=(float k)
{
    float d = 1.0f/k;
    x *= d;
    y *= d;
    z *= d;
    return *this;
}

float Vector::operator*(const Vector &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vector Vector::operator^(const Vector &v) const
{
    return Vector(
        y*v.z-z*v.y,
        z*v.x-x*v.z,
        x*v.y-y*v.x
    );
}

std::ostream &operator<<(std::ostream &o, const Vector &v)
{
    return o << v.x << " " << v.y << " " << v.z;
}


float Vector::length() const
{
    return std::sqrt(length2());
}

float Vector::length2() const
{
    return x*x + y*y + z*z;
}

Vector& Vector::normalize()
{
    float l = length();
    float dl = 1.0f/l;
    x *= dl;
    y *= dl;
    z *= dl;
    return *this;
}

Vector Vector::normalized() const
{
    float l = length();
    float dl = 1.0f/l;
    
    return Vector(x * dl, y * dl, z * dl);
}


float distance2(const Vector &a, const Vector &b)
{
    return Vector(b-a).length2();
}

float distance(const Vector &a, const Vector &b)
{
    return Vector(b-a).length();
}


#endif