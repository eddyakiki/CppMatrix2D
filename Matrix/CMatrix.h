#ifndef __MATRIX2DCLASS__
#define __MATRIX2DCLASS__

#include <iostream>
#include <vector>

class CMatrix2D
{
private:
    int rows;
    int cols;
    std::vector<std::vector<int> > data;

public:
    CMatrix2D(int pRows, int pCols);

    int Get(int pRow, int pCol) const;

    int GetRows() const;

    int GetCols() const;

    std::pair<int,int> GetDimensions() const;

    void Set(int pRow, int pCol, int pVal);

    void SetZerosMatrix();

    void SetOnesMatrix();

    bool IsZerosMatrix() const;

    bool IsOnesMatrix() const;

    void OutPutMatrix();

    CMatrix2D operator+(const CMatrix2D& pOther) const;

    CMatrix2D operator*(float pScalar) const;

    CMatrix2D operator*(const CMatrix2D& pMatrix) const;

    friend CMatrix2D operator*(float pScalar, const CMatrix2D& pMatrix);
};

#endif