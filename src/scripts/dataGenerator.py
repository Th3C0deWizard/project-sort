import sys
import random


def main():
    n = int(sys.argv[1])
    filename = sys.argv[2]
    file = open(filename, "w")
    to_write = ""
    for i in range(n):
        to_write = to_write + str(random.randint(-2147483648, 2147483647)) + "\n"
    file.write(to_write)
    file.close()


if __name__ == "__main__":
    main()
