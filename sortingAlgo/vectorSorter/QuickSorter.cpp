#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    if (left < right)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        Element pivot = choose_pivot(left, right);
        int pi = partition(left, right, pivot);
         // swap(0, pi - 1);
        // Separately sort elements before
        // partition and after partition
        quicksort(left, pi - 1);
        quicksort(pi, right);
    }
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
      int i = left, j = right;
      while (i <= j) {
            compare_count++;
            while (data[i] < pivot)
            {
                i++;
                compare_count++;
            }
            while (data[j] > pivot)
            {
                compare_count++;
                j--;
            }
            if (i <= j) {
                  compare_count++;
                  swap(i, j);
                  i++;
                  j--;
            }
      };
      return i;
}
