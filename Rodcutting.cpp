// 2019067429_ÇÑ½Â¿ì_B

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int N;
int p[101];
int r[101];
int s[101];
int main(void) {

	cin >> N;

	p[0] = 0;
	r[0] = 0;
	s[0] = 0;

	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= N; i++) {
		int temp = INT_MIN;
		for (int j = 1; j <= i; j++) {
			if (temp < p[j] + r[i - j]) {
				temp = p[j] + r[i - j];
				s[i] = j;
			}
		}
		r[i] = temp;
	}

	cout << r[N] << "\n";
	int answer[101];
	int k = 0;
	while (N > 0) {
		answer[k] = s[N];
		N = N - s[N];
		k++;
	}

	sort(answer, answer + k);

	for (int i = 0; i < k; i++) {
		cout << answer[i] << " ";
	}

}