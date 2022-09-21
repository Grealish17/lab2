#include <iostream>
#include <cmath>
#include <cstring>

class Lemniscate_Bernoulli{
private:
    double c = 1.0;
public:
    void set_data(double data_c){
        c = data_c;
    }
    double get_data(){
        return c;
    }
    double get_polar_radius_by_angle(double& fi){
        return sqrt(2*c*c*cos(2*fi));
    }
    double get_radius_of_curvature_by_polar_radius(double & r){
        return 2*c*c/(3*r);
    }
    double get_radius_of_curvature_by_angle(double & fi){
        return 2*c*c/(3* get_polar_radius_by_angle(fi));
    }
    double get_sector_area_by_angle(double & alpha){
        return c*c*sin(2*alpha)/2;
    }
    double get_area_of_lemniscate(){
        return 2*c*c;
    }
};

int dialog(const char *msgs[], int);
int D_Set_Data(Lemniscate_Bernoulli &);
int D_Get_Data(Lemniscate_Bernoulli &);
int D_Get_Polar_Radius_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Radius_Of_Curvature_By_Polar_Radius(Lemniscate_Bernoulli &);
int D_Get_Radius_Of_Curvature_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Sector_Area_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Area_Of_Lemniscate(Lemniscate_Bernoulli &);