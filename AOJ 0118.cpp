#include <iostream>
#define MAX_N 101
using namespace std;
 
int N, M;
char filed[MAX_N][MAX_N];
int path[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int res;
 
void dfs(int rx, int ry, char flag)
{
	filed[rx][ry] = '.';
	for(int i = 0; i < 4; i++){
		int dx = rx + path[i][0];
		int dy = ry + path[i][1];
		
		if(dx >= 0 && dy >= 0 && dx < M && dy < N && filed[dx][dy] == flag){
			dfs(dx, dy, flag);
		}
	}
} 
 
void solve()
{
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(filed[i][j] != '.'){
				dfs(i, j, filed[i][j]);
				res++;
			}
		}
	}
	cout << res << endl;
}
 
int main()
{
	while(cin >> M >> N, N > 0){
		res = 0;
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				cin >> filed[i][j];
			}
		}	
		solve();
	}
	return 0;
}
