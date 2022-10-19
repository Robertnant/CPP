#include "vector.hh"

Vector::Vector() {
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(std::initializer_list<value> list) {
    x = data(list)[0];
    y = data(list)[1];
    z = data(list)[2];
}

value Vector::operator*(const Vector &rhs) {
    if (NDIM == 2)
        return (x * rhs.x) + (y * rhs.y);
    return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}

value &Vector::operator[](size_t index) {
    if (index >= NDIM)
        throw std::invalid_argument(
                "Index should be smaller than number of dimensions");
    if (index == 0)
        return x;
    if (index == 1)
        return y;

    return z;
}

Vector &Vector::operator+=(const value &rhs) {
    x += rhs;
    y += rhs;

    if (NDIM == 3)
        z += rhs;

    return *this;
}

Vector &Vector::operator+=(const Vector &rhs) {
    x += rhs.x;
    y += rhs.y;

    if (NDIM == 3)
        z += rhs.z;

    return *this;
}

Vector &Vector::operator-=(const Vector &rhs) {
    x -= rhs.x;
    y -= rhs.y;

    if (NDIM == 3)
        z -= rhs.z;

    return *this;
}

Vector &Vector::operator*=(const value &rhs) {
    x *= rhs;
    y *= rhs;

    if (NDIM == 3)
        z *= rhs;

    return *this;
}

Vector Vector::operator+(const Vector& rhs) {
    Vector sum_vector = NDIM == 3 ? Vector(
            {this->x + rhs.x, this->y + rhs.y, this->z + rhs.z}) :
                            Vector({this->x + rhs.x, this->y + rhs.y});
    return sum_vector;
}

Vector Vector::operator*(const value &rhs) {
    Vector product_vector = NDIM == 3 ? Vector(
            {this->x * rhs, this->y * rhs, this->z * rhs}) :
                            Vector({this->x * rhs, this->y * rhs});

    return product_vector;
}

value Vector::get_x() {
    return x;
}


value Vector::get_y() {
    return y;
}

value Vector::get_z() {
    return z;
}
