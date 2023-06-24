// 2019067429_ÇÑ½Â¿ì_12838


#include <stdio.h>

#include <stdlib.h>

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int N, M, k;
bool ather;
int answer = 0;
int a[100001];
int b[100001];
int c1[100001];
int c2[100001];


int main() {

	cin >> N >> M;
	if (N > M) {
		k = M;
		ather = true;
	}
	else {
		k = N;
		ather = false;
	}

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= M; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= N; i++) {
		c1[a[i]] = c1[a[i]] + 1;
	}

	for (int i = 1; i <= M; i++) {
		c2[b[i]] = c2[b[i]] + 1;
	}

	for (int i = 1; i <= k; i++) {
		if (ather) {
			answer += min(c2[b[i]], c1[b[i]]);
		}
		else {
			answer += min(c2[a[i]], c1[a[i]]);
		}
	}

	cout << answer;
	return 0;

}
