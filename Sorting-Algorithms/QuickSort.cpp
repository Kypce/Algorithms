/** QUICK SORT INFORMATION
 * Space Complexity: O(logn)
 * 
 * Best Case Time Complexity: O(nlogn)
 * Average Case Time Complexity: O(nlogn)
 * Worst Case Time Complexity: O(n^2)
 * 
 * Stability: No
 * 
 * How it works . . .
 *  - A pivot element is randomly chosen (in this code's case) and the list is reordered so all elements to the left will be smaller 
 *    and all elements to the right will be larger
 *      - The quick sort algorithm will then recursivley be used on the two sublists. This process is repeated until a sublists contains fewer than two elements
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

// Randomly chooses the pivot position in the array
int random_value(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int partition(int A[], int min, int max) {
	int pivotpos = random_value(min, max);
	int pivot = A[pivotpos];

	swap(A[max], A[pivotpos]);
	
    int p = min;
	int q = min;

	while(p < max) {
		if(A[p] >= pivot)
			p+=1;
		else {
			swap(A[p], A[q]);
			p+=1;
			q+=1;
		}
	}

	swap(A[max], A[q]);
	return q;
}

void quickSort(int A[], int min, int max) {
    if((max - min) < 1)
		return;
    
	int p = partition(A, min, max);
	quickSort(A, min, p - 1);
	quickSort(A, p + 1, max);
}

int main(int argc, char * argv[]) { 
    int *arr;
    arr = insertRandVals();

    auto startTime = chrono::system_clock::now();
    quickSort(arr, 0, arrSize - 1);
    auto endTime = chrono::system_clock::now();

    // Use only for seeing if the sorting algorithm works
    //printList(arr);

    chrono::duration<double> elapsedTime = endTime - startTime;

    cout << "QuickSort total elapsed time: " << elapsedTime.count() << " seconds.\n";
}
