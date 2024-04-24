#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    virtual void ejecutar()
    {
        cout << "opcion no valida" << endl;
    }
};

class Parte2 : public Base
{
public:
    virtual void ejecutar() override
    {
        string nombre = "";
        string puesto = "";
        int experiencia = 0;
        int horas = 0;
        bool continuar = false;
        do
        {
            cout << "ingrese el nombre: ";
            cin >> nombre;

            cout << "ingrese el puesto: ";
            cin >> puesto;

            cout << "ingrese la cantidad de experiencia: ";
            cin >> experiencia;

            cout << "ingrese las horas laboradas: ";
            cin >> horas;

            float salarioBase = 0;
            float bono = 0;
            float salarioNeto = 0;

            salarioBase = calculoSalarioBase(puesto, horas);
            bono = puesto == "Consultor" ? 0 : calcularBono(experiencia, puesto, salarioBase);

            salarioNeto = puesto == "Consultor" ? salarioBase : calcularSalarioNeto(salarioBase, bono);

            cout << "Salario Base: " << salarioBase << endl;
            cout << "Bono: " << bono << endl;
            cout << "Salario Neto: " << salarioNeto << endl;

            int continuar_I;
            cout << "¿Desea procesar otro trabajador? (1 para si)" << endl;
            cin >> continuar_I;
            continuar = continuar_I == 1;
        } while (continuar);
    }

private:
    float montoBase(string puesto)
    {
        float resultado = 0;
        switch (puesto[0])
        {
        case 'O': // Use en el examen "
            resultado = 520000;
            break;
        case 'P': // Use en el examen "
            resultado = 1800000;
            break;
        case 'J': // Use en el examen "
            resultado = 2500000;
            break;
        case 'C': // Use en el examen "
            resultado = 10000;
            break;
        }
        return resultado;
    }

    float calculoSalarioBase(string puesto, int horas)
    {
        int resultado = 0;
        float salarioBase = montoBase(puesto);
        // resultado = puesto == "Consultor" ? horas * salarioBase : salarioBase / 100;
        resultado = horas * (puesto == "Consultor" ? salarioBase : salarioBase / 48); // Correcion;
        return resultado;
    }
    float calcularBono(int experiencia, string puesto, float salarioBase)
    {
        int porcentaje = 0;
        float resultado = 0;
        if ((puesto == "Consultor") || (experiencia < 5) == false)
        {

            if (experiencia <= 10)
                porcentaje = 5;
            else
                porcentaje = experiencia <= 20 ? 15 : 20;
        }
        if (resultado > 0)
            resultado = salarioBase / 100 * porcentaje;
        return resultado;
    }
    float calcularSalarioNeto(float salarioBase, float bono)
    {
        float ccss = 9;
        float pRenta1 = 5;
        float pRenta2 = 15;
        float pRenta3 = 20;
        float renta = 0;
        float rentaBase1 = 600000;
        float rentaBase2 = 1000000;
        float rentaBase3 = 2000000;
        float porcentajeRentaRetener = 0;

        float baseImponible = salarioBase + bono;
        float decucciones = baseImponible / 100 * ccss;
        if (!(baseImponible < rentaBase1))
        {
            if (baseImponible < rentaBase2)
                porcentajeRentaRetener = pRenta1;
            else
                porcentajeRentaRetener = baseImponible <= rentaBase2 ? pRenta2 : pRenta3;
        }
        decucciones += baseImponible / 100 * porcentajeRentaRetener;
        return baseImponible - decucciones;
    }
};

class Parte3 : public Base
{
public:
    virtual void ejecutar() override
    {
        int continuar = 0;
        do
        {
            int valor = 0;
            int valor1 = 0;
            cout << "valor ha verificar: ";
            cin >> valor;
            cout << "el valor " << valor << " es binario:" << (verificarBinario(valor) ? "si" : "no") << endl;

            cout << "valor1 ha verificar: ";
            cin >> valor;
            cout << "valor2 ha verificar: ";
            cin >> valor1;
            cout << "el and de valor1  y valor2 es:" << andBinario(valor,valor1)<< endl;

            cout << "1 para continuar" << endl;
            cin >> continuar;

        } while (continuar == 1);
    }

private:
    bool verificarBinario(int numero)
    {
        bool resultado = false;
        if (numero < 0)
            numero *= -1;

        if (numero <= 1)
            resultado = true;
        else
        {
            if (numero >= 10)
            {
                //resultado = verificarBinario(numero/10); linea que puse en el examen
                //Correccion inicio
               int digito = numero % 10;
                if (verificarBinario(digito))
                {
                    numero /= 10;
                    resultado = verificarBinario(numero);
                }
                //Correccion no
            }
        }
        return resultado;
    }
    int andBinario(int numero1, int numero2){
        int resultado =0;
        int post = 1;

        while (numero1>0 && numero2>0){
            int digito1 = numero1 % 10;
            int digito2 = numero2 % 10;
            numero1 /= 10;
            numero2 /= 10;
            int valor = (digito1 ==digito2) && (digito1==1) ? 1:0;
            if(valor)
                resultado = post+resultado;
                post*=10;
        }
        return resultado;
    }
};

int main()
{
    int continuar = 0;
    do
    {
        Base *parteEjecutar = new Base();
        int parte = 0;

        cout << "cual ejercicio ejecutar, 2 o 3 ? ";
        cin >> parte;

        switch (parte)
        {
        case 2:
            parteEjecutar = new Parte2();
            break;
        case 3:
            parteEjecutar = new Parte3();
            break;
        }

        parteEjecutar->ejecutar();

        cout << "1 para continuar" << endl;

        cin >> continuar;
    } while (continuar == 1);

    return 0;
}