//dael12345@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
using namespace matrix;

TEST_CASE("Constructor and basic access") {
    CHECK_THROWS(SquareMat(-1));
    SquareMat m(3);
    m.addValueAt(0,0,1);
    m.addValueAt(1,1,2);
    m.addValueAt(2,2,3);
    CHECK(m[0][0] == 1);
    CHECK(m[1][1] == 2);
    CHECK(m[2][2] == 3);
    CHECK_THROWS(m.addValueAt(3,0,1));
}

TEST_CASE("Addition and subtraction") {
    SquareMat a(2), b(2);
    a.addValueAt(0,0,1);
    a.addValueAt(1,1,1);
    b.addValueAt(0,0,2);
    b.addValueAt(1,1,3);
    auto sum = a + b;
    auto diff = b - a;
    CHECK(sum[0][0] == 3);
    CHECK(diff[1][1] == 2);
    CHECK_THROWS(a + SquareMat(3));
}

TEST_CASE("Unary minus") {
    SquareMat a(2);
    a.addValueAt(0,0,5);
    auto neg = -a;
    CHECK(neg[0][0] == -5);
}

TEST_CASE("Multiplication") {
    SquareMat a(2), b(2);
    a.addValueAt(0,0,1);
    a.addValueAt(0,1,2);
    a.addValueAt(1,0,3);
    a.addValueAt(1,1,4);
    b.addValueAt(0,0,2);
    b.addValueAt(0,1,0);
    b.addValueAt(1,0,1);
    b.addValueAt(1,1,2);
    auto result = a * b;
    CHECK(result[0][0] == 4);
    CHECK(result[1][1] == 8);
}

TEST_CASE("Scalar operations") {
    SquareMat a(2);
    a.addValueAt(0,0,6);
    auto scaled = a * 2;
    CHECK(scaled[0][0] == 12);
    CHECK_THROWS(a % 0);
    auto mod = a % 4;
    CHECK(mod[0][0] == 2);
}

TEST_CASE("Power and transpose") {
    SquareMat a(2);
    a.addValueAt(0,0,2);
    a.addValueAt(1,1,2);
    auto pow = a ^ 2;
    CHECK(pow[0][0] == 4);
    auto trans = ~a;
    CHECK(trans[1][1] == 2);
}

TEST_CASE("Determinant") {
    SquareMat a(2);
    a.addValueAt(0,0,3);
    a.addValueAt(0,1,8);
    a.addValueAt(1,0,4);
    a.addValueAt(1,1,6);
    double det = !a;
    CHECK(det == doctest::Approx(-14));
}

TEST_CASE("Comparisons") {
    SquareMat a(2), b(2);
    a.addValueAt(0,0,1);
    a.addValueAt(1,1,1);
    b.addValueAt(0,0,2);
    b.addValueAt(1,1,2);
    CHECK(a != b);
    CHECK(a < b);
    CHECK(b > a);
    CHECK(a <= b);
    CHECK(b >= a);
}

TEST_CASE("Compound assignments") {
    SquareMat a(2), b(2);
    a.addValueAt(0,0,2);
    b.addValueAt(0,0,1);
    a += b;
    CHECK(a[0][0] == 3);
    a -= b;
    CHECK(a[0][0] == 2);
    a *= 2;
    CHECK(a[0][0] == 4);
    a %= 3;
    CHECK(a[0][0] == 1);
}

TEST_CASE("Increment and decrement") {
    SquareMat a(2);
    a.addValueAt(0,0,1);
    ++a;
    CHECK(a[0][0] == 2);
    a--;
    CHECK(a[0][0] == 1);
}
