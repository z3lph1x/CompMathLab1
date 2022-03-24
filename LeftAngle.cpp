#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using std::cout;
double pi = 3.141592653589793238;

double IE(double x, double L) {
    return sin(4 * pi * x / L);
}

double LeftAngle(double Umn, double Um_1n, double tau, double h) {
    return Umn + (Um_1n - Umn) * tau / h;
}

int main() {
    double L = 20;
    double T = 18;
    double h = 0.5;
    double Co = 1.01;
    double tau = Co * h;
    int Nx = L / h + 1;
    int Nt = T / tau + 1;
    vector<vector<double>> u;
    u.assign(Nt,vector<double>(Nx));
    for (int i = 0; i < Nx; i++) {
        u[0][i] = IE(h * i, L);
    }
    for (int i = 1; i < Nt; i++) {
        for (int j = 1; j < Nx; j++) {
            u[i][j] = LeftAngle(u[i-1][j], u[i-1][j-1], tau, h);
        }
        u[i][0] = u[i][Nx-1];
    }

    ofstream out("LA06.txt");
    for (int x = 0; x < Nt; x++) {
        for (int y = 0; y < Nx; y++) {

            out << u[x][y] << ' ';
        }
        out << "\n";
    }
}

