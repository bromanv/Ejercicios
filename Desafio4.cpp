// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
class Utils {
    public:
        void println(std::string message) {
            std::cout << message << std::endl;
        }
};
class Desafio4 {
    private:
        Utils myUtils;
        std::string mark;
        void header(std::string message) {
            myUtils.println(mark);
            myUtils.println("Ejecutando Desafio 4." + message+".");
        }
        void footer(std::string message) {
            myUtils.println("Desafio 4."+message+" ejecutado.");
            myUtils.println(mark);
        }
        void methodUITemplate(std::string id, std::function<void()> callback){
            header(id);
            callback();
            footer(id);
        }
        void Desafio1Callback() {
            int largo =3;
            int ancho =5;
            myUtils.println("Área de un rectángulo de 3 x 5: "+std::to_string(largo*ancho));
        }

        void Desafio2Callback() {
            int largo =3;
            int ancho =5;
            std::cout << "largo:";
            std::cin >> largo;
            std::cout << "Ancho:";
            std::cin >> ancho;

            myUtils.println("Área de un rectángulo: "+std::to_string(largo*ancho));
        }
    public:
        Desafio4(){
            mark ="****************";
        }
        // Métodos DesafioX
        void SubDesafio1() {
            methodUITemplate("1", std::bind(&Desafio4::Desafio1Callback, this));
        }

        void SubDesafio2() {
            methodUITemplate("2", std::bind(&Desafio4::Desafio2Callback, this));
        }

        void Ejecutar() {
            std::vector<std::function<void()>> metodos = {
                std::bind(&Desafio4::SubDesafio1, this),
                std::bind(&Desafio4::SubDesafio2, this)
            };

            for (auto& metodo : metodos) {
                metodo();
            }
    }
};
int main() {
    Desafio4 d4;
    d4.Ejecutar();
    return 0;
}