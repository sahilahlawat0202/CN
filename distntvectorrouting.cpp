#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define V 4
void printSolution(int dist[][V]);
void DVR(int graph[][V], int src){
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
void printSolution(int dist[][V]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}
int main()
{
    int graph[V][V] = {{0, 3, 5, 7},
                       {9, 0, 3, INF},
                       {2, INF, 0, 8},
                       {6, 4, 3, 0}};
    cout << "Initial Distance Matrix: " << endl;
    printSolution(graph);
    cout << endl;
    cout << "The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    DVR(graph, 0);
    return 0;
}
