#include "lemniscate.h"

using namespace LB;

int dialog(const char *msgs[], int K){
    std::string errmsg;
    int rc;
    int n;
    do{
        std::cout << errmsg << "\n";
        errmsg = "You are wrong. Repeat, please!";
        std::cout << "==============================================================================\n";
        std::cout << "This is Lemniscate Bernoulli. Its equation is (x^2 + y^2)^2 = 2*c^2(x^2 - y^2)\n";
        std::cout << "==============================================================================\n";
        for(int i=0; i<K; ++i)
        {
            std::cout << msgs[i] << "\n";
        }
        std::cout << "\n";
        std::cout << "Make your choice: ";
        n = scanf("%d", &rc);
        scanf("%*[^\n]");
        scanf("%*c");
        if(n == 0)
        {
            rc = 0;
        }
    } while (rc<0 || rc >= K);
    return rc;
}

int D_Set_Data(Lemniscate_Bernoulli& lemniscate){
    double c;
    std::cout << "Enter parameter 'c' value: ";
    std::cin >> c;
    lemniscate.set_data(c);
    return 1;
}
int D_Get_Data(Lemniscate_Bernoulli& lemniscate){
    std::cout << "Lemniscate parameter value is: " << lemniscate.get_data() << "\n";
    return 1;
}
int D_Get_Polar_Radius_By_Angle(Lemniscate_Bernoulli& lemniscate){
    double fi;
    std::cout << "Enter angle value in radians: ";
    std::cin >> fi;
    try{
        double r = lemniscate.get_polar_radius_by_angle(fi);
        std::cout << "Polar radius value is: " <<  r << "\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Lemniscate is defined for the angle [-pi/4; pi/4] U [3*pi/4; 5*pi/4]! Your angle value is: " << fi << "\n";
    }
    return 1;
}
int D_Get_Radius_Of_Curvature_By_Polar_Radius(Lemniscate_Bernoulli& lemniscate){
    double r;
    std::cout << "Enter polar radius value: ";
    std::cin >> r;
    try{
        double R = lemniscate.get_radius_of_curvature_by_polar_radius(r);
        std::cout << "Radius of curvature value is: " << R << "\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Polar radius value must be a positive real number and less than c*sqrt(2)! Your radius value is: " << r << "\n";
    }
    return 1;
}
int D_Get_Radius_Of_Curvature_By_Angle(Lemniscate_Bernoulli& lemniscate){
    double fi;
    std::cout << "Enter angle value in radians: ";
    std::cin >> fi;
    try{
        double r = lemniscate.get_radius_of_curvature_by_angle(fi);
        std::cout << "Radius of curvature value is: " << r << "\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Lemniscate is defined for the angle [-pi/4; pi/4] U [3*pi/4; 5*pi/4]! Your angle value is: " << fi << "\n";
    }
    return 1;
}
int D_Analytically_Get_Radius_Of_Curvature_By_Angle(Lemniscate_Bernoulli& lemniscate){
    double fi;
    std::cout << "Enter angle value in radians: ";
    std::cin >> fi;
    try{
        double d_fi = 1e-5;
        double r = lemniscate.get_radius_of_curvature_by_angle(fi, d_fi);
        std::cout << "Radius of curvature value is: " << r << "\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Lemniscate is defined for the angle [-pi/4; pi/4] U [3*pi/4; 5*pi/4]! Your angle value is: " << fi << "\n";
    }
    return 1;
}
int D_Get_Sector_Area_By_Angle(Lemniscate_Bernoulli& lemniscate){
    double alpha;
    std::cout << "Enter angle value in radians: ";
    std::cin >> alpha;
    try{
        double area = lemniscate.get_sector_area_by_angle(alpha);
        std::cout << "Sector area is: " << area << "\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Sector area is defined for the angle [0; pi/4]! Your angle value is: " << alpha << "\n";
    }
    return 1;
}
int D_Get_Area_Of_Lemniscate(Lemniscate_Bernoulli& lemniscate){
    std::cout << "Lemniscate area is: " << lemniscate.get_area_of_lemniscate() << "\n";
    return 1;
}