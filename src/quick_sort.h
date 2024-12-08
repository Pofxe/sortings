#include <algorithm>
#include <iterator>

template<typename Container>
void QuickSort(Container& cont_, typename Container::iterator begin_, typename Container::iterator end_)
{
    if (std::distance(begin_, end_) <= 1) 
    {
        return;
    }

    auto pivot = std::prev(end_);
    auto partition_point = std::partition(begin_, pivot, [pivot](const auto& elem) 
    {
        return elem < *pivot;
    });

    std::swap(*partition_point, *pivot);

    QuickSort(cont_, begin_, partition_point);
    QuickSort(cont_, std::next(partition_point), end_);
}

template<typename Container>
Container QuickSort(const Container& cont_)
{
    Container cont_temp = cont_;
    QuickSort(cont_temp, std::begin(cont_temp), std::end(cont_temp));
    return cont_temp;
}