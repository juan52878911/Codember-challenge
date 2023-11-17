#include <iostream>
#include <string>

using namespace std;

// Declaramos la variable que contendra el string a cifrar
string challenge = "&###@&*&###@@##@##&######@@#####@#@#@#@##@@@@@@@@@@@@@@@*&&@@@@@@@@@####@@@@@@@@@#########&#&##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@&";

int main() {
    // Recorremos el vector en busca de los siguientes simbolos
    // "#" Incrementa el valor numérico en 1.
    // "@" Decrementa el valor numérico en 1.
    // "*" Multiplica el valor numérico por sí mismo.
    // "&" Imprime el valor numérico actual.

    // Declaramos la variable que contendra el valor numerico
    int number = 0;

    // Recorremos el string
    for (int i = 0; i < challenge.length(); i++) {
        // Si el caracter actual no es un numero, verificamos si es un simbolo
        switch (challenge[i]) {
            case '#':
                // Si el caracter actual es un simbolo, verificamos que simbolo es y realizamos la operacion correspondiente
                number++;
                break;
            case '@':
                number--;
                break;
            case '*':
                number *= number;
                break;
            case '&':
                cout << number;
                break;
        }
    }

    return 0;
}