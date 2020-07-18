#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TC int tc; cin >> tc; while(tc--)

using namespace std;

const int INF = 1e9 + 7;

vector<vector<int>> adj;
vector<int> ord;
vector<int> seen;

void dfs(int u){
	seen[u] = 1;
	for(int v : adj[u]){
		if(!seen[v]) dfs(v);
	}
	ord.pb(u);
}

int main(void)
{
	FAST
	TC{
		int n, m; cin >> n >> m;
		vector<pair<int, int>> edges;
		adj = vector<vector<int>>(n);

		while(m--){
			int i, u, v; cin >> i >> u >> v;
			u--; v--;
			if(i) adj[u].pb(v);
			edges.pb(make_pair(u, v));
		}

		ord.clear();
		seen = vector<int>(n, 0);
		for(int i = 0; i < n; i++){
			if(!seen[i]) dfs(i);
		}

		vector<int> pos(n);
		reverse(ord.begin(), ord.end());
		for(int i = 0; i < n; i++) pos[ord[i]] = i;


		bool ok = 1;

		for(int i = 0; i < n; i++){
			for(int v : adj[i]){
				if(pos[v] < pos[i]){
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}

		if(!ok){
			cout << "NO" << '\n';
		}else{
			cout << "YES" << '\n';
			for(auto [x, y] : edges){

				if(pos[x] < pos[y]){
					cout << x+1 << ' ' << y+1 << '\n';
				}else{
					cout << y+1 << ' ' << x+1 << '\n';
				}
			}

		}


	}
	return 0;
}
