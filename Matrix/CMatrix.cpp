#include "CMatrix.h"

CMatrix2D::CMatrix2D(int pRows, int pCols) : rows(pRows),
                                             cols(pCols)
{
    data.resize(rows, std::vector<int>(cols, 0));
}

int CMatrix2D::Get(int pRow, int pCol) const
{
    if ((pRow < 0 || pRow >= rows) || (pCol < 0 || pCol >= cols))
    {
        throw std::out_of_range("Index out of range");
    }
    else
    {
        return data[pRow][pCol];
    }
}

void CMatrix2D::Set(int pRow, int pCol, int pVal)
{
    if ((pRow < 0 || pRow >= rows) || (pCol < 0 || pCol >= cols))
    {
        throw std::out_of_range("Index out of range");
    }
    else
    {
        data[pRow][pCol] = pVal;
    }
}

void CMatrix2D::OutPutMatrix()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << data[i][j];
            std::cout << " ";
        }

        std::cout << "\n";
    }
}