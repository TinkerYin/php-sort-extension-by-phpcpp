#pragma once
#include <vector>

template<typename T>
void quickSort(std::vector<T> &arr, unsigned int start = 0, unsigned int end = 0)
{
    if (start == 0 && end == 0) {
        start = 0;
        end = arr.size() - 1;
    }

    if (start >= end || end > arr.size()) return;

    T middle = arr[end];
    int left = 0, right = end - 1;
    while (left < right) {
        while (arr[left] < middle && left < right) ++left;
        while (arr[right] >= middle && left < right) --right;
        std::swap(arr[left], arr[right]);
    }

    if (arr[left] >= arr[end]) {
        std::swap(arr[left],  arr[end]);
    } else {
        ++left;
    }

    quickSort(arr, start, left - 1);
    quickSort(arr, left + 1, end);
}