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

    void Set(int pRow, int pCol, int pVal);

    void OutPutMatrix();
};

#endif