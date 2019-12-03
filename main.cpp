#include <iostream>
#include <fstream>
#include "Data.h"
#include <vector>
#include <cassert>

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
                swap(arr[j], arr[j + 1]);
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
int Partition(vector<T> &numbers, int i, int k) {
    int l;
    int h;
    int midpoint;
    Data pivot;
    Data temp;
    bool done;

    //Pick middle element as pivot
    midpoint = i + (k - i) / 2;
    //pivot = numbers.at(midpoint);

    done = false;
    l = i;
    h = k;

    while (!done) {

        //Increment l while numbers[l] < pivot
        //while (numbers.at(l) < pivot) {
        while (numbers.at(l) < numbers.at(midpoint)) {
            ++l;
        }

        //Decrement h while pivot < numbers[h]
        //while (pivot < numbers.at(h)) {
        while (numbers.at(midpoint) < numbers.at(h)) {
            --h;
        }

        //If there are zero or one elements remaining, all numbers are partitioned. Return h
        if (l >= h) {
            done = true;
        } else {
            //Swap numbers[l] and numbers[h], update l and h
            swap(numbers.at(l), numbers.at(h));
            /*temp = numbers.at(l);
            numbers.at(l) = numbers.at(h);
            numbers.at(h) = temp;*/

            ++l;
            --h;
        }
    }
    return h;
}

template<typename T>
void Quicksort(vector<T> &numbers, int i, int k) {
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
void Merge(vector<T> &numbers, int i, int j, int k) {

    int mergedSize; // Size of merged partition
    int mergePos; // Position to insert merged number
    int leftPos; // Position of elements in left partition
    int rightPos; // Position of elements in right partition
    //int *mergedNumbers = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i; // Initialize left partition position
    rightPos = j + 1; // Initialize right partition position
    //mergedNumbers = vector<int> (mergedSize); // Dynamically allocates temporary array for merged numbers
    vector<T> mergedNumbers(mergedSize);

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers.at(mergePos) = numbers.at(leftPos);
            ++leftPos;
        } else {
            mergedNumbers.at(mergePos) = numbers.at(rightPos);
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
    //delete[] mergedNumbers;
}

template<typename T>
void MergeSort(vector<T> &numbers, int i, int k) {
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

    //Create new vectors
    vector<Data> dataV;
    vector<int> intV;

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
        double duration = stod(durationString);
        double price = stod(priceString);


        //Stores each item in to a Data class object
        Data newData = Data(mile, duration, price, payment);

        //Repeatedly places the Data objects into a vector
        dataV.push_back(newData);
    }

    //Four copies of dataV
    vector<Data> dataV_B = dataV;
    vector<Data> dataV_S = dataV;
    vector<Data> dataV_Q = dataV;
    vector<Data> dataV_M = dataV;


    srand(time(NULL)); // seed random number generator with time

    //fill vector with random integers
    for (int i = 0; i < intV.size(); i++) {
        intV[i] = rand() % 100;
    }

    //Four copies of intV
    vector<int> intV_B = intV;
    vector<int> intV_S = intV;
    vector<int> intV_Q = intV;
    vector<int> intV_M = intV;

    //sort the vectors using the implemented algorithms
    cout << "Sorting..." << endl;
    //Bubble Sort

    cout << "Bubble..." << endl;
    bubbleSort(dataV_B, dataV_B.size());
    bubbleSort(intV_B, intV_B.size());

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_B.size() - 1; i++) {
        assert(dataV_B.at(i - 1) <= dataV_B.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_B.size() - 1; i++) {
        assert(intV_B.at(i - 1) <= intV_B.at(i));
    }
    cout << "Bubble Done." << endl;


    //Selection Sort
    cout << "Selection..." << endl;
    MinSort(dataV_S, dataV_S.size());
    MinSort(intV_S, intV_S.size());

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_S.size() - 1; i++) {
        assert(dataV_S.at(i - 1) <= dataV_S.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_S.size() - 1; i++) {
        assert(intV_S.at(i - 1) <= intV_S.at(i));
    }
    cout << "Selection Done." << endl;

    //Quick Sort
    cout << "Quick..." << endl;
    Quicksort(dataV_Q, 0, dataV_Q.size() - 1);
    Quicksort(intV_Q, 0, intV_Q.size() - 1);

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_Q.size() - 1; i++) {
        assert(dataV_Q.at(i - 1) <= dataV_Q.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_Q.size() - 1; i++) {
        assert(intV_Q.at(i - 1) <= intV_Q.at(i));
    }
    cout << "Quick Done." << endl;

    //Merge Sort
    cout << "Merge..." << endl;
    MergeSort(dataV_M, 0, dataV_M.size() - 1);
    MergeSort(intV_M, 0, intV_M.size() - 1);

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_M.size() - 1; i++) {
        assert(dataV_M.at(i - 1) <= dataV_M.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_M.size() - 1; i++) {
        assert(intV_M.at(i - 1) <= intV_M.at(i));
    }
    cout << "Merge Done." << endl;

    cout << "First Round Done." << endl << endl;

    //Re-sorts the sorted vectors again by the same set of algorithms
    cout << "Re-Sorting..." << endl;
    //Bubble Sort
    cout << "Bubble..." << endl;
    bubbleSort(dataV_B, dataV_B.size());
    bubbleSort(intV_B, intV_B.size());

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_B.size() - 1; i++) {
        assert(dataV_B.at(i - 1) <= dataV_B.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_B.size() - 1; i++) {
        assert(intV_B.at(i - 1) <= intV_B.at(i));
    }
    cout << "Bubble Done." << endl;


    //Selection Sort
    cout << "Selection..." << endl;
    MinSort(dataV_S, dataV_S.size());
    MinSort(intV_S, intV_S.size());

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_S.size() - 1; i++) {
        assert(dataV_S.at(i - 1) <= dataV_S.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_S.size() - 1; i++) {
        assert(intV_S.at(i - 1) <= intV_S.at(i));
    }
    cout << "Selection Done." << endl;

    //Quick Sort
    cout << "Quick..." << endl;
    Quicksort(dataV_Q, 0, dataV_Q.size() - 1);
    Quicksort(intV_Q, 0, intV_Q.size() - 1);

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_Q.size() - 1; i++) {
        assert(dataV_Q.at(i - 1) <= dataV_Q.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_Q.size() - 1; i++) {
        assert(intV_Q.at(i - 1) <= intV_Q.at(i));
    }
    cout << "Quick Done." << endl;

    //Merge Sort
    cout << "Merge..." << endl;
    MergeSort(dataV_M, 0, dataV_M.size() - 1);
    MergeSort(intV_M, 0, intV_M.size() - 1);

    //Unit Test to make sure is sorted
    for(int i = 1; i < dataV_M.size() - 1; i++) {
        assert(dataV_M.at(i - 1) <= dataV_M.at(i));
    }
    //Unit Test to make sure is sorted
    for(int i = 1; i < intV_M.size() - 1; i++) {
        assert(intV_M.at(i - 1) <= intV_M.at(i));
    }
    cout << "Merge Done." << endl;

    cout << "Second Round Done." << endl;

    return 0;
}

