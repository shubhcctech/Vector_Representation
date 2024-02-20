#pragma once
#include <string>
#include <vector>
#include "VectorOperations.h"
using namespace std;
class Writer
{
public:
    // Function to write geometry data to an STL file
    void write(string &, vector<GeomVectors> &);
};
