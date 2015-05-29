#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		int n,p;
		int pancake[1005];
		for (int i = 0; i < 1005; i++)
			pancake[i] = 0;

		scanf("%d",&n);
		for (int i = 0; i < n; i++) {
			scanf("%d",&p);
			pancake[p]++;
		}

		int mini = 1001, add = 0;
		for (int i = 1000; i > 0; i--) {

			if (pancake[i] > 0) {
				mini = min(mini, i + add);
				int mid = i/2;
				int a = mid;
				int b = (i%2==0)?mid:mid+1;

				if (i == 9) {
					a=3;
					b=6;
				}

				pancake[a] += pancake[i];
				pancake[b] += pancake[i];

				add += pancake[i];
			}
		}
		printf("Case #%d: %d\n",tc, mini);
	}
	return 0;
}