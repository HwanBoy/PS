#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath> 
#include<cstring>

using namespace std;

int N,M; // �Է°� 
int eachPower; // ����� 
char map[100][100], cpy[100][100]; // ������ 
int dx[] = {0,0,-1,1}; // �����¿� �����̴� ���ø� 
int dy[] = {-1,1,0,0}; // �����¿� �����̴� ���ø� 
vector<int> wPower, bPower; // ������ ��� vector


// 'W' ����� ī��Ʈ (�Ʊ�) 
void dfs(int x, int y){
	
	eachPower++; // ����� ���� 
	map[x][y] = 'F'; // 'B', 'W'�� �ƴ� ������ ���Ƿ� ġȯ 
	
	for(int i=0; i<4; i++){ // ���ø� (Ž��) 
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=M || ny>=N || nx<0 || ny<0) continue; // 'F' �� ��� ����
		
		if(map[nx][ny] == 'W'){
			dfs(nx,ny); 			
		}
		
	}		
}

// 'B' ����� ī��Ʈ (����) 
void dfs2(int x, int y){
	
	eachPower++; // ����� ���� 
	cpy[x][y] = 'F'; // 'B', 'W'�� �ƴ� ������ ���Ƿ� ġȯ 
	
	for(int i=0; i<4; i++){ // ���ø� (Ž��) 
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=M || ny>=N || nx<0 || ny<0) continue; // 'F' �� ��� ����
		
		if(cpy[nx][ny] == 'B'){
			dfs2(nx,ny); 			
		}
		
	}		
}



int main(){
	
	cin >> N >> M;
	
	// �Է¹� 
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	
	// copy
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cpy[i][j] = map[i][j];
		}
	}
	
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == 'W'){
				eachPower = 0;
				dfs(i,j);
				wPower.push_back(eachPower);
			}
		}
	}
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(cpy[i][j] == 'B'){
				eachPower = 0;
				dfs2(i,j);
				bPower.push_back(eachPower);
			}
		}
	}
	
		
	int wSize = wPower.size(); // �Ͼ��� ���� ��
	int bSize = bPower.size(); // �Ķ��� ���� ��
	
	int wRst = 0, bRst = 0;
	
	for(int i=0; i<wSize; i++){
		wRst += pow(wPower[i],2);	
	}
	
	for(int i=0; i<bSize; i++){
		bRst += pow(bPower[i],2);	
	}
	
	printf("%d %d", wRst, bRst);
	
	return 0;
}

