#include "Sorts.h"

void swap(int primero, int segundo){
    int temporal = primero;
    primero = segundo;
    segundo = temporal;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n ;i++){
        int clave = arr[i];
        int j = j = i -1;
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

void mergeSort(int arr[], int n){

}

void heapSort(){

}

void quickSort(){

}