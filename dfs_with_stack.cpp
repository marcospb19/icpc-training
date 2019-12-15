/// DFS using a stack (Depth First Search on graph)
///
/// O(V + E), V being the vertices and E the edges connecting them

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
#define MAXN int(1e5) + 1

///
vector<int> adj[MAXN];
bool visited[MAXN];

void clear_visited()
{
	memset(visited , false , sizeof visited);
}

bool dfs(int start , int target)
{
	if (start == target)
		return true;

	stack<int> s;
	s.push(start);

	while (!s.empty())
	{
		int current = s.top();
		s.pop();

		for (auto v : adj[current])
		{
			if (!visited[v])
			{
				if (v == target)
					return true;

				s.push(v);
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

	if (dfs(1 , 4))
		printf("1 is connected to 4\n");
}
