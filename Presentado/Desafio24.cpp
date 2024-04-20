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
class Desafio24
{
private:
    Utils myUtils;
    std::string mark;
    void header(std::string message)
    {
        myUtils.println(mark);
        myUtils.println("Ejecutando Desafio 24." + message + ".");
    }
    void footer(std::string message)
    {
        myUtils.println("Desafio 24." + message + " ejecutado.");
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
        int n;
        std::cout << "Ingrese un número para invertir: ";
        std::cin >> n;
        int resultado = invertirNumero(n);
        std::cout << "Número invertido: " << resultado << std::endl;
    }

    int invertirNumero(int n)
    {
        int numeroInvertido = 0;
        bool esNegativo = n < 0; // Verificar si el número es negativo

        if (esNegativo)
        {
            n = -n; // Hacer el número positivo para facilitar la inversión
        }

        while (n > 0)
        {
            int digito = n % 10;                             // Obtener el último dígito
            numeroInvertido = numeroInvertido * 10 + digito; // Agregarlo al nuevo número invertido
            n /= 10;                                         // Remover el último dígito
        }

        if (esNegativo)
        {
            numeroInvertido = -numeroInvertido; // Reconvertir a negativo si es necesario
        }

        return numeroInvertido;
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
        int numero;
        std::cout << "Ingrese un número para representar en el ábaco: ";
        std::cin >> numero;

        // Obtener la representación en ábaco
        std::vector<std::string> abaco = representarEnAbaco(numero);

        std::cout << "Representación en ábaco del número " << numero << ":\n";
        for (const auto &fila : abaco)
        {
            std::cout << fila << std::endl;
        }
    }

    // Función para convertir un número a su representación en un ábaco
    std::vector<std::string> representarEnAbaco(int n)
    {
        std::vector<std::string> representacion;
        while (n > 0)
        {
            int digito = n % 10;
            std::string fila(digito, 'O'); // Crear una hilera de 'O's con longitud igual al dígito
            representacion.push_back(fila);
            n /= 10;
        }
        std::reverse(representacion.begin(), representacion.end()); // Invertir para que el orden de las filas sea el correcto
        return representacion;
    }

    void Desafio3Callback()
    {
        std::string palabra;
        std::cout << "Ingrese una palabra para verificar si es un palíndromo: ";
        std::cin >> palabra;

        if (esPalindromo(palabra))
        {
            std::cout << palabra << " es un palíndromo." << std::endl;
        }
        else
        {
            std::cout << palabra << " no es un palíndromo." << std::endl;
        }
    }

    // Función para determinar si una cadena es un palíndromo
    bool esPalindromo(const std::string &palabra)
    {
        int izquierda = 0;                  // Índice para el inicio de la palabra
        int derecha = palabra.length() - 1; // Índice para el final de la palabra

        while (izquierda < derecha)
        {
            // Convertir ambos caracteres a minúsculas para comparación insensible a mayúsculas
            char cIzquierda = tolower(palabra[izquierda]);
            char cDerecha = tolower(palabra[derecha]);

            if (cIzquierda != cDerecha)
            {
                return false; // No es un palíndromo si los caracteres no coinciden
            }

            izquierda++; // Mover hacia el centro desde la izquierda
            derecha--;   // Mover hacia el centro desde la derecha
        }

        return true; // Todos los caracteres coincidieron, es un palíndromo
    }

public:
    Desafio24()
    {
        mark = "****************";
    }
    // Métodos DesafioX

    void SubDesafio0()
    {
        methodUITemplate("0", std::bind(&Desafio24::Desafio0Callback, this));
    }
    void SubDesafio1()
    {
        methodUITemplate("1", std::bind(&Desafio24::Desafio1Callback, this));
    }
    void SubDesafio2()
    {
        methodUITemplate(" 24.4", std::bind(&Desafio24::Desafio2Callback, this));
    }
    void SubDesafio3()
    {
        methodUITemplate("  26.3", std::bind(&Desafio24::Desafio3Callback, this));
    }

    void Ejecutar()
    {
#ifdef _WIN32
        SetConsoleOutputCP(65001); // Ensure Windows console is in UTF-8 mode
#endif

        std::vector<std::function<void()>> metodos = {
            std::bind(&Desafio24::SubDesafio0, this),
            std::bind(&Desafio24::SubDesafio1, this),
            std::bind(&Desafio24::SubDesafio2, this)};
        for (auto &metodo : metodos)
        {
            metodo();
        }
    }
};
int main()
{
    Desafio24 d3;
    d3.Ejecutar();
    return 0;
}