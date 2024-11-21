#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>


using namespace std;

void quickSort(int[], int, int);
int partition(int[], int, int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void bubbleSort(int[], int);
void printArray(int[], int);

void copyArray(int[], int[], int);

void buildArray(int[], int);

int main()
{
    const int arrSize = 1000;
    
    // int numbers[] = {42, 15, 23, 9, 100, 5, 13, 1};
    int numbers[arrSize];
    int bubbleArray[arrSize];
    int quickArray[arrSize];
    int mergeArray[arrSize];
    int insertArray[arrSize];
    int selectionArray[arrSize];
    int stlArray[arrSize];
    int stlstableArray[arrSize];

    buildArray(numbers,arrSize);
    copyArray(numbers, bubbleArray, arrSize);
    copyArray(numbers, selectionArray, arrSize);
    copyArray(numbers, insertArray, arrSize);
    copyArray(numbers, mergeArray, arrSize);
    copyArray(numbers, quickArray, arrSize);

   
    // Bubble Sort
    auto start = chrono::system_clock::now();
    bubbleSort(bubbleArray, arrSize);
    auto end = chrono::system_clock::now();
    auto elapsed = end - start;
    cout << "Bubble Sort Time: " << elapsed.count() << endl;

    // Selection Sort
    start = chrono::system_clock::now();
    selectionSort(selectionArray, arrSize);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Selection Sort Time: " << elapsed.count() << endl;

    // Insertion Sort
    start = chrono::system_clock::now();
    insertionSort(insertArray, arrSize);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Insertion Sort Time: " << elapsed.count() << endl;

    // Merge Sort
    start = chrono::system_clock::now();
    mergeSort(mergeArray, 0, arrSize - 1);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Merge Sort Time: " << elapsed.count() << endl;

    // Quick Sort
    start = chrono::system_clock::now();
    quickSort(quickArray, 0, arrSize - 1);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Quick Sort Time: " << elapsed.count() << endl;

    //std sort
    start = chrono::system_clock::now();
    sort(begin(stlArray), std::end(stlArray));
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "std Sort Time: " << elapsed.count() << endl;

    //std sort
    start = chrono::system_clock::now();
    stable_sort(begin(stlstableArray), std::end(stlstableArray));
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "std stable Sort Time: " << elapsed.count() << endl;
    
    // Uncomment the sorting algorithm you want to use:
    // bubbleSort(numbers, arrSize);
    // selectionSort(numbers, arrSize);
    // insertionSort(numbers, arrSize);
    quickSort(numbers, 0, arrSize - 1);
    // mergeSort(numbers, 0, arrSize - 1);

    cout << "Sorted: " << endl;
    //printArray(numbers, arrSize);

    return 0;
}
void buildArray(int array[], int arrSize)
{
    srand(time(0));
    for (int i = 0; i < arrSize; i++)
    {
        array[i] = rand();
    }
}

void copyArray(int array[], int array2[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        array2[i] = array[i];
    }
}

void printArray(int numbers[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void quickSort(int numbers[], int begin, int end)
{
    if (begin >= end)
        return;

    int partIdx = partition(numbers, begin, end);
    quickSort(numbers, begin, partIdx - 1);
    quickSort(numbers, partIdx + 1, end);
}

int partition(int numbers[], int begin, int end)
{
    int pivot = numbers[end];
    int i = begin - 1;

    for (int j = begin; j < end; j++)
    {
        if (numbers[j] <= pivot)
        {
            i++;
            swap(numbers[i], numbers[j]);
        }
    }
    swap(numbers[i + 1], numbers[end]);
    return i + 1;
}

void bubbleSort(int numbers[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arrSize - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1]) // ascending
            {
                swapped = true;
                swap(numbers[j], numbers[j + 1]);
            }
        }
        //printArray(numbers, arrSize);
        if (!swapped)
            break;
    }
}

void selectionSort(int numbers[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (numbers[j] < numbers[minimum])
            {
                minimum = j;
            }
        }
        if (minimum != i)
        {
            swap(numbers[minimum], numbers[i]);
        }
        //printArray(numbers, arrSize);
    }
}

void insertionSort(int numbers[], int arrSize)
{
    for (int i = 1; i < arrSize; i++)
    {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
        //printArray(numbers, arrSize);
    }
}

void mergeSort(int numbers[], int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(numbers, begin, mid);
    mergeSort(numbers, mid + 1, end);
    merge(numbers, begin, mid, end);
}

void merge(int numbers[], int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;

    int leftNums[leftSize], rightNums[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftNums[i] = numbers[begin + i];
    for (int i = 0; i < rightSize; i++)
        rightNums[i] = numbers[mid + 1 + i];

    int i = 0, j = 0, k = begin;
    while (i < leftSize && j < rightSize)
    {
        if (leftNums[i] <= rightNums[j])
            numbers[k++] = leftNums[i++];
        else
            numbers[k++] = rightNums[j++];
    }

    while (i < leftSize)
        numbers[k++] = leftNums[i++];
    while (j < rightSize)
        numbers[k++] = rightNums[j++];
}
