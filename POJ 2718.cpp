#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 99999999
 
using namespace std;
 
char s[11];
int perm[11];
int res;
int rank[5] = {1, 10, 100, 1000, 10000}; 
 
 
void solve(int len)
{
	for(int i = 0; i < len; i++){
		perm[i] = i;
	}
	
	do{
		if(s[perm[len / 2 - 1]] == '0' || s[perm[len - 1]] == '0' && len > 2)
			continue;
		
		int ans1 = 0, ans2 = 0;
		int ind = 0;
		for(int i = 0; i < len / 2; i++)
			ans1 += (s[perm[i]] - 48) * rank[ind++];
		
		ind = 0;
		for(int i = len / 2; i < len; i++)
			ans2 += (s[perm[i]] - 48) * rank[ind++];
			
		int ans = max(ans1, ans2) - min(ans1, ans2);
		
		if(ans < res)
			res = ans;
		
	}while(next_permutation(perm, perm + len));
}
 
int main()
{
	
	int m;
	cin >> m;
	getchar();
 
	for(int i = 0; i < m; i++){
		res = INF;
		char t[21];
		gets(t);
		char *pt = t, *st = s;
		
		while(*pt != '\0'){
			if(*pt != ' '){
				*st++ = *pt;
			}
			pt++;
		}
		*st = '\0';
		
		int len = strlen(s);
		solve(len);
		cout << res << endl;
	}
 } 	
