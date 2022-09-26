#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lemniscate.h"
using namespace LB;

TEST_CASE( "class Lemniscate_Bernoulli" ) {
    Lemniscate_Bernoulli lb = Lemniscate_Bernoulli(1);
    REQUIRE(fabs(lb.get_data() - 1.0) < 1e-5);
    double fi = 0.0;
    REQUIRE(fabs(lb.get_polar_radius_by_angle(fi) - 1.414213) < 1e-5);
    double r = 1.0;
    REQUIRE(fabs(lb.get_radius_of_curvature_by_polar_radius(r) - 0.666667) < 1e-5);
    fi = 0.0;
    REQUIRE(fabs(lb.get_radius_of_curvature_by_angle(fi) - 0.471406) < 1e-5);
    fi = 0.785398;
    REQUIRE(fabs(lb.get_sector_area_by_angle(fi) - 0.5) < 1e-5);
    REQUIRE(fabs(lb.get_area_of_lemniscate() - 2.0) < 1e-5);
    fi = 0.5;
    double d_fi = 1e-5;
    REQUIRE(fabs(lb.get_radius_of_curvature_by_angle(fi, d_fi) - 1.92398) < 1e-5);
}