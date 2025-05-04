#include <iostream>
#include <stdexcept>
namespace matrix{
    class SquareMat
    {
    private:
        int n;
        double** matrix;
        double mod(double x, double y) const;
    public:
        SquareMat(int n);
        SquareMat(const SquareMat& other);
        ~SquareMat();
        SquareMat& operator=(const SquareMat& other);
        void addValueAt(int row, int col, double value);
        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat& other) const;
        SquareMat operator*(double scalar) const;
        friend SquareMat operator*(double scalar, const SquareMat& mat);
        SquareMat operator%(const SquareMat& other) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator/(int scalar) const;
        SquareMat operator^(int p) const;
        SquareMat& operator++();     // prefix ++
        SquareMat operator++(int);   // postfix ++
        SquareMat& operator--();     // prefix --
        SquareMat operator--(int);
        SquareMat operator~() const;
        double* operator[](int i);
        bool operator ==(const SquareMat& other)const;
        bool operator!=(const SquareMat& other) const;
        bool operator <(const SquareMat& other)const;
        bool operator >(const SquareMat& other)const;
        bool operator <=(const SquareMat& other)const;
        bool operator >=(const SquareMat& other)const;
        double operator !()const;
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator/=(const SquareMat& other); 
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat& operator%=(int scalar);
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
    };
}