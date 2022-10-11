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
    Vector(std::initializer_list<int> list);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    Vector& operator+=(const int& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector& operator*=(const int& rhs);
    Vector operator+(const Vector& rhs);
    int operator*(const Vector& rhs);
    Vector operator*(const int& rhs);
    int& operator[](size_t index);
    // More to go
    int get_x();
    int get_y();
    int get_z();
    void set_x(int value);
    void set_y(int value);
    void set_z(int value);

private:
// Private Member functions here
// Member variables are ALWAYS private, and they go here
    int x;
    int y;
    int z;
};

// Nonmember function operators go here
std::ostream& operator << (std::ostream &out, Vector rhs) {
    if (NDIM == 3)
        out << '{' + rhs.get_x() + ',' + rhs.get_y() + ',' + rhs.get_z() + '}';
    else
        out << "{" << rhs.get_x() << ',' << rhs.get_y() << "}";
    return out;
}