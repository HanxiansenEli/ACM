#include <iostream>
#define INF 9999
#define MAX_N 21
 
using namespace std;
 
typedef pair<int, int> p;
 
int d[MAX_N][MAX_N];
int w, h, sx, sy, gx, gy;
int direction[4][2] = {{0,-1},{0,1},{-1,0},{1,0}}; // 左右上下 
int res, min_res;
int state; // 0: 遇到障碍	1: 经过终点  	2: 出界 
 
p station(int px, int py, int i)
{
    while(px < h && py < w && px >= 0 && py >= 0){
        px += direction[i][0];
        py += direction[i][1];
        
        // 遇到障碍物
        if(d[px][py] == 1){
        	state = 0; 
        	d[px][py] = 0; 
        	break;
		}
		
		// 遇到终点
		if(px == gx && py == gy){
			state = 1;
			break;
		}
    }
    
    // 出界
    if(px == h || py == w || px < 0 || py < 0){	
        state = 2;
    }
    
    p temp;
    temp.first = px - direction[i][0];
    temp.second = py - direction[i][1];
    
    return temp;
}
 
void dfs(int cx, int cy)
{
	if(res >= 10 || res > min_res) // 剪枝 
		return;
		
		
    for(int i = 0; i < 4; i++){
        int px = cx + direction[i][0];
        int py = cy + direction[i][1];
        if(px >= 0 && py >= 0 && px < h && py < w && d[px][py] != 1){
                p temp = station(cx, cy, i);
                
                if(state == 2){
                	continue;
				}
				
                if(state == 1){
                	min_res = min(res + 1, min_res);
                	continue;
				}
				
				
				res++;
                dfs(temp.first, temp.second);
                
                // 恢复现场 
                res--;
                d[temp.first + direction[i][0]][temp.second + direction[i][1]] = 1;
                
        }
    }
}
void solve()
{
	dfs(sx, sy);
	cout << (min_res > 10 ? -1 : min_res) << endl;
}
 
int main()
{
    while(cin >> w >> h, w || h){
    	
    	min_res = INF;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++){
                    cin >> d[i][j];
            if(d[i][j] == 2){
                sx = i; sy = j;
            }
            else if(d[i][j] == 3){
                gx = i; gy = j;
            }
        }
    solve();
    }
}
