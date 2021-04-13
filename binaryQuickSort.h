#ifndef LAB6_BINARYQUICKSORT_H
#define LAB6_BINARYQUICKSORT_H

#include <iostream>
#include <string.h>

void fillFile(char* fileName, int size) {
    std::ofstream out(fileName);
    if(!out.is_open())
        throw std::invalid_argument("Couldn't open this file");

    for (int i=0; i<size; i++) {
        out << rand()%10000+1 << " ";
    }

    out.close();
}

int readFile(unsigned short* arr, char* fileName) {
    int size = 0;
    memset(arr, 0, 10000);
    std::ifstream in(fileName);

    int elem;
    while(in >> elem) {
        arr[size] = elem;
        size++;
    }

    return size;
}

void printArr(unsigned short* arr, int size) {
    for (int i=0; i<size; i++) {
        std::cout << arr[i] << "; ";
    }
    std::cout << std::endl;
}

void binQuickSort(unsigned short* array, int begin, int end, int bitNum) {
    int i = begin, j = end;

    if (bitNum < 0 || i == j)
        return;

    while(i < j) {

        while(!(array[i] & (1u << bitNum)))
            i++;
        while(array[j] & (1u << bitNum))
            j--;

        if(i <= j) {
            unsigned short temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    binQuickSort(array, begin, j, bitNum - 1);
    binQuickSort(array, i, end, bitNum - 1);
}

#endif //LAB6_BINARYQUICKSORT_H
