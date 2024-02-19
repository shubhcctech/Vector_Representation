#pragma once
#include <cmath>
#include "Point3D.h"
#include "Matrix.h"

class Plane;
class VectorOperations : public Point3D
{
public:
    VectorOperations();
    VectorOperations(double x, double y, double z);
    ~VectorOperations();

    bool operator==(const VectorOperations &other) const;
    double getMagnitude() const;
    VectorOperations getNormalized() const;
    double getDotProduct(const VectorOperations &other) const;
    VectorOperations getCrossProduct(const VectorOperations &other) const;

    VectorOperations operator+(const VectorOperations &other) const;
    VectorOperations operator-(const VectorOperations &other) const;
    VectorOperations operator*(const VectorOperations &other) const;
    VectorOperations operator/(const VectorOperations &other) const;
    VectorOperations setVectorLength(double newLength) const;

    VectorOperations addScalar(double scalar) const;
    VectorOperations subtractScalar(double scalar) const;
    VectorOperations multiplyScalar(double scalar) const;
    VectorOperations divideScalar(double scalar) const;

    double getDistanceBetweenVectors(const VectorOperations &other) const;
    double getDistanceBetweenVectorAndPlane(const Plane &plane) const;
    double getAngleBetweenVectors(const VectorOperations &other) const;
    double getAngleBetweenVectorAndPlane(const Plane &plane) const;
    void angleBetweenVectorAndAxis() const;

    VectorOperations multiplyMatrix(const Matrix &matrix) const;
    VectorOperations projectionOnVector(const VectorOperations &otherVector) const;
    VectorOperations projectVectorOnPlane(const VectorOperations &vector, const VectorOperations &planeNormal) const;
    double angleBetweenVector(const VectorOperations& other);
    void directionCosines() const;
    double angleWithXaxis();
    double angleWithYaxis();
    double angleWithZaxis();

};
