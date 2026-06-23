import random
import time

def insertion_sort(arr, low, high):
    for i in range(low + 1, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def hybrid_quicksort(arr, low, high, threshold):
    while low < high:

        if high - low + 1 <= threshold:
            insertion_sort(arr, low, high)
            break

        pivot = partition(arr, low, high)

        if pivot - low < high - pivot:
            hybrid_quicksort(arr, low, pivot - 1, threshold)
            low = pivot + 1
        else:
            hybrid_quicksort(arr, pivot + 1, high, threshold)
            high = pivot - 1

size = 5000
thresholds = [5, 10, 20, 30, 50]

for threshold in thresholds:
    arr = [random.randint(1, 10000) for _ in range(size)]

    start = time.time()
    hybrid_quicksort(arr, 0, len(arr) - 1, threshold)
    end = time.time()

    print("Threshold =", threshold,
          "Execution Time =", round(end - start, 6), "seconds")
