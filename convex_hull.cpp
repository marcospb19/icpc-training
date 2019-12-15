/// Convex Hull construction using Graham's Scan
///
/// O(N logN)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///
#define pii pair<int , int>
#define point pii
#define x first
#define y second

inline int signed_parallelogram_area(point a, point b, point c) {
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

bool cw(point a, point b, point c) {
	return signed_parallelogram_area(a , b , c) < 0;
}

bool ccw(point a, point b, point c) {
	return signed_parallelogram_area(a , b , c) > 0;
}

void convex_hull(vector<point>& v)
{
	if (v.size() < 3)
		return;

	sort(v.begin(), v.end());

	point leftmost = v.front();
	point rightmost = v.back();

	vector<point> up, down;
	up.push_back(leftmost);
	down.push_back(leftmost);

	for (size_t i = 1; i < v.size(); i++)
	{
		if (i == v.size() - 1 || cw(leftmost , v[i] , rightmost))
		{
			while (up.size() >= 2 && !cw(up[up.size() - 2] , up[up.size() - 1] , v[i]))
				up.pop_back();
			up.push_back(v[i]);
		}
		if (i == v.size() - 1 || ccw(leftmost , v[i] , rightmost))
		{
			while (down.size() >= 2 && !ccw(down[down.size() - 2] ,down[down.size() - 1] , v[i]))
				down.pop_back();
			down.push_back(v[i]);
		}
	}

	v = up;
	for (size_t i = down.size() - 2; i > 0; i--)
		v.push_back(down[i]);
}
///

int main()
{
	vector<point> v;

	// Part of the final convex hull
	v.push_back(make_pair( 0 ,  0));
	v.push_back(make_pair(10 ,  0));
	v.push_back(make_pair(10 , 10));
	v.push_back(make_pair( 0 , 10));

	// Not part of the final convex hull
	v.push_back(make_pair(5 , 5)); // At the center
	v.push_back(make_pair(0 , 5)); // At the bottom edge

	convex_hull(v);

	printf("New size: %ld\n" , v.size());
	for (auto e : v)
		printf("%d, %d\n" , e.x , e.y);
}
