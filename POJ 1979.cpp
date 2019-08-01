#include <iostream>
#define MAX_N 10001
using namespace std;
 
int N, M;
int rx, ry;
char filed[MAX_N][MAX_N];
int path[][4] = {{1, 0},{0, -1},{-1, 0},{0, 1}};
int res;
 
void dfs(int px, int py)
{
	for(int i = 0; i < 4; i++)
	{
		int sx = px + path[i][0];
		int sy = py + path[i][1];
		if(sx < M && sy < N && sx >= 0 && sy >= 0 &&  filed[sx][sy] == '.'){
			filed[sx][sy] = '#';
			res++;
			dfs(sx, sy);
		}
	}
}
 
void solve()
{
	dfs(rx, ry);	
	cout << res << endl;
}
 
int main()
{
	while(cin >> N >> M && M || N){
		res = 1;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++){
				cin >> filed[i][j];
				if(filed[i][j] == '@'){
					rx = i;
					ry = j;
				}
			}
		solve();
	} 
	
	return 0;
}
