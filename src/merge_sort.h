template<typename Container>
Container Merge(const Container& left_, const Container& right_)
{
    Container cont_temp;

    auto leftIt = left_.begin();
    auto rightIt = right_.begin();

    while (leftIt != left_.end() && rightIt != right_.end()) 
    {
        if (*leftIt < *rightIt) 
        {
            cont_temp.push_back(*leftIt);
            ++leftIt;
        } else 
        {
            cont_temp.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != left_.end()) 
    {
        cont_temp.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right_.end()) 
    {
        cont_temp.push_back(*rightIt);
        ++rightIt;
    }

    return cont_temp;
}

template<typename Container>
Container MergeSortRecursive(const Container& cont_)
{
    if (cont_.size() <= 1) 
    {
        return cont_;
    }

    size_t mid = cont_.size() / 2;

    Container left(cont_.begin(), cont_.begin() + mid);
    Container right(cont_.begin() + mid, cont_.end());

    left = MergeSortRecursive(left);
    right = MergeSortRecursive(right);

    return Merge(left, right);
}

template<typename Container>
Container MergeSort(const Container& cont_)
{
    return MergeSortRecursive(cont_);
}