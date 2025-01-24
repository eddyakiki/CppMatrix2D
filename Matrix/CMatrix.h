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

    CMatrix2D(int pRows, int pCols);

    CMatrix2D(const CMatrix2D<T>& pCopyMatrix);

    CMatrix2D(CMatrix2D<T>&& pCopyMatrix) noexcept;

    virtual ~CMatrix2D() = default;

    T Get(int pRow, int pCol) const;

    int GetRows() const;

    int GetCols() const;

    std::pair<int,int> GetDimensions() const;

    void Set(int pRow, int pCol, T pVal);

    void SetZerosMatrix();

    void SetOnesMatrix();

    void Fill(T pScalar);

    void Randomize();

    bool Identity();

    bool IsZerosMatrix() const;

    bool IsOnesMatrix() const;

    void OutPutMatrix();

    T operator()(int row, int col);

    CMatrix2D<T>& Transpose();

    CMatrix2D<T>& operator=(const CMatrix2D<T>& pMatrix);

    CMatrix2D<T> operator+(const CMatrix2D<T>& pMatrix) const;

    CMatrix2D<T>& operator+=(const CMatrix2D<T>& pMatrix);

    CMatrix2D<T> operator-(const CMatrix2D<T>& pMatrix) const;

    CMatrix2D<T>& operator-=(const CMatrix2D<T>& pMatrix);

    CMatrix2D<T> operator*(T pScalar) const;

    CMatrix2D<T> operator/(T pScalar) const;

    CMatrix2D<T> operator*(const CMatrix2D<T>& pMatrix) const;

    template <typename U>
    friend CMatrix2D<U> operator*(U pScalar, const CMatrix2D<U>& pMatrix);
};

#endif