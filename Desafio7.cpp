#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string nombre ="";
    string apellido1 ="";
    string apellido2 ="";
    cout<< "¡¡¡Buenos dias!!!"<<endl;
    cout<< "¿Cual es su primer apellido?"<<endl;
    cin>>apellido1;
    cout<< "¿Cual es su segundo apellido?"<<endl;
    cin>>apellido2;
    cout<< "¿Cual es su nombre?"<<endl;
    cin>>nombre;
    //muestra en pantalla un saludo personalizado con los datos ingresados por el usuario.
    cout<<nombre<<" "<<apellido1<<" "<<apellido2<<endl;

    return 0;
}
//permite recepcion de argumentos por linea de comandos
int main_transcrito(int argc, char *argv[]) {
    //declara una variable de tipo cadena de texto llamada nombre.
    string nombre ="";    
    //imprime en consola un saludo, y le pergrnta al usuario por su nombre y hace un salto de linea.
    cout<< "Buenos dias!!!  Cuál es tu nombre???"<<endl;
    //lee desde consola el los caracteres ingresados por el usuario y los guarda en la variable nombre,
    //el usuario debe presionar enter/salto de linea para completar el ingreso de valores.
    cin>>nombre;
    //muestra en pantalla un saludo personalizado con los datos ingresados por el usuario.
    cout<<"Hola "<<nombre<<"!! Espero que pases un buen día"<<endl;

    return 0;
}

