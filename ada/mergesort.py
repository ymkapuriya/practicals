def merge(a, left, mid, right):

    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right:
        if a[i] < a[j]:
            b[k] = a[i]
            i += 1
        else:
            b[k] = a[j]
            j += 1
        k += 1

    while i <= mid:
        b[k] = a[i]
        i += 1
        k += 1

    while j <= right:
        b[k] = a[j]
        j += 1
        k += 1

    for i in range(left, right + 1):
        a[i] = b[i]

    pass


def merge_sort(a, left, right):

    if left < right:
        mid = int((left + right) / 2)
        merge_sort(a, left, mid)
        merge_sort(a, mid + 1, right)
        merge(a, left, mid, right)


def rec_binary_search(a, left, right, key):

    if left <= right:
        mid = int((left + right) / 2)
        if key == a[mid]:
            return mid
        elif key <= a[mid]:
            return rec_binary_search(a, left, mid - 1, key)
        else:
            return rec_binary_search(a, mid + 1, right, key)
    else:
        return -1


def binary_search(a, key):
    left = 0
    right = len(a) - 1

    while left <= right:
        mid = int((left + right)/2)
        if key == a[mid]:
            return mid
        elif key < a[mid]:
            right = mid - 1
        else:
            left = mid + 1

    return -1


if __name__ == "__main__":

    a = [23, 3, 2, 54, 67, 36]
    b = [0, 0, 0, 0, 0, 0]

    left = 0
    right = len(a) - 1
    merge_sort(a, left, right)
    print(a)

    # pos = rec_binary_search(a, left, right, 67)
    pos = binary_search(a, 15)
    if pos < 0:
        print("Element not found")
    else:
        print("Element is found at position " + str(pos + 1))
