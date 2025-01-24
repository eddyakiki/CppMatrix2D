#include "CMatrix.h"

template <typename T>
CMatrix2D<T>::CMatrix2D(int pRows, int pCols) : rows(pRows),
                                             cols(pCols)
{
    data.resize(pRows, std::vector<T>(pCols, 0));
}

template <typename T>
CMatrix2D<T>::CMatrix2D(const CMatrix2D<T>& pCopyMatrix)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            this->Set(i,j,pCopyMatrix.Get(i,j));
        }
    }  
}

template <typename T>
CMatrix2D<T>::CMatrix2D(CMatrix2D<T>&& pCopyMatrix) noexcept : rows(pCopyMatrix.rows), cols(pCopyMatrix.cols), data(std::move(pCopyMatrix.data))
{
    pCopyMatrix.rows = 0;
    pCopyMatrix.cols = 0;
}

template <typename T>
T CMatrix2D<T>::Get(int pRow, int pCol) const
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

template <typename T>
void CMatrix2D<T>::Set(int pRow, int pCol, T pVal)
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

template <typename T>
void CMatrix2D<T>::OutPutMatrix()
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

template <typename T>
void CMatrix2D<T>::SetZerosMatrix()
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            this->data[i][j] = 0;
        }
    }  
}

template <typename T>
bool CMatrix2D<T>::IsZerosMatrix() const
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

template <typename T>
void CMatrix2D<T>::SetOnesMatrix()
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            this->data[i][j] = 1;
        }
    }  
}

template <typename T>
bool CMatrix2D<T>::IsOnesMatrix() const
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

template <typename T>
void CMatrix2D<T>::Fill(T pScalar)
{
    for(int i = 0; i < this->GetRows(); ++i)
    {
        for(int j = 0; j < this->GetCols(); ++j)
        {
            this->Set(i,j,pScalar);
        }
    }    
}

template <typename T>
void CMatrix2D<T>::Randomize()
{
    srand(time(NULL)); 

    for(int i = 0; i < this->GetRows(); ++i)
    {
        for(int j = 0; j < this->GetCols(); ++j)
        {
            this->Set(i,j,rand() % 1000);
        }
    }
}

template <typename T>
bool CMatrix2D<T>::Identity()
{
    if(this->GetCols() != this->GetRows())
    {
        return false;
    }

    this->SetZerosMatrix();

    for(int i = 0; i < this->GetRows(); ++i)
    {
        for(int j = 0; j < this->GetCols(); ++j)
        {
            if(i == j)
            {
                this->Set(i,j,1);
            }
        }
    }
    return true;
}

template <typename T>
int CMatrix2D<T>::GetRows() const
{
    return this->rows;
}

template <typename T>
int CMatrix2D<T>::GetCols() const
{
    return this->cols;
}

template <typename T>
std::pair<int,int> CMatrix2D<T>::GetDimensions() const
{
    return std::pair<int,int>(rows,cols);
}

template <typename T>
CMatrix2D<T> CMatrix2D<T>::operator+(const CMatrix2D<T>& pMatrix) const
{
    CMatrix2D<T> SumMatrix(rows, cols);
    SumMatrix.SetZerosMatrix();

    if(pMatrix.GetDimensions() != this->GetDimensions())
    {
        return SumMatrix;
    }
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            SumMatrix.Set(i,j,pMatrix.Get(i,j) + this->Get(i,j));
        }
    }
    return SumMatrix;
}

template <typename T>
CMatrix2D<T>& CMatrix2D<T>::operator+=(const CMatrix2D<T>& pMatrix)
{
    for(int i = 0; i < this->GetRows(); ++i)
    {
        for(int j = 0; j < this->GetCols(); ++j)
        {
            this->Set(i,j,pMatrix.Get(i,j) + this->Get(i,j));
        }
    }
    return *this;    
}

template <typename T>
CMatrix2D<T> CMatrix2D<T>::operator-(const CMatrix2D<T>& pMatrix) const
{
    CMatrix2D<T> SumMatrix(rows, cols);
    SumMatrix.SetZerosMatrix();

    if(pMatrix.GetDimensions() != this->GetDimensions())
    {
        return SumMatrix;
    }
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            SumMatrix.Set(i,j,this->Get(i,j) - pMatrix.Get(i,j));
        }
    }
    return SumMatrix;
}

template <typename T>
CMatrix2D<T>& CMatrix2D<T>::operator-=(const CMatrix2D<T>& pMatrix)
{
    for(int i = 0; i < this->GetRows(); ++i)
    {
        for(int j = 0; j < this->GetCols(); ++j)
        {
            this->Set(i,j,this->Get(i,j) - pMatrix.Get(i,j));
        }
    }
    return *this;    
}

template <typename T>
CMatrix2D<T> CMatrix2D<T>::operator*(T pScalar) const
{
    CMatrix2D<T> MultMatrix(rows, cols);
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

template <typename T>
CMatrix2D<T> operator*(T pScalar, const CMatrix2D<T>& pMatrix)
{
    CMatrix2D<T> MultMatrix(pMatrix.GetRows(), pMatrix.GetCols());
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

template <typename T>
CMatrix2D<T> CMatrix2D<T>::operator/(T pScalar) const
{
    CMatrix2D<T> DivMatrix(rows, cols);
    DivMatrix.SetZerosMatrix();

    if(pScalar == 0) return DivMatrix;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            DivMatrix.Set(i,j,this->Get(i,j) / pScalar);
        }
    }

    return DivMatrix;
}

template <typename T>
CMatrix2D<T> CMatrix2D<T>::operator*(const CMatrix2D<T>& pMatrix) const
{
    CMatrix2D<T> MultMatrix(pMatrix.GetRows(), pMatrix.GetCols());
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

template <typename T>
CMatrix2D<T>& CMatrix2D<T>::operator=(const CMatrix2D<T>& pMatrix)
{

    if(pMatrix.GetDimensions() != this->GetDimensions())
    {
        this->data.resize(pMatrix.GetRows(), std::vector<T>(pMatrix.GetCols(), 0));
        this->rows = pMatrix.GetRows();
        this->cols = pMatrix.GetCols();
    }

    for(int i = 0; i < this->GetRows(); ++i)
    {
        for(int j = 0; j < this->GetCols(); ++j)
        {
            this->Set(i,j,pMatrix.Get(i,j));
        }
    }

    return *this;    
}

template <typename T>
CMatrix2D<T>& CMatrix2D<T>::Transpose()
{
    CMatrix2D<T> tempMat(this->GetCols(),this->GetRows());

    for (int i = 0; i < this->GetRows(); ++i)
    {
        for (int j = 0; j < this->GetCols(); ++j)
        {
            tempMat.Set(j, i, this->Get(i, j));
        }
    }

    *this = tempMat;

    return *this; 
}

template class CMatrix2D<int>;
template class CMatrix2D<float>;
template class CMatrix2D<double>;

template CMatrix2D<int> operator*(int, const CMatrix2D<int>&);
template CMatrix2D<float> operator*(float, const CMatrix2D<float>&);
template CMatrix2D<double> operator*(double, const CMatrix2D<double>&);