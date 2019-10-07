#include <iostream>

using namespace std;

char to[1001];
char dir[1001];
char arr[6][10];

//too much nogada

void format()
{
	for(int i=0;i<6;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if(i==0) arr[i][j]='o';
			else if(i==1) arr[i][j]='g';
			else if(i==2) arr[i][j]='w';
			else if(i==3) arr[i][j]='b';
			else if(i==4) arr[i][j]='r';
			else if(i==5) arr[i][j]='y';
		}
	}
}

void cube(int n)
{
	int tmp[4];
	for(int i=0;i<n;i++)
	{
		if(to[i]=='U')
		{
			if(dir[i]=='+')
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
			else
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
		}
		else if(to[i]=='D')
		{
			if(dir[i]=='+')
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
			else
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
		}
		else if(to[i]=='F')
		{
			if(dir[i]=='+')
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
			else
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
		}
		else if(to[i]=='B')
		{
			if(dir[i]=='+')
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
			else
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;	
			}
		}
		else if(to[i]=='L')
		{
			if(dir[i]=='+')
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
			else
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;	
			}
		}
		else if(to[i]=='R')
		{
			if(dir[i]=='+')
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;
			}
			else
			{
				tmp[1~3]=arr[1][1~3];

				arr[3][1~3]=arr[0][1~3];
				arr[4][1~3]=arr[3][1~3];
				arr[1][1~3]=arr[4][1~3];
				arr[0][1~3]=tmp;	
			}
		}

	}
}

int main()
{
	int m;
	cin>>m;
	while(m--)
	{
		int n;
		cin>>n;
		format();
		for(int i=0;i<n;i++)
			cin>>to[i]>>dir[i];
		cube(n);
		cout<<
	}
}