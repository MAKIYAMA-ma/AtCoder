input_str = input()
l, r = map(int, input_str.split())

if l:
    if r:
        print("Invalid")
    else:
        print("Yes")
else:
    if r:
        print("No")
    else:
        print("Invalid")
