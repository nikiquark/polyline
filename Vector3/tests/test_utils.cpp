#include <gtest/gtest.h>
#include <Vector3.h>
#include <cmath>

using Math::Vector3lf;

const double eps = 1e-5;

TEST(MathUtils, DistanceFromPointToLine) {
    using Math::utils::distance_to_line;
    EXPECT_NEAR(distance_to_line({0, 0, 0}, {0, 1, 0}, {1, 0, 0}), 
                1,
                eps);

    EXPECT_NEAR(distance_to_line({0, 0, 0}, {0, 1, 0}, {1, 1, 0}), 
                std::sqrt(2)/2, 
                eps);
}

TEST(MathUtils, ProjectionPointToLine){
    using Math::utils::project_point_to_line;
    auto res1 = project_point_to_line({0, 0, 0}, {0, 1, 0}, {1, 0, 0});
    EXPECT_NEAR(res1.x, 0, eps);
    EXPECT_NEAR(res1.y, 1, eps);
    EXPECT_NEAR(res1.z, 0, eps);

    auto res2 = project_point_to_line({0, 0, 0}, {0, 1, 0}, {1, 1, 0});
    EXPECT_NEAR(res2.x, -0.5, eps);
    EXPECT_NEAR(res2.y, 0.5, eps);
    EXPECT_NEAR(res2.z, 0, eps);

}