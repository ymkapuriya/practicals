

def quicksort(a, left, right):
    if left < right:
        p = partition(a, left, right)
        quicksort(a, left, p-1)
        quicksort(a, p+1, right)


def partition(a, left, right):
    pivot = a[left]
    i = left
    j = right
    while i < j:
        while a[i] <= pivot and i <= right:
            i += 1
        while a[j] > pivot and j >= left:
            j -= 1
        if i < j:
            temp = a[i]
            a[i] = a[j]
            a[j] = temp
    a[left] = a[j]
    a[j] = pivot
    return j


if __name__ == "__main__":
    a = [12, 5, 10, 6, 4, 23]
    quicksort(a, 0, len(a) - 1)
    print(a)
