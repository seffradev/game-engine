#pragma once

#include <iostream>

#include "Real.hpp"

namespace Engine {

class Vector2D {
   private:
    real _x, _y;

   public:
    Vector2D() : _x(0), _y(0) {}
    Vector2D(real x, real y) : _x(x), _y(y) {}

    static real dot(const Vector2D& lhs, const Vector2D& rhs) {
        return lhs._x * rhs._x + lhs._y * rhs._y;
    }

    real dot(const Vector2D& rhs) {
        return dot(*this, rhs);
    }

    static real angle(const Vector2D& vector) {
        return tan(vector._y / vector._x);
    }

    real angle() {
        return angle(*this);
    }

    static real norm(const Vector2D& vector) {
        return sqrt(vector._x * vector._x + vector._y * vector._y);
    }

    real norm() {
        return norm(*this);
    }

    static Vector2D normalise(const Vector2D& vector) {
        return vector / norm(vector);
    }

    Vector2D& operator+=(const Vector2D& rhs) {
        this->_x += rhs._x;
        this->_y += rhs._y;

        return *this;
    }

    friend Vector2D operator+(Vector2D lhs, const Vector2D& rhs) {
        return lhs += rhs;
    }

    Vector2D& operator-=(const Vector2D& rhs) {
        this->_x -= rhs._x;
        this->_y -= rhs._y;

        return *this;
    }

    friend Vector2D operator-(Vector2D lhs, const Vector2D& rhs) {
        return lhs -= rhs;
    }

    Vector2D& operator*=(const real& rhs) {
        this->_x *= rhs;
        this->_y *= rhs;

        return *this;
    }

    friend Vector2D operator*(Vector2D lhs, const real& rhs) {
        return lhs *= rhs;
    }

    Vector2D& operator/=(const real& rhs) {
        this->_x /= rhs;
        this->_y /= rhs;

        return *this;
    }

    friend Vector2D operator/(Vector2D lhs, const real& rhs) {
        return lhs /= rhs;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector) {
        os << "(" << vector._x << ", " << vector._y << ")";
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
};

}  // namespace Engine
