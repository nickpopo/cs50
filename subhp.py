# get string input and return list of substrings of string with lenght n
def subs(string, n):
    length = len(string)
    s = []
    for i in range(length):
        if length - i < n:
            break
        s.append(string[i:n+i])
    return s