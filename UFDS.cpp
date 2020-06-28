#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9 + 7;

class disjoint_sets
{
private: int *rank, *p, size, *setSize, numSets;
public:
	disjoint_sets(int n) { size = n; numSets = n;
		rank = (int*)malloc(n*sizeof(int)); memset(rank, 0, sizeof(rank));
		p = (int*)malloc(n*sizeof(int)); iota(p, p+n, 0);
		setSize = (int*)malloc(n*sizeof(int)); for(int i=0; i < n; i++) setSize[i] = 1;}

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
	
	disjoint_sets s(8);
	s.unionSet(0,1);
	s.unionSet(2,3);
	s.unionSet(4,5);
	s.unionSet(6,7);
	s.unionSet(0,2);
	s.unionSet(4,6);
	s.unionSet(6,2);

	s.printRank();
	cout << s.sizeOfSet(2) << endl;

	return 0;
}
