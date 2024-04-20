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
class Desafio14
{
private:
    Utils myUtils;
    std::string mark;
    void header(std::string message)
    {
        myUtils.println(mark);
        myUtils.println("Ejecutando Desafio 14." + message + ".");
    }
    void footer(std::string message)
    {
        myUtils.println("Desafio 14." + message + " ejecutado.");
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
        float a = 0;
        float b = 0;
        float c = 0;
        cin >> a >> b >> c;
        float notB = b * -1;
        float d = pow(b,2) - (4 * a * c);
        float x1 = 0;
        float x2 = 0;
        std::ostringstream oss;
        if (d > 0)
        {
            x1 = ((b * -1) + sqrt(d)) / a * 2;
            x2 = ((b * -1) - sqrt(d)) / a * 2;
            oss << "r1:" << x1;
            oss << "r2:" << x2;
        }
        else 
        if (d != 0){
            x1 = ((b * -1) + sqrt(d)) / a * 2;
               oss << "r1:" << x1;
        }
            else
               oss << "No tiene raíces reales";

        cout << oss.str();
    }   

public:
    Desafio14()
    {
        mark = "****************";
    }
    // Métodos DesafioX
    void SubDesafio1()
    {
        methodUITemplate("1", std::bind(&Desafio14::Desafio1Callback, this));
    }

    void Ejecutar()
    {
        std::vector<std::function<void()>> metodos = {
            std::bind(&Desafio14::SubDesafio1, this)
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
    Desafio14 d3;
    d3.Ejecutar();
    return 0;
}