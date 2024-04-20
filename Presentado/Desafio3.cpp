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
class Desafio3 {
    private:
        Utils myUtils;
        std::string mark;
        void header(std::string message) {
            myUtils.println(mark);
            myUtils.println("Ejecutando Desafio 3." + message+".");
        }
        void footer(std::string message) {
            myUtils.println("Desafio 3."+message+" ejecutado.");
            myUtils.println(mark);
        }
        void methodUITemplate(std::string id, std::function<void()> callback){
            header(id);
            callback();
            footer(id);
        }
        void Desafio1Callback() {
            myUtils.println("Lo lograré!!!");
        }

        void Desafio2Callback() {
            for (int idx = 0; idx < 50; idx++){
                myUtils.println("Lo lograré!!!");
            }
        }

        void Desafio3Callback() {
            for (int idx = 0; idx < 50; idx++){
                myUtils.println(std::to_string(idx+1) + ": Lo lograré!!!");
            }
        }

        void Desafio4Callback() {
            int max = 0;
            std::cout << "Cantidad de veces:";
            std::cin >> max;
            for (int idx = 0; idx < max; idx++){
                myUtils.println(std::to_string(idx+1) + ": Lo lograré!!!");
            }
        }

        void Desafio5Callback() {
           int max = 0;
            std::string message="";
            std::cout << "Mensaje a mostrar:";
            std::cin >> message;
            std::cout << "Cantidad de veces:";
            std::cin >> max;
            
            for (int idx = 0; idx < max; idx++){
                myUtils.println(std::to_string(idx+1) + ":"+message);
            }
          }

        void Desafio6Callback() {
            int max = 0;
            std::string message="";
            std::cout << "Mensaje a mostrar:";
            std::cin >> message;
            max = message.length();
            for (int idx = 0; idx < max; idx++){
                myUtils.println(std::to_string(idx+1) + ":"+message[idx]);
            }
          }

        void Desafio7Callback() {
            int max = 0;
            std::string message="";
            std::cout << "Mensaje a mostrar:";
            std::cin >> message;
            max = message.length();
            for (int idx = 0; idx < max; idx++){
                myUtils.println(std::to_string(idx+1) + ":"+message);
            }
          }

        void Desafio8Callback() {
            int max = 0;
            std::string message;
            std::cout << "Mensaje a mostrar:";
            std::cin >> message;
            int messageLength = sizeof(message)/sizeof(char);
            std::ostringstream oss;
            for (int idx = message.length()-1; idx > -1; idx--){
                max+=static_cast<int>(message[idx]);
                /* oss <<message[idx]<< ":"<< static_cast<int>(message[idx]);
                myUtils.println(oss.str());
                oss.str("");
                oss.clear();*/
            }
            for (int idx = 0; idx < max; idx++){
                myUtils.println(std::to_string(idx+1) + ":"+message);
            }
          }
    public:
        Desafio3(){
            mark ="****************";
        }
        // Métodos DesafioX
        void SubDesafio1() {
            methodUITemplate("1", std::bind(&Desafio3::Desafio1Callback, this));
        }

        void SubDesafio2() {
            methodUITemplate("2", std::bind(&Desafio3::Desafio2Callback, this));
        }

        void SubDesafio3() {
            methodUITemplate("3", std::bind(&Desafio3::Desafio3Callback, this));
        }

        void SubDesafio4() {
             methodUITemplate("4", std::bind(&Desafio3::Desafio4Callback, this));
        }

        void SubDesafio5() {
             methodUITemplate("5", std::bind(&Desafio3::Desafio5Callback, this));
        }

        void SubDesafio6() {
             methodUITemplate("6", std::bind(&Desafio3::Desafio6Callback, this));
        }

        void SubDesafio7() {
             methodUITemplate("7", std::bind(&Desafio3::Desafio7Callback, this));
        }

        void SubDesafio8() {
             methodUITemplate("8", std::bind(&Desafio3::Desafio8Callback, this));
        }
        void Ejecutar() {
            std::vector<std::function<void()>> metodos = {
                std::bind(&Desafio3::SubDesafio1, this),
                std::bind(&Desafio3::SubDesafio2, this),
                std::bind(&Desafio3::SubDesafio3, this),
                std::bind(&Desafio3::SubDesafio4, this),
                std::bind(&Desafio3::SubDesafio5, this),
                std::bind(&Desafio3::SubDesafio6, this),
                std::bind(&Desafio3::SubDesafio7, this),
                std::bind(&Desafio3::SubDesafio8, this)
            };

            for (auto& metodo : metodos) {
                metodo();
            }
    }
};
int main() {
    Desafio3 d3;
    d3.Ejecutar();
    return 0;
}