#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

class Frase
{
private:
    static const int TAMANO_INICIAL = 100; // Tamaño inicial del arreglo

    char vector[TAMANO_INICIAL]{};
    int cantidad;
    int tamano;

    void setCantidad(int value)
    {
        cantidad = value;
    }
    int buscar(char value, bool invertido, int desde)
    {
        if (getCantidad() > 0)
        {
            int inicio = desde;
            int ultimo = getCantidad();
            if (invertido)
            {
                inicio = ultimo - 1;
                ultimo = desde;
            }

            for (int idx = inicio; (invertido ? idx >= ultimo : idx < ultimo); idx += invertido ? -1 : 1)
                if (value == vector[idx])
                    return idx;
        }
        return -1;
    }

public:
    Frase() : cantidad(0)
    {
    }
    Frase(int tamano, int cantidad) : cantidad(cantidad)
    {
        setTamano(tamano);
    }
    ~Frase()
    {
    }

    void setTamano(int value)
    {
        tamano = value;
    }

    int getTamano()
    {
        return tamano;
    }
    int getCantidad()
    {
        return cantidad> TAMANO_INICIAL ? TAMANO_INICIAL: cantidad;
    }

    void almacenaFrase(string valores)
    {
        setCantidad(valores.length());
        for (int idx = 0; idx < getCantidad() ; idx++)
            vector[idx] = valores[idx];
    }
    int aparicionesDe(char letra)
    {
        int resultado = 0;
        int encontrado = buscar(letra, false, 0);
        while (encontrado != -1)
        {
            resultado++;
            encontrado = buscar(letra, false, encontrado + 1);
        }
        return resultado;
    }
    int cantidadPalabras()
    {
        int resultado = 0;
        if (getCantidad() > 0)
        {
            resultado = aparicionesDe(' ') + 1;
        }
        return resultado;
    }
    int cantidadPalabrasReal()
    {
        int resultado = 0;
        if (getCantidad() > 0)
        {
            resultado = 1;
            int idx = buscar(' ', false, 0);
            while (idx != -1)
            {
                if (vector[idx + 1] != ' ')
                    resultado++;
                idx = buscar(' ', false, idx + 1);
            }
        }
        return resultado;
    }

    Frase codificar()
    {
        Frase resultado;
        resultado.setCantidad(cantidad);
        for (int idx = 0; idx < getCantidad(); idx++)
        {
            switch (vector[idx])
            {
            case 'a':
            case 'A':
                resultado.vector[idx] = '1';
                break;
            case 'e':
            case 'E':
                resultado.vector[idx] = '2';
                break;
            case 'i':
            case 'I':
                resultado.vector[idx] = '3';
                break;
            case 'o':
            case 'O':
                resultado.vector[idx] = '4';
                break;
            case 'u':
            case 'U':
                resultado.vector[idx] = '5';
                break;
            default:
                resultado.vector[idx] = vector[idx];
                break;
            }
        }
        return resultado;
    }

    Frase codificarAlfabeto()
    {
        Frase resultado;
        std::ostringstream stream;
        for (int idx = 0; idx < getCantidad(); idx++)
        {
            char caracter = vector[idx];
            int codigo = -1;
            if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z'))
            {
                if (caracter >= 'a' && caracter <= 'z')
                    codigo = caracter -= 'a';
                else
                    codigo = caracter -= 'A';
                stream << codigo;
            }
            else
                stream << caracter;
        }
        resultado.almacenaFrase(stream.str());
        return resultado;
    }
    bool contiene(Frase &otra)
    {
        bool resultado = false;
        for (int idx = 0; idx < getCantidad(); idx++)
        {
            if (vector[idx] == otra.vector[0])
            {
                for (int idx1 = 1; idx1 < otra.getCantidad(); idx1++)
                {
                    if (vector[idx + idx1] != otra.vector[idx1])
                    {
                        resultado = false;
                        break;
                    }
                    resultado = true;
                }
                if (resultado)
                    break;
            }
        }
        return resultado;
    }
    // Método para probar todos los métodos de la clase Frase
    static void testFrase()
    {
        // Crear una instancia de Frase para realizar pruebas
        Frase frase;
        frase.almacenaFrase("Hola Mundo");

        // Prueba del método almacenaFrase
        assert(frase.getCantidad() == 10);

        // Prueba del método aparicionesDe
        assert(frase.aparicionesDe('o') == 2);

        // Prueba del método cantidadPalabras
        assert(frase.cantidadPalabras() == 2);

        // Prueba del método cantidadPalabrasReal
        assert(frase.cantidadPalabrasReal() == 2);

        // Prueba del método codificar
        Frase otra =frase.codificar();
        assert(otra.toString() == "H4l1 M5nd4");

        // Prueba del método codificarAlfabeto
        Frase fraseCodificada = frase.codificarAlfabeto();
        assert(fraseCodificada.toString() == "714110 122013314");

        // Prueba del método contiene
        Frase otraFrase;
        otraFrase.almacenaFrase("la");
        assert(frase.contiene(otraFrase) == true);

        std::cout << "Todas las pruebas pasaron correctamente." << std::endl;
    }
    string toString(){
        std::ostringstream stream;
        for (int idx = 0; idx < getCantidad(); idx++)
                stream << vector[idx];
        return stream.str();
    }
};

int main()
{
    // Ejecutar las pruebas de la clase Frase
    Frase::testFrase();

    return 0;
}