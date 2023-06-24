// 2019067429_ÇÑ½Â¿ì_B

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int N;
vector<int> p;
int m[101][101];
int s[101][101];
int num = 1;
void print_answer(int s[101][101], int i, int j)
{
	if (i == j) {
		cout << num << " ";
		num++;
	}
	else {
		cout << "( ";
		print_answer(s, i, s[i][j]);
		print_answer(s, s[i][j] + 1, j);
		cout << ") ";
	}
}
int main(void) {
	cin >> N;
	for (int i = 1; i <= N + 1; i++) {
		int a;
		cin >> a;
		p.push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= N; l++) {
		for (int i = 1; i <= N - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout << m[1][N] << "\n";
	print_answer(s, 1, N);


}