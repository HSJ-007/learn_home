#include<iostream>
#include<algorithm>
#include<queue>
#include<iomanip> 
#define inf 0x3f3f3f3f
using namespace std;

int n, m;
int x, y;
int map[401][401];
int dong[9][2] = {{0, 0}, {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
struct node {
	int x;
	int y;
};
queue<node> s;

void bfs() {
	int num = 0; //步数
	while (!s.empty()) {

		node hd = s.front();
		s.pop();
		num = map[hd.x][hd.y] + 1;
		for (int i = 1; i < 9; i++) {
			if (hd.x + dong[i][0] > n || hd.x + dong[i][0] < 1 || hd.y + dong[i][1] > m || hd.y + dong[i][1] < 1)
				continue;//是否越界
			else if (map[hd.x + dong[i][0]][hd.y + dong[i][1]] <= num)
				continue;//剪枝
			else {
				map[hd.x + dong[i][0]][hd.y + dong[i][1]] = num;
				node bk;
				bk.x = hd.x + dong[i][0];
				bk.y = hd.y + dong[i][1];
				s.push(bk);//放入新的被挖掘的点 
			}
		}

	}
}
int main(void) {
	cin >> n >> m;
	cin >> x >> y;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			map[i][j] = inf;
	struct node first;
	first.x = x;
	first.y = y;
	s.push(first);
	map[x][y] = 0;
	//////////////初始化
	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (map[i][j] == inf)
				cout <<setw(5)<<left<< -1;
			else
				cout <<setw(5)<<left<< map[i][j];
		cout << endl;
	}
	return 0;
}

/*知识点：BFS广搜 
小常识：流算子iomanip头文件
setw(int num)   :该函数控制位宽 ，num就是数
left            :如果字符长度不够，将填充字符放在字符后面 (将字符串左移)
*/
 