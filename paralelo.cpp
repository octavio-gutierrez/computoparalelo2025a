#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    cout << "Inicio region paralela" << endl;
    omp_set_num_threads(4);
    int thread_id = 0;
    #pragma omp parallel private(thread_id)  
    {
        thread_id = omp_get_thread_num();
        cout << "Hola soy el Hilo " << thread_id << endl;

        // solo el maestro evaluara TRUE
        if (thread_id == 0) {
            int num_threads = omp_get_num_threads();
            cout << "Hay " << num_threads << " hilos" << endl;
        }


    }
    cout << "Inicia region serial nuevamente" << endl; 


    return 0;
}
