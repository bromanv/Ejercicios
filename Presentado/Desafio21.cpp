// utf-8
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

#include <utility> // Para std::pair

#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

class Utils
{
public:
    void println(std::string message)
    {
        std::cout << message << std::endl;
    }
};
class Desafio21
{
private:
    Utils myUtils;
    std::string mark;
    void header(std::string message)
    {
        myUtils.println(mark);
        myUtils.println("Ejecutando Desafio 21." + message + ".");
    }
    void footer(std::string message)
    {
        myUtils.println("Desafio 21." + message + " ejecutado.");
        myUtils.println(mark);
    }
    void methodUITemplate(std::string id, std::function<void()> callback)
    {
        header(id);
        callback();
        footer(id);
    }

    void Desafio0Callback()
    {
        int numeroDePlaca;
        std::cout << "Ingrese el número de placa: ";
        std::cin >> numeroDePlaca;

        std::vector<std::string> dias = diasRestriccion(numeroDePlaca);
        std::cout << "Restricción de circulación: " << dias[0] << " y " << dias[1] << std::endl;
    }
    std::vector<std::vector<std::string>> crearTablaDeRestricciones()
    {
        // Definir el vector multidimensional con los días de restricción correspondientes
        std::vector<std::vector<std::string>> diasRestriccion = {
            {"Viernes", "Domingo"},   // caso 0
            {"Lunes", "Sabado"},      // caso 1
            {"Lunes", "Domingo"},     // caso 2
            {"Martes", "Sabado"},     // caso 3
            {"Martes", "Domingo"},    // caso 4
            {"Miercoles", "Sabado"},  // caso 5
            {"Miercoles", "Domingo"}, // caso 6
            {"Jueves", "Sabado"},     // caso 7
            {"Jueves", "Domingo"},    // caso 8
            {"Viernes", "Sabado"}     // caso 9
        };

        return diasRestriccion;
    }
    std::vector<std::string> diasRestriccion(int placa)
    {
        std::vector<std::vector<std::string>> tabla = crearTablaDeRestricciones();
        int ultimoDigito = placa % 10; // Obtener el último dígito de la placa

        // Acceder al vector correspondiente basado en el último dígito
        return tabla[ultimoDigito];
    }

    void Desafio1Callback()
    {
        int n;
        std::cout << "Ingrese el tamaño de los catetos del triángulo rectángulo: ";
        std::cin >> n;

        // Verifica que el número ingresado sea positivo y mayor que cero
        if (n > 0)
        {
            std::string triangulo = generarPerimetroTriangulo(n);
            std::cout << "Perímetro del triángulo rectángulo de catetos " << n << ":\n"
                      << triangulo;
        }
        else
        {
            std::cout << "Por favor, ingrese un número entero positivo mayor que cero.\n";
        }
    }
    std::string generarPerimetroTriangulo(int n)
    {
        std::ostringstream stream;

        // Generar el primer cateto vertical
        for (int i = 0; i < n; i++)
        {
            stream << "*\n"; // Agrega un asterisco y un salto de línea
        }

        // Generar la base del triángulo
        for (int i = 0; i < n; i++)
        {
            stream << "*";
        }

        // Agrega una nueva línea al final
        stream << "\n";

        // Regresa el string que representa el perímetro del triángulo
        return stream.str();
    }

    void Desafio2Callback()
    {
        int n;
        std::cout << "Ingrese el tamaño de la base del triángulo isósceles (número impar): ";
        std::cin >> n;

        // Verifica que el número ingresado sea mayor que cero
        if (n > 0)
        {
            std::string triangulo = generarTrianguloIsosceles(n);
            std::cout << "Triángulo isósceles de base " << n << ":\n"
                      << triangulo;
        }
        else
        {
            std::cout << "Por favor, ingrese un número entero positivo.\n";
        }
    }
    std::string generarTrianguloIsosceles(int n)
    {
        if (n % 2 == 0)
        {
            n++; // Asegurar que la base siempre sea impar para mantener la simetría
        }
        std::ostringstream stream;
        int altura = (n / 2) + 1; // Altura del triángulo

        for (int i = 0; i < altura; i++)
        {
            // Imprimir espacios en blanco
            for (int j = 0; j < altura - i - 1; j++)
            {
                stream << " ";
            }
            // Imprimir asteriscos
            for (int k = 0; k < 2 * i + 1; k++)
            {
                stream << "*";
            }
            stream << "\n";
        }

        return stream.str();
    }

public:
    Desafio21()
    {
        mark = "****************";
    }
    // Métodos DesafioX

    void SubDesafio0()
    {
        methodUITemplate("0", std::bind(&Desafio21::Desafio0Callback, this));
    }
    void SubDesafio1()
    {
        methodUITemplate("1", std::bind(&Desafio21::Desafio1Callback, this));
    }
    void SubDesafio2()
    {
        methodUITemplate("2", std::bind(&Desafio21::Desafio2Callback, this));
    }

    void Ejecutar()
    {
#ifdef _WIN32
        SetConsoleOutputCP(65001); // Ensure Windows console is in UTF-8 mode
#endif

        std::vector<std::function<void()>> metodos = {
            std::bind(&Desafio21::SubDesafio0, this),
            std::bind(&Desafio21::SubDesafio1, this),
            std::bind(&Desafio21::SubDesafio2, this)};
        for (auto &metodo : metodos)
        {
            metodo();
        }
    }
};
int main()
{
    Desafio21 d3;
    d3.Ejecutar();
    return 0;
}