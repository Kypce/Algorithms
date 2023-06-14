/** BUBBLE SORT INFORMATION
 * Space Complexity: O(1)
 * 
 * Best Case Time Complexity: O(n)
 * Average Case Time Complexity: O(n^2)
 * Worst Case Time Complexity: O(n^2)
 * 
 * Stability: Yes
 * 
 * How it works . . .
 *  - Compares adjacent indices in the array "bubbling" up the largest of the two indices up the array
 *      - This process is repeated until the entire array is sorted
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

void swap(int &a, int &b) { 
    int temp = a;
    a = b;
    b = temp; 
}
       
void bubbleSort(int A[], int N) { 
    for(int i = N; i > 1; i -= 1) { 
        for(int j = 0; j < i - 1; j += 1) { 
            if(A[j] > A[j+1]) { 
                swap(A[j], A[j+1]); 
            } 
        } 
    } 
}        
               
int main(int argc, char * argv[]) { 
    int *arr;
    arr = insertRandVals();

    auto startTime = chrono::system_clock::now();
    bubbleSort(arr, arrSize);
    auto endTime = chrono::system_clock::now();

    // Use only for seeing if the sorting algorithm works
    //printList(arr);

    chrono::duration<double> elapsedTime = endTime - startTime;

    cout << "BubbleSort total elapsed time: " << elapsedTime.count() << " seconds.\n";
}
