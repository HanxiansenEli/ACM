#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
 
#define MAX_N 312
#define MAX_M 50000
 
using namespace std;
 
int M;
struct meteor{
	int x;
	int y;
	int t;
};
 
meteor Meteor[MAX_M];
int filed[MAX_N][MAX_N];
bool flag[MAX_N][MAX_N];
 
int path[5][2] = {{0,-1},{0,1},{-1,0},{1,0},{0,0}};
 
 
bool compare(const meteor & x, const meteor & y)
{
	return x.t < y.t;
}
 
int bfs()
{
	if(filed[1][0] == 0)
		return -1;
	
	memset(flag, 0, sizeof(flag));
	
	queue<meteor> que;
	
	meteor s;
	s.x = 1; s.y = 0; s.t = 0;
	que.push(s);
	
	flag[1][0] = true;
 
	while(que.size()){
		meteor p = que.front();
		que.pop();
		
		if(filed[p.x][p.y] == 0x7f7f7f7f)
			return p.t;
			
		meteor tmp;
		for(int i = 0; i < 4; i++){
			tmp.x = p.x + path[i][0];
			tmp.y = p.y + path[i][1];
			tmp.t = p.t + 1;	
			
			if(tmp.x < MAX_N - 2 && tmp.y < MAX_N - 2 && tmp.x > 0 && tmp.y >= 0 && \
				!flag[tmp.x][tmp.y] && tmp.t < filed[tmp.x][tmp.y]){
				
					que.push(tmp);
					flag[tmp.x][tmp.y] = true;
				}
		}
	}
	return -1;
}
 
 
int main()
{		
	cin >> M;																																																																																			
	memset(Meteor, -1, sizeof(filed));
	for(int i = 0; i < M; i++){
		cin >> Meteor[i].x >> Meteor[i].y >> Meteor[i].t;
	}
	
	memset(filed, 0x7f, sizeof(filed));	
	
	sort(Meteor, Meteor + M, compare);
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < 5; j++){
			int nx = Meteor[i].x + 1 + path[j][0];
			int ny = Meteor[i].y + path[j][1];
			
			filed[nx][ny] = min(Meteor[i].t, filed[nx][ny]);
			}
	}
	cout << bfs();
}
