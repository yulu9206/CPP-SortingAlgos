#include <string>
#include "MergeSort.h"
#include "LinkedList.h"
/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();
    
    mergesort(data);
    
    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
        to_string(size_before) + ", size after " +
        to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    if (list.get_size() == 0 || list.get_size() == 1) return;
    LinkedList l1, l2;
    list.split(l1, l2);
    move_count++;
    // Sort first and second halves
    mergesort(l1);
    mergesort(l2);
    merge(list, l1, l2);
    return;
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    Node *i = sublist1.get_head();
    Node *j = sublist2.get_head();
    Node *n1 = sublist1.get_tail();
    Node *n2 = sublist2.get_tail();
    Node *h = list.get_head();
    Node *t = list.get_tail();
    Node *k;
    if (*i <= *j)
    {
        h = i;
        i = i->next;
    }
    else
    {
        h = j;
        j = j->next;
    }
    compare_count++;
    move_count++;
    if(*n1 <= *n2) t = n2;
    else t = n1;
    compare_count++;
    list.set(h, t, list.get_size());
    
    k = h;
    while ( i != nullptr  && j != nullptr && k != t)
    {
        if (*i <= *j)
        {
            k->next = i;
            k = i;
            i = i->next;
        }
        else
        {
            k->next = j;
            k = j;
            j = j->next;
        }
        move_count++;
        compare_count++;
    }
    
    /* Copy the remaining elements of list1, if there
     are any */
    if (i != nullptr)
    {
        k->next = i;
//        move_count++;
        
    }
    
    /* Copy the remaining elements of list2, if there
     are any */
    if (j != nullptr)
    {
        k->next = j;
//        move_count++;
        
    }
    move_count++;
    return;
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }

