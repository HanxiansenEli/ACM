#include <iostream>
#include <algorithm>
using namespace std;
 
int n, res;
int s[11];
int t[11];
 
void cal(int n)
{
	while(n > 0){
		for(int i = 0; i < n - 1; i++)
			t[i] = t[i] + t[i+1];
		--n;
	}
}
 
void solve()
{
	for(int i = 0; i < n; i++){
		s[i] = i + 1;
	}
	do{
		for(int i = 0; i < n; i++)
			t[i] = s[i];
		cal(n);
		
		if(t[0] == res)
			break;
	}while(next_permutation(s, s + n));
	
	for(int i = 0; i < n; i++)
		cout << s[i] << " ";
}
 
int main()
{
	while(cin >> n >> res){
		solve();
	}
}
