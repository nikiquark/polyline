#include <gtest/gtest.h>
#include <Solver.h>
#include <Polyline.h>

using namespace Math;

TEST(Solver, Example1){
    auto polyline = Polyline{{{0, 0, 0}, {1, 0, 0}, {2, 1, 0}, {3, 1, 1}}};

    auto res = Solver::solve(polyline, {2, 0.5, 0.5});
    ASSERT_EQ(res.size(), 2);

    ASSERT_EQ(res[0].first, 1);
    ASSERT_EQ(res[0].second, (Vector3lf{1.75, 0.75, 0}));
    ASSERT_EQ(res[1].first, 2);
    ASSERT_EQ(res[1].second, (Vector3lf{2.25, 1, 0.25}));


}

TEST(Solver, Example2){
    auto polyline = Polyline{{{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}, {0, 0, 0}}};

    auto res = Solver::solve(polyline, {1, 1, 1});
    ASSERT_EQ(res.size(), 4);

    ASSERT_EQ(res[0].first, 0);
    ASSERT_EQ(res[0].second, (Vector3lf{1, 0, 0}));
    ASSERT_EQ(res[1].first, 1);
    ASSERT_EQ(res[1].second, (Vector3lf{2, 1, 0}));
    ASSERT_EQ(res[2].first, 2);
    ASSERT_EQ(res[2].second, (Vector3lf{1, 2, 0}));
    ASSERT_EQ(res[3].first, 3);
    ASSERT_EQ(res[3].second, (Vector3lf{0, 1, 0}));
}

TEST(Solver, Example3){
    auto polyline = Polyline{{{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}, {0, 0, 0}}};

    auto res = Solver::solve(polyline, {3, 3, 3});
    ASSERT_EQ(res.size(), 2);

    ASSERT_EQ(res[0].first, 1);
    ASSERT_EQ(res[0].second, (Vector3lf{2, 2, 0}));
    ASSERT_EQ(res[1].first, 2);
    ASSERT_EQ(res[1].second, (Vector3lf{2, 2, 0}));
}

TEST(Solver, PointOnBorder){
    auto polyline = Polyline{{{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}, {0, 0, 0}}};

    auto res = Solver::solve(polyline, {1, 0, 0});
    ASSERT_EQ(res.size(), 1);
    
    ASSERT_EQ(res[0].first, 0);
    ASSERT_EQ(res[0].second, (Vector3lf{1, 0, 0}));
}

TEST(Solver, PointOnCorner){
    auto polyline = Polyline{{{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}, {0, 0, 0}}};

    auto res = Solver::solve(polyline, {0, 0, 0});
    ASSERT_EQ(res.size(), 2);
    
    ASSERT_EQ(res[0].first, 0);
    ASSERT_EQ(res[0].second, (Vector3lf{0, 0, 0}));
    ASSERT_EQ(res[1].first, 3);
    ASSERT_EQ(res[1].second, (Vector3lf{0, 0, 0}));
}