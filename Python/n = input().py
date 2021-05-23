n = input()
s = n.split()
for i in s:
    if i[0] in {'a','e','i','o','u'}:
        print(i)