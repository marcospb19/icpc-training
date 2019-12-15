/// BFS (Breath First Search on graph)
///
/// O(V + E), V being the vertices and E the edges connecting them

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
#define MAXN int(1e5) + 1

///
vector<int> adj[MAXN];
bool visited[MAXN];

void clear_visited()
{
	memset(visited , false , sizeof visited);
}

bool bfs(int start , int target)
{
	if (start == target)
		return true;

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (auto v : adj[current])
		{
			if (!visited[v])
			{
				if (v == target)
					return true;

				q.push(v);
			}
		}
	}

	return false;
}
///

int main()
{
	clear_visited();

	adj[1].push_back(2); // 1 -> 2
	adj[2].push_back(3); // 1 -> 2 -> 3
	adj[3].push_back(4); // 1 -> 2 -> 3 -> 4

	if (bfs(1 , 4))
		printf("1 is connected to 4\n");
}
