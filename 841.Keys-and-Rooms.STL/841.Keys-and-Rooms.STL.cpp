/*
LeetCode 841. Keys and Rooms
https://leetcode.com/problems/keys-and-rooms/

Input 1: [[1],[2],[3],[]]
Output 1: true

Input 2: [[1,3],[3,0,1],[2],[0]]
Output 2: false
*/

#include <bits/stdc++.h>

using namespace std;

void canVisitAllRoomsRecursive(int k, vector<vector<int>>& rooms, vector<bool>& visited) {
	if (k >= rooms.size()) return;
	visited[k] = true;
	for (int i = 0; i < rooms[k].size(); i++)
		if (!visited[rooms[k][i]])
			canVisitAllRoomsRecursive(rooms[k][i], rooms, visited);
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	vector<bool> visited(rooms.size(), false);
	canVisitAllRoomsRecursive(0, rooms, visited);
	return all_of(visited.begin(), visited.end(), [](const bool i) { return i; });
}

void check(vector<vector<int>>& rooms, bool expected) {
	bool actual = canVisitAllRooms(rooms);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	vector<vector<int>> rooms1;
	vector<int> keys;
	keys.clear(); keys.push_back(1); rooms1.push_back(keys);
	keys.clear(); keys.push_back(2); rooms1.push_back(keys);
	keys.clear(); keys.push_back(3); rooms1.push_back(keys);
	keys.clear(); rooms1.push_back(keys);
	check(rooms1, true);

	vector<vector<int>> rooms2;
	keys.clear(); keys.push_back(1); keys.push_back(3); rooms2.push_back(keys);
	keys.clear(); keys.push_back(3); keys.push_back(0); keys.push_back(1); rooms2.push_back(keys);
	keys.clear(); keys.push_back(2); rooms2.push_back(keys);
	keys.clear(); keys.push_back(1); rooms2.push_back(keys);
	check(rooms2, false);

	system("pause");
	return 0;
}
