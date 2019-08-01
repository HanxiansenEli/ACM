#include<iostream>
using namespace std;
int T, W, tree[1001], res;
int dp[31];
 
void solve()
{
	for(int i = 1; i <= T; i++)
		for(int j = 0; j <= W; j++){
			dp[j] = max(dp[j], dp[j-1]) + (tree[i] == j % 2); 
		}
	for(int j = 0; j <= W; j++)
		res = max(res, dp[j]);
	cout << res << endl;
}
 
int main()
{
	cin >> T >> W;
	for(int i = 1; i <= T; i++){
		cin >> tree[i];
		tree[i]--;
	}
	solve();
} 
