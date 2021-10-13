
def factorial(n):
    fact = 1
    i = 1
    while i <= n:
        fact = fact * i
        i = i + 1
    return fact


def rfactorial(n):
    if n == 1:
        return n
    else:
        return n * rfactorial(n-1)


if __name__ == "__main__":
    ans = rfactorial(5)
    print("Answer = " + str(ans))
