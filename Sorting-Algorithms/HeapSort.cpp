/** HEAP SORT INFORMATION
 * Space Complexity: O(1)
 * 
 * Best Case Time Complexity: O(nlogn)
 * Average Case Time Complexity: O(nlogn)
 * Worst Case Time Complexity: O(nlogn)
 * 
 * Stability: No
 * 
 * How it works . . .
 *  - The first step is constructing a heap binary tree through the heapify function.
 *      - This will construct a balanced tree (as balanced as it can be) by inserting the elements not in order but just in the next minimum available
 *        leaf node.
 *      - If a value is inputted that is greater than its parent though, this will be brought up the tree until it is greater than the children but less than its
 *        parent.
 *      - Once this is completed, the sorting process can begin.
 *  - The array is then reconstructed by running through tree from left to right, and sorting begins.
 *      - The head (the largest value) is swapped with the farthest leaf node and then deleted from the heap tree (in the array, the largest value is at the
 *        front of the array and the farthest leaf node is at the end of the array; hence the largest value goes to the end)
 *      - The heap tree is then re-heapified to reorder the tree putting the largest value at the root again
 *      - This process is then repeated until the entire tree is gone and the array is completed orderd.
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

void heapify(int A[], int size, int i) {
    int largest = i;
	int lft = 2 * i + 1;
	int rht = 2 * i + 2;

	if(lft < size && A[lft] > A[largest])
		largest = lft;

	if(rht < size && A[rht] > A[largest])
		largest = rht;

	if(largest != i) {
		swap(A[i], A[largest]);
		heapify(A, size, largest);
	}
}

void heapSort(int A[], int size) { 
    for(int i = ((size / 2) - 1); i >= 0; i--) {
        heapify(A, size, i);
    }
    for(int i = size - 1; i > 0; i--) {
            swap(A[0], A[i]);
            heapify(A, i, 0);
    }
}     
               
int main(int argc, char * argv[]) { 
    int *arr;
    arr = insertRandVals();

    auto startTime = chrono::system_clock::now();
    heapSort(arr, arrSize);
    auto endTime = chrono::system_clock::now();

    // Use only for seeing if the sorting algorithm works
    //printList(arr);

    chrono::duration<double> elapsedTime = endTime - startTime;

    cout << "HeapSort total elapsed time: " << elapsedTime.count() << " seconds.\n";
}
