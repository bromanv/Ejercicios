// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
#include <optional>
#include <cmath>

using namespace std;

class Utils
{
public:
    void println(std::string message)
    {
        std::cout << message << std::endl;
    }
};
class Desafio15
{
private:
    Utils myUtils;
    std::string mark;
    void header(std::string message)
    {
        myUtils.println(mark);
        myUtils.println("Ejecutando Desafio 15." + message + ".");
    }
    void footer(std::string message)
    {
        myUtils.println("Desafio 15." + message + " ejecutado.");
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
        int number = 0;
        std::cin >> number;
        for(;number > 0; number--)
            std::cout << number << std::endl;
        
    }   

public:
    Desafio15()
    {
        mark = "****************";
    }
    // Métodos DesafioX
    void SubDesafio1()
    {
        methodUITemplate("1", std::bind(&Desafio15::Desafio1Callback, this));
    }

    void Ejecutar()
    {
        std::vector<std::function<void()>> metodos = {
            std::bind(&Desafio15::SubDesafio1, this)
            //,std::bind(&Desafio14::SubDesafio2, this)
            };

        for (auto &metodo : metodos)
        {
            metodo();
        }
    }
};
int main()
{
    Desafio15 d3;
    d3.Ejecutar();
    return 0;
}