// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
using namespace std;
class Utils
{
public:
    void println(std::string message)
    {
        std::cout << message << std::endl;
    }
};
class Desafio13
{
private:
    Utils myUtils;
    std::string mark;
    void header(std::string message)
    {
        myUtils.println(mark);
        myUtils.println("Ejecutando Desafio 13." + message + ".");
    }
    void footer(std::string message)
    {
        myUtils.println("Desafio 13." + message + " ejecutado.");
        myUtils.println(mark);
    }
    void methodUITemplate(std::string id, std::function<void()> callback)
    {
        header(id);
        callback();
        footer(id);
    }
    void Desafio1Callback()
    {
        int a = 0;
        string result = "";
        cin >> a;
        result = (a % 2 == 0 ? "es par" : "no es par");
        cout << result << std::endl;
    }

    void Desafio2Callback()
    {
        int a = 0;
        int b = 0;
        string result = "";
        cin >> a >> b;
        result = (a > b ? "a es le mayor" : a == b ? "son iguales"
                                                   : "b es el mayor");
        cout << result << std::endl;
    }


public:
    Desafio13()
    {
        mark = "****************";
    }
    // Métodos DesafioX
    void SubDesafio1()
    {
        methodUITemplate("1", std::bind(&Desafio13::Desafio1Callback, this));
    }

    void SubDesafio2()
    {
        methodUITemplate("2", std::bind(&Desafio13::Desafio2Callback, this));
    }

    
    void Ejecutar()
    {
        std::vector<std::function<void()>> metodos = {
            std::bind(&Desafio13::SubDesafio1, this),
            std::bind(&Desafio13::SubDesafio2, this)
        };

        for (auto &metodo : metodos)
        {
            metodo();
        }
    }
};
int main()
{
    Desafio13 d3;
    d3.Ejecutar();
    return 0;
}