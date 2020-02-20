import random as r

with open("2-8-2-test.txt","w") as f:
    a=r.randint(1000,10000)
    print(a)
    f.write(str(a))
    f.write("\n")
    for i in range(a):
        t=f"{r.randint(0,10000000)} {r.randint(0,10000000)}"
        print(t)
        f.write(t)
        f.write("\n")