#include <iostream>
#include <fstream>
#include <memory.h>
#include "binaryQuickSort.h"
#include <istream>

using namespace std;

int main() {
    fillFile("test1.txt", 100);
    fillFile("test2.txt", 1000);
    fillFile("test3.txt", 10000);

    auto* arr = new unsigned short[10000];
    int size = readFile(arr, "test1.txt");

    ofstream out("output1.txt");

    binQuickSort(arr, 0, size-1, sizeof(unsigned short)*8-1);

    printArr(arr, size);

    for (int i=0; i<size; i++) {
        out << arr[i] << " ";
    }
    out.close();

    size = readFile(arr, "test2.txt");

    ofstream out2("output2.txt");

    binQuickSort(arr, 0, size-1, sizeof(unsigned short)*8-1);

    printArr(arr, size);

    for (int i=0; i<size; i++) {
        out2 << arr[i] << " ";
    }
    out2.close();

    size = readFile(arr, "test3.txt");

    ofstream out3("output3.txt");

    binQuickSort(arr, 0, size-1, sizeof(unsigned short)*8-1);

    printArr(arr, size);

    for (int i=0; i<size; i++) {
        out3 << arr[i] << " ";
    }
    out3.close();
}
