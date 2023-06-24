// 2019067429_ÇÑ½Â¿ì_B

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
int e1, e2;
int x1, x2;
vector<int> arr1;
vector<int> arr2;
vector<int> t1;
vector<int> t2;
int s[101][101];
int l[101][101];
int answer;
int answer_start;

int main(void) {
	cin >> N;
	cin >> e1 >> e2;
	cin >> x1 >> x2;
	arr1.push_back(0);
	arr2.push_back(0);
	t1.push_back(0);
	t2.push_back(0);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr1.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		arr2.push_back(b);
	}
	for (int i = 0; i < N - 1; i++) {
		int c;
		cin >> c;
		t1.push_back(c);
	}
	for (int i = 0; i < N - 1; i++) {
		int d;
		cin >> d;
		t2.push_back(d);
	}

	s[1][1] = e1 + arr1[1];
	s[2][1] = e2 + arr2[1];
	for (int j = 2; j <= N; j++) {
		if (s[1][j - 1] <= s[2][j - 1] + t2[j - 1]) {
			s[1][j] = s[1][j - 1] + arr1[j];
			l[1][j] = 1;
		}
		else {
			s[1][j] = s[2][j - 1] + t2[j - 1] + arr1[j];
			l[1][j] = 2;
		}
		if (s[2][j - 1] <= s[1][j - 1] + t1[j - 1]) {
			s[2][j] = s[2][j - 1] + arr2[j];
			l[2][j] = 2;
		}
		else {
			s[2][j] = s[1][j - 1] + t1[j - 1] + arr2[j];
			l[2][j] = 1;
		}
	}

	if (s[1][N] + x1 <= s[2][N] + x2) {
		answer = s[1][N] + x1;
		answer_start = 1;
	}
	else {
		answer = s[2][N] + x2;
		answer_start = 2;
	}

	cout << answer << "\n";

	int answer_arr[101];
	answer_arr[N] = answer_start;
	for (int i = N; i > 1; i--) {
		answer_arr[i - 1] = l[answer_start][i];
		answer_start = answer_arr[i - 1];
	}

	for (int i = 1; i <= N; i++) {
		cout << answer_arr[i] << " " << i << "\n";
	}

}