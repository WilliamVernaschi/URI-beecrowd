import sys
for l in sys.stdin:
    l = l.strip()
    if l == '*':
        break
    c = l[0].lower()
    ok = True
    for w in l.split(' '):
        if(w[0].lower() != c):
            print("N")
            ok = False
            break
    if(ok):
        print("Y")
