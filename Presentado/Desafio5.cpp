// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
#include <math.h>
class Utils {
    public:
        void println(std::string message) {
            std::cout << message << std::endl;
        }
};
class Desafio5 {
    private:
        Utils myUtils;
        std::string mark;
        void header(std::string message) {
            myUtils.println(mark);
            myUtils.println("Ejecutando Desafio 5." + message+".");
        }
        void footer(std::string message) {
            myUtils.println("Desafio 5."+message+" ejecutado.");
            myUtils.println(mark);
        }
        void methodUITemplate(std::string id, std::function<void()> callback){
            header(id);
            callback();
            footer(id);
        }
        void Desafio1Callback() {
            float radio = 0;
            const float pi = 3.14;//std::atan(1)*4;//C++20 std::numbers::pi
            std::cout << "Radio:";
            std::cin >> radio;
            myUtils.println("constante circular: "+std::to_string(pi) );
             myUtils.println(std::to_string(2*radio*pi) + " es el valor de la circunferencia ");
             myUtils.println(std::to_string(pow(radio,2)*pi) + " es el valor del área ");

        }
    public:
        Desafio5(){
            mark ="****************";
        }
        // Métodos DesafioX
        void SubDesafio1() {
            methodUITemplate("1", std::bind(&Desafio5::Desafio1Callback, this));
        }

        void Ejecutar() {
            std::vector<std::function<void()>> metodos = {
                std::bind(&Desafio5::SubDesafio1, this)
            };

            for (auto& metodo : metodos) {
                metodo();
            }
    }
};
int main() {
    Desafio5 d3;
    d3.Ejecutar();
    return 0;
}