#include <iostream>
#include <string>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

using namespace std;


const int totalParams = 3;

const char suma = '+';
const char resta = '-';
const char multiplicacion = '*';
const char division = '/';

float sumar(float num1, float num2){
    return num1 + num2;
}

float restar(float num1, float num2){
    return num1 - num2;
}

float multiplicar(float num1, float num2){
    return num1 * num2;
}

float dividir(float num1, float num2){
    return num1 / num2;
}

int main(){
    setlocale(LC_ALL, "");
    bindtextdomain("calculadora", "lang");
    textdomain("calculadora");
    float num1;
    char op;
    float num2;
    do{
        cout <<  _("Introduce un numero, el simbolo de operacion y otro numero, separados por espacios: ") << endl;
        cin >> num1;
        cin >> op;
        cin >> num2;

        switch(op){
            case suma: cout << _("Resultado: ") << sumar(num1, num2) << endl; break;
            case resta: cout << _("Resultado: ") << restar(num1, num2) << endl; break;
            case multiplicacion: cout << _("Resultado: ") << multiplicar(num1, num2) << endl; break;
            case division: cout << _("Resultado: ") << dividir(num1, num2) << endl; break;
            default: cout << _("Error. El simbolo de operacion no es valido") << endl;
        }
        cout << _("Operacion terminada. Comenzando otra operacion...") << endl;
    
    }while (true);
}
