#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath> 
using namespace std;

int N,M; // �Է°� 
int eachPower; // ����� 
char map[100][100]; // ������ 
int dx[] = {0,0,-1,1}; // �����¿� �����̴� ���ø� 
int dy[] = {-1,1,0,0}; // �����¿� �����̴� ���ø� 
vector<int> wPower, bPower; // ������ ��� vector


void dfs(int x, int y){
	
	eachPower++; // ����� ���� 
	map[x][y] = 'F'; // 'B', 'W'�� �ƴ� ������ ���Ƿ� ġȯ 
	
	for(int i=0; i<4; i++){ // ���ø� (Ž��) 
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=N || ny>=M || nx<0 || ny<0 || map[nx][ny] == 'F') continue; // 'F' �� ��� ����
		
		if(map[nx][ny] == 'W'){ 
			 dfs(nx,ny); // ���̿켱Ž�� 		
		}
	}		
}

void dfs2(int x, int y){
	
	eachPower++; // ����� ���� 
	map[x][y] = 'F'; // 'B', 'W'�� �ƴ� ������ ���Ƿ� ġȯ 
	
	for(int i=0; i<4; i++){ // ���ø� (Ž��) 
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=N || ny>=M || nx<0 || ny<0 || map[nx][ny] == 'F') continue; // 'F' �� ��� ����
		
		if(map[nx][ny] == 'B'){ 
			 dfs2(nx,ny); // ���̿켱Ž�� 		
		}
	}		
}


int main(){
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 'W'){
				eachPower = 0;
				dfs(i,j);
				wPower.push_back(eachPower);
			}
		}
	}	
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 'B'){
				eachPower = 0;
				dfs2(i,j);
				bPower.push_back(eachPower);
			}
		}
	}	
		
	int wSize = wPower.size(); // �Ͼ��� ���� ��
	int bSize = bPower.size(); // �Ķ��� ���� ��
	
	//printf("%d %d", wPower.size(), bPower.size());
	
	int wRst = 0, bRst = 0;
	
	for(int i=0; i<wSize; i++){
		wRst += pow(wPower[i],wSize);	
	}
	
	for(int i=0; i<wSize; i++){
		bRst += pow(bPower[i],bSize);	
	}
	
	printf("%d %d", wRst, bRst);
	
	return 0;
}

 
