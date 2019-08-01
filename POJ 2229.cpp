// 超时代码
/*
#include<iostream>
#define M 1000001
 
using namespace std;
 
int N;
int dp[M], scale[21];
 
int main()
{
	scale[0] = 1;
	for(int i = 1; i < 20; i++)
		scale[i] = scale[i - 1] * 2;	
	
	dp[0] = 1;
	for(int i = 0; i < 20; i++)
		for(int j = scale[i]; j < M; j++)
			dp[j] = (dp[j] + dp[j - scale[i]]) % 1000000000;
		
	while(cin >> N)
		cout << dp[N] << endl;
}
*/

// 正确代码
#include<iostream>
 
using namespace std;
 
int a[1000002], N;
int main()
{
	a[0] = 1;
	for(int i = 1; i <= 1000002; i++){
		if(i & 1)
			a[i] = a[i-1];
		else 
			a[i] = (a[i >> 1] + a[i - 1]) % 1000000000;
	}
	while(cin >> N)
		cout << a[N] << endl;
} 
