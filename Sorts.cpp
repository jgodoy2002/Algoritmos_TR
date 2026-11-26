#include "Sorts.h"

void swap(int& primero, int& segundo){
    int temporal = primero;
    primero = segundo;
    segundo = temporal;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n ;i++){ 
        int clave = arr[i];
        int j = i -1;
        while(j >= 0 && arr[j] > clave){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=clave;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minimo = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minimo]) {
                minimo = j;
            }
        }
        swap(arr[i], arr[minimo]);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool cambio = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cambio = true;
            }
        }
        if(!cambio){
            break;
        }
    }
}

void mezclar(int arr[], int izq, int medio, int der){
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    int* izquierda = new int[n1];
    int* derecha = new int[n2];

    for (int i = 0; i < n1; i++){ 
        izquierda[i] = arr[izq + i];
    }
    for (int j = 0; j < n2; j++) {
        derecha[j] = arr[medio + 1 + j];
    }
    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) 
            arr[k++] = izquierda[i++];
        else                            
            arr[k++] = derecha[j++];
    }
    while (i < n1) 
        arr[k++] = izquierda[i++];
    while (j < n2) 
        arr[k++] = derecha[j++];

    delete[] izquierda;
    delete[] derecha;
}

void mergeSortRec(int arr[], int izq, int der) {
    if (izq >= der) return;
    int medio = izq + (der - izq) / 2;
    mergeSortRec(arr, izq, medio);
    mergeSortRec(arr, medio + 1, der);
    mezclar(arr, izq, medio, der);
}

void mergeSort(int arr[], int n){
    mergeSortRec(arr,0,n-1);
}

void heapify(int arr[], int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && arr[izq] > arr[mayor]) mayor = izq;
    if (der < n && arr[der] > arr[mayor]) mayor = der;

    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        heapify(arr, n, mayor);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int particion(int arr[], int bajo, int alto){
    int pivote = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if (arr[j] < pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[alto]);
    return i + 1;
}

void quickSortRec(int arr[], int bajo, int alto){
    if (bajo<alto){
        int p = particion(arr, bajo, alto);
        quickSortRec(arr, bajo, p-1);
        quickSortRec(arr,p+1,alto);
    }
}

void quickSort(int arr[], int n){
    quickSortRec(arr,0,n-1);
}

