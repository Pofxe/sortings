template<typename Container>
Container SelectionSort(const Container& cont_)
{
    Container cont_temp = cont_;

    for (auto it = cont_temp.begin(); it != cont_temp.end(); ++it) 
    {
        auto min_it = it;
        for (auto inner_it = it; inner_it != cont_temp.end(); ++inner_it) 
        {
            if (*inner_it < *min_it) 
            {
                min_it = inner_it;
            }
        }
        std::swap(*it, *min_it);
    }

    return cont_temp;
}