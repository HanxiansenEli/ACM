#include <iostream>
#include <math.h>
 
using namespace std;
 
int count[6], res;
 
// sec1:最多可以放入多少个 2 * 2, sec2: 最多可以放入多少个 1 * 1 
void func(int sec1, int sec2)
{
	if(count[1] / (sec1 * 1.0) < 1){
		count[0] = max(count[0] - sec2 - (sec1 - count[1]), 0);
		count[1] = 0;
	}
	
	else{
		count[1] -= sec1;
		count[0] = max(count[0] - sec2, 0);
	}
}
 
void solve()
{
	// 放入 6 * 6 pack
	res += count[5];
	
	// 放入 5 * 5 pack
	if(count[4]){
		res += count[4];
		count[0] = max(count[0] - count[4] * 11, 0);
	}
	
	// 放入 4 * 4 pack
	if(count[3]){
		res += count[3];
		// p = 0, 表示正好放入或者还有剩余位置
		// p != 0, 表示全部放入
		int p = max(count[1] - count[3] * 5, 0);
		 
		if(!p)
			count[0] = max(count[0] - (count[3] * 20 - 4 * count[1]), 0);
		
		count[1] = p;
	}
	// 放入 3 * 3 pack
	if(count[2]){
		int rem = count[2] % 4;
		res += ceil(count[2] / 4.0);
		switch(rem){
			case 0:{
				break;
			}
			
			// 5个 2 * 2 pack, 7个 1 * 1 pack 
			case 1:{
				func(5, 7);
				break;
			}
			
			// 3 个 2 * 2 pack, 6个 1 * 1 pack 
			case 2:{
				func(3, 6);
				break;
			}
			
			// 1 个 2 * 2 pack, 5个 1 * 1 pack 
			case 3:{
				func(1, 5);
				break;
			}
		}
	}
	
	if(count[1]){
		res += ceil(count[1] / 9.0);
		count[0] = max(count[0] - 36 + count[1] % 9 * 4, 0);
	}
	
	res += ceil(count[0] / 36.0);
	
	cout << res << endl;
}
 
int main()
{
	while(true){
		res = 0;
		for(int i = 0; i < 6; i++)
			cin >> count[i];
			
		bool flag = false;
		for(int i = 0; i < 6; i++){
			if(count[i])
				flag = true;
		}
		if(!flag)
			break;
		else
			solve();
	}
} 
