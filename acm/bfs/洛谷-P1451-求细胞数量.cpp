#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


int n, m;
int map[101][101];
int book[101][101];
int wei[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans;
struct node {
	int x;
	int y;
};
queue<node>s;

void bfs(int x, int y) {
	ans++;
	node hd;
	hd.x = x;
	hd.y = y;
	s.push(hd);
	book[x][y] = 1;
	while (!s.empty()) {
		hd = s.front();
		s.pop();
		for (int i = 1; i <= 4; i++) {
			int xx = hd.x + wei[i][0];
			int yy = hd.y + wei[i][1];
			if (xx < 1 || xx > n || yy > m || yy < 1)
				continue;
			if (map[xx][yy] == 0 || book[xx][yy] == 1)
				continue;
			else {
				node bk;
				bk.x = xx;
				bk.y = yy;
				s.push(bk);
				book[xx][yy] = 1;
			}
		}
	}
	return ;
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		 scanf("%1d",&map[i][j]);
	}
	///////初始化
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0 || book[i][j] == 1)
				continue;
			else
				bfs(i, j);
		}

	cout << ans;



	return 0;
}