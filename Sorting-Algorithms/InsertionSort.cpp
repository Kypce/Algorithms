/** INSERTION SORT INFORMATION
 * Space Complexity: O(1)
 * 
 * Best Case Time Complexity: O(n)
 * Average Case Time Complexity: O(n^2)
 * Worst Case Time Complexity: O(n^2)
 * 
 * Stability: Yes
 * 
 * How it works . . .
 *  - The array will be split into two regions (sorted and unsorted). The entire array will be searched through for the current minimum.
 *      - It will then put the current minimum into the current position in sorted section
 *      - This process is repeated until the entire array is sorted.
*/

#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <iostream>
               
using namespace std;

// Adjust as wanted to set the array size or the seed for inputting values
// If testing multiple sortings to compare, USE THE SAME SEED FOR ALL OF THEM
int const static arrSize = 50000;
int const static seed = ((unsigned)time(NULL));

// Used to insert values into array
int *insertRandVals() {
    int static arr[arrSize];

    srand(seed);

    for(int i = 0; i < arrSize; i++)
        arr[i] = rand();

    return arr;
}

// Used to test if the sorting algorithm is working
void printList(int A[]) {
    for(int i = 0; i < arrSize; i++) {
        if(i % 10 == 0)
            cout << "\n";
        cout << A[i] << " ";
    }

    cout << "\n\n";
}

void insertionSort(int A[], int size) {
    int key;
    int j;

    for(int i = 0; i < size; i++) {
        key = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j -= 1;
        }

        A[j + 1] = key;
    }
}

int main(int argc, char * argv[]) { 
    int *arr;
    arr = insertRandVals();

    auto startTime = chrono::system_clock::now();
    insertionSort(arr, arrSize);
    auto endTime = chrono::system_clock::now();

    // Use only for seeing if the sorting algorithm works
    //printList(arr);

    chrono::duration<double> elapsedTime = endTime - startTime;

    cout << "SelectionSort total elapsed time: " << elapsedTime.count() << " seconds.\n";
}
