def run(n):
	cnt=0
	for i in range(1,n+1):
		chk=0
		for j in range(1,10):
			if(int(str(j)+str(i))%i!=0):
				chk=1
				break
		if(chk==0): cnt+=1
	return cnt;

T =int(input())
for i in range(1,T+1):
	n = int(input())
	ans=run(n)
	print("#"+str(T),ans)
