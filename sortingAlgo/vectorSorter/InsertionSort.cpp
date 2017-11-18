#include "InsertionSort.h"
#include "Element.h"
#include "VectorSorter.h"
#include "Sorter.h"
/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
   int i, j;
   Element temp;
   for (i = 1; i < size; i++)
   {
       Element key = data[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && data[j] > key)
       {
           temp = data[j];
           data[j+1] = temp;
           move_count++;
           compare_count++;
           j = j-1;
       }
       data[j+1] = key;
   }
}
