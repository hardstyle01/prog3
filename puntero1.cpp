#include <iostream>
using namespace std;

int main (int argc, char *argv[]){
	int v[]={6,7,8,9};
	int *pi=NULL;
	
	
	int num;
	pi=v;
	for(int i = 0; i < 4; ++i) 
	{
		num = v[i];
		
		cout << "num:" << num << endl;
		cout << "pi:" << *pi << endl;
		pi++;
	}
	
	return 0;
}
