#include "../headers/Plane.h"
#include "../headers/VectorOperations.h"
 
Plane::Plane() : mNormal(GeomVectors(0, 0, 0)), mPointOnPlane(Point3D(0, 0, 0)) {}
Plane::Plane(GeomVectors &normal, Point3D &pointOnPlane) : mNormal(normal), mPointOnPlane(pointOnPlane) {}
 
GeomVectors Plane::normal() const
{
    return this->mNormal;
}
 
Point3D Plane::pointOnPlane() const
{
    return this->mPointOnPlane;
}
 
Plane::~Plane() {}