#include <iostream>
#include <string.h>
#include "maxPriorityQueue.h"

template <class T>
class maxHeap : public maxPriorityQueue<T>
{
public:
    maxHeap(T *theHeap, int theSize) : heap(theHeap), heapSize(theSize), arrayLength(theSize)
    {
        initialize(theHeap, theSize);
    }
    maxHeap(int length = 10) : heap(new T[length]), arrayLength(length) {}

    ~maxHeap() override
    {
        if (heap)
        {
            delete[] heap;
            heap = nullptr;
            arrayLength = heapSize = 0;
        }
    }

    bool empty() const override
    {
        return heapSize == 0;
    }

    int size() const override
    {
        return this->heapSize;
    }

    const T &top() const override
    {
        if (empty())
            throw "empty queue";

        return heap[1];
    }

    void push(const T &theElement) override;

    void pop() override;

    static void heapSort(T a[], int n);

private:
    void initialize(T *theHeap, int theSize);

    void expandArray();

    T *heap = nullptr;
    int arrayLength = 0;
    int heapSize = 0;
};

template <class T>
void maxHeap<T>::expandArray()
{
    std::cout << "expand array" << std::endl;

    T *origin = heap;
    heap = new T[arrayLength *= 2 + 1];

    memcpy(heap, origin, sizeof(T) * (heapSize + 1));
    delete[] origin;
}

template <class T>
void maxHeap<T>::push(const T &theElement)
{
    if (heapSize == arrayLength)
        expandArray();

    int targetPos = ++heapSize;
    int parentPos = targetPos / 2;

    while (parentPos > 0 && theElement > heap[parentPos])
    {
        std::swap(heap[parentPos], heap[targetPos]);
        targetPos = parentPos;
        parentPos /= 2;
    }
    heap[targetPos] = theElement;
}

template <class T>
void maxHeap<T>::pop()
{
    if (empty())
        throw "empty queue";

    T theElement = heap[heapSize];
    heap[heapSize--].~T();

    heap[1].~T();

    int pos = 1, child;

    while (pos * 2 <= heapSize)
    {
        child = pos * 2 < heapSize ? (heap[pos * 2] >= heap[pos * 2 + 1] ? pos * 2 : pos * 2 + 1)
                                   : pos * 2;

        if (theElement >= heap[child])
            break;

        std::swap(heap[pos], heap[child]);
        pos = child;
    }
    heap[pos] = theElement;
}

template <class T>
void maxHeap<T>::initialize(T *theHeap, int theSize)
{
    int child;
    for (int pos = theSize / 2; pos >= 1; --pos)
    {
        T theElement = heap[pos];
        int child = pos * 2;

        while (child <= heapSize)
        {
            child = child < heapSize ? (heap[child] >= heap[child + 1] ? child : child + 1)
                                     : child;

            if (theElement >= heap[child])
                break;

            std::swap(heap[child / 2], heap[child]);
            child *= 2;
        }
        heap[child / 2] = theElement;
    }
}

template <class T>
void maxHeap<T>::heapSort(T a[], int n)
{
    maxHeap<T> heap(a, n);

    for (int i = n - 1; i >= 1; --i)
    {
        T x = heap.top();
        heap.pop();
        a[i + 1] = x;
    }
}