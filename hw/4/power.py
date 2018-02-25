def powers(a, n):
    if (n == 0): return a
    return powers(a*a, n-1)

if __name__ == "__main__":
    n = int(input("num: "))

    print(powers(3, n))
