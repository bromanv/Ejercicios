// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std ;

class Utils
{
public:
    void println(std::string message)
    {
        std::cout << message << std::endl;
    }
};
class Desafio11
{
private:
    Utils myUtils;
    std::string mark;
    void header(std::string message)
    {
        myUtils.println(mark);
        myUtils.println("Ejecutando Desafio 11." + message + ".");
    }
    void footer(std::string message)
    {
        myUtils.println("Desafio 11." + message + " ejecutado.");
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
        int employeeNumber = 0;
        int workedHours = 0;
        double hourlyRate = 0;
        double salary = 0;

        //std::cout << "Numero de empleadp: ";
        std::cin >> employeeNumber;
        //std::cout << "Horas laboradas al mes: ";
        std::cin >> workedHours;
        //std::cout << "Salario por hora: ";
        std::cin >> hourlyRate;

        salary = workedHours * hourlyRate;

        std::cout << "NUMBER = " << employeeNumber << std::endl;
        std::cout << fixed << setprecision(2);
        std::cout << "SALARY = U$ " << salary << std::endl;
    }

    void Desafio2Callback()
    {
        std::string sellerName;
        double fixedSalary = 0; 
        double totalSales = 0;
        double finalSalary = 0;
        
        //cout << "Nombre del vendedor: ";
        getline(cin, sellerName);
        //cout << "Salario fijo: ";
        std::cin >> fixedSalary;
        //cout << "Monto total vendido: ";
        std::cin >> totalSales;
        
        finalSalary = fixedSalary + (totalSales * 0.15);

        std::cout << fixed << setprecision(2);
        std::cout << "TOTAL = R$ " << finalSalary << std::endl;
    }

    void Desafio3Callback()
    {
        int a  = 0;
        int b  = 0;
        int c  = 0;
        int maiorAB = 0;
        int maior = 0;
        cin >> a >> b >> c;
        maiorAB = (a + b + abs(a - b)) / 2;
        maior = (maiorAB + c + abs(maiorAB - c)) / 2;
        cout << maior << " eh o maior" << endl;
    }

    void Desafio4Callback()
    {
        double x1 = 0; 
        double y1 = 0; 
        double x2 = 0; 
        double y2 = 0; 
        double distance = 0;
        
        //cout << "p1 (x1 y1): ";
        cin >> x1 >> y1;
        //cout << "p2 (x2 y2): ";
        cin >> x2 >> y2;
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        cout << fixed << setprecision(4);
        //cout << "Distance = " << distance << endl;
        cout << distance << endl;

    }

    void Desafio5Callback()
    {
        int spentTime = 0;
        int averageSpeed = 0;
        double distance = 0;
        double fuelNeeded = 0;

        cin >> spentTime >> averageSpeed;

        distance = spentTime * averageSpeed;
        fuelNeeded = distance / 12.0;

        cout << fixed << setprecision(3) << fuelNeeded << endl;
    }


public:
    Desafio11()
    {
        mark = "****************";
    }
    // Métodos DesafioX
    void SubDesafio1()
    {
        methodUITemplate("1", std::bind(&Desafio11::Desafio1Callback, this));
    }

    void SubDesafio2()
    {
        methodUITemplate("2", std::bind(&Desafio11::Desafio2Callback, this));
    }

    void SubDesafio3()
    {
        methodUITemplate("3", std::bind(&Desafio11::Desafio3Callback, this));
    }

    void SubDesafio4()
    {
        methodUITemplate("4", std::bind(&Desafio11::Desafio4Callback, this));
    }

    void SubDesafio5()
    {
        methodUITemplate("5", std::bind(&Desafio11::Desafio5Callback, this));
    }
    
    void Ejecutar()
    {
        std::vector<std::function<void()>> metodos = {
            std::bind(&Desafio11::SubDesafio1, this),
            std::bind(&Desafio11::SubDesafio2, this),
            std::bind(&Desafio11::SubDesafio3, this),
            std::bind(&Desafio11::SubDesafio4, this),
            std::bind(&Desafio11::SubDesafio5, this)
        };

        for (auto &metodo : metodos)
        {
            metodo();
        }
    }
};
int main()
{
    Desafio11 d3;
    d3.Ejecutar();
    return 0;
}