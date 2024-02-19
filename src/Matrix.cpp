#include <iostream>
#include "../headers/Matrix.h"

Matrix::Matrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->matrix[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}
Matrix::Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
    this->matrix[0][0] = a;
    this->matrix[0][1] = b;
    this->matrix[0][2] = c;
    this->matrix[1][0] = d;
    this->matrix[1][1] = e;
    this->matrix[1][2] = f;
    this->matrix[2][0] = g;
    this->matrix[2][1] = h;
    this->matrix[2][2] = i;
}
Matrix::~Matrix()
{
}

double Matrix::getElement(int row, int col) const
{
    return this->matrix[row][col];
}

