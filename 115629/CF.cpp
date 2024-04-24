#include <iostream>
#include <cmath>

class Fraccion
{
private:
    int numerador;
    int denominador;

public:
    // Constructor por defecto
    Fraccion() : numerador(0), denominador(1) {}

    // Constructor con parámetros
    Fraccion(int num, int den) : numerador(num), denominador(den)
    {
        if (denominador == 0)
        {
            std::cerr << "Error: El denominador no puede ser cero." << std::endl;
            denominador = 1; // Asignamos el denominador a 1 para evitar la división por cero.
        }
    }

    // Destructor
    ~Fraccion()
    {
        // Aquí podrías colocar código de limpieza si fuera necesario
        // std::cout << "Destruyendo fracción " << numerador << "/" << denominador << std::endl;
    }

    // Métodos de acceso
    int getNumerador() const { return numerador; }
    int getDenominador() const { return denominador; }

    // Métodos de modificación
    void setNumerador(int num) { numerador = num; }
    void setDenominador(int den)
    {
        if (den == 0)
        {
            std::cerr << "Error: El denominador no puede ser cero." << std::endl;
            return;
        }
        denominador = den;
    }

    // Método para mostrar la fracción
    void mostrar() const
    {
        std::cout << numerador << "/" << denominador << std::endl;
    }
    bool esPropia()
    {
        return numerador < denominador;
    }
    bool esUnitaria()
    {
        return numerador == denominador;
    }
    float valorDecimal() const
    {
        return static_cast<float>(numerador) / denominador;
    }
    Fraccion mayor(const Fraccion &otra) const
    {
        return *this > otra ? *this : otra;
    }
    Fraccion multiplicacion(const Fraccion &otra) const
    {
        return *this * otra;
    }
    Fraccion division(const Fraccion &otra) const
    {
        return *this / otra;
    }

    Fraccion suma(const Fraccion &otra) const
    {
        return *this + otra;
    }
    Fraccion resta(const Fraccion &otra) const
    {
        return *this - otra;
    }

    // por estilo deberia ser calcularMcd
    int MCD(int r0, int r1) const
    {
        while (r1 != 0)
        {
            int tmp = r1;
            r1 = r0 % r1;
            r0 = tmp;
        }
        return r0;
    }
    int mcm(int n, int m)
    {
        int mcd = MCD(n, m);
        return (n / mcd) * m;
    }
    // Devuelve el inverso aditivo de la fracción, es decir, una fracción que, sumada a la fracción original, resulte en cero.
    // Para cualquier fracción 𝑎/𝑏, su inverso aditivo es −𝑎/𝑏.
    Fraccion inversoAditivo()
    {
        return Fraccion(-numerador, denominador);
    }

    Fraccion inversoMultiplicativo()
    {
        if (numerador == 0)
        {
            std::cerr << "Error: No existe inverso multiplicativo para cero." << std::endl;
            return *this; // Retorna la fracción como está si es cero.
        }
        return Fraccion(denominador, numerador);
    }

    Fraccion canonica() const
    {
        int mcd = MCD(numerador, denominador);
        return Fraccion(numerador / mcd, denominador / mcd);
    }

    // No visto en clase pero de lo mas hermoso que tiene c++ sobrecarga de operadores
    bool operator>(const Fraccion &otra) const
    {
        return valorDecimal() > otra.valorDecimal();
    }
    //todas las operaciones simplifican usando canonica
    Fraccion operator*(const Fraccion &otra) const
    {
        return Fraccion(numerador * otra.numerador, denominador * otra.denominador).canonica();
    }
    Fraccion operator/(const Fraccion &otra) const
    {
        return Fraccion(numerador * otra.denominador, denominador * otra.numerador).canonica();
    }
    Fraccion operator+(const Fraccion &otra) const
    {
        return Fraccion(
                   numerador * otra.denominador + otra.numerador * denominador,
                   denominador * otra.denominador)
            .canonica();
    }
    Fraccion operator-(const Fraccion &otra) const
    {
        return Fraccion(
                   numerador * otra.denominador - otra.numerador * denominador,
                   denominador * otra.denominador)
            .canonica();
    }
};

// Función para ayudar a comparar fracciones y mostrar el resultado de las pruebas
void testFraccion(const Fraccion &result, const Fraccion &expected, const std::string &test_name)
{
    if (result.getNumerador() == expected.getNumerador() && result.getDenominador() == expected.getDenominador())
    {
        std::cout << test_name << ": PASS\n";
    }
    else
    {
        std::cout << test_name << ": FAIL, got " << result.getNumerador() << "/" << result.getDenominador();
        std::cout << ", expected " << expected.getNumerador() << "/" << expected.getDenominador() << "\n";
    }
}

int main()
{
    // Creación de fracciones para pruebas
    Fraccion f1(3, 4), f2(1, 2);

    // Prueba de suma
    testFraccion(f1 + f2, Fraccion(5, 4), "Suma");

    // Prueba de resta
    testFraccion(f1 - f2, Fraccion(1, 4), "Resta");

    // Prueba de multiplicación
    testFraccion(f1 * f2, Fraccion(3, 8), "Multiplicacion");

    // Prueba de división
    testFraccion(f1 / f2, Fraccion(3, 2), "Division");

    // Prueba de inverso aditivo
    testFraccion(f1.inversoAditivo(), Fraccion(-3, 4), "Inverso Aditivo");

    // Prueba de inverso multiplicativo
    testFraccion(f1.inversoMultiplicativo(), Fraccion(4, 3), "Inverso Multiplicativo");

    // Prueba de fracción canónica
    testFraccion(Fraccion(10, 20).canonica(), Fraccion(1, 2), "Canonica");

    // Prueba de comparación mayor que
    std::cout << "Mayor que (f1 > f2): " << (f1 > f2 ? "PASS" : "FAIL") << "\n";

    // Prueba de esPropia
    std::cout << "Es propia f1: " << (f1.esPropia() ? "PASS" : "FAIL") << "\n";

    // Prueba de esUnitaria
    std::cout << "Es unitaria f2: " << (Fraccion(2, 2).esUnitaria() ? "PASS" : "FAIL") << "\n";

    // Prueba de valor decimal
    std::cout << "Valor decimal f1: ";
    float valorDecimal = f1.valorDecimal();
    std::cout << (fabs(valorDecimal - 0.75) < 0.001 ? "PASS" : "FAIL") << "\n";

    return 0;
}