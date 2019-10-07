T = int(input())
 
for i in range(1, T+1):
    P,Q,R,S,W =  list(map(int, input().split()))
     
    A = P * W
    if W-R > 0:
        B = Q + (W-R)*S
    else:
        B = Q
    if A>B:
        ans = B
    else:
        ans = A
    print("#" + str(i) + " " + str(ans))