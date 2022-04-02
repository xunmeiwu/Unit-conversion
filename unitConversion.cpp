#include <iostream>
#include <math.h>

using namespace std;

void parameters(double Ulb) {
    double Lphy = 0.15;      //physical length
    double N = 127.0;        //resolution,lattice number
    double Llb = N;        //Dimensionless length
    int Re = 10000;         //Reynolds stress
    double Vphy = 0.000001;    //physical viscosity coefficient
    double Cl = Lphy / Llb;
    double Uphy = Re * Vphy / Lphy;  //Physical characteristic velocity
    double Cs = 1 / sqrt(3);
//    double Ulb = 0.1;
    double Ma = Ulb / Cs;
//    double Ulb = Ma * Cs;     //Dimensionless velocity is determined according to Mach number
    double Cu = Uphy / Ulb;  //Speed conversion coefficient
    double Ct = Cl / Cu;      //Physical time step (time conversion coefficient);One LB iteration is equivalent to Ct
    double Tlb = Llb / Ulb;   //dimensionless time
    double Tphy = Tlb * Ct;     //Physical time
    double Vlb = Ulb * Llb / Re;  //Dimensionless viscosity
    double Cv = Vphy /Vlb;      //Viscosity conversion coefficient
    double dx = 1/N;         //Dimensionless time step
    double dt = Ulb * dx;    //Dimensionless space step

    cout << "physical velocity " << Uphy << std::endl;
    cout << "physical time " << Tphy << std::endl;
    cout << "physical length " << Lphy << std::endl;
    cout << "physical viscosity " << Vphy << std::endl;
    cout << "lattice time " << Tlb << std::endl;
    cout << "lattice length " << Llb << std::endl;
    cout << "lattice velocity " << Ulb << std::endl;
    cout << "lattice viscosity " << Vlb << std::endl;
    cout << "Ct " << Ct << std::endl;
    cout << "Cl " << Cl << std::endl;
    cout << "Cu " << Cu << std::endl;
    cout << "Cv " << Cv << std::endl;
    cout << "pre time " << 500 * Tphy << std::endl;
    cout << "ave time " << 150 * Tphy << std::endl;
    cout << "total time " << 650 * Tphy << std::endl;
    cout << "dx " << dx << std::endl;
    cout << "dt " << dt << std::endl;
    cout << "Ma " << Ma << std::endl;
}

int main() {
    parameters(0.4);
    return 0;
}
//0.2 跑7h15min
