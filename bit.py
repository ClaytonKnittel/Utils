import sys

from math import ceil, log2


def divvy(n):
    if n <= 2:
        return n
    else:
        return [divvy(n - (n // 2)), divvy(n // 2)]

def combine_pairs(lis):
    if isintance(lis, int):
        return None
    if isintance(lis[0], int):
        if isintance(lis[1], int):
            return lis[0] + lis[1]
        else:
            return [lis[0], combine_pairs(lis[1])]
    else:
        if isinstance(lis[1], int):
            return [combine_pairs(lis[0]), lis[1]]
        else:
            return [combine_pairs(lis[0]), combine_pais(lis[1])]

def for_each(tre):
    if isinstance(tre, int):
        yield tre
    else:
        yield from for_each(tre[0])
        yield from for_each(tre[1])

def next_pow2(n):
    next_pow2 = 1
    while next_pow2 < n:
        next_pow2 *= 2


def pb(len):
    n_ops = 0
    sizes = divvy(len)
    while True:
        idx = 0
        evn = True
        for l in for_each(tre):
            p2 = next_pow2(l)
            offs = p2 // 2
            while offs > 0:
                for iter in range(l // 2):
                    start = idx + (iter // offs) * 2 * offs + (iter % offs)
                    end = start + offs
                    if end >= :
                        continue
                    n_ops += 1
                    if evn:
                        print("swap {} and {}".format(start, end))
                    else:
                        print("swap {} and {}".format(end, start))
                offs //= 2
            idx += l
            evn = not evn

        if sizes is None:
            break
        sizes = combine_pairs(sizes)
    return n_ops


def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def sort_lowb(len):
    # number of possible combinations:
    combos = factorial(len)
    # minimum size of tree
    return ceil(log2(combos))


if len(sys.argv) != 2:
    print("usage: {} <N>".format(sys.argv[0]))
    exit(-1)

n = int(sys.argv[1])
n_ops = pb(n)

print("{} ops, min = {}".format(n_ops, sort_lowb(n)))

