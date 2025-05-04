#include"SquareMat.hpp"
#include <iostream>
using namespace matrix;
using namespace std;
int main(){

    SquareMat a(2);
    SquareMat b(2);
    SquareMat c(2);

    a.addValueAt(0,0,1);
    a.addValueAt(0,1,1);
    a.addValueAt(1,0,1);
    a.addValueAt(1,1,1);

    b.addValueAt(0,0,2);
    b.addValueAt(0,1,2);
    b.addValueAt(1,0,2);
    b.addValueAt(1,1,2);

    printf("matrix a:\n");
    cout<<a<<endl;

    printf("matrix b:\n");
    cout<<b<<endl;

    c = a + b;
    printf("c = a+b:\n");
    cout<<c<<endl;

    c = a-b;
    printf("c = a-b:\n");
    cout<<c<<endl;

    c = a*b;
    printf("c = a*b:\n");
    cout<<c<<endl;

    c = a%b;
    printf("c = a%%b:\n");
    cout<<c<<endl;

    c = a*3;
    printf("c = a*3:\n");
    cout<<c<<endl;

    c = a/3;
    printf("c = a/3:\n");
    cout<<c<<endl;

    c = a%3;
    printf("c = a%%3:\n");
    cout<<c<<endl;

    c = -c;
    printf("c = -c:\n");
    cout<<c<<endl;

    c = b^2;
    printf("c = b^3:\n");
    cout<<c<<endl;

    c++;
    printf("b++:\n");
    cout<<c<<endl;

    ++c;
    printf("++b:\n");
    cout<<c<<endl;

    c--;
    printf("c--:\n");
    cout<<c<<endl;

    --c;
    printf("--c:\n");
    cout<<c<<endl;

    ~c;
    printf("~c:\n");
    cout<<c<<endl;

    c[1][1]=9;
    printf("c[1][1]=9:\n");
    cout<<c<<endl;

    if (a==b)
    {
        printf("a==b");
    }
    if (a!=b)
    {
        printf("a is not equale to b");
    }

    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a > b: "  << (a > b)  << endl;
    cout << "a < b: "  << (a < b)  << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a <= b: " << (a <= b) << endl;

    // דטרמיננטה
    cout << "Determinant of a (!a): " << !a << endl;

    c = a; c += b;
    cout << "a += b:\n" << c;

    c = a; c -= b;
    cout << "a -= b:\n" << c;

    c = a; c *= b;
    cout << "a *= b:\n" << c;

    c = a; c /= b;
    cout << "a /= b:\n" << c;

    c = a; c %= b;
    cout << "a %= b:\n" << c;

    c = a; c *= 2;
    cout << "a *= 2:\n" << c;

    c = a; c %= 3;
    cout << "a %= 3:\n" << c;

    return 0;
}