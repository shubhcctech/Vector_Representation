#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

class Vector {
public:
    // Constructors
    Vector();
    Vector(const std::vector<double>& elems);

    // Getter
    std::vector<double> getElements() const;

    // Vector operations
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
    double dot(const Vector& other) const;
    Vector cross(const Vector& other) const;

private:
    std::vector<double> elements;
};

#endif // VECTOR_H
