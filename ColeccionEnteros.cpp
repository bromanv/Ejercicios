#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;
class ColeccionEnteros
{
private:
    static const int TAMANO_INICIAL = 10; // Tamaño inicial del arreglo

    int vector[TAMANO_INICIAL]{}; // inicializar en 0
    int tamano;
    int cantidad;

    int recorrer(int idx, int incremento)
    {
        int resultado = 0;
        for (; idx < getCantidad(); idx += incremento)
            resultado += vector[idx];
        return resultado;
    }
    int buscar(int value, bool invertido, int desde)
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
    void aumentarCantidad(int aumento)
    {
        setCantidad(getCantidad() + aumento);
    }
    void setCantidad(int value)
    {
        cantidad = value;
    }
    int ValorFibonacci(int elemento)
    {
        if ((elemento == 1) || (elemento == 2))
            return 1;

        int elemento1 = 1;
        int elemento2 = 1;
        int tmp = 0;
        for (int idx = 2; idx <= elemento; idx++)
        {
            tmp = elemento1 + elemento2;
            elemento1 = elemento2;
            elemento2 = tmp;
        }
        return elemento2;
    }

public:
    ColeccionEnteros() : cantidad(0)
    {
    }
    ColeccionEnteros(int tamano, int cantidad) : cantidad(cantidad)
    {
        setTamano(tamano);
    }
    ~ColeccionEnteros()
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
        return cantidad;
    }

    int sumaPosicionesPares()
    {
        return recorrer(0, 2);
    }
    float promedioPosicionesImpares()
    {
        return static_cast<float>(recorrer(1, 2)) / (getCantidad() / 2);
    }
    int buscar(int value)
    {
        return buscar(value, false, 0);
    }
    int buscar(int value, int inicio)
    {
        return buscar(value, false, inicio);
    }
    int aparicionesDe(int value)
    {
        int resultado = 0;
        for (int idx = 0; idx < getCantidad(); idx++)
            if (value == vector[idx])
                resultado++;
        return resultado;
    }
    void intercambiaPosiciones(int pos1, int pos2)
    {
        if ((pos1 <= getCantidad()) && (pos2 <= getCantidad()) && pos1 != pos2)
        {
            int tmp = vector[pos2];
            vector[pos2] = vector[pos1];
            vector[pos1] = tmp;
            // std::swap(vector[pos1],vector[pos2]);
        }
    }
    void eliminePosicion(int pos)
    {
        if ((getCantidad() > 0) && (pos <= getCantidad()))
        {
            vector[pos] = 0;
            for (int idx = pos; idx < getCantidad() - 1; idx++)
                intercambiaPosiciones(idx + 1, idx);
            aumentarCantidad(-1);
        }
    }
    void elimine(int value)
    {
        int pos = buscar(value, true);
        while (pos > -1)
        {
            eliminePosicion(pos);
            buscar(value, true);
        }
    }
    void eliminarHasta(int value)
    {
        int inicio = value + 1;
        int cantidadEliminar = inicio;

        if (getCantidad() > 0)
        {
            for (int idx = 0; idx < getCantidad() - cantidadEliminar; idx++)
                intercambiaPosiciones(idx, inicio++);
            aumentarCantidad(-cantidadEliminar);
        }
    }
    void insertarElemento(int valor, int pos)
    {
        aumentarCantidad(1);
        for (int idx = getCantidad() - 1; idx > pos; idx--)
            intercambiaPosiciones(idx - 1, idx);
        vector[pos] = valor;
    }
    void invertir()
    {
        int cantidad = getCantidad();
        if (cantidad > 0)
        {
            for (int idx = 0; idx < (cantidad / 2); idx++)
                intercambiaPosiciones(idx, cantidad - 1 - idx);
        }
    }
    ColeccionEnteros enPosicionesPares()
    {
        ColeccionEnteros resultado;
        for (int idx = 0; idx < getCantidad(); idx += 2)
            resultado.insertarElemento(idx / 2, vector[idx]);
        return resultado;
    }
    void Fibonacci(int elementos)
    {
        setTamano(elementos);
        setCantidad(0);
        for (int idx = 0; idx < elementos; idx++)
            insertarElemento(ValorFibonacci(idx + 1), idx);
    }
    int sumaSelectiva(ColeccionEnteros flags)
    {
        int resultado = 0;
        int idx = flags.buscar(1);
        while (idx != -1)
        {
            resultado += vector[idx];
            idx = flags.buscar(1, idx + 1);
        }
        return resultado;
    }
    ColeccionEnteros suma(ColeccionEnteros &otra)
    {
        return *this + otra;
    }
    ColeccionEnteros operator+(const ColeccionEnteros &otra) const
    {
        int elementos = cantidad < otra.cantidad ? cantidad : otra.cantidad;
        ColeccionEnteros resultado;
        for (int idx = 0; idx < elementos; idx++)
            resultado.insertarElemento(vector[idx] + otra.vector[idx], idx);
        return resultado;
    }
    string toString()
    {
        std::ostringstream stream;
        // int max = sizeof(vector);
        // max = max > 0 ? sizeof(vector) / sizeof(vector[0]) : 0;
        int max = getCantidad();
        for (int idx = 0; idx < max; idx++)
            stream << vector[idx] << (idx < max - 1 ? "," : "");
        string resultado = stream.str();
        return resultado;
    }

    // Prueba para verificar la funcionalidad general de la clase ColeccionEnteros
    static void testColeccion()
    {
        // Creamos una instancia de ColeccionEnteros
        ColeccionEnteros coleccion;

        // Insertamos algunos elementos
        coleccion.insertarElemento(1, 0);
        coleccion.insertarElemento(2, 1);
        coleccion.insertarElemento(3, 2);
        coleccion.insertarElemento(4, 3);
        coleccion.insertarElemento(5, 4);

        // Verificamos el tamaño de la colección
        assert(coleccion.getCantidad() == 5);

        // Verificamos la suma de posiciones pares
        assert(coleccion.sumaPosicionesPares() == 9); // 1 + 3 + 5 = 9

        // Verificamos el promedio de posiciones impares
        assert(coleccion.promedioPosicionesImpares() == 3.0); // (2 + 4 ) / 2 = 3.0

        // Verificamos la búsqueda de un elemento
        assert(coleccion.buscar(3) == 2); // El elemento 3 está en la posición 2

        // Verificamos el número de apariciones de un elemento
        assert(coleccion.aparicionesDe(2) == 1); // El elemento 2 aparece una vez

        // Intercambiamos las posiciones de dos elementos
        coleccion.intercambiaPosiciones(0, 4);
        assert(coleccion.toString() == "5,2,3,4,1"); // Verificamos el orden de los elementos

        // Eliminamos un elemento
        coleccion.elimine(3);
        assert(coleccion.getCantidad() == 4); // El tamaño de la colección ahora es 4

        // Eliminamos hasta cierto elemento
        coleccion.eliminarHasta(3);
        assert(coleccion.getCantidad() == 2);  // El tamaño de la colección ahora es 2
        assert(coleccion.toString() == "4,1"); // Verificamos el orden de los elementos

        // Insertamos un elemento en una posición específica
        coleccion.insertarElemento(3, 1);
        assert(coleccion.getCantidad() == 3);    // El tamaño de la colección ahora es 3
        assert(coleccion.toString() == "4,3,1"); // Verificamos el orden de los elementos

        // Invertimos la colección
        coleccion.invertir();
        assert(coleccion.toString() == "1,3,4"); // Verificamos el orden invertido de los elementos

        std::cout << "Todas las pruebas pasaron correctamente." << std::endl;
    }
};
int main()
{
    // Ejecutamos la prueba para la clase ColeccionEnteros
    // ColeccionEnteros::testColeccion();
    int cantidadTerminos;
    std::cout << "Ingrese la cantidad de terminos de la serie de Fibonacci que desea generar: ";
    std::cin >> cantidadTerminos;

    ColeccionEnteros coleccion;
    coleccion.Fibonacci(cantidadTerminos);

    std::cout << "Serie de Fibonacci generada: " << coleccion.toString() << std::endl;

    return 0;
}