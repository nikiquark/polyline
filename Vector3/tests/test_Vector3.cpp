#include <sstream>
#include <gtest/gtest.h>
#include <Vector3.h>

using Math::Vector3;

TEST(Vector3, DefaultConstructor) {
    Vector3<int> v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
    EXPECT_EQ(v.z, 0);
    EXPECT_EQ(v, Vector3<int>(0, 0, 0));
}

TEST(Vector3, Constructor) {
    Vector3<int> v(1, 2, 3);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 3);
}

TEST(Vector3, OperatorPlus) {
    Vector3<int> v(1, 2, 3);
    Vector3<int> w(4, 5, 6);
    EXPECT_EQ(v + w, Vector3<int>(5, 7, 9));

    for (int i = 0; i < 100; i++) {
        int x = rand() % 100;
        int y = rand() % 100;
        int z = rand() % 100;
        Vector3<int> a(x, y, z);
        Vector3<int> b(x, y, z);
        EXPECT_EQ(a + b, Vector3<int>(2 * x, 2 * y, 2 * z));
    }
}

TEST(Vector3, OperatorMinus) {
    Vector3<int> v(1, 2, 3);
    Vector3<int> w(4, 5, 6);
    EXPECT_EQ(v - w, Vector3<int>(-3, -3, -3));
    EXPECT_EQ(-v, Vector3<int>(-1, -2, -3));
}

TEST(Vector3, Multiplication) {
    Vector3<int> v(1, 2, 3);
    Vector3<int> w(4, 5, 6);
    EXPECT_EQ(v * 2, Vector3<int>(2, 4, 6));
    EXPECT_EQ(2 * v, Vector3<int>(2, 4, 6));
    EXPECT_EQ(v * w, Vector3<int>(-3, 6, -3));
    EXPECT_EQ(v % w, 32);
}

TEST(Vector3, Division) {
    Vector3<double> v(1, 2, 3);
    EXPECT_EQ(v / 2, Vector3<double>(0.5, 1, 1.5));
    EXPECT_THROW(v / 0, std::domain_error);
}

TEST(Vector3, Abs) {
    Vector3<double> v(3, 4, 0);
    EXPECT_EQ(v.abs(), 5);
    EXPECT_EQ((-v).abs(), 5);
}

TEST(Vector3, Streams) {
    Vector3<int> v(1, 2, 3);
    std::stringstream ss;
    ss << v;
    EXPECT_EQ(ss.str(), "1 2 3");
    Vector3<int> w;
    ss >> w;
    EXPECT_EQ(w, v);
}