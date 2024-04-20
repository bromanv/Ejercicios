// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Utils {
    public:
        void println(std::string message) {
            std::cout << message << std::endl;
        }
};
class Desafio6 {
    private:
        Utils myUtils;
        std::string mark;
        void header(std::string message) {
            myUtils.println(mark);
            myUtils.println("Ejecutando Desafio 6." + message+".");
        }
        void footer(std::string message) {
            myUtils.println("Desafio 6."+message+" ejecutado.");
            myUtils.println(mark);
        }
        void methodUITemplate(std::string id, std::function<void()> callback){
            header(id);
            callback();
            footer(id);
        }
        void Desafio1Callback() {
            float a = 0;
            float b = 0;            
            std::cout << "cateto a:";
            std::cin >> a;
            std::cout << "cateto b:";
            std::cin >> b;
            std::cout <<"Hipotenusa => "<< sqrt(pow(a,2)+pow(b,2)) << endl;
            std::cout <<"Cateto a => "<< a << endl;
            std::cout <<"Cateto b => "<< b << endl;
        }
    public:
        Desafio6(){
            mark ="****************";
        }
        // Métodos DesafioX
        void SubDesafio1() {
            methodUITemplate("1", std::bind(&Desafio6::Desafio1Callback, this));
        }

        void Ejecutar() {
            std::vector<std::function<void()>> metodos = {
                std::bind(&Desafio6::SubDesafio1, this)
            };

            for (auto& metodo : metodos) {
                metodo();
            }
    }
};
int main() {
    Desafio6 d3;
    d3.Ejecutar();
    return 0;
}