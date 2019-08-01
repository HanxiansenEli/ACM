#include <iostream>
 
using namespace std;
 
int N, S;
long long res;
int cost[10001], del[10001];
 
void solve()
{
	
	res += cost[0] * del[0];
	for(int i = 1; i < N; i++){
		
		int min_cost = cost[i];
		for(int j = 0; j < i; j++)
			min_cost = min(min_cost, cost[j] + (i - j) * S);
	
		res += min_cost * del[i];
	}
	
	cout << res << endl;
}
 
int main()
{
	cin >> N >> S;
	for(int i = 0; i < N; i++)
		cin >> cost[i] >> del[i];
	solve();
}
