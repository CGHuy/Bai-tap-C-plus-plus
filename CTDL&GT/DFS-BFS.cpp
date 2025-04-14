#include <iostream>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	cout << u << " ";
	visited[u] = true; // Danh dau u da duoc tham
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS(v);
		}
	}
}

void BFS(int u) {
	queue<int> q; // Khoi tao hang doi
	q.push(u);
	visited[u] = true;
	while (q.empty()) { // Neu hang doi khac rong thi thuc hien lenh 
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main() {
	
}
