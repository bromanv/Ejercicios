#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

enum TipoCliente
{
    GOBIERNO,
    FISICO,
    ECOLOGICO
};
enum TipoEnvio
{
    NACIONAL,
    INTERNACIONAL
};

class Envio
{
private:
    TipoCliente tipoCliente;
    double pesoGramos;
    TipoEnvio tipoEnvio;
    double costoBase;
    double iva;
    double aduana;
    double descuento;

public:
    Envio(TipoCliente tipoCliente, double pesoGramos, TipoEnvio tipoEnvio)
        : tipoCliente(tipoCliente), pesoGramos(pesoGramos), tipoEnvio(tipoEnvio)
    {
        calcularCostoBase();
        aplicarDescuento();
        calcularIVA();
        calcularAduana();
    }

    // Getters
    TipoCliente getTipoCliente() const
    {
        return tipoCliente;
    }

    double getPesoGramos() const
    {
        return pesoGramos;
    }

    TipoEnvio getTipoEnvio() const
    {
        return tipoEnvio;
    }

    double getCostoBase() const
    {
        return costoBase;
    }

    double getIva() const
    {
        return iva;
    }

    double getAduana() const
    {
        return aduana;
    }

    double getDescuento() const
    {
        return descuento;
    }

    // Setters
    void setTipoCliente(TipoCliente value) { tipoCliente = value; }
    void setPesoGramos(double value) { pesoGramos = value; }
    void setTipoEnvio(TipoEnvio value) { tipoEnvio = value; }
    void setCostoBase(double value) { costoBase = value; }
    void setIva(double value) { iva = value; }
    void setAduana(double value) { aduana = value; }
    void setDescuento(double value) { descuento = value; }

    void calcularCostoBase()
    {
        if (pesoGramos < 500)
            costoBase = 1;
        else if (pesoGramos < 1000)
            costoBase = 2;
        else if (pesoGramos < 2000)
            costoBase = 5;
        else
            costoBase = 20;

        if (tipoEnvio == INTERNACIONAL)
        {
            costoBase *= 1.30; // 30% más para envíos internacionales
        }
    }

    void aplicarDescuento()
    {
        switch (tipoCliente)
        {
        case ECOLOGICO:
            descuento = 0.07 * costoBase;
            break;
        case GOBIERNO:
            descuento = 0.05 * costoBase;
            break;
        default:
            descuento = 0.0;
            break;
        }
    }

    double calcularIVA()
    {
        if (tipoCliente == GOBIERNO)
            return 0.0;
        return 0.15 * (costoBase - descuento);
    }

    double calcularAduana()
    {
        if (tipoEnvio == INTERNACIONAL)
            return 0.10 * costoBase;
        return 0.0;
    }

    double calcularTotal()
    {
        return costoBase + calcularIVA() + calcularAduana() - descuento;
    }

    std::string toString()
    {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2);
        ss << "Tipo Cliente: " << (tipoCliente == GOBIERNO ? "Gobierno" : tipoCliente == FISICO ? "Físico"
                                                                                                : "Ecológico")
           << std::endl
           << "Peso Gramos: " << pesoGramos << std::endl
           << "Tipo Envio: " << (tipoEnvio == NACIONAL ? "Nacional" : "Internacional") << std::endl
           << "Costo Base: " << costoBase << std::endl
           << "Descuento: " << descuento << std::endl
           << "IVA: " << calcularIVA() << std::endl
           << "Aduana: " << calcularAduana() << std::endl
           << "Total a Pagar: " << calcularTotal() << std::endl;
        return ss.str();
    }
};

int main()
{
    int tipoClienteIndex, tipoEnvioIndex;
    double pesoGramos;
    int numEnvios;

    std::cout << "Ingrese el número de envíos: ";
    std::cin >> numEnvios;
    for (int i = 0; i < numEnvios; ++i)
    {
        std::cout << "Ingrese el tipo de cliente (0: Gobierno, 1: Físico, 2: Ecológico): ";
        std::cin >> tipoClienteIndex;
        std::cout << "Ingrese el peso del paquete en gramos: ";
        std::cin >> pesoGramos;
        std::cout << "Ingrese el tipo de envío (0: Nacional, 1: Internacional): ";
        std::cin >> tipoEnvioIndex;

        Envio envio(static_cast<TipoCliente>(tipoClienteIndex), pesoGramos, static_cast<TipoEnvio>(tipoEnvioIndex));
        std::cout << "Factura del Envío:\n"
                  << envio.toString() << std::endl;
    }

    return 0;
}
