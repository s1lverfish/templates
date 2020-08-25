#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define TC int tc; cin >> tc; while(tc--)

using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

const int INF = 1e9 + 7;


struct dsu 
{
	int size, numSets;
	vector<int> rank, p, setSize;

	void init(int n) { size = n; numSets = n;
		rank.assign(n, 0);
		p.resize(n); iota(p.begin(), p.end(), 0);
		setSize.assign(n, 1);
	}

	void printParents(){ for(int i = 0; i < size; i++) cout << i << " : " << p[i] << endl; }
	void printRank(){ for(int i = 0; i < size; i++) cout << i << " : " << rank[i] << endl; }

	int findSet(int node){
		int root = node; while(root != p[root]) root = p[root];
		int nxt = node;	while(p[node] != root) { nxt = p[node]; p[node] = root; node = nxt; } 
		return root;
	}

	bool isSameSet(int a, int  b){return findSet(a) == findSet(b);}
	int numOfSets() { return numSets; }
	int sizeOfSet(int a) { return setSize[findSet(a)]; }

	void unionSet(int a, int b) {
		if(!isSameSet(a,b)){	
			numSets--;
			a = findSet(a); b = findSet(b);
			if(rank[a] > rank[b]) p[b] = a, setSize[a] += setSize[b];
			else {	p[a] = b; setSize[b] += setSize[a];
					if(rank[a] == rank[b]) rank[b]++; }
		}
	}
};

int main(void)
{
	FAST
	
	dsu s;
	s.init(8);
	s.unionSet(0,1);
	s.unionSet(2,3);
	s.unionSet(4,5);
	s.unionSet(6,7);
	s.unionSet(0,2);
	s.unionSet(4,6);
	s.unionSet(6,2);

	s.printRank();
	cout << s.sizeOfSet(0) << endl;

	return 0;
}
