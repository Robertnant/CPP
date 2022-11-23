// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template <class T>
T container_min(T begin, T end) {
    T min = begin++;
    while (begin != end) {
        if (*begin < *min)
            min = begin;
        begin++;
    }

    return min;
}

template <class T>
void my_selection_sort(T begin, T end) {
    while (begin != end) {
        T min = container_min(begin, end);

        // Swap.
        auto tmp = *min;
        *min = *begin;
        *begin = tmp;

        begin++;
    }
}