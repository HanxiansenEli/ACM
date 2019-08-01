#include <iostream>
#include <queue>
 
#define INF -1
#define MAX_N 10001
#define MAX_M 11
 
using namespace std;
 
typedef pair<int, int> P;
 
int sx, sy, n, h, w;
int res;
char filed[MAX_N][MAX_N];
 
int d[MAX_N][MAX_N]; 
int path[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
 
P award[MAX_M];
 
 
int bfs(int sx, int sy, int gx, int gy)
{
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			d[i][j] = INF;
	queue<P> que;
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	
	
	while(que.size()){
		
		P p = que.front();
		que.pop();
		
		if(p.first == gx && p.second == gy)
			break;
		
		for(int i = 0; i < 4; i++){
			int nx = p.first + path[i][0];
			int ny = p.second + path[i][1];
			
			if(nx >= 0 && ny >= 0 && nx < h && ny < w && \
			filed[nx][ny] != 'X' && d[nx][ny] == INF){
				d[nx][ny] = d[p.first][p.second] + 1;
				que.push(P(nx, ny));
			}
		}
	}
	return d[gx][gy];
}
 
int main()
{
	while(cin >> h >> w >> n, n || h || w){
		res = 0;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				cin >> filed[i][j];
				
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(filed[i][j] == 'S'){
					sx = i;
					sy = j;
				}
				
				if(filed[i][j] >= '0' && filed[i][j] <= '9'){
					award[filed[i][j] - 48].first = i;
					award[filed[i][j] - 48].second = j;
				}
			}
		}
			
		for(int i = 1; i <= n; i++){
			res += bfs(sx, sy, award[i].first, award[i].second);
			//cout << bfs(sx, sy, a) 
			sx = award[i].first;
			sy = award[i].second;
		}
		cout << res;
	}
}
