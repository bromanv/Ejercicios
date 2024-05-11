#include <iostream>
#include <iomanip>
#include <sstream>

class Hora
{
private:
    int horas;
    int minutos;
    int segundos;

    int addSegment(int &segmento, int valor, int factor)
    {
        segmento = valor % factor;
        return valor / factor;
    }

    int removeSegment1(int &segmento, int valor, int factor)
    {
        int complemento = factor - valor;//Calcula el complemento la suma de los complementos debe ser factor, si lo super hay desborde

        segmento = (factor - (complemento % factor)) % factor; // ajusta el valor para que este entre [0,factor[ y obtien el complemento
        return complemento / (factor + 1) * -1;                // cuando hay desborde el numero inverso sera factor+1, por lo que solo asi la operacion retorna != 0
    }

public:
    // Constructor sin parámetros
    Hora() : horas(0), minutos(0), segundos(0) {}

    // Constructor con parámetros
    Hora(int h, int m, int s) : horas(h % 24), minutos(m % 60), segundos(s % 60)
    {
    }
    Hora(int h, int m, int s, bool handleOverflow) : horas(0), minutos(0), segundos()
    {
        int overflow = addSegment(segundos, s, 60);
        overflow = addSegment(minutos, m + overflow, 60);
        overflow = addSegment(horas, h + overflow, 24);
    }

    // Destructor
    ~Hora() {}

    // Métodos de acceso
    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }
    int getSegundos() const { return segundos; }

    // Métodos de modificación
    void setHoras(int h) { horas = h % 24; }
    void setMinutos(int m) { minutos = m % 60; }
    void setSegundos(int s) { segundos = s % 60; }

    // Método muestraHora24Hrs
    std::string muestraHora24Hrs() const
    {
        std::ostringstream stream;
        stream << std::setfill('0') << std::setw(2) << horas << ":"
               << std::setw(2) << minutos << ":" << std::setw(2) << segundos;
        return stream.str();
    }

    // Método muestraHora12Hrs
    std::string muestraHora12Hrs() const
    {
        std::ostringstream stream;
        int hour = horas % 12 == 0 ? 12 : horas % 12;

        std::string ampm = horas < 12 ? " a.m." : " p.m.";
        stream << std::setfill('0') << std::setw(2) << hour << ":"
               << std::setw(2) << minutos << ":" << std::setw(2) << segundos << ampm;
        return stream.str();
    }

    // Método avanza
    void avanza()
    {
        segundos++;
        if (segundos >= 60)
        {
            segundos = 0;
            minutos++;
            if (minutos >= 60)
            {
                minutos = 0;
                horas = (horas + 1) % 24;
            }
        }
    }
    void avanza2()
    {
        int overflow = addSegment(segundos, segundos + 1, 60);
        overflow = addSegment(minutos, minutos + overflow, 60);
        overflow = addSegment(horas, horas + overflow, 24);
    }

    // Método retrocede
    void retrocede()
    {
        segundos--;
        if (segundos < 0)
        {
            segundos = 59;
            minutos--;
            if (minutos < 0)
            {
                minutos = 59;
                horas = (horas - 1 + 24) % 24;
            }
        }
    }
    void retrocede2()
    {
        int overflow = removeSegment(segundos, segundos - 1, 60);
        overflow = removeSegment(minutos, minutos + overflow, 60);
        overflow = removeSegment(horas, horas + overflow, 24);
    }

    // Método mayor
    Hora mayor(const Hora &otra) const
    {
        if (horas > otra.horas || (horas == otra.horas && minutos > otra.minutos) ||
            (horas == otra.horas && minutos == otra.minutos && segundos > otra.segundos))
            return *this;
        else
            return otra;
    }

    // Método sumaHora
    void sumaHora(const Hora &otra)
    {
        segundos += otra.segundos;
        minutos += otra.minutos + segundos / 60;
        horas += otra.horas + minutos / 60;
        segundos %= 60;
        minutos %= 60;
        horas %= 24;
    }

    // Método intercambia
    void intercambia(Hora &otra)
    {
        // se usa swap que intercambia los valores, pero se puede hacer con una variable temporal
        std::swap(horas, otra.horas);
        std::swap(minutos, otra.minutos);
        std::swap(segundos, otra.segundos);
    }
};

int main()
{
    Hora hora1(17, 15, 59), hora2(5, 59, 01), hora3(17, 15, 59), hora4(5, 59, 01);

    std::cout << "Hora 1 (24h): " << hora1.muestraHora24Hrs() << std::endl;
    std::cout << "Hora 1 (12h): " << hora1.muestraHora12Hrs() << std::endl;
    std::cout << "Hora 2 (24h): " << hora2.muestraHora24Hrs() << std::endl;
    std::cout << "Hora 2 (12h): " << hora2.muestraHora12Hrs() << std::endl;

    hora1.avanza();
    std::cout << "Hora 1 avanzada: " << hora1.muestraHora24Hrs() << std::endl;
    hora3.avanza2();
    std::cout << "Hora 3 avanzada: " << hora3.muestraHora24Hrs() << std::endl;
    for (int i = 0; i < 60; i++)
    {
        hora2.retrocede();
        std::cout << "Hora 2 retrocedida: " << hora2.muestraHora24Hrs() << std::endl;
        hora4.retrocede2();
        std::cout << "Hora 4 retrocedida: " << hora4.muestraHora24Hrs() << std::endl;
    }
    Hora mayor = hora1.mayor(hora2);
    std::cout << "Hora mayor (24h): " << mayor.muestraHora24Hrs() << std::endl;
    std::cout << "Hora mayor (12h): " << mayor.muestraHora12Hrs() << std::endl;

    hora1.sumaHora(hora2);
    std::cout << "Suma de Hora 1 + Hora 2: " << hora1.muestraHora24Hrs() << std::endl;

    hora1.intercambia(hora2);
    std::cout << "Hora 1 intercambiada: " << hora1.muestraHora24Hrs() << std::endl;
    std::cout << "Hora 2 intercambiada: " << hora2.muestraHora24Hrs() << std::endl;

    return 0;
}
