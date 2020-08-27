#include <bits/stdc++.h>
using namespace std;

/*<DEBUG>*/
#define tem template <typename 
#define can_shift(_X_, ...) enable_if_t<sizeof test<_X_>(0) __VA_ARGS__ 8, debug&> operator<<(T i)
#define op debug& operator<<
tem C > auto test(C *x) -> decltype(cerr << *x, 0LL);
tem C > char test(...);
tem C > struct itr{C begin, end; };
tem C > itr<C> get_range(C b, C e) { return itr<C>{b, e}; };
struct debug{
#ifdef _LOCAL
	~debug(){ cerr << endl; }
	tem T > can_shift(T, ==){ cerr << boolalpha << i; return *this; }
	tem T> can_shift(T, !=){ return *this << get_range(begin(i), end(i)); }
	tem T, typename U > op (pair<T, U> i){ 
		return *this << "< " << i.first << " , " << i.second << " >"; }
	tem T> op (itr<T> i){
		*this <<  "{ ";
		for(auto it = i.begin; it != i.end; it++){
			*this << " , " + (it==i.begin?2:0) << *it;
		}
		return *this << " }";
	}
#else
tem T> op (const T&) { return *this; }
#endif 
};

string _ARR_(int* arr, int sz){
	string ret = "{ " + to_string(arr[0]); 
	for(int i = 1; i < sz; i++) ret += " , " +  to_string(arr[i]);
	ret += " }"; return ret;
}

#define exp(...) " [ " << #__VA_ARGS__ << " : " << (__VA_ARGS__) << " ]"
/*</DEBUG>*/

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define TC int __TC__; cin >> __TC__; while(__TC__--)

const int INF = 1e9 + 7;

int main(void)
{
	FAST;

	return 0;
}
