#include <iostream>
using namespace std;
#define MAXN int(1e5) + 1

///
int parent[MAXN];
int ranks [MAXN];

void prepare_sets() {
	for (int i = 0; i < MAXN; ++i) {
		parent[i] = i;
		ranks [i] = 1;
	}
}

int find_set(int i) {
	if (parent[i] == i)
		return i;
	return parent[i] = find_set(parent[i]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a == b)
		return;
	if (ranks[a] < ranks[b])
		swap(a , b);

	parent[b] = a; // B is attached to A
	ranks[a] += ranks[b];
}
///

int main()
{
	prepare_sets();
	union_sets(1 , 2); // { 1 , 2 }
	union_sets(2 , 3); // { 1 , 2 , 3 }

	if (find_set(1) == find_set(3))
		printf("1 and 3 are in the same set (%d)\n" , find_set(1));
}
