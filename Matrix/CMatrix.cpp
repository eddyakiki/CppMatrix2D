#include "CMatrix.h"

// Constructor
template <typename T>
CMatrix2D<T>::CMatrix2D(int pRows, int pCols) : rows(pRows),
                                             cols(pCols)
{
    data.resize(pRows, std::vector<T>(pCols, 0));
}

// Copy Constructor
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

// Move Constructor
template <typename T>
CMatrix2D<T>::CMatrix2D(CMatrix2D<T>&& pCopyMatrix) noexcept : rows(pCopyMatrix.rows), cols(pCopyMatrix.cols), data(std::move(pCopyMatrix.data))
{
    pCopyMatrix.rows = 0;
    pCopyMatrix.cols = 0;
}

// Gets a specific value from the matrix
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

// Sets a specific element of the matrix to a certain value
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

// Prints the matirx's content
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

// Sets all elements of the matrix to zero
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

// Checks if the matrix is a zero matrix
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

// Sets all elements of the matrix to one
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

// Check if the matrix is a ones matrix
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

// Fill all elements of a matrix with a specific value
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

// Fill the matrix with random values between 0 and 999
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

// Set the matrix to the identity matrix (needs to be a square matrix) 
// return true if it is a square matrix, false if it is not
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

// Get the number of rows of a matrix
template <typename T>
int CMatrix2D<T>::GetRows() const
{
    return this->rows;
}

// Get the number of columns of a matrix
template <typename T>
int CMatrix2D<T>::GetCols() const
{
    return this->cols;
}

// Get the dimensions of the matrix as a (row,cols) pair
template <typename T>
std::pair<int,int> CMatrix2D<T>::GetDimensions() const
{
    return std::pair<int,int>(rows,cols);
}

// Override of the + operator to allow matrix addition
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

// Override of the += operator to allow matrix addition
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

// Override of the - operator to allow matrix substraction
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

// Override of the -= operator to allow matrix substraction
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

// Override of the * operator to multiply all elements of a matrix by a scalar (mat * scalar)
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

// Override of the * operator to multiply all elements of a matrix by a scalar (for commutative multiplication scalar * mat)
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

// Override of the / operator to divide all elements of a matrix by a scalar
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

// Matrix multiplication A * B with A_number_of_cols = B_number_of_rows
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

// Assigns the values of the given matrix (pMatrix) to the current matrix (*this).
template <typename T>
CMatrix2D<T>& CMatrix2D<T>::operator=(const CMatrix2D<T>& pMatrix)
{

    if(pMatrix.GetDimensions() != this->GetDimensions())
    {
        // Resize the matrix if the the old structure is incompatible with the new one
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

// Transposes the matrix
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