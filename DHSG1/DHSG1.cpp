// DHSG1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

using namespace std;

void writeFile(char path[],int a[],size_t n) {
    FILE* fp;
    fopen_s(&fp, path, "wb");

    if (fp == NULL) {
        cout << "Unable to open file" << endl;
        exit(0);
    }

    // insert arr

    fwrite(a, sizeof(int), n, fp);

    // insert each elem of arr

    /*for (size_t i = 0; i < n; i++)
        fwrite(&a[i], sizeof(int), 1, fp);*/

    fclose(fp);
}

void readFile(char path[],size_t n) {
    // read file
    FILE* fp;
    fopen_s(&fp, path, "rb");

    if (fp == NULL) {
        cout << "Unable to open file" << endl;
        exit(0);
    }

    // static array
    
    // int arr[MAXN];
    // fread(&arr, sizeof(int), n, fp);

    // dynamic array
    n = 0;

    // finding how many numbers in file
    // method 1

    int tmp;
    while (!feof(fp)) {
        fread(&tmp, sizeof(int), 1, fp);
        n++;
    }
    rewind(fp);
    n--;

    // method 2

    //fseek(fp, 0, SEEK_END);
    //size_t fsize = ftell(fp);
    //rewind(fp);
    //n = fsize / sizeof(int);

    // dynamic array
    // 
    // method 1

    /*int* arr;
    arr = new int[n];*/

    // method 2

    int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        cout << "Not enough memory" << endl;
        exit(0);
    }

    fread(arr, sizeof(int), n, fp);

    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";

    //
    fclose(fp);
}

int main()
{
    size_t n = 5;
    // static array
    
    // int a[MAXN] = { 14,23,52,41,33 };
    
    // dynamic array
    //
    // method 1
    /*int* a;
    a = new int[n] {14, 23, 46, 98, 142};*/

    // method 2
    int* a = (int*)malloc(n * sizeof(int));

    if (a == NULL) {
        cout << "Not enough memory" << endl;
        exit(0);
    }

    // method 2 only
    for (int i = 0; i < n; i++)
    {
        a[i] = (i + 1) * 6;
    }

    char path[] = "D:\\_____SGU IT Dept\\File & Dynamic Array\\data.bin";

    writeFile(path, a, n);
    readFile(path,n);

    cout << endl;
    cout << "End of program." << endl;
}
