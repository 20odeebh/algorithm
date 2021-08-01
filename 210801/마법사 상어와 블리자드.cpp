#include <iostream>
#include <queue>

using namespace std;

int n, m, shark_y, shark_x;
int ball[50][50][2],arr[3];
int ry[] = {0,-1,0,1}, rx[] = {1,0,-1,0};
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};


void move() {
	int d = ball[shark_y][shark_x][1];
	int ny = shark_y + ry[d];
	int nx = shark_x + rx[d];
	queue<int> q;

	while (!(ny == 1 && nx == 0)) {
		if (ball[ny][nx][0] == 0)break;
		if (ball[ny][nx][0] != -1) {
			q.push(ball[ny][nx][0]);
			
		}		
		d = ball[ny][nx][1];
		ny += ry[d];
		nx += rx[d];
	}

	d = ball[shark_y][shark_x][1];
	ny = shark_y + ry[d];
	nx = shark_x + rx[d];

	while (!(ny == 1 && nx == 0)) {
		if (q.empty()) ball[ny][nx][0] = 0;
		else {
			ball[ny][nx][0] = q.front();
			q.pop();
		}
		d = ball[ny][nx][1];
		ny += ry[d];
		nx += rx[d];
	}
}

void throw_ice(int di, int si) {
	for (int i = 1; i <= si; i++) {
		int ny = shark_y + (dy[di] * i);
		int nx = shark_x + (dx[di] * i);
		ball[ny][nx][0] = -1;
	}	
	move();
}

void explode() {			
		while (true) {
			bool flag = false;
			int cy = shark_y + ry[2];
			int cx = shark_x + rx[2];
			int d = ball[cy][cx][1];
			int ny = cy + ry[d];
			int nx = cx + rx[d];
			int state = ball[cy][cx][0];

			while (!(ny == 1 && nx == 3)) {
				vector <pair<int, int>> temp;
				//cout << cy << " " << cx << " " << d << " " << ny << " " << nx << " " << state << "\n";
				if (ball[cy][cx][0] == 0)break;
				temp.push_back({ cy,cx });
				while (state == ball[ny][nx][0]) {
					temp.push_back({ ny,nx });
					d = ball[ny][nx][1];
					ny += ry[d];
					nx += rx[d];
				}

				if (temp.size() >= 4) {
					flag = true;
					for (auto a : temp) {
						arr[--ball[a.first][a.second][0]]++;
						ball[a.first][a.second][0] = -1;
					}
				}

				cy = ny;
				cx = nx;
				state = ball[cy][cx][0];
				d = ball[cy][cx][1];
				ny = cy + ry[d];
				nx = cx + rx[d];
			}
			if (flag)move();
			else break;
		}
		
}

void change() {
	bool flag = false;
	int cy = shark_y + ry[2];
	int cx = shark_x + rx[2];
	int d = ball[cy][cx][1];
	int ny = cy + ry[d];
	int nx = cx + rx[d];
	int state = ball[cy][cx][0];
	int t_board[50][50] = { 0, };
	int ty = cy;
	int tx = cx;
	int td = d;

	while (!(ny == 1 && nx == 0)) {
		vector <pair<int, int>> temp;
		//cout << cy << " " << cx << " " << d << " " << ny << " " << nx << " " << state << "\n";
		if (ball[cy][cx][0] == 0)break;
		int cnt = 1;
		while (state == ball[ny][nx][0]) {
			cnt++;
			d = ball[ny][nx][1];
			ny += ry[d];
			nx += rx[d];
		}

		if (ty == 1 && tx == 0)break;
		t_board[ty][tx] = cnt;
		td = ball[ty][tx][1];
		ty += ry[td];
		tx += rx[td];

		if (ty == 1 && tx == 0)break;
		t_board[ty][tx] = state;
		td = ball[ty][tx][1];
		ty += ry[td];
		tx += rx[td];

		cy = ny;
		cx = nx;
		state = ball[cy][cx][0];
		d = ball[cy][cx][1];
		ny = cy + ry[d];
		nx = cx + rx[d];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ball[i][j][0]=t_board[i][j];
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ball[i][j][0];
		}
	}
	
	shark_y = (n + 1) / 2;
	shark_x = (n + 1) / 2;
	int ny = shark_y;
	int nx = shark_x;
	int d = 2;

	for (int i = 1; i <= n - 1; i++) {
		for (int cnt = 1; cnt <= 2; cnt++) {
			for (int j = 1; j <= i; j++) {
				//cout << ny << " " << nx << " " << d << "\n";
				ball[ny][nx][1] = d;
				ny += ry[d];
				nx += rx[d];
			}
			d = (d + 1) % 4;
		}
	}

	for (int i = 1; i <= n; i++) {
		ball[ny][nx][1] = d;
		ny += ry[d];
		nx += rx[d];
	}
	while (m--) {
		int di, si;
		cin >> di >> si;
		di--;
		throw_ice(di, si);
		explode();
		change();
	}
	
	int rs = 0;
	for (int i = 0; i < 3; i++) {
		rs += arr[i] * (i + 1);
	}
	cout << rs;
}