#include<iostream>
#include<cmath>
using namespace std;

int w[9] = {0};
int b[9] = { 0 };
int chessboard[9][9]={0};
int sum=0;
int n;
int flag = 0;

int clo(int i,int j,int a[]) {
	for (; i-1 > 0; i--) 
		if (a[i-1] == j) return 0;
	return 1;
}

int dia(int i, int j, int a[]) {
	int k1 = i + j, k2 = abs(i - j);
	for (int q = i, p = j; p+1 <= n&&q - 1 > 0; q--, p++) 
		if (abs(a[q - 1] - j) == abs(q - 1 - i)) return 0;
	for (int q = i, p = j; p - 1 > 0 && q - 1 > 0; q--, p--)
		if (abs(a[q - 1] - j) == abs(q - 1 - i)) return 0;
	return 1;
}

void empty(int i, int a[]) {
	for (; i <= n; i++) a[i] = 0;
}

int two( int i,int j) {
	if (b[i] == j) return 0;
	else return 1;
}
void wq();
void bq() {
	int i = 1, j = 1;
	for (; i <= n;) {
		for (; j <= n;) {
			if (chessboard[i][j]) {
				if (clo(i, j, b) && dia(i, j, b)) {
					b[i] = j;
					j = 1;
					break;
				}
				else ++j;
			}
			else ++j;
		}
		if (b[i] == 0) {
			if (i == 1) break;
			else {
				--i;
				j = b[i] + 1;
				b[i] = 0;
				continue;
			}
		}
		if (i == n) {
			wq();
			j = b[i] + 1;
			b[i] = 0;
			continue;
		}
		++i;
	}
}



void wq() {
	int i = 1, j = 1;
	for (; i <= n;) {
		for (; j <= n;) {
			if (chessboard[i][j]&&two(i,j)) {
				if (clo(i, j, w) && dia(i, j, w)) {
					w[i] = j;
					j = 1;
					break;
				}
				else ++j;
			}
			else ++j;
		}
		if (w[i] == 0) {
			if (i == 1) break;
			else {
				--i;
				j = w[i] + 1;
				w[i] = 0;
				continue;
			}
		}
		if (i == n) {
			sum++;
			j = w[i] + 1;
			w[i] = 0;
			continue;
		}
		++i;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> chessboard[i][j];
	bq();
	cout << sum << endl;
}
