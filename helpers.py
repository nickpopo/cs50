from nltk.tokenize import sent_tokenize
from subhp import subs

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
