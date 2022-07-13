#include <iostream>
#include <algorithm>
using namespace std;

int a[101][101];
bool check[101][101] = { false };
int n;
int mat[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };

void dfs(int x, int y, int h) {
	check[x][y] = true;
	int nextX, nextY;
	for (int i = 0; i < 4; i++) {
		nextX = x + mat[i][0];
		nextY = y + mat[i][1];
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY <n && check[nextX][nextY] == false && a[nextX][nextY]>h) dfs(nextX, nextY, h);
	}
}

int main() {
	int s = 150;
	int m = 0;
	int cnt;
	int answer = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			s = min(a[i][j], s);
			m = max(a[i][j], m);
		}
	}
	for (int k = s; k < m; k++) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > k && check[i][j] == false) { //물에 잠기지 않은 곳을 세야 하므로 >k 를 함
					dfs(i, j, k); //현재 높이도 넘겨줌(높이 넘는 것만 찾기 위해)
					cnt++; //해당 구역 카운트 올림
				}
			}
		}
		if (cnt > answer) {
			answer = cnt;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false; //다음 높이 시작하기 전 visit 초기화 필요
			}
		}
	}
	if (answer == 0) printf("1\n");
	else {
		printf("%d\n", answer);
	}
	return 0;
}