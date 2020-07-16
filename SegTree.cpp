#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9 + 7;

struct item{
	ll mx;
};

struct SegTree{
	int sz, n;
	vector<item> values;

	//-----<Set up the neutral element, single, and merge for current item>-----//
	item NEUTRAL_ELEMENT = {0};

	item merge(item a, item b){
		return {max(a.mx, b.mx)};
	}

	item single(int v){
		return {v};
	}
	//-----</Set up the neutral element, single, and merge for current item>-----//

	void init(int n){
		sz = 1;
		while(sz < n) sz*=2;
		values.resize(sz*2);
		return;
	}

	void build(vector<int> &a, int x, int lx, int rx){
		
		if(rx-lx == 1){
			if(lx < n) values[x] = single(a[lx]);
			return;
		}
	
		int m = lx + (rx - lx)/2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);

		//-----<Do associative operation>-----//
		values[x] = merge(values[2*x + 1], values[2*x + 2]);
		//-----</Do associative operation>-----//
	}


	void build(vector<int> &a){
		n = a.size();
		build(a, 0, 0, sz);
		return;
	}

	void set(int i, int v, int x, int lx, int rx){

		if(rx - lx == 1){
			values[x] = single(v); //base case, set bottom level
			return;
		}

		int m = lx + (rx - lx)/2;

		if(m > i) set(i, v, 2*x + 1, lx, m); //go left
		else set(i, v, 2*x + 2, m, rx); //go right

		//-----<Do associative operation>-----//
		values[x] = merge(values[x*2 + 1], values[x*2 + 2]);
		//-----</Do associative operation>-----//
	}

	void set(int i, int v){
		set(i, v, 0, 0, sz);
		return;
	}

	item calc_range(int l, int r, int x, int lx, int rx){

		//Case 1: segment outside l, r
		if(lx >= r || rx <= l) return NEUTRAL_ELEMENT; //Neutral Element
		//Case 2: segment completely inside l, r
		if(lx >= l && rx <= r) return values[x];
		//Case 3: segment partly inside, partly outside l, r
		
		int m = lx + (rx - lx) / 2;

		item left = calc_range(l, r, 2*x + 1, lx, m);
		item right = calc_range(l, r, 2*x + 2, m, rx);

		//-----<Do associative operation>-----//
		return merge(left, right);
		//-----</Do associative operation>-----//
	}

	item calc_range(int l, int r){
		return calc_range(l, r, 0, 0, sz);
	}

	int pos_value(int v, int l, int x, int lx, int rx){

		if(values[x].mx < v) return -1; //if item isn't in this subtree
		if(rx <= l) return -1; //if item is left of this subtree

		if(rx - lx == 1) return lx; //if leftmost item is found

		int m = lx + (rx - lx) / 2;
		int res = pos_value(v, l, 2*x + 1, lx, m); //go left
		if(res == -1){
			res  = pos_value(v, l, 2*x + 2, m, rx); //if stuck, go right
		}

		return res;
	}


	int pos_value(int v, int l){
		return pos_value(v, l, 0, 0, sz);
	}
};


int main(void)
{ 
	FAST
	int n, m; cin >> n >> m;
	vector<int> a(n);

	SegTree st;
	st.init(n);

	for(int &t : a) cin >> t;
	st.build(a);

	while(m--){
		int q; cin >> q;
		if(q == 1){
			int i, v; cin >> i >> v;
			st.set(i, v);
		}else{
			int k, l; cin >> k >> l;
			cout << st.pos_value(k, l) << '\n';
		}
	}

	return 0;
}
