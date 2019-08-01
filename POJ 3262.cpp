#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct cow{
	int T, D;
	double rate;
}; 
 
int N;
cow c[100001];
long long res;
 
bool cmp(const cow & c1, const cow & c2){
	return c1.rate < c2.rate;
}
 
void solve()
{
	for(int i = 0; i < N; i++){
		c[i].rate = c[i].T / (c[i].D * 1.0);		
	}
	sort(c, c + N, cmp);
	
	long long temp = 0;
	for(int i = 1; i < N; i++)
		temp += c[i].D;
	
	for(int i = 0; i < N - 1; i++){
		res += c[i].T * 2 * temp;
		temp -= c[i + 1].D;
	}
	
	cout << res << endl;
}
 
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> c[i].T >> c[i].D;
	solve();	
} 
