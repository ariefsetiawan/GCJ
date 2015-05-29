#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long calculate(long long r, long long n) {
	return (2ll*n - 1ll)*n + 2ll*r*n;
}

long long solve(long long r, long long paint) {
	if (paint <= r)
		return 0;

	long long a = 0, b = min(paint/r, (long long)sqrt(paint));
	while ((b-a) > 1) {
		long long mid = (a + b)/2;
		long long temp = calculate(r,mid);

		if (temp < paint)
			a = mid;
		else
			b = mid;
	}
	if (calculate(r,b) <= paint)
		return b;
	else
		return a;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		long long r, paint;
		scanf("%lld %lld",&r,&paint);
		printf("Case #%d: %lld\n",tc,solve(r,paint));
	}
	return 0;
}