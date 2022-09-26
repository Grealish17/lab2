#include "lemniscate.h"


using namespace LB;

int dialog(const char *msgs[], int);
int D_Set_Data(Lemniscate_Bernoulli &);
int D_Get_Data(Lemniscate_Bernoulli &);
int D_Get_Polar_Radius_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Radius_Of_Curvature_By_Polar_Radius(Lemniscate_Bernoulli &);
int D_Get_Radius_Of_Curvature_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Sector_Area_By_Angle(Lemniscate_Bernoulli &);
int D_Get_Area_Of_Lemniscate(Lemniscate_Bernoulli &);
int D_Analytically_Get_Radius_Of_Curvature_By_Angle(Lemniscate_Bernoulli &);

int (*fptr[])(Lemniscate_Bernoulli &)= {nullptr, D_Set_Data, D_Get_Data, D_Get_Polar_Radius_By_Angle, D_Get_Radius_Of_Curvature_By_Polar_Radius, D_Get_Radius_Of_Curvature_By_Angle, D_Get_Sector_Area_By_Angle, D_Get_Area_Of_Lemniscate, D_Analytically_Get_Radius_Of_Curvature_By_Angle};
const char *msgs[]={"0. Quit", "1. Set Data", "2. Get Data","3. Get Polar Radius By Angle", "4. Get Radius Of Curvature By Polar Radius", "5. Get Radius Of Curvature By Angle", "6. Get Sector Area By Angle", "7. Get Area Of Lemniscate", "8. Analytically Get Radius Of Curvature By Angle"};
const int NMsgs = sizeof(msgs)/sizeof(msgs[0]);

int main() {
    auto lemniscate = Lemniscate_Bernoulli(1);
    int rc;
    rc = dialog(msgs, NMsgs);
    while(rc)
    {
        if(!fptr[rc](lemniscate))
            break;
        rc = dialog(msgs, NMsgs);
    }
    std::cout << "That's all. Bye!\n";
    return 0;
}
