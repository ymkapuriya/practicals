
def l_search(a, key):
    i = 1
    for value in a:
        if key == value:
            return i
        i = i + 1
    return -1


def binary_search(a, key):
    '''Array must be sorted'''
    left = 0
    right = len(a) - 1
    while left <= right:
        mid = int((left + right) / 2)
        if key > a[mid]:
            # look in to the right of mid
            left = mid + 1
        elif key < a[mid]:
            # look in to the left of mid
            right = mid - 1
        else:
            # match is found at mid
            return mid
    return -1


def rec_binary_search(a, key, left, right):
    if left <= right:
        mid = int((left + right) / 2)
        if key > a[mid]:
            # look in to right of mid
            return rec_binary_search(a, key, mid+1, right)
        elif key < a[mid]:
            # look in to left of mid
            return rec_binary_search(a, key, left, mid - 1)
        else:
            # match is found
            return mid
    else:
        return -1


def factorial(n):
    fact = 1
    i = 1
    while i <= n:
        fact = fact * i
        i = i + 1
    return fact


def rec_factorial(n):
    if n == 1:
        return 1
    return n * rec_factorial(n-1)


def insertion_sort(a):
    n = len(a)
    i = 1
    while i < n:
        key = a[i]
        j = i - 1
        while key < a[j] and j >= 0:
            a[j+1] = a[j]
            j = j - 1
        a[j+1] = key
        i = i + 1
    print(a)
    return


if __name__ == "__main__":
    '''
      ans = rec_factorial(5)
      print("Answer is " + str(ans))
    '''

    input = [45, 15, 67, 32, 12, 20]
    print("Input")
    print(input)
    insertion_sort(input)

    '''    key = 20
    pos = l_search(input, key)
    if pos > 0:
        print("Element is found at postition " + str(pos))
    else:
        print("Element not found")
    
    pos = rec_binary_search(input, key, 0, len(input) - 1) + 1
    if pos > 0:
        print("Element is found at postition " + str(pos))
    else:
        print("Element not found")
    '''
