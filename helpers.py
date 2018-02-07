from nltk.tokenize import sent_tokenize

# get string input and return list of substrings of string with lenght n
def subs(string, n):
    length = len(string)
    s = []
    for i in range(length):
        if length - i < n:
            break
        s.append(string[i:n+i])
    return s

def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    aSet = set(a.splitlines())
    bSet = set(b.splitlines())

    return list(aSet & bSet)


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    aSet = set(sent_tokenize(a))
    bSet = set(sent_tokenize(b))

    return list(aSet & bSet)


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    aSet = set(subs(a,n))
    bSet = set(subs(b,n))

    return list(aSet & bSet)
