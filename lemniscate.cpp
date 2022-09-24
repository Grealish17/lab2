#include "lemniscate.h"

namespace LB{
    Lemniscate_Bernoulli::Lemniscate_Bernoulli(double c){
        this->c = c;
    }
    void Lemniscate_Bernoulli::set_data(double data_c){
            c = data_c;
    }
    double Lemniscate_Bernoulli::get_data() const{
        return c;
    }
    double Lemniscate_Bernoulli::get_polar_radius_by_angle(double& fi) const{
        if(cos(2*fi) > 0.0)
            return sqrt(2*c*c*cos(2*fi));
        else
            throw std::invalid_argument("Incorrect data");
    }
    double Lemniscate_Bernoulli::get_radius_of_curvature_by_polar_radius(double & r) const{
        if(r > 0.0 && r < c*sqrt(2))
            return 2*c*c/(3*r);
        else
            throw std::invalid_argument("Incorrect data");
    }
    double Lemniscate_Bernoulli::get_radius_of_curvature_by_angle(double & fi) const{
        if(cos(2*fi) > 0.0)
            return 2*c*c/(3 * get_polar_radius_by_angle(fi));
        else
            throw std::invalid_argument("Incorrect data");
    }

    double Lemniscate_Bernoulli::get_radius_of_curvature_by_angle(double & fi, double & d_fi) const{
        if(cos(2*fi) > 0.0){
            double r = get_polar_radius_by_angle(fi);
            double FI = fi+d_fi;
            double R = get_polar_radius_by_angle(FI);
            double x = r*cos(fi);
            double y = r*sin(fi);
            double X = R*cos(FI);
            double Y = R*sin(FI);
            return sqrt((X-x)*(X-x) + (Y-y)*(Y-y))/d_fi;
        }
        else
            throw std::invalid_argument("Incorrect data");
    }

    double Lemniscate_Bernoulli::get_sector_area_by_angle(double & alpha) const{
        if(alpha >= 0 && alpha <= PI/4)
            return c*c*sin(2*alpha)/2;
        else
            throw std::invalid_argument("Incorrect data");
    }
    double Lemniscate_Bernoulli::get_area_of_lemniscate() const{
        return 2*c*c;
    }
}