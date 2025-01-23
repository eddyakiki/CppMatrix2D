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
        this->data[pRow][pCol] = pVal;
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

void CMatrix2D::SetZerosMatrix()
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            this->data[i][j] = 0;
        }
    }  
}

bool CMatrix2D::IsZerosMatrix() const
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(this->Get(i,j) == 0)
            {
                return false;
            }
        }
    }
    return true;  
}

void CMatrix2D::SetOnesMatrix()
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            this->data[i][j] = 1;
        }
    }  
}

bool CMatrix2D::IsOnesMatrix() const
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(this->Get(i,j) == 1)
            {
                return false;
            }
        }
    }
    return true;  
}

int CMatrix2D::GetRows() const
{
    return this->rows;
}

int CMatrix2D::GetCols() const
{
    return this->cols;
}

std::pair<int,int> CMatrix2D::GetDimensions() const
{
    return std::pair<int,int>(rows,cols);
}

CMatrix2D CMatrix2D::operator+(const CMatrix2D& pOther) const
{
    CMatrix2D SumMatrix(rows, cols);
    SumMatrix.SetZerosMatrix();

    if(pOther.GetDimensions() != this->GetDimensions())
    {
        return SumMatrix;
    }
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            SumMatrix.Set(i,j,pOther.Get(i,j) + this->Get(i,j));
        }
    }
    return SumMatrix;
}

CMatrix2D CMatrix2D::operator*(float pScalar) const
{
    CMatrix2D MultMatrix(rows, cols);
    MultMatrix.SetZerosMatrix();

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            MultMatrix.Set(i,j,this->Get(i,j) * pScalar);
        }
    }

    return MultMatrix;
}

CMatrix2D operator*(float pScalar, const CMatrix2D& pMatrix)
{
    CMatrix2D MultMatrix(pMatrix.GetRows(), pMatrix.GetCols());
    MultMatrix.SetZerosMatrix();

    for(int i = 0; i < pMatrix.GetRows(); ++i)
    {
        for(int j = 0; j < pMatrix.GetCols(); ++j)
        {
            MultMatrix.Set(i,j,pMatrix.Get(i,j) * pScalar);
        }
    }

    return MultMatrix;
}

CMatrix2D CMatrix2D::operator*(const CMatrix2D& pMatrix) const
{
    CMatrix2D MultMatrix(pMatrix.GetRows(), pMatrix.GetCols());
    MultMatrix.SetZerosMatrix();

    if(this->GetCols() != pMatrix.GetRows())
    {
        return MultMatrix;
    }

    for(int i = 0; i < this->GetRows(); ++i)
    {
        for(int j = 0; j < pMatrix.GetCols(); ++j)
        {
            long sum = 0;

            for (int k = 0; k < pMatrix.GetRows(); ++k)
            {
                sum += this->Get(i,k) * pMatrix.Get(k,j);
            }
            MultMatrix.Set(i,j,sum);
        }
    }
    return MultMatrix;
}