/*
LeetCode 743. Network Delay Time
https://leetcode.com/problems/network-delay-time/
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges2matrix(vector<vector<int>> &edges, int N) {
	vector<vector<int>> result;
	for (size_t i = 0; i < N + 1; i++)
	{
		vector<int> vv(N + 1, -1);
		result.push_back(vv);
	}
	for (auto e : edges)
		result[e[0]][e[1]] = e[2];
	return result;
}

size_t minDistance(vector<int>& dist, vector<bool>& sptSet, int N) {
	size_t result = INT32_MAX, result_index;
	for (size_t i = 1; i <= N; i++)
		if (!sptSet[i] && dist[i] <= result) 
		{
			result = dist[i];
			result_index = i;
		}
	return result_index;
}

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
	if (!times.size()) return -1;
	vector<vector<int>> matrix = edges2matrix(times, N);
	vector<int> dist(N + 1, INT32_MAX);
	vector<bool> sptSet(N + 1, false);
	dist[K] = 0;
	for (size_t i = 1; i < N; i++)
	{
		size_t md = minDistance(dist, sptSet, N);
		sptSet[md] = true;
		for (int j = 1; j <= N; j++)
			if (!sptSet[j] && matrix[md][j] >= 0 &&
				dist[md] != INT32_MAX && dist[md] + matrix[md][j] < dist[j])
				dist[j] = dist[md] + matrix[md][j];
	}
	for (auto d : dist) cout << d << " ";
	int result = *max_element(dist.begin() + 1, dist.end());
	if (result == INT32_MAX) result = -1;
	return result;
}

void check(int e[][3], int size, int N, int K, int expected) {
	vector<vector<int>> edges;
	for (size_t i = 0; i < size; i++)
	{ // converting int 2D array into 2D vector
		vector<int> vv(3);
		for (int j = 0; j < 3; j++)
			vv[j] = e[i][j];
		edges.push_back(vv);
	}
	int actual = networkDelayTime(edges, N, K);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int es[3][3] = { {2, 1, 1}, {2, 3, 1}, {3, 4, 1} };
	check(es, 3, 4, 2, 2);

	int es2[20][3] = 
	{
		{ 3,5,78 }, 
		{ 2,1, 1 }, 
		{ 1,3, 0 }, 
		{ 4,3,59 }, 
		{ 5,3,85 }, 
		{ 5,2,22 }, 
		{ 2,4,23 }, 
		{ 1,4,43 }, 
		{ 4,5,75 }, 
		{ 5,1,15 }, 
		{ 1,5,91 }, 
		{ 4,1,16 }, 
		{ 3,2,98 }, 
		{ 3,4,22 }, 
		{ 5,4,31 }, 
		{ 1,2, 0 }, 
		{ 2,5, 4 }, 
		{ 4,2,51 }, 
		{ 3,1,36 }, 
		{ 2,3,59 }
	};
	check(es2, 20, 5, 5, 31);

	system("pause");
	return 0;
}
