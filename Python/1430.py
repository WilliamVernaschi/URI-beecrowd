import sys
dc = {"W":64,"H":32,"Q":16,"E":8,"S":4,"T":2,"X":1}
for line in sys.stdin:
    ans=0
    line = line.rstrip()
    if(line == '*'):
        break
    ok = line.split('/')
        for field in ok:
        aa=0
        for char in field:
            aa += dc[char]
        if(aa == 64 and field != ""):
            ans+=1
    print(ans)
