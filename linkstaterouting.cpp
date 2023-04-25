#include <bits/stdc++.h>
using namespace std;

int main(){
    int count, src_router, i, j, k, w, v, min;
    int cost[10][10], dist[10][10], next[10][10];

    cout << "Enter the number of routers: ";
    cin >> count;

    cout << "Enter the cost matrix:\n";
    for (i = 0; i < count; i++)
        for (j = 0; j < count; j++){
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
            dist[i][j] = cost[i][j];
            next[i][j] = j;
        }

    cout << "Enter the source router: ";
    cin >> src_router;

    for (k = 0; k < count; k++)
        for (i = 0; i < count; i++)
            for (j = 0; j < count; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }

    cout << "Routing table for router " << src_router << ":\n";
    cout << "Destination\tNext hop\tCost\n";

    for (i = 0; i < count; i++){
        if (i != src_router){
            cout << i << "\t\t" << next[src_router][i] << "\t\t" 
                 << dist[src_router][i] << "\n";
        }
    }
    return 0;
}
