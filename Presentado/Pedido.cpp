#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

 enum Tipo { DESAYUNO = 'D', ALMUERZO = 'A', CENA = 'C' };

class Pedido {
private:
    std::string codigo;
   Tipo tipo;
    int cantidadPlatos;
    int cantidadBebidas;
    static int consecutivo;

public:
    // Constructor sin parámetros
    Pedido() : codigo("000"), tipo(DESAYUNO), cantidadPlatos(0), cantidadBebidas(0) {
        actualizarCodigo();
    }

    // Constructor con parámetros
    Pedido(Tipo tipo, int cantidadPlatos, int cantidadBebidas)
        : tipo(tipo), cantidadPlatos(cantidadPlatos), cantidadBebidas(cantidadBebidas) {
        actualizarCodigo();
    }

    // Destructor
    ~Pedido() {}

    // Métodos de acceso
    std::string getCodigo() const { return codigo; }
    Tipo getTipo() const { return tipo; }
    int getCantidadPlatos() const { return cantidadPlatos; }
    int getCantidadBebidas() const { return cantidadBebidas; }

    // Métodos de modificación
    void setTipo(Tipo value) { this->tipo = value; }
    void setCantidadPlatos(int value) { cantidadPlatos = value; }
    void setCantidadBebidas(int value) { cantidadBebidas = value; }

    // Método para actualizar el código del pedido
    void actualizarCodigo() {
        std::ostringstream ss;
         //No visto en clase , creo, Uso de std::setw() logar el padding 
        ss << std::setw(3) << std::setfill('0') << ++consecutivo;
        codigo = ss.str();
    }

    // Método que determina el porcentaje de descuento
    double getDescuento() const {
        if (cantidadPlatos >= 10) return 15.0;
        if (cantidadPlatos > 7) return 10.0;
        if (cantidadPlatos >= 5) return 5.0;
        return 1.0;
    }

    // Método que calcula el precio total del pedido
    double getPrecio() const {
        double precioBase = 0;
        switch (tipo) {
            case DESAYUNO:
                precioBase = 2500 * cantidadPlatos;
                break;
            case ALMUERZO:
                precioBase = 3500 * cantidadPlatos + 1000 * cantidadBebidas;
                break;
            case CENA:
                precioBase = 4500 * cantidadPlatos + 1000 * std::max(0, cantidadBebidas - cantidadPlatos);
                break;
        }
        double descuento = getDescuento();
        return precioBase * (1 - descuento / 100.0);
    }

    // Método para generar la factura del pedido
    std::string toStringFactura() const {
        int margen=25;
        std::ostringstream ss;
        //TODO no logro identifcar porque debo sumar 1 para que el codigo quede bien alineado
        ss << std::left << std::setw(margen+1) << "Código del Pedido:" << codigo << std::endl
           << std::setw(margen) << "Tipo de Pedido:" << (tipo == DESAYUNO ? "Desayuno" : tipo == ALMUERZO ? "Almuerzo" : "Cena") << std::endl
           << std::setw(margen) << "Cantidad de Platos:" << cantidadPlatos <<  std::endl
           << std::setw(margen) << "Cantidad de Bebidas:" << cantidadBebidas <<  std::endl
           << std::setw(margen) << "Precio Total:" << std::fixed << std::setprecision(2) << getPrecio() / (1 - getDescuento() / 100.0) << std::endl
           << std::setw(margen) << "Descuento:" << getDescuento() << "%" << std::endl
           << std::setw(margen) << "Precio con Descuento:" << getPrecio() <<  std::endl;
        return ss.str();
    }
};

int Pedido::consecutivo = 0;

int main() {
    char tipoChar;
    Tipo tipo;
    int cantidadPlatos, cantidadBebidas;
    int continuar = 1;

    while (continuar == 1) {
        std::cout << "Ingrese el tipo de pedido ('D' para desayuno, 'A' para almuerzo, 'C' para cena): ";
        std::cin >> tipoChar;
        switch (tipoChar) {
            case 'D': tipo = Tipo::DESAYUNO; break;
            case 'A': tipo = Tipo::ALMUERZO; break;
            case 'C': tipo = Tipo::CENA; break;
            default: 
                std::cout << "Tipo inválido. Por favor ingrese un tipo válido." << std::endl;
                continue;
        }
        std::cout << "Ingrese la cantidad de platos: ";
        std::cin >> cantidadPlatos;
        std::cout << "Ingrese la cantidad de bebidas: ";
        std::cin >> cantidadBebidas;

        Pedido pedido(tipo, cantidadPlatos, cantidadBebidas);
        std::cout << "\nFactura del Pedido:\n" << pedido.toStringFactura() << std::endl;

        std::cout << "¿Desea ingresar otro pedido? (1 / 0): ";
        std::cin >> continuar;
        
    }

    return 0;
}
