#include "../headers/Plane.h"
#include "../headers/VectorOperations.h"
 
Plane::Plane() : mNormal(VectorOperations(0, 0, 0)), mPointOnPlane(Point3D(0, 0, 0)) {}
Plane::Plane(VectorOperations &normal, Point3D &pointOnPlane) : mNormal(normal), mPointOnPlane(pointOnPlane) {}
 
VectorOperations Plane::getNormal() const
{
    return this->mNormal;
}
 
Point3D Plane::getPointOnPlane() const
{
    return this->mPointOnPlane;
}
 
Plane::~Plane() {}