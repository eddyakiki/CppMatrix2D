#include "iostream"
#include "Matrix/CMatrix.h"

int main()
{
    CMatrix2D mat(3, 3); // Create a 3x3 matrix

    // Initialize the matrix using setter
    int value = 1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            mat.Set(i, j, value++);
        }
    }

    // Print the matrix
    std::cout << "Matrix:" << std::endl;
    mat.OutPutMatrix();

    return 0;
}