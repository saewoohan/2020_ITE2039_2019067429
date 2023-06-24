//2019067429_한승우_B

#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX_N 1001
using namespace std;

vector <int > vt[MAX_N];
stack <int > st;
int n, m, x, y;
int visited[MAX_N + 1];
bool hasCycle = false;
vector <bool > finished;

void dfs(int v) {

    visited[v] = true;
    sort(vt[v].begin(),vt[v].end());
    for (int i = 0; i < vt[v].size(); i++) {
        int j = vt[v][i];
        if (!visited[j]) {
            dfs(j);
        }
        else if (!finished[j])
        {
            hasCycle = true;
        }

    }

    finished[v] = true;

    st.push(v);
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
    }
    finished.resize(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (hasCycle) {
            printf("0");
            return 0;
        }
        if (!visited[i])
            dfs(i);
    }

    printf("1\n");
    while (st.size()) {
        printf("%d ", st.top());
        st.pop();
    }
    return 0;

}