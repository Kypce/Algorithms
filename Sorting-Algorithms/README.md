# Sorting Algorithms

For each file, there is an array size and seed global variable at the top. These can be changed to set the array size or the seed.
If you are testing multiple sorting algorithms and want to compare the speed, the seed should be set to the same for all of them.

Specific information regarding an overview of how the sorting algorithm works can be found in the comment block at the top of the each 
respective code.

## Sorting stats
| Name           | Space Complexity | Best Case Time Complexity | Average Case Time Complexity | Worst Case Time Complexity | Stability |
| :------------: | :--------------: | :-----------------------: | :--------------------------: | :------------------------: | :-------: | 
| Bubble Sort    | O(1)             | O(n)                      | O(n^2)                       | O(n^2)                     | Yes       |
| Insertion Sort | O(1)             | O(n)                      | O(n^2)                       | O(n^2)                     | Yes       |
| Selection Sort | O(1)             | O(n^2)                    | O(n^2)                       | O(n^2)                     | No        |
| Heap Sort      | O(1)             | O(nlogn)                  | O(nlogn)                     | O(nlogn)                   | No        |
| Quick Sort     | O(logn)          | O(nlogn)                  | O(nlogn)                     | O(n^2)                     | No        |
| Merge Sort     | O(n)             | O(nlogn)                  | O(nlogn)                     | O(nlogn)                   | Yes       |

Stability: If a sorting algorithm is stable, the relative order of the items with equal sorting keys is maintained. An example can be shown with sorting a list of names and grades where the goal is to have it in order of highest to lowest grade and for names with same grades to be alphabetical. (Explanation and graphics can be found at https://www.freecodecamp.org/news/stability-in-sorting-algorithms-a-treatment-of-equality-fa3140a5a539/).

This image shows the result of using a stable algorithm. Here it is first sorted by name, then once it is sorted by grade, those with the same key (i.e., the same grade) will then be ordered by their names.

<img width="382" alt="image" src="https://github.com/Kypce/Algorithms/assets/69166331/7f8e0fb8-39b4-4cb2-8e38-46baefb4a8f2">

This image shows the result of using an unstable algorithm. Here the alphabetical sorting is lost once it is sorted by grade.
<img width="383" alt="image" src="https://github.com/Kypce/Algorithms/assets/69166331/05a5e4fa-9130-4893-b1bf-458a7b722110">
