#include <bits/stdc++.h>
using namespace std;

/*<DEBUG>*/
#define tem template <typename 
#define can_shift(_X_, ...) enable_if_t<sizeof test<_X_>(0) __VA_ARGS__ 8, debug&> operator<<(T i)
#define _op debug& operator<<
tem C > auto test(C *x) -> decltype(cerr << *x, 0LL);
tem C > char test(...);
tem C > struct itr{C begin, end; };
tem C > itr<C> get_range(C b, C e) { return itr<C>{b, e}; };
struct debug{
#ifdef _LOCAL
	~debug(){ cerr << endl; }
	tem T > can_shift(T, ==){ cerr << boolalpha << i; return *this; }
	tem T> can_shift(T, !=){ return *this << get_range(begin(i), end(i)); }
	tem T, typename U > _op (pair<T, U> i){ 
		return *this << "< " << i.first << " , " << i.second << " >"; }
	tem T> _op (itr<T> i){
		*this <<  "{ ";
		for(auto it = i.begin; it != i.end; it++){
			*this << " , " + (it==i.begin?2:0) << *it;
		}
		return *this << " }";
	}
#else
tem T> _op (const T&) { return *this; }
#endif 
};

string _ARR_(int* arr, int sz){
	string ret = "{ " + to_string(arr[0]); 
	for(int i = 1; i < sz; i++) ret += " , " +  to_string(arr[i]);
	ret += " }"; return ret;
}

#define exp(...) " [ " << #__VA_ARGS__ << " : " << (__VA_ARGS__) << " ]"
/*</DEBUG>*/

typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t uint;
typedef pair<int, int> pii;

#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define TC int __TC__; cin >> __TC__; while(__TC__--)

const int INF = 1e9 + 7;

struct item{
	ll sum;
};

struct SegTree{
	int sz, n;
	vector<item> values;
	vector<ll> op;

	//-----<Set up the neutral element, single, and merge for current item>-----//
	
	item NEUTRAL_ELEMENT = {0};
	ll NO_OP = 0;


	void do_mod_op(ll &a, ll &b, ll len){
		return;
	}

	void prop(int x, int lx, int rx){
		return;
	}

	void merge(int x, int lx, int rx){
		return;
	}


	//-----</Set up the neutral element, single, and merge for current item>-----//

	void init(int n){
		sz = 1;
		while(sz < n) sz*=2;
		values.assign(sz*2, NEUTRAL_ELEMENT);
		op.assign(sz*2, NO_OP);
		return;
	}

	void print_tree(int x, int lx, int rx){
		int len = (rx - lx)/2;
		if(rx - lx == 1) {
			do_mod_op(values[x].sum, op[x], len);
			cout << values[x].sum << ' ';
			return;
		}

		prop(x, lx, rx);
		int m = lx + (rx - lx) /2;
		print_tree(2*x + 1, lx, m);
		print_tree(2*x + 2, m, rx);
		merge(x, lx, rx);
		return;
	}

	void print_tree() {
		print_tree(0, 0, sz);
		return;
	}

	void modify_range(int l, int r, int x, int lx, int rx){
		prop(x, lx, rx);

		if(r <= lx || l >= rx) return;

		if(lx >= l && rx <= r){
			op[x] = 1;
			do_mod_op(values[x].sum, op[x], rx-lx);
			return;
		}

		int m = lx + (rx - lx)/2;
		modify_range(l, r, 2*x + 1, lx, m);
		modify_range(l, r, 2*x + 2, m, rx);
		merge(x, lx, rx);
		return;
	}

	void modify_range(int l, int r){
		modify_range(l, r, 0, 0, sz);
		return;
	}

	ll calc_range(int l, int r, int x, int lx, int rx){
		prop(x, lx, rx);

		if(r <= lx || l >= rx) return NEUTRAL_ELEMENT.sum;

		if(lx >= l && rx <= r){
			do_mod_op(values[x].sum, op[x], rx-lx);
			return values[x].sum;
		}

		int m = lx + (rx - lx)/2;
		ll left = calc_range(l, r, 2*x + 1, lx, m);
		ll right = calc_range(l, r, 2*x + 2, m, rx);
		merge(x, lx, rx);
		return left + right;
	}


	ll calc_range(int l, int r){
		return calc_range(l, r, 0, 0, sz);
	}
};


int main(void)
{ 
	FAST;
	int n, m; cin >> n >> m;

	SegTree st;
	st.init(n);


	return 0;
}

