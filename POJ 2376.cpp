#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
 
typedef pair<int, int> p;
 
int N, T;
p cows[25001];
int res;
 
void solve()
{
	// 标记终点 遍历数组索引 
	int end = 0, ind = 0;
	 
	sort(cows, cows + N);
	
	while(end < T){
		p tmp;
		tmp.first = 0;
		tmp.second = 0;
		
		bool isok = false; 
		
		// 在 start ~ end 内选取终点长度最大的 
		for(int i = ind; cows[i].first <= end + 1; i++){
			if(cows[i].second >= end + 1 && cows[i].second > tmp.second){
					isok = true;
					ind = i;
					tmp = cows[i];
			}
		}
		if(!isok){
			res = -1;
			break;
		}
		
		end = tmp.second;
		res++;
	}
}
 
int main()
{
	while(cin >> N >> T)
	{
		res = 0;
		for(int i = 0; i < N; i++)
			cin >> cows[i].first >> cows[i].second;
		solve();
		cout << res << endl;
	}
} 
