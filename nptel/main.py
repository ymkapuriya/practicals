
def h(n):
    s = True
    for i in range(1, n+1):
        if i*i == n:
            s = False
    return(s)


def f(n):
    s = 0
    for i in range(2, n):
        if n % i == 0 and i % 2 == 1:
            s = s+1
    return(s)


def g(y):
    b = 0
    while y >= 3:
        (y, b) = (y/3, b+1)
    return(b)


def foo(m):
    if m == 0:
        return(0)
    else:
        return(m+foo(m-1))


if __name__ == "__main__":
    print(g(728))
    print(f(90))
    print(f(89))
    print(f(90)-f(89))
    print("Odd : 21", h(21))
    print("Odd : 13", h(13))
    print("Odd : 64", h(64))
    print("Odd : 46", h(46))

    print("6", foo(-6))
    print("7", foo(7))
