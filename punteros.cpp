#include <iostream>

using namespace std;

int main() {
    int numero = 8;
    int* aptNumero = &numero;
    cout    << "Numero " << numero << "\n"
            << "Donde vive numero " << &numero << "\n"
            << "\n\n\n";
    cout    << "Apuntador " << aptNumero << "\n"
            << "Donde vide aptNumero " << &aptNumero << "\n"
            << "Cruzando el puente " << *aptNumero << endl;
    *aptNumero = 88;

    cout    << "Numero " << numero << "\n"
    << "Donde vive numero " << &numero << "\n"
    << "\n\n\n";
    cout    << "Apuntador " << aptNumero << "\n"
    << "Donde vide aptNumero " << &aptNumero << "\n"
    << "Cruzando el puente " << *aptNumero << endl;


    return 0;
}
