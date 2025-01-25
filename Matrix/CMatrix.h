#ifndef __MATRIX2DCLASS__
#define __MATRIX2DCLASS__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
class CMatrix2D
{
private:
    int rows;
    int cols;
    std::vector<std::vector<T>> data;

public:

    // Constructor
    CMatrix2D(int pRows, int pCols);

    //Copy Constructor
    CMatrix2D(const CMatrix2D<T>& pCopyMatrix);

    //Move Constructor
    CMatrix2D(CMatrix2D<T>&& pCopyMatrix) noexcept;

    //Destructor
    virtual ~CMatrix2D() = default;

    //Get the matrix element at index pRow and pCol
    T Get(int pRow, int pCol) const;

    //Get number of rows
    int GetRows() const;

    //Get number of Cols
    int GetCols() const;

    //Get dimension as a (rows,cols) pair
    std::pair<int,int> GetDimensions() const;

    //Set the value of a certain element
    void Set(int pRow, int pCol, T pVal);

    //Set to zero matrix
    void SetZerosMatrix();

    //Set to Ones matrix
    void SetOnesMatrix();

    //Fill matrix with the pScalar value
    void Fill(T pScalar);

    //Fill the matrix with random values between 0 and 999
    void Randomize();

    //Set the matrix to the identity matrix if it is a square matrix
    bool Identity();

    //Check if the matrix is a zeros matrix
    bool IsZerosMatrix() const;

    //Check if the matrix is a ones matrix    
    bool IsOnesMatrix() const;

    //Print the content of the matrix
    void OutPutMatrix();

    //Transposes the matrix
    CMatrix2D<T>& Transpose();

    //Assign operator overload
    CMatrix2D<T>& operator=(const CMatrix2D<T>& pMatrix);

    //Allow matrix addition
    CMatrix2D<T> operator+(const CMatrix2D<T>& pMatrix) const;

    CMatrix2D<T>& operator+=(const CMatrix2D<T>& pMatrix);

    //Allow matrix substraction
    CMatrix2D<T> operator-(const CMatrix2D<T>& pMatrix) const;

    CMatrix2D<T>& operator-=(const CMatrix2D<T>& pMatrix);

    //Multiply all elements by pScalar (mat * pScalar)
    CMatrix2D<T> operator*(T pScalar) const;

    //Divide all elements by pScalar
    CMatrix2D<T> operator/(T pScalar) const;

    //Matrix multiplication
    CMatrix2D<T> operator*(const CMatrix2D<T>& pMatrix) const;
    
    //Allows commutative scalar multiplication (scalar * mat)
    template <typename U>
    friend CMatrix2D<U> operator*(U pScalar, const CMatrix2D<U>& pMatrix);
};

#endif