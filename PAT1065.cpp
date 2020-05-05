if __name__ == "__main__":
    N=int(input())
    for i in range(N):
        t=input()
        a=int(t.split()[0])
        b=int(t.split()[1])
        c=int(t.split()[2])
        if(a+b>c):
            print("Case #"+str(i+1)+": true")
        else:
            print("Case #"+str(i+1)+": false")