#include"SquareMat.hpp"
#include <cmath>
namespace matrix{
double SquareMat::mod(double x, double y) const
{
    return x - y * (int)(x / y);
}
/**
 * @brief Constructor that initializes an N x N matrix with all values set to 0.
 * @param N Size of the matrix.
 * @throws std::invalid_argument if N <= 0.
 */
SquareMat::SquareMat(int N): n(N),matrix(nullptr){//רשימת איתחול
    if (N <= 0) {//בדיקה שהגודל שהוכנס לא שלילי
        throw std::invalid_argument("Matrix size must be positive");
    }
      //כאן אני מקצה זיכרון למטריצה  
        matrix = new double*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new double[n]; 
    }
    //אני מאתחל את המטריצה עם הערך 0 בכולה
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j]=0;
        }
    }
}
/**
 * @brief Copy constructor. Deep-copies another matrix.
 * @param other Matrix to copy.
 */
SquareMat::SquareMat(const SquareMat& other) : n(other.n), matrix(nullptr) {
    matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = other.matrix[i][j];  // העתקת הערכים
        }
    }
}

/**
 * @brief Destructor. Frees allocated memory.
 */
SquareMat::~SquareMat(){//דיסטרקטור לאובייקט שלנו
    if (matrix != nullptr)
    {
        for (int i = 0; i < n; i++)
    {
        delete[]matrix[i];
    }
    delete[] matrix;
    }
}

/**
 * @brief Assignment operator. Performs deep copy and memory management.
 * @param other Matrix to copy.
 * @return Reference to this matrix.
 */
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) return *this; 

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    n = other.n;
    matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }

    return *this;
}


/**
 * @brief Adds a value to a specific (row, col) in the matrix.
 * @param row Row index.
 * @param col Column index.
 * @param value Value to assign.
 * @throws std::out_of_range if indices are out of bounds.
 */
void SquareMat::addValueAt(int row, int col, double value){
    if (row < 0 || row >= n || col < 0 || col >= n) {//בדיקה שהשורות והעמודות בגבולות הגודל של המטריצה
        throw std::out_of_range("Index out of bounds");
    }
    matrix[row][col]=value;
}

/**
 * @brief Element-wise matrix addition.
 * @param other Matrix to add.
 * @return New matrix result.
 * @throws std::invalid_argument if sizes differ.
 */
SquareMat SquareMat::operator+(const SquareMat &other) const//פונקציה להעמסת אופרטור + שעושה חיבור של שני מטריצות
{
    if (n != other.n) {
        throw std::invalid_argument("Cannot add matrices of different sizes");
    }
    
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = matrix[i][j]+other.matrix[i][j]; 
            m.addValueAt(i,j,data); 
        }
    }
    return m;
}

/**
 * @brief Element-wise subtraction between matrices.
 * @param other Matrix to subtract.
 * @return Resulting matrix.
 * @throws std::invalid_argument if sizes differ.
 */
SquareMat SquareMat::operator-(const SquareMat &other) const//פונקציה להעמסת אופרטור - שעושה חיסור של שני מטריצות
{
    if (n != other.n) {
        throw std::invalid_argument("The matrices is with a different sizes");
    }
    
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = matrix[i][j]-other.matrix[i][j]; 
            m.addValueAt(i,j,data); 
        }
    }
    return m;
}

/**
 * @brief Unary minus operator. Negates all matrix values.
 * @return Negated matrix.
 */
SquareMat SquareMat::operator-() const//פונקציה להעמסת אופרטור - אונארי שהופכת את הסימון של כל סקלר בתוך המטריצה
{
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = 0 - matrix[i][j];
            m.addValueAt(i,j,data); 
        }
    }
    return m;
}

/**
 * @brief Matrix multiplication.
 * @param other Matrix to multiply with.
 * @return Resulting matrix.
 * @throws std::invalid_argument if sizes differ.
 */
SquareMat SquareMat::operator*(const SquareMat &other) const//פונקציה להעמסת האופרטור * הפונקציה מבצעת כפל בין שתי מטריצות
{
    if (n != other.n) {
        throw std::invalid_argument("The matrices is with a different sizes");
    }
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double sum = 0;
            for (int k = 0; k < n; k++)
            {
                double mult = matrix[i][k] * other.matrix[k][j];
                sum += mult;
            }
            m.addValueAt(i,j,sum);
        }
    }
   return m;
}

/**
 * @brief Multiplies each element of the matrix by a scalar value.
 * @param scalar A scalar value.
 * @return A new matrix where each element is multiplied by the scalar.
 */
SquareMat SquareMat::operator*(double scalar) const
{
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = matrix[i][j]*scalar; 
            m.addValueAt(i,j,data); 
        }
    }
    return m;
}

/**
 * @brief Multiplies a scalar by a matrix (commutative scalar multiplication).
 * @param scalar Scalar value.
 * @param mat Matrix to multiply.
 * @return New matrix result of scalar * matrix.
 */
SquareMat operator*(double scalar, const SquareMat &mat)
{
    return mat*scalar;
}


/**
 * @brief Performs element-wise multiplication between two matrices.
 * @param other Matrix to multiply with.
 * @return New matrix with each element as the product of corresponding elements.
 * @throws std::invalid_argument if matrix sizes do not match.
 */
SquareMat SquareMat::operator%(const SquareMat &other) const
{
    if (n != other.n) {
        throw std::invalid_argument("The matrices is with a different sizes");
    }
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = matrix[i][j]*other.matrix[i][j]; 
            m.addValueAt(i,j,data); 
        }
    }
    return m;
}

/**
 * @brief Performs modulo operation on each element with a scalar.
 * @param scalar The integer to use for modulo.
 * @return Matrix with each element modulo scalar.
 * @throws std::invalid_argument if scalar is zero.
 */
SquareMat SquareMat::operator%(int scalar) const
{
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero is undefined.");
    }

    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = mod(matrix[i][j], scalar); 
            m.addValueAt(i,j,data); 
        }
    }
    return m;
}

/**
 * @brief Divides each matrix element by a scalar.
 * @param scalar Integer scalar divisor.
 * @return Matrix with elements divided by scalar.
 */
SquareMat SquareMat::operator/(int scalar) const
{
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = matrix[i][j] / scalar; 
            m.addValueAt(i,j,data); 
        }
    }
    return m;
}

/**
 * @brief Raises the matrix to an integer power.
 * @param p Power to raise to (must be >= 0).
 * @return Matrix raised to the power p.
 * @throws std::invalid_argument if p < 0.
 */
SquareMat SquareMat::operator^(int p) const//לתקן
{
    if (p < 0) {
        throw std::invalid_argument("Power must be non-negative");
    }
    
    SquareMat m(n);
    if (p==0)
    {
        for (int i = 0; i < n; i++)
        {
            m.addValueAt(i,i,1);   
        }
        return m;
        
    }
    
    m = *this;
    for (int i = 1; i < p; i++)
    {
    m=m*m;
    }
    
    return m;
}

/**
 * @brief Prefix increment operator. Increments all matrix elements by 1.
 * @return Reference to the incremented matrix.
 * @throws std::logic_error if matrix is invalid.
 */
SquareMat& SquareMat::operator++(){
    if (matrix == nullptr || n <= 0) {
        throw std::logic_error("Invalid matrix: cannot increment");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           double data = matrix[i][j]+1;
           this->addValueAt(i,j,data);
        }
    }
    return *this;

}

/**
 * @brief Postfix increment operator. Increments all elements by 1 but returns the original state.
 * @return A copy of the matrix before incrementing.
 */
SquareMat SquareMat:: operator++(int){
    SquareMat m(*this);
    ++(*this);
    return m;
}

/**
 * @brief Prefix decrement operator. Decrements all matrix elements by 1.
 * @return Reference to the decremented matrix.
 * @throws std::logic_error if matrix is invalid.
 */
SquareMat& SquareMat::operator--(){
    if (matrix == nullptr || n <= 0) {
        throw std::logic_error("Invalid matrix: cannot decrement");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           double data = matrix[i][j]-1;
           this->addValueAt(i,j,data);
        }
    }
    return *this;

}

/**
 * @brief Postfix decrement operator. Decrements all matrix elements by 1 but returns the original state.
 * @return A copy of the matrix before decrementing.
 */
SquareMat SquareMat:: operator--(int){
    SquareMat m(*this);
    --(*this);
    return m;
}

/**
 * @brief Transposes the matrix (flips rows and columns).
 * @return A new matrix that is the transpose of the original.
 * @throws std::logic_error if the matrix is uninitialized or empty.
 */
SquareMat SquareMat:: operator~() const{
    if (matrix == nullptr || n <= 0) {
        throw std::logic_error("Cannot transpose an empty or uninitialized matrix");
    }    
    SquareMat m(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double data = matrix[i][j];
            m.addValueAt(j,i,data);
        }
    }
    return m;
}

/**
 * @brief Provides access to a specific row in the matrix.
 * @param i Row index.
 * @return Pointer to the beginning of the row.
 * @throws std::logic_error if matrix is uninitialized.
 * @throws std::out_of_range if row index is invalid.
 */
double* SquareMat::operator[](int i) {
    if (matrix == nullptr)
    throw std::logic_error("Matrix is uninitialized");

    if (i < 0 || i >= n)
        throw std::out_of_range("Row index out of bounds");
    return matrix[i];
}

/**
 * @brief Checks equality between two matrices based on the sum of their elements.
 * @param other Matrix to compare with.
 * @return true if sums are equal, false otherwise.
 * @throws std::invalid_argument if matrices are different sizes.
 * @throws std::logic_error if either matrix is uninitialized.
 */
bool SquareMat::operator==(const SquareMat &other) const
{
    if (n != other.n)
    throw std::invalid_argument("Cannot compare matrices of different sizes");
if (matrix == nullptr || other.matrix == nullptr){
    throw std::logic_error("Cannot compare uninitialized matrices");}

    double sum1=0;
    double sum2=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum1+=matrix[i][j];
            sum2+=other.matrix[i][j];
        }
    }
    if (sum1==sum2)
    {
       return true;
    }
    return false;
}

/**
 * @brief Checks inequality between two matrices.
 * @param other Matrix to compare with.
 * @return true if matrices are not equal.
 */
bool SquareMat::operator!=(const SquareMat &other) const
{
    if (*this==other)
    {
       return false;
    }
    
    return true;
}

/**
 * @brief Checks if this matrix is less than another by comparing sums of elements.
 * @param other Matrix to compare with.
 * @return true if this matrix's sum is less than the other's.
 * @throws std::invalid_argument if matrices are different sizes.
 */
bool SquareMat::operator<(const SquareMat &other) const
{
    if (other.n != n) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    
    double sum1=0;
    double sum2=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum1+=matrix[i][j];
            sum2+=other.matrix[i][j];
        }
    }
    if (sum1<sum2)
    {
       return true;
    }
    return false;
}

/**
 * @brief Checks if this matrix is greater than another by comparing sums of elements.
 * @param other Matrix to compare with.
 * @return true if this matrix's sum is greater than the other's.
 * @throws std::invalid_argument if matrices are different sizes.
 */
bool SquareMat::operator>(const SquareMat &other) const
{
    if (other.n != n) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    
    if (*this<other||*this==other)
    {
        return false;
    }
    
    return true;
}

/**
 * @brief Checks if this matrix is less than or equal to another matrix.
 * @param other Matrix to compare with.
 * @return true if this matrix is less than or equal to the other.
 * @throws std::invalid_argument if matrices are different sizes.
 * @throws std::logic_error if one of the matrices is uninitialized.
 */
bool SquareMat::operator<=(const SquareMat &other) const
{
    if (n != other.n)
    throw std::invalid_argument("Cannot compare matrices of different sizes");

    if (matrix == nullptr || other.matrix == nullptr)
    throw std::logic_error("Cannot compare uninitialized matrices");

    if (*this<other||*this==other)
    {
        return true;
    }
    return false;
}

/**
 * @brief Checks if this matrix is greater than or equal to another matrix.
 * @param other Matrix to compare with.
 * @return true if this matrix is greater than or equal to the other.
 * @throws std::invalid_argument if matrices are different sizes.
 * @throws std::logic_error if one of the matrices is uninitialized.
 */
bool SquareMat::operator>=(const SquareMat &other) const
{
    if (n != other.n)
        throw std::invalid_argument("Cannot compare matrices of different sizes");

    if (matrix == nullptr || other.matrix == nullptr)
        throw std::logic_error("Cannot compare uninitialized matrices");

    if (*this>other||*this==other)
    {
        return true;
    }
    
    return false;
}

/**
 * @brief Computes the determinant of the square matrix.
 * @return Determinant as a double.
 * @throws std::invalid_argument if matrix size is non-positive.
 * @throws std::logic_error if matrix is uninitialized.
 */
double SquareMat::operator!() const {
    if (n < 1)
    throw std::invalid_argument("Matrix size must be positive");

    if (matrix == nullptr)
    throw std::logic_error("Matrix is not initialized");

    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;
    for (int j = 0; j < n; ++j) {
        SquareMat minor(n - 1);

        for (int row = 1; row < n; ++row) {
            int colIndex = 0;
            for (int col = 0; col < n; ++col) {
                if (col == j) continue;
                minor.addValueAt(row - 1, colIndex, matrix[row][col]);
                ++colIndex;
            }
        }

        double cofactor = (j % 2 == 0 ? 1 : -1) * matrix[0][j];
        det += cofactor * !minor; 
    }

    return det;
}

/**
 * @brief Adds another matrix to this matrix in-place.
 * @param other Matrix to add.
 * @return Reference to the updated matrix.
 * @throws std::invalid_argument if matrix sizes differ.
 * @throws std::logic_error if either matrix is uninitialized.
 */
SquareMat &SquareMat::operator+=(const SquareMat &other)
{
    if (n != other.n)
        throw std::invalid_argument("Matrix sizes do not match for += operation");

    if (matrix == nullptr || other.matrix == nullptr)
        throw std::logic_error("One of the matrices is uninitialized");

   for (int i = 0; i < n; i++)
   {
    for (int j = 0;  j < n; j++)
    {
        matrix[i][j]+=other.matrix[i][j];
    }
   }
   return *this;
}

/**
 * @brief Subtracts another matrix from this matrix in-place.
 * @param other Matrix to subtract.
 * @return Reference to the updated matrix.
 * @throws std::invalid_argument if matrix sizes differ.
 * @throws std::logic_error if either matrix is uninitialized.
 */
SquareMat &SquareMat::operator-=(const SquareMat &other)
{
    if (n != other.n)
        throw std::invalid_argument("Matrix sizes do not match for += operation");

    if (matrix == nullptr || other.matrix == nullptr)
        throw std::logic_error("One of the matrices is uninitialized");

    for (int i = 0; i < n; i++)
    {
     for (int j = 0;  j < n; j++)
     {
         matrix[i][j]-=other.matrix[i][j];
     }
    }
    return *this;
}

/**
 * @brief Multiplies this matrix by another matrix in-place.
 * @param other Matrix to multiply by.
 * @return Reference to the updated matrix.
 * @throws std::invalid_argument if matrix sizes differ.
 * @throws std::logic_error if either matrix is uninitialized.
 */
SquareMat &SquareMat::operator*=(const SquareMat &other)
{
    if (n != other.n)
    throw std::invalid_argument("Matrix sizes do not match for *= operation");

    if (matrix == nullptr || other.matrix == nullptr)
    throw std::logic_error("One of the matrices is uninitialized");

    SquareMat m(n);
    m = *this*other;
    *this = m;
    return *this;
}

/**
 * @brief Divides this matrix by another matrix element-wise in-place.
 * @param other Matrix to divide by.
 * @return Reference to the updated matrix.
 * @throws std::invalid_argument if matrix sizes differ.
 * @throws std::logic_error if either matrix is uninitialized.
 * @throws std::runtime_error if division by zero occurs.
 */
SquareMat &SquareMat::operator/=(const SquareMat &other)
{
    if (n != other.n)
    throw std::invalid_argument("Matrix sizes do not match for /= operation");

    if (matrix == nullptr || other.matrix == nullptr)
    throw std::logic_error("One of the matrices is uninitialized");

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (other.matrix[i][j] == 0)
            {
                throw std::runtime_error("Division by zero in matrix.");
            }
            matrix[i][j] /= other.matrix[i][j];
        }
    }
    return *this;
}

/**
 * @brief Applies element-wise modulo operation between this matrix and another matrix in-place.
 * @param other Matrix for modulo operation.
 * @return Reference to the updated matrix.
 * @throws std::invalid_argument if matrix sizes differ.
 * @throws std::logic_error if either matrix is uninitialized.
 */
SquareMat &SquareMat::operator%=(const SquareMat &other)
{
    if (n != other.n)
    throw std::invalid_argument("Matrix sizes do not match for %= operation");

    if (matrix == nullptr || other.matrix == nullptr)
    throw std::logic_error("One of the matrices is uninitialized");

    *this = *this % other;
    return *this;
}

/**
 * @brief Multiplies this matrix by a scalar in-place.
 * @param scalar Scalar value.
 * @return Reference to the updated matrix.
 * @throws std::logic_error if the matrix is uninitialized.
 */
SquareMat &SquareMat::operator*=(double scalar)
{
    if (matrix == nullptr)
    throw std::logic_error("Matrix is uninitialized");

    *this = *this * scalar;
    return *this;
}

/**
 * @brief Applies modulo operation to each element of the matrix with an integer scalar in-place.
 * @param scalar Scalar integer.
 * @return Reference to the updated matrix.
 * @throws std::invalid_argument if scalar is zero.
 */
SquareMat &SquareMat::operator%=(int scalar)
{
    if (scalar == 0)
    throw std::invalid_argument("Modulo by zero is not allowed");

    *this = *this % scalar;
    return *this;
}

/**
 * @brief Stream insertion operator to print the matrix.
 * @param os Output stream.
 * @param mat Matrix to print.
 * @return Reference to the output stream.
 * @throws std::runtime_error if matrix is empty or uninitialized.
 */
std::ostream &operator<<(std::ostream &os, const SquareMat &mat)
{
    if (mat.n == 0 || mat.matrix == nullptr) {
        throw std::runtime_error("Cannot print an empty or uninitialized matrix.");
    }

    for (int i = 0; i < mat.n; ++i) {
        for (int j = 0; j < mat.n; ++j) {
            os << mat.matrix[i][j] << ' ';
        }
        os << '\n'; // שורה חדשה אחרי כל שורה במטריצה
    }
    return os;
}
}