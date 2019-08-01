#include <iostream>
#define INF -99999999
 
using namespace std;
 
int N;
int a[10];
 
bool solve()
{
	bool flag = true;
	int b[11], c[11];
	b[0] = INF + 1;
	c[0] = INF;
	int p1 = 0,p2 = 0;
	for(int i = 0; i < 10; i++){
		if(a[i] > b[p1]){
			if(a[i] > c[p2]){
				if(b[p1] > c[p2])
					b[++p1] = a[i];
				else
					c[++p2] = a[i];
			}
			b[++p1] = a[i];
		}
		else if(a[i] > c[p2])
			c[++p2] = a[i];
		else{
			flag = false;
			break;
		}
	}
	return flag;
}
 
int main()
{
	cin >> N;
	while(N--){
		for(int i = 0; i < 10; i++)
			cin >> a[i];
		if(solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
