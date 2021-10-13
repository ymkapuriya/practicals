
def linear_search(a, key):
    i = 1
    for value in a:
        if value == key:
            return i
        i = i + 1
    return -1


def linear_search_new(a, key):
    i = 0
    while i < len(a):
        if a[i] == key:
            return i + 1
        i = i + 1
    return -1


def rec_binary_search(a, key, left, right):
    if left <= right:
        mid = int((left + right) / 2)
        if a[mid] > key:
            return rec_binary_search(a, key, left, mid - 1)
        elif a[mid] < key:
            return rec_binary_search(a, key, mid + 1, right)
        else:
            return mid
    else:
        return -1


def binary_search(a, key):
    left = 0
    right = len(a) - 1
    while left <= right:
        mid = int((left + right) / 2)
        if key == a[mid]:
            return mid
        elif key > a[mid]:
            left = mid + 1
        else:
            right = mid - 1
    return -1


if __name__ == "__main__":
    input = [13, 22, 33, 52, 63, 72]
    key = 63
    '''
    position = linear_search_new(input, key)
    if position >= 1:
        print("Element is found at position " + str(position))
    else:
        print("Element is not found")
    '''
    position = rec_binary_search(input, key, 0, len(input)) + 1
    if position >= 1:
        print("Element is found at position " + str(position))
    else:
        print("Element is not found")
