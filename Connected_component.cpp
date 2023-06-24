//2019067429_한승우_B
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 1001
using namespace std;

vector<int> a[MAX_N];
int n, m, x, y;
int visited[MAX_N + 1];
int ans;

void dfs(int start) {
    if (visited[start]) {
        return;
    }
    visited[start] = true;
    for (int i = 0; i < a[start].size(); i++) {
        int x = a[start][i];
        dfs(x);
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    printf("%d", ans);

    return 0;

}