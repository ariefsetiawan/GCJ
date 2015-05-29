#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0)
#define vi vector<int>
#define vii vector<pii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 1000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		LL N;
		scanf("%lld",&N);
		printf("Case #%d: ", tc);

		if (N < 10) {
			printf("%d\n",N);
			continue;
		}

		LL M = 10ll;
		LL count = 10;
		int k = 2;
		while (N / M >= 10ll) {
			M *= 10ll;
			count = count + 1;
			LL temp = 0;
			for (int i = 0; i < k/2; i++)
				temp = temp*10 + 9;
			
			count += temp;

			if (k%2 == 0)
				count += temp;
			else
				count += (temp*10+9);

			k++;
		}

		LL mini = N-M;

		bool genap = N%10 == 0;

		LL temp = 0ll;
		LL pangkat = 1ll;
		for (int i = 0; i < k/2; i++) {
			pangkat *= 10ll;
		}

		temp = N%pangkat;

		N/= pangkat;

		LL temp2 = 0ll;

		if (genap) {
			N--;
			temp += pangkat - 1;
		}

		while (N > 0) {
			temp2 = (temp2*10ll) + (N%10);
			N /= 10ll;
		}

		mini = min(mini,temp+temp2);

		printf("%lld\n",mini+count);
	}
	return 0;
}