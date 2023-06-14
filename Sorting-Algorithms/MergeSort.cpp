/** MERGE SORT INFORMATION
 * Space Complexity: O(n)
 * 
 * Best Case Time Complexity: O(nlogn)
 * Average Case Time Complexity: O(nlogn)
 * Worst Case Time Complexity: O(nlogn)
 * 
 * Stability: Yes
 * 
 * How it works . . .
 *  - Divides the unsorted list into two halves, the middle of each of these halves are found and then split into two as well.
 *      - This is repeated until each split results in sub-lists of size one (hence each sub-list is sorted)
 *  - Each sub-list is then re-merged and sorted together as they are merged.
 *      - This is done until we are back to a single list that is now sorted
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

void merge(int A[], int lower, int mid, int upper) {
  int Z1 = mid - lower + 1;
	int Z2 = upper - mid;
	int *upp = new int[Z1];
	int *low = new int[Z2];

	for(int i = 0; i < Z1; i++) {
		upp[i] = A[lower + i];
	}
	for(int j = 0; j < Z2; j++) {
		low[j] = A[mid + 1 + j];
	}
	
	int i = 0;
	int j = 0;
	int n = lower;
	while(i < Z1 && j < Z2) {
		if(upp[i] <= low[j]) {
			A[n] = upp[i];
			i++;
			n++;
		} else {
			A[n] = low[j];
			j++;
			n++;
		}
	}
	while(i < Z1) {
		A[n] = upp[i];
		i++;
		n++;
	}
	while(j < Z2) {
		A[n] = low[j];
		j++;
		n++;
	}
}

void mergeSort(int A[], int lower, int upper) {
    if(lower >= upper)
		return;

	int mid = lower + (upper - lower) / 2;
	
	mergeSort(A, lower, mid);
	mergeSort(A, mid + 1, upper);
	merge(A, lower, mid, upper);
}

int main(int argc, char * argv[]) { 
    int *arr;
    arr = insertRandVals();

    auto startTime = chrono::system_clock::now();
    mergeSort(arr, 0, arrSize - 1);
    auto endTime = chrono::system_clock::now();

    // Use only for seeing if the sorting algorithm works
    //printList(arr);

    chrono::duration<double> elapsedTime = endTime - startTime;

    cout << "MergeSort total elapsed time: " << elapsedTime.count() << " seconds.\n";
}
