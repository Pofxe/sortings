#include <iostream>
#include <vector>
#include <chrono>
#include <list>
#include <deque>

#include "bubble_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"

using namespace std;
using namespace std::chrono;

template <typename Container>
using SortFunction = Container(*)(const Container&);

template <typename Container>
void measureSortTime(const Container& container_, SortFunction<Container> sortFunction_, const string& sortName_) 
{
    auto start = high_resolution_clock::now();
    Container sortedContainer = sortFunction_(container_);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << sortName_ << " took "s << duration.count() << " milliseconds"s << endl;
}

int main() 
{
    srand(time(NULL));

    vector<int> vec(100000);
    for(int i = 0; i < vec.size(); i++)
    {
        vec[i] = rand() % 21000;
    }

    cout << "Container size = "s << vec.size() << " elements"s << endl;
    //---------------------------------------------------------------- Bubble Sort

    measureSortTime(vec, BubbleSort, "Bubble Sort (vector)");

    //---------------------------------------------------------------- Quick Sort

    measureSortTime(vec, QuickSort, "Quick Sort (vector)");

    //---------------------------------------------------------------- Heap Sort

    measureSortTime(vec, HeapSort, "Heap Sort (vector)");

    //---------------------------------------------------------------- Selection Sort

    measureSortTime(vec, SelectionSort, "Selection Sort (vector)");

    //---------------------------------------------------------------- Merge Sort

    measureSortTime(vec, MergeSort, "Merge Sort (vector)");
}