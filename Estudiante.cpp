#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

class Estudiante
{
private:
    string identificacion;
    string nombre;
    int fechaNacimiento[3]; // Formato [dia, mes, año]
    int anoIngresoUNA;
    int grupoEIF200;
    float calificaciones[20];
    int numeroProvincia;  // Atributo nuevo para el número de la provincia

public:
    // Constructor
    Estudiante() : anoIngresoUNA(0), grupoEIF200(0)
    {
        for (auto &calificacion : calificaciones)
        {
            calificacion = -1.0f;
        }
    }

    // Constructor con parámetros para inicializar todas las propiedades
    Estudiante(string id, string nom, int dia, int mes, int ano, int ingreso, int grupo,  float califs[20])
        : identificacion(id), nombre(nom), anoIngresoUNA(ingreso), grupoEIF200(grupo) {
        fechaNacimiento[0] = dia;
        fechaNacimiento[1] = mes;
        fechaNacimiento[2] = ano;
        for (int i = 0; i < 20; ++i) {
            calificaciones[i] = califs[i];
        }
    }

    // Destructor
    ~Estudiante() {}

    // Getters y Setters
    string getIdentificacion()
    {
        return identificacion;
    }

    void setIdentificacion(string cedula)
    {
        identificacion = cedula;
    }

    string getNombre()
    {
        return nombre;
    }

    void setNombre(string elNombre)
    {
        nombre = elNombre;
    }

    int getFechaNacimiento(char DiaMesAno)
    {
        switch (DiaMesAno)
        {
        case 'D':
        case 'd':
            return fechaNacimiento[0];
        case 'M':
        case 'm':
            return fechaNacimiento[1];
        case 'A':
        case 'a':
            return fechaNacimiento[2];
        default:
            return -1; // Valor inválido si se pasa un caracter incorrecto
        }
    }

    void setFechaNacimiento(int dia, int mes, int ano)
    {
        fechaNacimiento[0] = dia;
        fechaNacimiento[1] = mes;
        fechaNacimiento[2] = ano;
    }

    int getAnoIngresoUNA()
    {
        return anoIngresoUNA;
    }

    void setAnoIngresoUNA(int generacion)
    {
        anoIngresoUNA = generacion;
    }

    int getGrupoEIF200()
    {
        return grupoEIF200;
    }

    void setGrupoEIF200(int grupo)
    {
        grupoEIF200 = grupo;
    }

    float getCalificaciones(int prueba)
    {
        if (prueba >= 0 && prueba < 20)
        {
            return calificaciones[prueba];
        }
        else
        {
            return -1; // Valor inválido para índice fuera de rango
        }
    }

    void setCalificaciones(int prueba, float nota)
    {
        if (prueba >= 0 && prueba < 20)
        {
            calificaciones[prueba] = nota;
        }
    }

    float promedioCalificaciones()
    {
        float sum = 0.0;
        for (int i = 0; i < 20; ++i)
        {
            sum += calificaciones[i];
        }
        return sum / 20;
    }

    bool aprobo()
    {
        return promedioCalificaciones() >= 70.0;
    }

    string mostrar()
    {
        stringstream s;
        s << "Identificacion: " << identificacion << endl;
        s << "Nombre: " << nombre << endl;
        s << "Fecha Nacimiento: " << fechaNacimiento[0] << "/" << fechaNacimiento[1] << "/" << fechaNacimiento[2] << endl;
        s << "Año Ingreso: " << anoIngresoUNA << endl;
        s << "Grupo: " << grupoEIF200 << endl;
        return s.str();
    }
   
    // Método para calcular el promedio de las primeras 3 calificaciones
    float promedio3Calificaciones() {
        if (sizeof(calificaciones) < 3) {
            cerr << "No hay suficientes calificaciones registradas." << endl;
            return 0.0;
        }
        float suma = 0;
        for (int i = 0; i < 3; ++i) {
            suma += calificaciones[i];
        }
        return suma / 3;
    }
   
    // Método para calcular el promedio de las primeras 5 calificaciones
    float promedio5Calificaciones() {
        if ( sizeof(calificaciones) < 5) {
            cerr << "No hay suficientes calificaciones registradas." << endl;
            return 0.0;
        }
        float suma = 0;
        for (int i = 0; i < 5; ++i) {
            suma += calificaciones[i];
        }
        return suma / 5;
    }

   // Método para determinar si aprueba con una curva de porcentaje
    bool apruebaConCurva(int porcentaje) {
        float promedio = promedioCalificaciones();
        float promedioConCurva = promedio + (promedio * porcentaje / 100.0);
        return promedioConCurva >= 70.0;
    }

    // Método que devuelve true si el estudiante aprueba con una curva del 10%
    bool apruebaConCurva10pct() {
        return apruebaConCurva(10);
    }

    // Método para devolver el nombre de la provincia basado en el número
    string provinciaNacimiento() {
        switch (numeroProvincia) {
            case 1: return "San Jose";
            case 2: return "Alajuela";
            case 3: return "Cartago";
            case 4: return "Heredia";
            case 5: return "Guanacaste";
            case 6: return "Puntarenas";
            case 7: return "Limon";
            default: return "Provincia desconocida";
        }
    }

      // Método para calcular los años cumplidos hasta una fecha dada
    int annosCumplidos(int dia, int mes, int ano) {
        int year = fechaNacimiento[2];
        int month = fechaNacimiento[1];
        int day = fechaNacimiento[0];

        // Calcular los años preliminares
        int years = ano - year;
        
        // Ajustar si el mes actual es antes del mes de nacimiento o si estamos en el mes pero el día no ha llegado aún
        if (mes < month || (mes == month && dia < day)) {
            years--;
        }

        return years;
    }
};


class Profesor {
private:
    string identificacion;
    string nombre;
    string departamento;
    int anosExperiencia;

public:
    // Constructor sin parámetros
    Profesor() : anosExperiencia(0) {}

    // Constructor con parámetros para inicializar todas las propiedades
    Profesor( string id,  string nom,  string depto, int anos)
        : identificacion(id), nombre(nom), departamento(depto), anosExperiencia(anos) {}

    // Destructor
    ~Profesor() {}

    // Getters y Setters
    string getIdentificacion()  { return identificacion; }
    void setIdentificacion( string id) { identificacion = id; }

    string getNombre()  { return nombre; }
    void setNombre( string nom) { nombre = nom; }

    string getDepartamento()  { return departamento; }
    void setDepartamento( string depto) { departamento = depto; }

    int getAnosExperiencia()  { return anosExperiencia; }
    void setAnosExperiencia(int anos) { anosExperiencia = anos; }

    // Método para mostrar la información del profesor
    string mostrar()  {
        stringstream ss;
        ss << "Identificación: " << identificacion << "\n"
           << "Nombre: " << nombre << "\n"
           << "Departamento: " << departamento << "\n"
           << "Años de experiencia: " << anosExperiencia;
        return ss.str();
    }
};

class GrupoEIF200 {
private:
    Profesor profesor;  // Objeto Profesor para almacenar la información del profesor
    vector<Estudiante> estudiantes;  // Lista de estudiantes matriculados en el grupo

public:
    // Constructor por defecto
    GrupoEIF200() {}

    // Constructor con profesor inicial
    GrupoEIF200( Profesor& profesor) : profesor(profesor) {}

    // Destructor
    ~GrupoEIF200() {}

    // Métodos para gestionar profesor
    void setProfesor( Profesor& prof) {
        profesor = prof;
    }

    Profesor getProfesor()  {
        return profesor;
    }

    // Métodos para gestionar estudiantes
    void agregarEstudiante( Estudiante& estudiante) {
        estudiantes.push_back(estudiante);
    }

    void removerEstudiante( string identificacion) {
        auto it = remove_if(estudiantes.begin(), estudiantes.end(),
                            [&]( Estudiante& e) { return e.getIdentificacion() == identificacion; });
        estudiantes.erase(it, estudiantes.end());
    }

    // Método para mostrar la información del grupo
    string mostrarGrupo()  {
        stringstream ss;
        ss << "Profesor: " << profesor.mostrar() << "\nEstudiantes:\n";
        for ( Estudiante& estudiante : estudiantes) {
            ss << estudiante.mostrar() << endl;
        }
        return ss.str();
    }
};

int main() {
    // Creando el profesor
    Profesor profesor =  Profesor("11223344", "Oscar Benavides", "FUNDAMENTOS DE INFORMÁTICA", 2024 - 1999);

    // Creando los estudiantes
    vector<Estudiante> estudiantes;
    // 19 estudiantes menores de 22 años
    for (int i = 0; i < 19; ++i) {
        string id = "E" + to_string(1000 + i);
        string nombre = "Estudiante_" + to_string(i + 1);
        int anoNacimiento = 2003 + (i % 2);  // Alternando entre 2003 y 2004
        Estudiante est(id, nombre, 1, 1, anoNacimiento, 2024, 1, (float[20]){});
        estudiantes.push_back(est);
    }
    // 1 estudiante de 38 años
    Estudiante byron("E1020", "Byron Roman", 1, 1, 1986, 2024, 1, (float[20]){});
    estudiantes.push_back(byron);

    // Creando el grupo EIF200
    GrupoEIF200 grupo(profesor);
    for (Estudiante& est : estudiantes) {
        grupo.agregarEstudiante(est);
    }

    // Mostrando información del grupo
    cout << "Información del Grupo EIF200:\n" << grupo.mostrarGrupo() << endl;

    return 0;
}