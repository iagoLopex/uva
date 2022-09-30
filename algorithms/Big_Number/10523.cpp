while True:
    try:
        n,a = list(map(int, input().split()))
        n=n+1
        ans = 0;
        for i in range (1,n):
            ans = ans + (i*pow(a,i))
        print(ans)
        
    except EOFError:
        break
    
