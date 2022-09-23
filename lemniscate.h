#include <iostream>
#include <cmath>
#include <cstring>
#define PI 3.14159265

namespace LB{
    class Lemniscate_Bernoulli{
    private:
        double c = 1.0;
    public:
        explicit Lemniscate_Bernoulli(double c){
            this->c = c;
        }
        void set_data(double data_c){
            c = data_c;
        }
        [[nodiscard]]
        double get_data() const{
            return c;
        }
        double get_polar_radius_by_angle(double& fi) const{
            if(cos(2*fi) > 0.0)
                return sqrt(2*c*c*cos(2*fi));
            else
                throw std::invalid_argument("Incorrect data");
        }
        double get_radius_of_curvature_by_polar_radius(double & r) const{
            if(r > 0.0 && r < c*sqrt(2))
                return 2*c*c/(3*r);
            else
                throw std::invalid_argument("Incorrect data");
        }
        double get_radius_of_curvature_by_angle(double & fi) const{
            if(cos(2*fi) > 0.0)
                return 2*c*c/(3 * get_polar_radius_by_angle(fi));
            else
                throw std::invalid_argument("Incorrect data");
        }
        double get_sector_area_by_angle(double & alpha) const{
            if(alpha >= 0 && alpha <= PI/4)
                return c*c*sin(2*alpha)/2;
            else
                throw std::invalid_argument("Incorrect data");
        }
        [[nodiscard]]
        double get_area_of_lemniscate() const{
            return 2*c*c;
        }
    };
}

using namespace LB;

int dialog(const char *msgs[], int);
int D_Set_Data(Lemniscate_Bernoulli &);
int D_Get_Data(Lemniscate_Bernoulli &);
int D_Get_Polar_Radius_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Radius_Of_Curvature_By_Polar_Radius(Lemniscate_Bernoulli &);
int D_Get_Radius_Of_Curvature_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Sector_Area_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Area_Of_Lemniscate(Lemniscate_Bernoulli &);