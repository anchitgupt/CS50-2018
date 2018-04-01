from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    file1_list = []
    file2_list = []
    file1_list = (list(a.splitlines()))
    file2_list = (list(b.splitlines()))
    file1_list_final = list(set(file1_list))
    file2_list_final = list(set(file2_list))

    return list(set(file1_list_final).intersection(file2_list_final))


def sentences(a, b):
    """Return sentences in both a and b"""

    return list((set(sent_tokenize(a))).intersection(set(sent_tokenize(b))))


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    list_final1 = list()
    list_final2 = list()
    for x in range(len(a)):
        temp = a[x:x + n]
        list_final1.append(temp)
    for x in range(len(b)):
        temp = b[x:x + n]
        list_final2.append(temp)
    file1_list_final = list(set(list_final1))
    file2_list_final = list(set(list_final2))
    return list(set(file1_list_final).intersection(file2_list_final))