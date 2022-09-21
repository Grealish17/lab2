#include "lemniscate.h"

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

int D_Set_Data(Lemniscate_Bernoulli &){
    std::cout << "Enter parameter 'c': ";
}
int D_Get_Data(Lemniscate_Bernoulli &){

}
int D_Get_Polar_Radius_By_Angle(Lemniscate_Bernoulli &){

}
int D_Get_Radius_Of_Curvature_By_Polar_Radius(Lemniscate_Bernoulli &){

}
int D_Get_Radius_Of_Curvature_By_Angle(Lemniscate_Bernoulli &){

}
int D_Get_Sector_Area_By_Angle(Lemniscate_Bernoulli &){

}
int D_Get_Area_Of_Lemniscate(Lemniscate_Bernoulli &){

}