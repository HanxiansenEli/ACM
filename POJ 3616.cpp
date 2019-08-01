#include <iostream>
#include <algorithm>
// LIS思路 
using namespace std;
 
struct cow{
	int start, end, effi;
};
 
int N, M, R, res;
cow cows[1002];
int dp[1002];
 
bool compare(const cow & c1, const cow & c2){
	return c1.start < c2.start;
}
 
void solve()
{
	sort(cows, cows + M, compare);
	for(int i = 0; i < M; i++){
		dp[i] = cows[i].effi;
		for(int j = 0; j < i; j++){
			if(cows[i].start >= cows[j].end)    // 这个细节部分注意一下, 有等于
				dp[i] = max(dp[i], dp[j] + cows[i].effi);
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
}
 
int main()
{
	cin >> N >> M >> R;
	for(int i = 0; i < M; i++){
		cin >> cows[i].start >> cows[i].end >> cows[i].effi;
		cows[i].end += R;
	}
		
	solve();
} 
