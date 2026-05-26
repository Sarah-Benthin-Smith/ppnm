#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <functional>
#include <stdexcept>
#include <vector>
#include <string>

#include "matrix.h"
#include "minimizers.h"

double rosenbrock(pp::vector v){

    double x = v[0];
    double y = v[1];

    return pow(1-x,2)
         + 100*pow(y-x*x,2);
}

double himmelblau(pp::vector v){

    double x = v[0];
    double y = v[1];

    return pow(x*x+y-11,2)
         + pow(x+y*y-7,2);
}

// Assignment B

struct HiggsPoint {
    double energy;
    double signal;
    double error;
};

bool is_comment_or_blank(const std::string& line){
    auto pos = line.find_first_not_of(" \t\r\n");
    return pos == std::string::npos || line[pos] == '#';
}

std::vector<HiggsPoint> read_higgs_data(std::istream& in){
    std::vector<HiggsPoint> data;
    std::string line;

    while(std::getline(in, line)){
        if(is_comment_or_blank(line)) continue;

        std::istringstream iss(line);
        HiggsPoint p;
        if(iss >> p.energy >> p.signal >> p.error)
            data.push_back(p);
    }

    return data;
}

double breit_wigner(double E, const pp::vector& x){
    double m = x[0];
    double G = x[1];
    double A = x[2];

    if(G <= 0.0 || A <= 0.0)
        return 1e99;

    double denom = (E - m)*(E - m) + (G*G)/4.0;
    return A / denom;
}

double higgs_deviation(const pp::vector& x, const std::vector<HiggsPoint>& data){
    if(x[1] <= 0.0 || x[2] <= 0.0)
        return 1e99;

    double D = 0.0;

    for(const auto& p : data){
        double F = breit_wigner(p.energy, x);
        double r = (F - p.signal) / p.error;
        D += r*r;
    }

    return D;
}

void write_higgs_data(const std::string& filename, const std::vector<HiggsPoint>& data){
    std::ofstream out(filename);
    for(const auto& p : data)
        out << p.energy << " " << p.signal << " " << p.error << "\n";
}

void write_higgs_fit(const std::string& filename, const pp::vector& x){
    std::ofstream out(filename);

    for(double E = 100.0; E <= 160.0; E += 0.1)
        out << E << " " << breit_wigner(E, x) << "\n";
}

int main(){

    // std::ofstream pout("minimas.txt");

    // // Rosenbrock funktion

    // pp::vector start(2);

    // start[0] = -2;
    // start[1] = 5;

    // pout << "=== Rosenbrock function ===\n";

    // auto resR = newton(rosenbrock, start);

    // pout << "Steps   = " << resR.steps << "\n";

    // pout << "Minimum = (";
    // for(int i = 0; i < resR.xmin.size(); i++){
    //     pout << resR.xmin[i];
    //     if(i < resR.xmin.size() - 1) pout << ", ";
    // }
    // pout << ")\n\n";

    // // Himmelblau funktion

    // pp::vector starth(2);

    // starth[0] = 4;
    // starth[1] = 4;

    // pout << "=== Himmelblau function ===\n";

    // auto resH = newton(himmelblau, starth);

    // pout << "Steps   = " << resH.steps << "\n";

    // pout << "Minimum = (";
    // for(int i = 0; i < resH.xmin.size(); i++){
    //     pout << resH.xmin[i];
    //     if(i < resH.xmin.size() - 1) pout << ", ";
    // }
    // pout << ")\n";


    // Higgs

    std::cout << "\nPART B: Higgs fit\n";

    std::vector<HiggsPoint> data = read_higgs_data(std::cin);

    if(data.empty()){
        std::cerr << "No Higgs data read from stdin.\n";
        return 1;
    }

    write_higgs_data("higgsdata.txt", data);

    auto objective = [&](pp::vector x){
        return higgs_deviation(x, data);
    };

    pp::vector xfit = {126.0, 2.0, 10.0};

    auto [best, fit_steps] = pp::newton_minimize(objective, xfit, 1e-6);
    double Dmin = higgs_deviation(best, data);

    std::cout << "Best fit parameters (forward):\n";
    std::cout << "m     = " << best[0] << "\n";
    std::cout << "Gamma = " << best[1] << "\n";
    std::cout << "A     = " << best[2] << "\n";
    std::cout << "Dmin  = " << Dmin << "\n";
    std::cout << "steps = " << fit_steps << "\n";

    write_higgs_fit("higgs_fit.dat", best);

    // std::cout << "\nPART C: Central differences\n";

    // auto [rosen_min_c, rosen_steps_c] = pp::newton_minimize_central(rosenbrock, x0);
    // std::cout << "Rosenbrock minimum (central): ";
    // rosen_min_c.print();
    // std::cout << "Rosenbrock steps (central): " << rosen_steps_c << "\n";

    // for(auto xstart : starts){
    //     auto [xmin, steps] = pp::newton_minimize_central(himmelblau, xstart);
    //     std::cout << "Himmelblau minimum (central): ";
    //     xmin.print();
    //     std::cout << "Himmelblau steps (central): " << steps << "\n";
    // }


    return 0;

}