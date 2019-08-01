#include <iostream>
#include <set>
#include <string> 
 
using namespace std;
 
int imap[5][5], stride;
int path[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
bool flag[5][5];
set<string> s;
string tp;
 
 
void dfs(int cx, int cy)
{
	int px = cx, py = cy;
	for(int i = 0; i < 4; i++){
		px = cx + path[i][0];
		py = cy + path[i][1];
		
		if(px >= 0 && py >= 0 && px < 5 && py < 5 && stride < 5){
			
			tp += (imap[px][py] - 48);
			
			if(stride == 4){
				if(s.find(tp) == s.end()){
					s.insert(tp);
				}
			}
			
			stride++;
			dfs(px, py);
			stride--;
			tp.erase(tp.end() - 1);
		}
	}
}
 
void solve()
{
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++){
			memset(flag, false, sizeof(flag));
			flag[i][j] = true;
			stride = 0;
			tp = (imap[i][j] - 48);
			dfs(i, j);
		}
	cout << s.size() << endl;
}
 
int main()
{
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin >> imap[i][j];
			
	solve();
	return 0;	
} 
