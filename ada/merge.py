
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
        k += 1
        i += 1
    while j <= right:
        b[k] = a[j]
        k += 1
        j += 1
    for i in range(left, right + 1):
        a[i] = b[i]


def merge_sort(a, left, right):

    if left < right:
        mid = int((left + right) / 2)
        merge_sort(a, left, mid)
        merge_sort(a, mid + 1, right)
        merge(a, left, mid, right)


if __name__ == '__main__':
    a = [12, 3, 24, 65, 2, 18]
    b = [0, 0, 0, 0, 0, 0]
    left = 0
    right = len(a) - 1
    print(right)
    merge_sort(a, left, right)
    print(a)
