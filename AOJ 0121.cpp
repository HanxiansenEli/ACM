#include <iostream>
#include <map>
#include <queue>
#include <string>
 
using namespace std;
 
typedef pair<string, int> p;
map<string, int> simap;
 
int path[4] = {-1, 1, -4, 4};
 
void bfs(){
	queue<p> que;
	que.push(p("01234567",0));
 
	simap.insert(map<string, int>::value_type("01234567", 0));
	while(!que.empty()){
		p cur = que.front();
		que.pop();
		int lo = cur.first.find("0", 0);
 
		//if(cur.first == "01234567")
		//	simap.insert(map<string, int>::value_type(cur.first,cur.second));
 
		for(int i = 0; i < 4; i++){
			int cur_lo = lo + path[i];
 
			if(cur_lo <= 7 && cur_lo >= 0 && \
			!(cur_lo == 3 && path[i] == 1) && \
			!(cur_lo == 4 && path[i] == -1)){
 
				p tmp = cur;
				tmp.first = cur.first;
				swap(tmp.first[cur_lo], tmp.first[lo]);
 
				// 不在搜索树中
				if(simap.find(tmp.first) == simap.end()){
					tmp.second = cur.second + 1;
					simap.insert(map<string, int>::value_type(tmp.first, tmp.second));
					que.push(tmp);
				}
			}
		}
	}
}
 
int main()
{
	bfs();
 
	string s;
	while(getline(cin, s, '\n')){
		int begin = s.find(" ", 0);
		while(begin != -1){
			s.replace(begin, 1, "");
			begin = s.find(" ", begin);
		}
		cout << simap[s] << endl;
	}
}
