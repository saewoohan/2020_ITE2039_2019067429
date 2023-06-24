//2019067429_한승우_B
#include <stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1e9
#define MAX_I 50001
using namespace std;

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    vector<pair<int, int> > arr[MAX_I + 1];

    for (int i = 0; i < E; i++) {
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
        arr[from].push_back({ to,val });
    }
    int dist[MAX_I + 1];
    fill(dist, dist + V + 1, INF);
    priority_queue<pair<int, int> > qu;

    qu.push({ 0,1 });
    dist[1] = 0;

    while (!qu.empty()) {
        int cost = -qu.top().first;
        int here = qu.top().second;

        qu.pop();

        for (int i = 0; i < arr[here].size(); i++) {
            int next = arr[here][i].first;
            int nextcost = arr[here][i].second;

            if (dist[next] > dist[here] + nextcost) {

                dist[next] = dist[here] + nextcost;
                qu.push({ -dist[next],next });
            }
        }

    }
    sort(dist, dist + V + 1);

    for (int i = V; i >= 1; i--) {
        if (dist[i] == INF) {
            continue;
        }
        else {
            printf("%d\n", dist[i]);
            break;
        }
    }

}
