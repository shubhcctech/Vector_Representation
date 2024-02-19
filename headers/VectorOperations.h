#pragma once
#include <cmath>
#include "Point3D.h"
#include "Matrix.h"

class Plane;
class GeomVectors : public Point3D
{
public:
    GeomVectors();
    GeomVectors(double x, double y, double z);
    ~GeomVectors();
    bool vectorEqualCheck(const GeomVectors& vector1 , const GeomVectors& vector2);
    bool operator==(const GeomVectors &other) const;
    double magnitude() const;
    GeomVectors normalizedVector() const;
    double dotProduct(const GeomVectors &other) const;
    GeomVectors crossProduct(const GeomVectors &other) const;

    GeomVectors operator+(const GeomVectors &other) const;
    GeomVectors operator-(const GeomVectors &other) const;
    GeomVectors operator*(const GeomVectors &other) const;
    GeomVectors operator/(const GeomVectors &other) const;
    GeomVectors setVectorLength(double newLength) const;

    GeomVectors addScalar(double scalar) const;
    GeomVectors subtractScalar(double scalar) const;
    GeomVectors multiplyScalar(double scalar) const;
    GeomVectors divideScalar(double scalar) const;

    double distanceBetweenVectors(const GeomVectors &other) const;
    double distanceBetweenVectorAndPlane(const Plane &plane) const;
    double angleBetweenVectors(const GeomVectors &other) const;
    double angleBetweenVectorAndPlane(const Plane &plane) const;
    void angleBetweenVectorAndAxis() const;

    GeomVectors multiplyMatrix(const Matrix &matrix) const;
    GeomVectors projectionOnVector(const GeomVectors &otherVector) const;
    GeomVectors projectVectorOnPlane(const GeomVectors &vector, const GeomVectors &planeNormal) const;
    double angleBetweenVector(const GeomVectors& other);
    void directionCosines() const;
    double angleWithXaxis();
    double angleWithYaxis();
    double angleWithZaxis();

};
