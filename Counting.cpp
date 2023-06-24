// 2019067429_ÇÑ½Â¿ì_12838


#include <stdio.h>

#include <stdlib.h>

#include <iostream>

#include <vector>

using namespace std;

int N, M, K;
vector<pair<int, int> > arr;
int a[100001];
vector<int> answer;
int c[100001];


int main() {

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> a[i];
	}

	for (int i = 1; i <= N; i++) {
		c[a[i]] = c[a[i]] + 1;
	}

	for (int i = 0; i < arr.size(); i++) {
		int num1 = arr[i].first;
		int num2 = arr[i].second;
		int num = 0;
		for (int j = num1; j <= num2; j++) {
			num += c[j];
		}
		answer.push_back(num);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;

}
