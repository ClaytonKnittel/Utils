import sys

from math import ceil, log2


def divvy(n):
    if n <= 2:
        return n
    else:
        return [divvy(n - (n // 2)), divvy(n // 2)]

def combine_pairs(lis):
    if isinstance(lis, int):
        return None
    if isinstance(lis[0], int):
        if isinstance(lis[1], int):
            return lis[0] + lis[1]
        else:
            return [lis[0], combine_pairs(lis[1])]
    else:
        if isinstance(lis[1], int):
            return [combine_pairs(lis[0]), lis[1]]
        else:
            return [combine_pairs(lis[0]), combine_pairs(lis[1])]

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
    return next_pow2


def pb(len):
    n_ops = 0
    tre = divvy(len)
    while tre is not None:
        print(tre)
        glob_offset = 0
        evn = True
        for l in for_each(tre):
            p2 = next_pow2(l)
            offs = p2 // 2
            while offs > 0:
                for iter in range(p2 // 2):
                    start = glob_offset + (iter // offs) * 2 * offs + (iter % offs)
                    end = start + offs
                    if end - glob_offset >= l:
                        continue
                    n_ops += 1
                    if evn:
                        print("swap {} and {}".format(start, end))
                    else:
                        print("swap {} and {}".format(end, start))
                offs //= 2
            glob_offset += l
            evn = not evn

        tre = combine_pairs(tre)
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
    return ceil(log2(2 * combos - 1)) - 1


if len(sys.argv) != 2:
    print("usage: {} <N>".format(sys.argv[0]))
    exit(-1)

n = int(sys.argv[1])
n_ops = pb(n)

print("{} ops, min = {}".format(n_ops, sort_lowb(n)))

