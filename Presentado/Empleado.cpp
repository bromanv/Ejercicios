#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Empleado {
private:
    std::string nombre;
    std::string cedula;
    enum Categoria { PRUEBA, REGULAR, BUENO, EXCELENTE } categoria;
    int horasTrabajadas;
    static const int salarioHora = 6000;

public:
    // Constructor sin parámetros
    Empleado() : nombre(""), cedula(""), categoria(PRUEBA), horasTrabajadas(0) {}

    // Constructor con parámetros
    Empleado(std::string nombre, std::string cedula, char categoriaChar, int horasTrabajadas)
        : nombre(nombre), cedula(cedula), horasTrabajadas(horasTrabajadas) {
        setCategoria(categoriaChar);
    }

    // Destructor
    ~Empleado() {}

    // Métodos set/get
    void setNombre(const std::string &value) { nombre = value; }
    void setCedula(const std::string &value) { cedula = value; }
    void setCategoria(char value) {
        switch (value) {
            case 'e': categoria = EXCELENTE; break;
            case 'b': categoria = BUENO; break;
            case 'r': categoria = REGULAR; break;
            case 'p': categoria = PRUEBA; break;
            default: categoria = PRUEBA;
        }
    }
    void setHorasTrabajadas(int value) { horasTrabajadas = value; }
    
    std::string getNombre() const { return nombre; }
    std::string getCedula() const { return cedula; }
    char getCategoriaChar() const {
        switch (categoria) {
            case EXCELENTE: return 'e';
            case BUENO: return 'b';
            case REGULAR: return 'r';
            case PRUEBA: return 'p';
        }
        return 'p';
    }
    int getHorasTrabajadas() const { return horasTrabajadas; }

    // Métodos de cálculo
    double salarioBruto() const {
        return salarioHora * horasTrabajadas;
    }

    double incentivo() const {
        switch (categoria) {
            case EXCELENTE: return 0.05 * salarioBruto();
            case BUENO: return 0.03 * salarioBruto();
            case REGULAR: return 0.01 * salarioBruto();
            default: return 0.0;
        }
    }

    double deduccionCCSS() const {
        return 0.28 * salarioBruto();
    }

    double salarioNeto() const {
        return salarioBruto() + incentivo() - deduccionCCSS();
    }

    // Método para mostrar la información del empleado
    std::string toString() const {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2);
        ss << "Nombre: " << nombre << "\n"
           << "Cédula: " << cedula << "\n"
           << "Categoría: " << getCategoriaChar() << "\n"
           << "Horas Trabajadas: " << horasTrabajadas << "\n"
           << "Salario Bruto: " << salarioBruto() << "\n"
           << "Incentivo: " << incentivo() << "\n"
           << "Deducción CCSS: " << deduccionCCSS() << "\n"
           << "Salario Neto: " << salarioNeto() << "\n";
        return ss.str();
    }
};

int main() {
    std::string nombre, cedula;
    char categoria;
    int horas;

    // Recibir los datos del empleado
    std::cout << "Ingrese nombre del empleado: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese cédula del empleado: ";
    std::getline(std::cin, cedula);
    std::cout << "Ingrese categoría del empleado (e, b, r, p): ";
    std::cin >> categoria;
    std::cout << "Ingrese horas trabajadas: ";
    std::cin >> horas;

    // Crear instancia de Empleado
    Empleado empleado(nombre, cedula, categoria, horas);

    // Mostrar los detalles y cálculos del salario
    std::cout << empleado.toString() << std::endl;

    return 0;
}
