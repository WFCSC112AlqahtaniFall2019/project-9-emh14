#include <iostream>
#include <fstream>
#include "Data.h"
#include <vector>

using namespace std;

//Different sorting algorithm functions

//Bubble Sort from slides
template<typename T>
void bubbleSort(vector<T> &arr, int size) {
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
    }
}

//Selection Sort from slides (min to max)
template<typename T>
void MinSort(vector<T> &arr, int size) {
    int min;
    for (int i = 0; i < size - 1; ++i) {
// Find index of smallest remaining element
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

//Quick Sort (and Partition) from ZyBooks
template<typename T>
int Partition(T numbers[], int i, int k) {
    int l;
    int h;
    int midpoint;
    int pivot;
    int temp;
    bool done;

    //Pick middle element as pivot
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    done = false;
    l = i;
    h = k;

    while (!done) {

        //Increment l while numbers[l] < pivot
        while (numbers[l] < pivot) {
            ++l;
        }

        //Decrement h while pivot < numbers[h]
        while (pivot < numbers[h]) {
            --h;
        }

        //If there are zero or one elements remaining, all numbers are partitioned. Return h
        if (l >= h) {
            done = true;
        } else {
            //Swap numbers[l] and numbers[h], update l and h
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }
    return h;
}

template<typename T>
void Quicksort(T numbers[], int i, int k) {
    int j;

    //Base case: If there are 1 or zero elements to sort, partition is already sorted
    if (i >= k) {
        return;
    }

    //Partition the data within the array. Value j returned from partitioning is location of last element in low partition
    j = Partition(numbers, i, k);

    //Recursively sort low partition (i to j) and high partition (j + 1 to k)
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
}

//Merge Sort from ZyBooks
template<typename T>
void Merge(T numbers[], int i, int j, int k) {
    int mergedSize; // Size of merged partition
    int mergePos; // Position to insert merged number
    int leftPos; // Position of elements in left partition
    int rightPos; // Position of elements in right partition
    int *mergedNumbers = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i; // Initialize left partition position
    rightPos = j + 1; // Initialize right partition position
    mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary array for merged numbers

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        } else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;

        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
    delete[] mergedNumbers;
}

template<typename T>
void MergeSort(T numbers[], int i, int k) {
    int j;

    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(numbers, i, j, k);
    }
}


int main() {

    //Create all the vectors
    vector<Data> dataV;

    //Four copies of dataV
    vector<Data> dataV_B;
    vector<Data> dataV_S;
    vector<Data> dataV_Q;
    vector<Data> dataV_M;

    //vector of random integers
    vector<int> intV;

    //Four copies of intV
    vector<int> intV_B;
    vector<int> intV_S;
    vector<int> intV_Q;
    vector<int> intV_M;


    //declare fstream type variables
    ifstream dataFile;

    //Link csv file
    dataFile.open("../TaxiData.csv");
    if (!dataFile.is_open()) {
        cout << "File not open!" << endl;
        return 1;
    } else {
        cout << "Reading TaxiData.csv..." << endl;
    }

    //read the file by each variable line
    while (!dataFile.eof()) {

        string mileString;
        getline(dataFile, mileString, ',');

        string durationString;
        getline(dataFile, durationString, ',');

        string priceString;
        getline(dataFile, priceString, ',');

        string payment;
        getline(dataFile, payment);

        //Convert from strings to correct data type
        double mile = stod(mileString);
        int duration = stoi(durationString);
        double price = stod(priceString);


        //Stores each item in to a Data class object
        Data newData = Data(mile, duration, price, payment);

        //Repeatedly places the Data objects into a vector
        dataV.emplace_back(newData);
    }

    return 0;
}