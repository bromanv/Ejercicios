#include <iostream>
#include <iomanip>
#include <sstream>

class AhorroPlazo
{

private:
    double capitalInicial;
    int plazo;
    int tipoInteres; // 1: simple, 2: compuesto

public:
    // Constructores
    AhorroPlazo() : capitalInicial(0), plazo(0), tipoInteres(1) {}
    AhorroPlazo(double ci, int p, int ti) : capitalInicial(ci), plazo(p), tipoInteres(ti) {}

    // Setters
    void setCapitalInicial(double value)
    {
        capitalInicial = value;
    }
    void setPlazo(int value)
    {
        plazo = value;
    }
    void setTipoInteres(int value)
    {
        tipoInteres = value;
    }
    // Getters
    double getCapitalInicial() const
    {
        return capitalInicial;
    }
    int getPlazo() const
    {
        return plazo;
    }
    int getTipoInteres() const
    {
        return tipoInteres;
    }

    // Calcula la tasa de interés según el plazo
    double calcularTasaInteres() const
    {
        double resultado = 0;
        switch (plazo)
        {
        case 1:
            resultado = 0.08;
            break;
        case 2:
            resultado = 0.09;
            break;
        case 3:
            resultado = 0.10;
            break;
        case 4:
            resultado = 0.12;
            break;
        case 5:
            resultado = 0.14;
            break;
        default:
            if (plazo >= 6)
                resultado = 0.15;
            break;
        }
        return resultado;
    }

    // Calcula el monto de interés generado al final del plazo
    double calcularMontoInteres() const
    {
        double tasa = calcularTasaInteres();
        if (tipoInteres == 1)
        { // Interés simple
            return capitalInicial * tasa * plazo;
        }
        else
        { // Interés compuesto
            double monto = capitalInicial;
            for (int i = 0; i < plazo; ++i)
            {
                monto *= (1 + tasa);
            }
            return monto - capitalInicial;
        }
    }

    // Calcula el monto total a retirar
    double calcularMontoFinal() const
    {
        return capitalInicial + calcularMontoInteres();
    }

    // Representación en cadena de la clase
    std::string toString() const
    {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2);
        stream << "Capital Inicial: $" << capitalInicial
               << ", Plazo: " << plazo << " años, Tipo de Interés: "
               << (tipoInteres == 1 ? "Simple" : "Compuesto")
               << ", Monto Final: $" << calcularMontoFinal();
        return stream.str();
    }
};

int main() {
    // Creación de objeto con parámetros
    AhorroPlazo ahorro1(100000, 5, 2);
    
    // Creación de objeto sin parámetros y configuración posterior
    AhorroPlazo ahorro2;
    double capital;
    int plazo, tipoInteres;

    std::cout << "Ingrese capital inicial, plazo y tipo de interés (1 para simple, 2 para compuesto): ";
    std::cin >> capital >> plazo >> tipoInteres;

    ahorro2.setCapitalInicial(capital);
    ahorro2.setPlazo(plazo);
    ahorro2.setTipoInteres(tipoInteres);

    // Muestra de la información de ambos objetos
    std::cout << "Primer objeto:\n" << ahorro1.toString() << std::endl;
    std::cout << "Segundo objeto:\n" << ahorro2.toString() << std::endl;

    // Comparación de montos de interés
    if (ahorro1.getCapitalInicial() == ahorro2.getCapitalInicial() && ahorro1.getPlazo() == ahorro2.getPlazo()) {
        double interes1 = ahorro1.calcularMontoInteres();
        double interes2 = ahorro2.calcularMontoInteres();
        if (interes1 > interes2) {
            std::cout << "El primer objeto ha generado más interés.\n";
        } else if (interes1 < interes2) {
            std::cout << "El segundo objeto ha generado más interés.\n";
        } else {
            std::cout << "Ambos objetos han generado el mismo monto de interés.\n";
        }
    }

    return 0;
}