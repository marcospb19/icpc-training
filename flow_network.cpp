// C++ program for implementation of Ford Fulkerson algorithm
#include <climits>
#include <iostream>
#include <queue>
using namespace std;

// Number of vertices in given graph
#define MAXN 501

/* Returns true if there is a path from source 's' to sink 't' in
residual graph. Also fills parent[] to store the path */
bool bfs(int residual[MAXN][MAXN], int source, int sink, int parent[]) {
    // Create a visited array and mark all vertices as not visited
    bool visited[MAXN] = {false};

    // Create the bfs queue
    queue<int> q({source});
    visited[source] = true;
    parent[source] = -1;

    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < MAXN; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // Return if we reached sink in BFS starting from source
    return visited[sink];
}

// Returns the maximum flow from s to t in the given graph
// Ford Fulkerson
int graph_network(int graph[MAXN][MAXN], int u, int v) {
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int residual[MAXN][MAXN];  // Residual graph where residual[i][j] indicates
                               // residual capacity of edge from i to j (if there
                               // is an edge. If residual[i][j] is 0, then there is not)
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            residual[i][j] = graph[i][j];

    int parent[MAXN];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(residual, u, v, parent)) {
        // path_flow, Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int flow = INT_MAX;
        for (int i = v; i != u; i = parent[i]) {
            int par = parent[i];
            flow = min(flow, residual[parent[i]][i]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (int i = v; i != u; i = parent[i]) {
            auto par = parent[i];
            residual[par][i] -= flow;
            residual[i][par] += flow;
        }

        // Add path flow to overall flow
        max_flow += flow;
    }

    // Return the overall flow
    return max_flow;
}

void zerar() {
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            adj[i][j] = 0;
}

// Driver
int main() {
    zerar();
    // int n;
    // scanf("%d", &n);

    // // Let us create a graph shown in the above example
    // int graph[MAXN][MAXN];

    // for (int i = 0; i < q; ++i) {
    //     scanf("%d", &graph[i][j]);
    // }

    // cout << "The maximum possible flow is " << graph_network(graph, 0, n - 1) << '\n';
}
