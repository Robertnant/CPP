#include "vector.hh"

Vector::Vector(const Vector& rhs) {
    dimension = rhs.size();
    values = std::make_unique<value[]>(dimension);
    for (size_t i = 0; i < dimension; i++) {
        values[i] = rhs[i];
    }
}

Vector& Vector::operator=(const Vector& rhs) {
    dimension = rhs.size();
    for (size_t i = 0; i < rhs.size(); i++) {
        values[i] = rhs[i];
    }

    return *this;
}

Vector::Vector(size_t N) {
    values = std::make_unique<value[]>(N);
    dimension = N;

    for (size_t i = 0; i < N; i++) {
        values[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> list) {
    values = std::make_unique<value[]>(dimension);
    dimension = list.size();
    for (size_t i = 0; i < list.size(); i++) {
        values[i] = data(list)[i];
    }
}

size_t Vector::size() const {
    return dimension;
}

value Vector::operator*(const Vector& rhs) const {
    if (dimension != rhs.size())
        throw std::runtime_error("Incompatible size");
    value product = 0;
    for (size_t i = 0; i < dimension; i++) {
        product += (values[i] * rhs[i]);
    }
    return product;
}

Vector operator+(const value& s, const Vector& v) {
    Vector sum_vector = Vector(v.size()) + s;
}

Vector operator*(const value& s, const Vector& v) {
    Vector sum_vector = Vector(v.size()) * s;
}

value &Vector::operator[](size_t idx) {
    if (idx >= size())
        throw std::runtime_error("Incompatible size");

    return values[idx];
}

value Vector::operator[](size_t idx) const {
    if (idx >= size())
        throw std::runtime_error("Incompatible size");

    return values[idx];
}

Vector &Vector::operator+=(value v) {
    for (size_t i = 0; i < dimension; i++) {
        values[i] += v;
    }

    return *this;
}

Vector &Vector::operator+=(const Vector &rhs) {
    if (rhs.size() != dimension) {
        throw std::runtime_error("Incompatible size");
    }
    for (size_t i = 0; i < dimension; i++) {
        values[i] += rhs[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs) {
    if (rhs.size() != dimension) {
        throw std::runtime_error("Incompatible size");
    }
    for (size_t i = 0; i < dimension; i++) {
        values[i] -= rhs[i];
    }
    return *this;
}

Vector &Vector::operator*=(value v) {
    for (size_t i = 0; i < dimension; i++) {
        values[i] *= v;
    }

    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    if (rhs.size() != dimension) {
        throw std::runtime_error("Incompatible size");
    }
    Vector sum_vector = Vector(dimension);
    sum_vector += rhs;
    return sum_vector;
}

Vector Vector::operator+(value v) const {
    Vector sum_vector = Vector(dimension);
    sum_vector += v;
    return sum_vector;
}

Vector Vector::operator*(value v) const {
    Vector product_vector = Vector(dimension);
    product_vector *= v;
    return product_vector;
}

std::ostream& operator<<(std::ostream &o, const Vector &v) {
    o << '{';
    for (size_t i = 0; i < v.size() - 1; i++) {
        o << v[i] << ',';
    }
    o << v[v.size() - 1] << '}';;

    return o;
}