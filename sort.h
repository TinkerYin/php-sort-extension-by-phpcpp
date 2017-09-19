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

template<typename T>
void maxHeapify(std::vector<T> &arr, int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;

    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1]) {
            ++son;
        }

        if (arr[dad] > arr[son]) {
            return;
        } else {
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

template<typename T>
void heapSort(std::vector<T> &arr)
{
    int length = arr.size();

    for (int i = length / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, i, length - 1);
    }

    for (int i = length - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i - 1);
    }
}
