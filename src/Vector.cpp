#include "../headers/Vector.h"

Vector::Vector() {}

Vector::Vector(const std::vector<double>& elems) : elements(elems) {}

std::vector<double> Vector::getElements() const {
    return elements;
}

Vector Vector::operator+(const Vector& other) const {
    std::vector<double> result;
    for (size_t i = 0; i < elements.size(); ++i) {
        result.push_back(elements[i] + other.getElements()[i]);
    }
    return Vector(result);
}

Vector Vector::operator-(const Vector& other) const {
    std::vector<double> result;
    for (size_t i = 0; i < elements.size(); ++i) {
        result.push_back(elements[i] - other.getElements()[i]);
    }
    return Vector(result);
}

Vector Vector::operator*(double scalar) const {
    std::vector<double> result;
    for (double element : elements) {
        result.push_back(element * scalar);
    }
    return Vector(result);
}

double Vector::dot(const Vector& other) const {
    double result = 0.0;
    for (size_t i = 0; i < elements.size(); ++i) {
        result += elements[i] * other.getElements()[i];
    }
    return result;
}

Vector Vector::cross(const Vector& other) const {
    if (elements.size() != 3 || other.getElements().size() != 3) {
        // throw std::runtime_error("Cross product is defined only for 3D vectors.");
    }

    std::vector<double> result(3);
    result[0] = elements[1] * other.getElements()[2] - elements[2] * other.getElements()[1];
    result[1] = elements[2] * other.getElements()[0] - elements[0] * other.getElements()[2];
    result[2] = elements[0] * other.getElements()[1] - elements[1] * other.getElements()[0];

    return Vector(result);
}
