n = int(input())
for i in range(n):
    s = input()
    notas = input().split()
    notas = [float(x) for x in notas]
    print(f"{s}: ", end="")
    notas_sum = sum(notas)
    res=0;
    if(len(notas) == 1):
        res = notas_sum/2
    elif(len(notas) == 2 or len(notas) == 3):
        res = notas_sum/len(notas)
    elif(len(notas) == 4):
        min_n = 100000
        for x in notas:
            if(x < min_n):
                min_n = x
        res = max((notas_sum-min_n)/3, notas_sum/4)
        if(len(str(res)) >= 4):
        form_res = str(res)[0:4]
        end_res = ""
        if (len(form_res) >= 4):
            if(int(form_res[3]) >= 5):
                end_res = form_res[0:-2] + str(int(form_res[2])+1)
            else:
                end_res = form_res[0:-1]
        print(end_res) 
    else:
        print(res)
                    
