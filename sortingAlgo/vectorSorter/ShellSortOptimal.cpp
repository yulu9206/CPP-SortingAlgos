#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    static int gap_sequence[] = { 13, 9, 5, 2, 1 } ;
    
    // for (gap = n/2; gap > 0; gap /= 2)
    for( int gap : gap_sequence ) if( gap < size )
    {
        // for (i = gap; i < n; i++)
        for( int i = gap ; i < size; ++i )
            
            // for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            for (int j = i-gap ; j >= 0 && data[j] > data[j+gap] ; j -= gap )
            {
                swap(j, j + gap) ;
                compare_count++;
            }
    }
    return;
}

