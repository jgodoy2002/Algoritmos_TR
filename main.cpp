#include <iostream>
#include <cstdlib>
#include <chrono>
#include "Sorts.h"
using namespace std;

int main() {
    srand(42);

    int tamanos[] = {100, 1000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000};
    int cantidad = 9;
    int limiteLentos = 200000;

    int opcion;
    cout << "===== ALGORITMOS DE ORDENAMIENTO =====" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Heap Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    if (opcion < 1 || opcion > 6) {
        cout << "Opcion no valida" << endl;
        return 0;
    }

    for (int t = 0; t < cantidad; t++) {
        int n = tamanos[t];
        if (opcion <= 3 && n > limiteLentos) {
            cout << "Tamano " << n << ": saltado (muy lento)" << endl;
            continue;
        }
        int* arr = new int[n];
        srand(42);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        auto inicio = chrono::high_resolution_clock::now();

        if (opcion == 1) insertionSort(arr, n);
        if (opcion == 2) selectionSort(arr, n);
        if (opcion == 3) bubbleSort(arr, n);
        if (opcion == 4) mergeSort(arr, n);
        if (opcion == 5) heapSort(arr, n);
        if (opcion == 6) quickSort(arr, n);
        auto fin = chrono::high_resolution_clock::now();
        double ms = chrono::duration<double, milli>(fin - inicio).count();

        cout << "Tamano " << n << ": " << ms << " ms" << endl;

        delete[] arr;
    }

    return 0;
}
