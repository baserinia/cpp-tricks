// Copyright (C) 2016 Amir Baserinia

// In C++11, lambda functions without a capture clase can be converted to
// function pointers. This comes handy for writing wrappers for C function
// which receive void* arguments; e.g. system calls.
//
// The following code snippet demonstrates the idea. We can use qsort without
// defining a comparison function or dangerous type casts.
//
// Please note that this is only a proof of concept. In a real code, you should
// always use std::sort rather than qsort.

#include <iostream>

template<typename T> void smart_sort(T* list, size_t sz) {
    qsort(list, sz, sizeof(T), [](const void* a, const void* b)->int{return *(T*)b < *(T*)a;});
}

int main()
{
    int list[] = {5, 4, 8, 6, 9, 1};
    size_t len = sizeof(list) / sizeof(list[0]);
    smart_sort(list, len);
    for (size_t i = 0; i < len; i++) std::cout << list[i] << std::endl;
    return 0;
}



