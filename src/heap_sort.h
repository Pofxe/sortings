template <typename Container>
void Heapify(Container& cont_, int cont_size_, int root_) 
{
    int largest = root_;
    int left = 2 * root_ + 1;
    int right = 2 * root_ + 2;

    if (left < cont_size_ && cont_[left] > cont_[largest])
    {
        largest = left;
    }

    if (right < cont_size_ && cont_[right] > cont_[largest])
    {
        largest = right;
    }

    if (largest != root_)
    {
        std::swap(cont_[root_], cont_[largest]);

        Heapify(cont_, cont_size_, largest);
    }
}

template <typename Container>
Container HeapSort(const Container& cont_) 
{
    Container cont_temp = cont_;
    int cont_size = cont_temp.size();

    for (int i = cont_size / 2 - 1; i >= 0; i--)
    {
        Heapify(cont_temp, cont_size, i);
    }

    for (int i = cont_size - 1; i > 0; i--) 
    {
        std::swap(cont_temp[0], cont_temp[i]);

        Heapify(cont_temp, i, 0);
    }
    return cont_temp;
}