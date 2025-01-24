#include "iostream"
#include "Matrix/CMatrix.h"

int main()
{
    CMatrix2D<int> mat(3, 2); // Create a 3x3 matrix
    CMatrix2D<int> mat2(3,2);
    // Initialize the matrix using setter
    int value = 1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            mat.Set(i, j, value);
            mat2.Set(i, j, value);
            value++;
        }
    }

    // Print the matrix
    std::cout << "Matrix:" << std::endl;
    CMatrix2D<int> mat3 = 2 * mat + mat2;
    mat3.OutPutMatrix();

    mat3 += mat3;
    mat3.OutPutMatrix();

    
    //mat3 -= mat3;
    //mat3.OutPutMatrix();
    mat3.Transpose();
    mat3.OutPutMatrix();

    mat.Fill(5);
    mat.OutPutMatrix();

    mat2.Randomize();
    mat2.OutPutMatrix();

    CMatrix2D<int> mat4(3,3);

    mat4.Identity();
    mat4.OutPutMatrix();
    
    return 0;
}