// SortImpls.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// BubbleSort - Part 1
// o(n^2)
void bubbleSort(vector<int> &array, int first, int last)  //takes in the first and last array indexes 
{

    bool elementsSwapped; //variable to check if variables are swapped 
    bool isSorted; //variable to check if the array is sorted

    for (int i = first; i < last; i++) //looping through the first and last index 
    {
        elementsSwapped = false; //declared initally as not swapped
        for (int j = first; j < last - i; j++) //looping through the first and 2nd to last index
        {
            if (array[j] > array[j + 1]) //comparing to see if the elements at index j is more than element next to it

            {
                swap(array[j], array[j + 1]); //if it is then swap them both 
                elementsSwapped = true; //the elements swapped is turned to true;
            }
        }

        // If no elements were swapped in this pass, the array is already sorted
        if (!elementsSwapped)
        {
            isSorted = true; //return true as the array is already sorted
            break;
        }
    }
}

// BubbleSort - Part 2
// o(n^2)
void bubbleSort2(vector<int> &array, int first, int last) 
{
    bool elementsSwapped;
    bool isSorted;

    for (int i = first; i < last; i++)
    {
        elementsSwapped = false;
        for (int j = first; j < last - i; j++)
        {
            if (array[j] > array[j + 1]) 

            {
                swap(array[j], array[j + 1]);
                elementsSwapped = true;
            }
        }

        if (!elementsSwapped)
        {
            isSorted = true;
            break;
        }
    }

    // If the array is not sorted, perform another pass to check the 2 neighboring terms
    if (!isSorted)
    {
        for (int i = first; i < last; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                elementsSwapped = true;
            }
        }
    }
}

// BubbleSort - Part 3
 // o(n^2)
void bubbleSort3(vector<int> &array, int index1, int index2)
{

    bool elementsSwapped;
    for (int i = 0; i < array.size() - 1; i++)//looping through the array size 
    {
        elementsSwapped = false;
        for (int j = index1; j < index2 - i - 1; j++) //loop through while index1 is less than index-i-1
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                elementsSwapped = true;
            }
        }
        if (!elementsSwapped)
            break;
    }
}

// InsertionSort
void insertionSort(vector<int> &array, int first, int last) // o(n^2)
{
    for (int i = first + 1; i <= last; i++) //looping through as the first+ 1 is less than or equal to last
    {
        int value = array[i]; //variable set to element at index i
        int j = i - 1; // variable j set to one behind i

        while (j >= first && array[j] > value)  //while j is less than first, and array is less than value
        {
            array[j + 1] = array[j]; //element next to j in array is equal to array at j
            j = j - 1; //setting value of j back one
        }
        array[j + 1] = value; //setting value to next index to be sorted 
    }
}

// MergeSort
// working
void merge(vector<int> &array, int start, int mid, int end) // o(n)
{
    int n1 = mid - start + 1; //varible with array size ranging from first half 
    int n2 = end - mid; //variable with array size rangign from end to middle

    vector<int> left(n1), right(n2); //making two subarrays out of first one

    for (int i = 0; i < n1; i++) //looping through size of first sub array

        left[i] = array[start + i]; //setting the left at i equal to start of org

    for (int j = 0; j < n2; j++) //looping through the size of second sub array

        right[j] = array[mid + 1 + j]; //setting the right at i equal to the middle index in org

    int i = 0;
    int j = 0;
    int k = start; 

    while (i < n1 && j < n2) //While both subarrays have not finished 
    {
        if (left[i] <= right[j]) //if the left is less than or equal ot
        {
            array[k] = left[i]; // array at k is equal to left at i 
            i++; 
        }
        else
        {
            array[k] = right[j]; //else if left is bigger or equal to right at j
            j++; 
        }
        k++;
    }

    while (i < n1) //while i is less than sub array
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) //while j is less than sub array
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &array, int first, int last) // o(nlogn)
{
    if (first < last)  
    {
        int mid = first + (last - first) / 2;

        mergeSort(array, first, mid);

        mergeSort(array, mid + 1, last);
      
        merge(array, first, mid, last);
    }
}

// QuickSort
// working
int partition(vector<int> &array, int first, int last) // o(n)
{
    int pivot = array[last]; //pivot last element in the array
    int indexFromLeft = first; //left index index as begining of the aray
    int indexFromRight = last - 1; //right index is element before pivot 

    while (indexFromLeft <= indexFromRight) //while the left is less than the right index 
    {
        while (indexFromLeft <= last && array[indexFromLeft] < pivot)
            indexFromLeft++;

        while (indexFromRight >= first && array[indexFromRight] > pivot)
            indexFromRight--;

        if (indexFromLeft < indexFromRight)
        {
            swap(array[indexFromLeft], array[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
        else
        {
            break;
        }
    }

    swap(array[last], array[indexFromLeft]);
    return indexFromLeft;
}

void quickSort(vector<int> &array, int first, int last) // o(nlogn)
{
    if (first < last)
    {
        int pivotIndex = partition(array, first, last);
        quickSort(array, first, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, last);
    }
}

// ShellSort
// working
void shellSort(vector<int> &array, int start, int end) // o(n^2)
{
    int n = end - start + 1; // the size of the subarray to be sorted
    for (int gap = n / 2; gap > 0; gap /= 2) //large gap and reduce it by half with the loop
    {
        for (int i = start + gap; i <= end; i++) //loop through the elements in array
        {
            int temp = array[i]; //store current as temp val
            int j;
            for (j = i; j >= start + gap && array[j - gap] > temp; j -= gap) 
                array[j] = array[j - gap]; // Shift elements to the right.
            array[j] = temp;
        }
    }
}