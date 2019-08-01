#include <iostream>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
typedef pair<int, int> Coin;
 
int N, C, res;
Coin coin[20];
int need[20];
 
bool cmp(const Coin & c1, const Coin & c2)
{
	return c1.first > c2.first;
}
 
void solve()
{
	sort(coin, coin + N, cmp);
	
	// value >= C 直接发放 
		for(int i = 0; i < N && coin[i].first >= C; i++){
			res += coin[i].second;
			coin[i].second = 0;
		}
	
	while(true){
		memset(need, 0, sizeof(need));
		
		int temp = C;
		for(int i = 0; i < N; i++){
			if(coin[i].second){ // 如果当前所选coin有剩余
				need[i] = min(coin[i].second, temp / coin[i].first);	// 选择所有的coin
				temp -= need[i] * coin[i].first;
			}
		}
		if(temp > 0){ // 仍有剩余
			for(int i = N - 1 ; i >= 0; i--){	// 从后往前扫描选择达到 剩余价值最小的 
				if(coin[i].second && coin[i].first >= temp){
					need[i]++;
					temp -= coin[i].first;
					break;
				}
			}
		}
		if(temp > 0) // 表示没有可以凑成C的coin了
			break;
		
		int ans = 99999999;
		for(int i = 0; i < N; i++){
			if(need[i])
				ans = min(ans, coin[i].second / need[i]);
		}
		res += ans;
		
		for(int i = 0; i < N; i++)
			if(need[i])
				coin[i].second -= ans * need[i]; 
	}
	cout << res << endl;
}
 
int main()
{
	cin >> N >> C;
	for(int i = 0; i < N; i++)
		cin >> coin[i].first >> coin[i].second;
	solve();
	return 0;
 } 
