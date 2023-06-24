//2019067429_한승우_B
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int check[1001];
int a, b;

typedef struct info
{
	int f, t, c;
}info;


int getParent(int node) {
	if (check[node] == node) return node;
	return getParent(check[node]);
}

void unionParent(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 < node2) check[node2] = node1;
	else check[node1] = node2;
}

bool isCycle(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 == node2) return true;
	else return false;
}

int main() {

	vector <pair<int, pair <int, int> > > v;
	scanf("%d", &a);
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		v.push_back(make_pair(w, make_pair(x, y)));
	}

	sort(v.begin(), v.end());


	//각 노드는 자기자신이 부모로 초기화해줍니다. 
	for (int i = 1; i <= a; ++i) {
		check[i] = i;
	}
	vector <info > vas;

	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {

		//싸이클이 존재하지 않으면 비용을 더합니다. 
		if (!isCycle(v[i].second.first, v[i].second.second)) {

			sum++;
			info ans;
			ans.c = v[i].second.first;
			ans.f = v[i].second.second;
			ans.t = v[i].first;
			vas.push_back(ans);

			unionParent(v[i].second.first, v[i].second.second);
		}
	}

	printf("%d\n", sum);
	for (int i = 0; i < sum; i++) {
		printf("%d %d %d\n", vas[i].c, vas[i].f, vas[i].t);
	}

	return 0;
}