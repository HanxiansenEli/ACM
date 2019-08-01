#include <iostream>
#include <string>
#define M 11
#define N 10001
 
using namespace std;
 
int r, c, res, max_res;
bool imap[M][N];
int ret[N];
 
void solve(int i)
{
	if(i == r){
		res = 0;
		
		for(int j = 0; j < c; j++)
			ret[j] = 0;
	
		for(int j = 0; j < c; j++)
			for(int k = 0; k < r; k++)
				if(imap[k][j])
					ret[j]++;
		
		for(int j = 0; j < c; j++)
			res += max((r - ret[j]), ret[j]);
		max_res = max(res, max_res);
		return;
	}
	solve(i + 1);
	for(int k = 0; k < c; k++)
		imap[i][k] = !imap[i][k];
	solve(i + 1);
}
 
int main()
{
	while(cin >> r >> c, r, c){
		max_res = 0;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				cin >> imap[i][j];
		solve(0);
		cout << max_res << endl;
	}
}
