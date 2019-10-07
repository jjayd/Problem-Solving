#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	for(int t=1;t<T;t++){
		string input,two;
		int year,month,day,hour,min,sec;
		cin>>input;
		cin>>two;
		int cnt=0;
		int date=0;
		string tmp;
		for(int i=0;i<6;i++){
			size_t sz;
			switch(date){
				case 0: year = stoi(input,&sz);
				case 1: month = stoi(input,&sz);
				case 2: day = stoi(input,&sz);
				case 3: hour = stoi(input,&sz);
				case 4: min = stoi(input,&sz);
				case 5: sec = stoi(input,&sz);
			}
			printf("%d\n",sz);

		//	if(date!=5)	string tmp = input.substr(sz+1);
			input = tmp;
			date++;
		}
		cout<< year<<month<<day<<hour<<min<<sec<<endl;
	}

}