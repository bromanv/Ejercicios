#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    // Variables para almacenar el peso y la estatura del usuario
    float peso = 0;
    float estatura = 0;
    float imc = 0;

    // Solicita al usuario que introduzca su peso en kilogramos
    cout << "Introduzca su peso en kilogramos: ";
    cin >> peso;

    // Solicita al usuario que introduzca su estatura en metros
    cout << "Introduzca su estatura en metros: ";
    cin >> estatura;

    // Calcula el Índice de Masa Corporal (IMC)
    imc = peso / (estatura * estatura);

    // Muestra el IMC con 2 decimales
    cout << fixed << setprecision(2);
    cout << "Su Índice de Masa Corporal (IMC) es: " << imc << endl;

    return 0;
}
