#include "iostream"
#include "Matrix/CMatrix.h"

int main()
{
    CMatrix2D mat(3, 3); // Create a 3x3 matrix
    CMatrix2D mat2(3,3);
    // Initialize the matrix using setter
    int value = 1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            mat.Set(i, j, value);
            mat2.Set(i, j, value);
            value++;
        }
    }

    // Print the matrix
    std::cout << "Matrix:" << std::endl;
    CMatrix2D mat3 = mat * mat2;
    mat.OutPutMatrix();
    mat2.OutPutMatrix();
    mat3.OutPutMatrix();

    return 0;
}