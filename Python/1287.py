import sys
for s in sys.stdin:
    s = s.replace("o", "0")
    s = s.replace("O", "0")
    s = s.replace("l", "1")
    s = s.replace(",", "")
    s = s.replace(".", "")
    s = s.replace(" ", "")
    try:
        s = int(s)
        if(s > 2147483647):
            raise "erro"
        print(s)
    except:
        print("error")
