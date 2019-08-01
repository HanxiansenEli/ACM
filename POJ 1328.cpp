#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
typedef pair<double, double> pd;
 
int n, d, cnt, res;
pair<int, int> p[1001];
 
pd sec[1001];
int __res[1001];
bool isok;
 
bool cmp(pd p1, pd p2)
{
	return p1.second < p2.second;	
}
 
void solve()
{
	res = 0;
	for(int i = 0; i < n; i++){
		int x = p[i].first, y = p[i].second;
		
		int anchor = x;
		
		if(y > d){
			isok = false;
			return; 
		}
		else
			isok = true;
			
			
		double len = sqrtf(d * d - y * y);
		sec[i].first = x - len;
		sec[i].second = x + len;
		/*
		while( fabs(sqrtf( y * y + (x-anchor)*(x-anchor))) - d < 1e-2 ){
			anchor++;
			isok = true;
		}
		
		if(!isok)
			return;
		anchor--;
		
		sec[i].first = x - (anchor - x);
		sec[i].second = anchor;
		*/
	}
	
	sort(sec, sec + n, cmp);
	
	for(int i = 0; i < n;){
		double anchor = sec[i].second;
		while(anchor >= sec[i].first && anchor <= sec[i].second)
			i++;
		res++;
	}
}
 
int main(){
	while(cin >> n >> d, n, d)
	{
		for(int i = 0; i < n; i++){
			cin >> p[i].first >> p[i].second;
		}
		solve();
		
		if(isok)
			__res[cnt++] = res;
		else
			__res[cnt++] = -1;
	}
	for(int i = 0; i < cnt; i++)
		cout << "Case " << i + 1 << ": " << __res[i] << endl;
		
}
