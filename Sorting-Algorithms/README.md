# Sorting Algorithms

For each file, there is an array size and seed global variable at the top. These can be changed to set the array size or the seed.
If you are testing multiple sorting algorithms and want to compare the speed, the seed should be set to the same for all of them.

## Sorting stats
| Name           | Space Complexity | Best Case Time Complexity | Average Case Time Complexity | Worst Case Time Complexity | Stability |
| :------------: | :--------------: | :-----------------------: | :--------------------------: | :------------------------: | :-------: | 
| Bubble Sort    | O(1)             | O(n)                      | O(n^2)                       | O(n^2)                     | Yes       |
| Insertion Sort | O(1)             | O(n)                      | O(n^2)                       | O(n^2)                     | Yes       |
| Selection Sort | O(1)             | O(n^2)                    | O(n^2)                       | O(n^2)                     | No        |
| Heap Sort      | O(1)             | O(nlogn)                  | O(nlogn)                     | O(nlogn)                   | No        |
| Quick Sort     | O(logn)          | O(nlogn)                  | O(nlogn)                     | O(n^2)                     | No        |
| Merge Sort     | O(n)             | O(nlogn)                  | O(nlogn)                     | O(nlogn)                   | Yes       |
