#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std::chrono;

enum Gama
{
    BAJA,
    MEDIA,
    ALTA
};
class Televisor
{
private:
    float precioCompra;
    std::string codigo;
    int fabricacion;
    int lote;
    Gama gama;

public:
    // Constructor sin parámetros
    Televisor() : precioCompra(0), codigo(""), fabricacion(0), lote(0), gama(BAJA) {}

    // Constructor con parámetros
    Televisor(float precio, std::string cod, int fab, int lot, Gama gam) : precioCompra(precio), codigo(cod), fabricacion(fab), lote(lot), gama(gam) {}

    // Métodos de acceso (getters)
    float getPrecioCompra() const { return precioCompra; }
    std::string getCodigo() const { return codigo; }
    int getFabricacion() const { return fabricacion; }
    int getLote() const { return lote; }
    Gama getGama() const { return gama; }

    // Métodos de modificación (setters)
    void setPrecioCompra(float value) { precioCompra = value; }
    void setCodigo(std::string value) { codigo = value; }
    void setFabricacion(int value) { fabricacion = value; }
    void setLote(int value) { lote = value; }
    Gama setGama(Gama value) { gama = value; }

    // Método para calcular el precio de venta
    float precioVenta(int actual)
    {
        float precio = precioCompra;

        if (lote < 0)
        {
            precio *= 0.75;
        }
        else
        {
            precio *= 1.30;
            if ((actual - fabricacion) < 2)
            {
                precio *= 1.05;
            }
            if (gama == ALTA)
            {
                precio *= 1.15;
            }
        }
        return precio;
    }

    // Método toString() modificado para usar stringstream
    std::string toString()
    {
        std::stringstream ss;
        ss << "Codigo: " << codigo << "\n"
           << "Año de Fabricación: " << fabricacion << "\n"
           << "Lote: " << lote << "\n"
           << "Gama: " << (gama == BAJA ? "Baja" : gama == MEDIA ? "Media"
                                                                 : "Alta")
           << "\n"
           << "Precio de Compra: $" << precioCompra << "\n"
           << "Precio de Venta: $" << precioVenta(obtenerAnioActual()) << "\n";
        return ss.str();
    }
    int obtenerAnioActual()
    {

        // Utilizando chrono para obtener la hora actual del sistema
        auto now = std::chrono::system_clock::now();

        // Convertir de tiempo de sistema a tiempo de calendario
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        // Convertir a estructura tm local
        std::tm *now_tm = std::localtime(&in_time_t);

        // Extraer el año de la estructura tm y ajustar desde 1900
        return  1900 + now_tm->tm_year;
    }
};

int main()
{
    Televisor tv;
    tv.setCodigo("001");
    tv.setFabricacion(2023);
    tv.setLote(101);
    tv.setGama(Gama::MEDIA);
    tv.setPrecioCompra(500.0);

    Televisor tv1(400, "002", 2022, 102, Gama::BAJA);
    Televisor tv2(550, "003", 2023, -1003, Gama::ALTA);
    Televisor tv3(600, "004", 2021, 104, Gama::ALTA);
    Televisor tv4(350, "005", 2022, 105, Gama::MEDIA);

    std::cout << tv.toString() << std::endl;
    std::cout << tv1.toString() << std::endl;
    std::cout << tv2.toString() << std::endl;
    std::cout << tv3.toString() << std::endl;
    std::cout << tv4.toString() << std::endl;

    return 0;
}
