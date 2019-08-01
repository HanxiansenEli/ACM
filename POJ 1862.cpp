#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
 
using namespace std;
 
int N;
priority_queue<double> que;
 
void solve()
{
	// 直到剩下一个元素就是最小的 
	while(que.size() > 1){
		double t1 = que.top();
		que.pop();
		double t2 = que.top();
		que.pop();
		
		que.push(2 * sqrt(t1 * t2));
	}
	
	printf("%.3f\n", que.top());
}
 
int main()
{
	double temp;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> temp;
		que.push(temp);
	}
	solve();
} 
