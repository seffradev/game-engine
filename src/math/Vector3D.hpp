#pragma once

#include <iostream>

#include "Real.hpp"

namespace Engine {

class Vector3D {
   private:
    real _x, _y, _z;

   public:
    Vector3D() : _x(0), _y(0), _z(0) {}
    Vector3D(real x, real y, real z) : _x(x), _y(y), _z(z) {}

    static real dot(const Vector3D& lhs, const Vector3D& rhs) {
        return lhs._x * rhs._x + lhs._y * rhs._y + lhs._z * rhs._z;
    }

    real dot(const Vector3D& rhs) {
        return dot(*this, rhs);
    }

    static real norm(const Vector3D& vector) {
        return sqrt(vector._x * vector._x + vector._y * vector._y + vector._z * vector._z);
    }

    real norm() {
        return norm(*this);
    }

    static Vector3D normalise(const Vector3D& vector) {
        return vector / norm(vector);
    }

    Vector3D& operator+=(const Vector3D& rhs) {
        this->_x += rhs._x;
        this->_y += rhs._y;
        this->_z += rhs._z;

        return *this;
    }

    friend Vector3D operator+(Vector3D lhs, const Vector3D& rhs) {
        return lhs += rhs;
    }

    Vector3D& operator-=(const Vector3D& rhs) {
        this->_x -= rhs._x;
        this->_y -= rhs._y;
        this->_z -= rhs._z;

        return *this;
    }

    friend Vector3D operator-(Vector3D lhs, const Vector3D& rhs) {
        return lhs -= rhs;
    }

    Vector3D& operator*=(const real& rhs) {
        this->_x *= rhs;
        this->_y *= rhs;
        this->_z *= rhs;

        return *this;
    }

    friend Vector3D operator*(Vector3D lhs, const real& rhs) {
        return lhs *= rhs;
    }

    Vector3D& operator/=(const real& rhs) {
        this->_x /= rhs;
        this->_y /= rhs;
        this->_z /= rhs;

        return *this;
    }

    friend Vector3D operator/(Vector3D lhs, const real& rhs) {
        return lhs /= rhs;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vector) {
        os << "(" << vector._x << ", " << vector._y << ", " << vector._z << ")";
        return os;
    }

    real x() {
        return _x;
    }

    void x(real x) {
        _x = x;
    }

    real y() {
        return _y;
    }

    void y(real y) {
        _y = y;
    }

    real z() {
        return _z;
    }

    void z(real z) {
        _z = z;
    }
};

}  // namespace Engine
