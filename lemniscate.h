#include <iostream>
#include <cmath>
#include <cstring>
#define PI 3.14159265

namespace LB{
    class Lemniscate_Bernoulli{
    private:
        double c = 1.0;
    public:
        explicit Lemniscate_Bernoulli(double c);

        void set_data(double data_c);

        [[nodiscard]]
        double get_data() const;

        double get_polar_radius_by_angle(double& fi) const;

        double get_radius_of_curvature_by_polar_radius(double & r) const;

        double get_radius_of_curvature_by_angle(double & fi) const;

        double get_radius_of_curvature_by_angle(double & fi, double & d_fi) const;

        double get_sector_area_by_angle(double & alpha) const;

        [[nodiscard]]
        double get_area_of_lemniscate() const;
    };
}