#include <iostream>
#include <omp.h>

using namespace std;

int main() {

    int tamano = 1000000000;

    int* a;
    int* b;
    int* c;
    a = new int[tamano];
    b = new int[tamano];
    c = new int[tamano];
    
	for (int i = 0; i < tamano; i++) {
        a[i] = b[i] = i * 1.0;
    }

    int num_threads[4] = {1, 3, 6, 12};
    int chunk_sizes[9] = {1, 10, 20, 40, 80, 160, 320, 640, 1280};


    double tiempo_inicio = omp_get_wtime();
    for (int i=0; i < tamano; i++) {
            c[i] = a[i] + b[i];
    }
    double tiempo_final = omp_get_wtime();
    double serial_time = tiempo_final - tiempo_inicio;
    cout << "Simple for " << 1 << " " << tiempo_final - tiempo_inicio << endl;        

    for (int num_thread : num_threads) {
        omp_set_num_threads(num_thread);
        int thread_id = 0;
        double tiempo_inicio = omp_get_wtime();
        #pragma omp parallel for 
        for (int i=0; i < tamano; i++) {
                c[i] = a[i] + b[i];
        }
        double tiempo_final = omp_get_wtime();
        cout << "Simple parallel for " << num_thread << " " << serial_time/(tiempo_final - tiempo_inicio) << endl;    
    }
    for (int num_thread : num_threads) { 
        omp_set_num_threads(num_thread);
        for (int chunk_size : chunk_sizes) {
            int thread_id = 0;
            double tiempo_inicio = omp_get_wtime();
            #pragma omp parallel for schedule(dynamic, chunk_size) 
            for (int i=0; i < tamano; i++) {
                    c[i] = a[i] + b[i];
            }
            double tiempo_final = omp_get_wtime();
            cout << "Dynamic schedule for " << num_thread <<  " " << chunk_size << " " << serial_time/(tiempo_final - tiempo_inicio) << endl;    
        }    
            
    }
    for (int num_thread : num_threads) {
        omp_set_num_threads(num_thread);
        for (int chunk_size : chunk_sizes) {
            int thread_id = 0;
            double tiempo_inicio = omp_get_wtime();
            #pragma omp parallel for schedule(static, chunk_size) 
            for (int i=0; i < tamano; i++) {
                    c[i] = a[i] + b[i];
            }
            double tiempo_final = omp_get_wtime();
            cout << "Static schedule for " << num_thread <<  " " << chunk_size << " " << serial_time/(tiempo_final - tiempo_inicio) << endl;    
        }    
    }






    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
