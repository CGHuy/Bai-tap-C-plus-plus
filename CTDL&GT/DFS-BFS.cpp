#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void DFS(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u]) {
		if (visited[v] == false) {
			DFS(v);
		}
	}
}

void BFS(int u) {
	queue<int> q; // Khoi tao hang doi
	q.push(u);
	visited[u] = true;
	while (!q.empty()) { // Neu hang doi rong thi dung 
		int v = q.front(); // Lay dinh dau tien trong queue ra
		q.pop(); // Xoa dinh dau tien trong queue
		cout << v << " ";
		for (int x : adj[v]) {
			if (visited[x] == false) { // Neu dinh chua duoc tham thi day vao queue va danh dau da tham
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

/*
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 7
3 9
5 8
6 7
9 8
*/

int main() {
	input();
	DFS(1);
	return 0;
}
