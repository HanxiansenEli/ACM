#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct cow{
	int id, first, second, pos;
	bool operator < (const cow & p) const{
		return second > p.second;
	}
};
 
bool cmp(const cow & p1, const cow & p2){
	return p1.first < p2.first;
}
 
int N, ans, res[50001];
cow cows[50001];
 
void solve()
{
	priority_queue<cow> que;
	
	sort(cows, cows + N, cmp);
 
	cows[0].pos = ++ans;
	que.push(cows[0]);
	
	for(int i = 1; i < N; i++){
		cow tmp = que.top();
		
		if(cows[i].first > tmp.second){
			
			res[tmp.id] = tmp.pos;
			que.pop();
			
			cows[i].pos = tmp.pos;
			que.push(cows[i]);
		}
		else{
			cows[i].pos = ++ans;
			que.push(cows[i]);
		}
	}
	
	while(que.size()){
		cow tmp = que.top();
		res[tmp.id] = tmp.pos;
		que.pop();
	}
	
	cout << ans << endl;
	for(int i = 0; i < N; i++)
		cout << res[i] << endl;
}
 
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		scanf("%d %d", &cows[i].first, &cows[i].second);
	
	for(int i = 0; i <= N; i++)
		cows[i].id = i;
	solve();
}
