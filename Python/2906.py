n = int(input())
ans = set()
for i in range(n):
    email = input()
    loc = email[:email.find('@')]
    loc = loc.replace('.', '')
    if loc.find('+') != -1:
        loc = loc[:loc.find('+')]
    fin = loc + email[email.find('@'):]
    ans.add(fin)
print(len(ans))
