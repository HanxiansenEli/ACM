#include <iostream>
 
using namespace std;
 
int N, ball[351][351];
int * Sum;
 
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= i; j++)
			cin >> ball[i][j];
	
	Sum = ball[N-1];
	for(int i = N - 2; i >= 0; i--)
		for(int j = 0; j <= i; j++)
			Sum[j] = max(Sum[j], Sum[j + 1]) + ball[i][j];
	cout << Sum[0] << endl;
 } 
