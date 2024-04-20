#include <iostream>

using namespace std;

int main() {
    // Variable para almacenar la cantidad de segundos ingresada por el usuario
    long long totalSegundos;
    cout << "Introduzca una cantidad de segundos: ";
    cin >> totalSegundos;

    // Calcula días, horas, minutos y segundos
    int segundosEnUnMinuto = 60;
    int segundosEnUnaHora = segundosEnUnMinuto * 60;
    int segundosEnUnDia = segundosEnUnaHora * 24;

    int dias = totalSegundos / segundosEnUnDia;
    int horas = (totalSegundos % segundosEnUnDia) / segundosEnUnaHora;
    int minutos = (totalSegundos % segundosEnUnaHora) / segundosEnUnMinuto;
    int segundos = totalSegundos % segundosEnUnMinuto;

    // Muestra el resultado
    cout << totalSegundos << " segundos equivalen a: " << endl;
    cout << dias << " días, " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." << endl;

    return 0;
}