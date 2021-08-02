#include<bits/stdc++.h>

using namespace std;


/*
- DFS�� BFS���� ���й�
 
BFS�� �ʺ�켱Ž������ ���� ���� ��ġ���� ���� ����� ��带 ���� �湮�ϴ� ���̴�
�湮�ϸ鼭 ���� ��ġ�� pop���ְ� �湮�� ���� üũ�� ��, �湮�� ���� ť�� �ִ� �����Դϴ�
����, �̷� Ž���� ���� �˰����� �ִ� �Ÿ����� ������ Ż���ϴ� ���̱⿡ BFS�� �����մϴ�

������ ����, �̷�Ž���� �����ϴµ�, �̵��� ������ ����ġ�� �پ �̵��Ѵٰų�, 
�̵� �������� ���� ������ ���� ���, DFS�� �����ϴ� ���� �����ϴ�.

*/

// 01. �������� 
int n;
int dv = 0;
int eachDiv = 1;
vector<int> vEachDiv;

int dx[] = {0,0,-1,1}; // �����¿� �̵��� ���� ���ø� 
int dy[] = {1,-1,0,0};// �����¿� �̵��� ���� ���ø�





void dfs(int x, int y, int hou){
		
	// map[x][y] = 0; // �迭�� ���� isVisited ����  
	
	
	hou++;
	eachDiv = hou;
	
	
	for(int i=0; i<4; i++){
		
		int nx = 0, ny = 0;
		
		nx = x + dx[i];
		ny = y + dy[i];
		
		if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
		
		dfs(nx,ny,hou);
		
	} 
	
	
} 


// �ִ��� �޿� üũ�ϰ� �� ������ ī���� �ϴ� ���̹Ƿ� �ִܰŸ��� �����ϴ� ������ �ƴϹǷ� DFS�� ����  
void solve04() {

	int map[25][25]; 

	cin >> n;	
	
	
	// cin.ignore();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
		}
	}
	
	/*
	������ ��� 2nd
	
	1. �迭�� ���� 1�� ��� ���ȣ�� ����
	2. �ʱ�ȭ�� ���������� Ȱ���ϰ� �ݺ��� ������ �̿��ؼ� �������� ����
    3. �������� ī�����ϴ� ���ڸ� �����ؼ� Ǯ��	 
	*/

	dv = 0;	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1){				
				dv = dv + 1;
				map[i][j] = 0; 
				dfs(i,j,1); // 1�� ��� ���̿켱Ž�� start
				vEachDiv.push_back(eachDiv); 								
			} 
			
		}
	}
	
	sort(vEachDiv.begin(), vEachDiv.end());
		
	cout << dv << endl;
	
	for(int i=0; i<dv; i++){
		cout << vEachDiv[i] << endl;
	}	
	
}


int main(){
	
	
	
	//solve03(); // ���丮�� 
	solve04(); // ������ȣ���̱�  
	
	return 0;
}
