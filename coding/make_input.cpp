#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int t=100;
	printf("%d\n",t);
	for(int p=0;p<t;p++)
	{
		int d=rand()%11+3;
		int w=rand()%20+1;
		int k=rand()%d+1;
		printf("%d %d %d\n",d,w,k);
		for(int i=0;i<d;i++)
		{
			for(int j=0;j<w;j++)
				printf("%d ",rand()%2);
			printf("\n");
		}
	}
	

}