#include<bits/stdc++.h>

using namespace std;


/*
1. return �� �� ���� (�ڱ��ڽŹݵ������) 
2. �������� ��� (if��) 
*/

int factorial(int n){
	
	if(n == 0) return 1;
	
	
	return n * factorial(n-1);
}



void solve03(){
	
	int n;
	int rst = 0;
	
	cin >> n;	

	rst = factorial(n);
	
	cout << rst << endl;
	
	
}


int main(){
	
	
	
	solve03();
	//solve04();	

	
	
	
	
	
}
