#include <iostream>
using namespace std;

int main ( ) {
    // arreglo estatico
    // int arreglo[5] = {11, 12, 13, 14, 15}; 
  /*
    int arreglo[5];
    arreglo[0] = 11;
    arreglo[1] = 12;
    arreglo[2] = 13;
    arreglo[3] = 14;
    arreglo[4] = 15;

    for (int i = 0; i < 5; i ++) {
        cout << arreglo[i] << endl;
    }
    for (int dato : arreglo) {
        cout << dato << endl;
    }
    for (int i = 0; i < sizeof(arreglo)/sizeof(int); i++){
        cout << arreglo[i] << endl;
    }

    int* arreglo_dinamico;
    int tamano = 5;
    arreglo_dinamico = new int[tamano];
    arreglo_dinamico[0] = 21;
    arreglo_dinamico[1] = 22;
    arreglo_dinamico[2] = 23;
    arreglo_dinamico[3] = 24;
    arreglo_dinamico[4] = 25;
    for (int i = 0; i < tamano; i++){
        cout << arreglo_dinamico[i] << endl; 
    }
    delete[] arreglo_dinamico;
*/
    int ren = 2;
    int col = 4;

    int** matriz;
    matriz = new int*[ren];
    for (int r = 0; r < ren; r++){
        matriz[r] = new int[col];
    }
    for (int i = 0; i < ren; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = i*col + j;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << *matriz << endl;
    for (int i = 0; i < ren; i++) {
        cout << matriz[i] << endl;
        for (int j = 0; j < col; j++) {
            cout << &matriz[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}