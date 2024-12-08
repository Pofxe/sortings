template<typename Container> 
Container BubbleSort(const Container& cont_)
{
    Container cont_temp = cont_;
    bool flag;
    size_t container_size = cont_temp.size();

    do
    {
         flag = false;
         for (size_t i = 1; i < container_size; ++i)
         {
            if(cont_temp[i] < cont_temp[i - 1])
            {
                std::swap(cont_temp[i], cont_temp[i - 1]);
                flag = true;
            }
         }

         container_size--;

    } while (flag);
    return cont_temp;
}