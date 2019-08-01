#include <iostream>
 
using namespace std;
 
int main()
{
	double a[10000];
	int N,K;
	cin >> N >> K;
	int number = 0,low = 0,high = 0;
	for(int i = 0; i < N; ++i)
	{
		cin >> a[i];
		a[i] *= 100;
		if(high < a[i])
			high = a[i]; 
	}
	
	high += 1;	// 精度设置为0.01 
	
	while(low < high - 1)
	{
		number = 0;
		int mid = (low + high) / 2;
		for(int i = 0; i < N; ++i)
			number += a[i] / mid;
		if(number >= K)		// 不断更迭 low high 缩小范围 
			low = mid;
		else
			high = mid; 
	}
	
	if(low < 1) 
		printf("%.2f",0);
	else
		printf("%.2f",low / 100.0);
	return 0;
}
