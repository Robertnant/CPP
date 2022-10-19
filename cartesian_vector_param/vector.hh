#pragma once

#include <ostream>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<value> list);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    Vector& operator+=(const value& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector& operator*=(const value& rhs);
    Vector operator+(const Vector& rhs);
    value operator*(const Vector& rhs);
    Vector operator*(const value& rhs);
    value& operator[](size_t index);
    // More to go
    value get_x();
    value get_y();
    value get_z();

private:
// Private Member functions here
// Member variables are ALWAYS private, and they go here
    value x;
    value y;
    value z;
};

// Nonmember function operators go here
std::ostream& operator << (std::ostream &out, Vector rhs) {
    if (NDIM == 3)
        out << '{' + rhs.get_x() + ',' + rhs.get_y() + ',' + rhs.get_z() + '}';
    else
        out << "{" << rhs.get_x() << ',' << rhs.get_y() << "}";
    return out;
}
