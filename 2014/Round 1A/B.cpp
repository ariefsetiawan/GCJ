#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

bool link[1005][1005];
int dp[1005][1005];
int N;

int makeFullBT(int node, int parent) {
	if (dp[node][parent] != -1)
		return dp[node][parent];

	vector<int> v;

	for (int i = 1; i <= N; i++) {
		if (!link[node][i] || i == parent)
			continue;

		v.push_back(makeFullBT(i,node));
	}

	//sort descending
	sort(v.rbegin(), v.rend());

	if (v.size() >= 2)
		dp[node][parent] = 1 + v[0] + v[1];
	else
		dp[node][parent] = 1;

	return dp[node][parent];
}

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {

		scanf("%d",&N);
		
		memset(link,0,sizeof link);
		
		int a,b;
		for (int i = 0; i < N-1; i++) {
			scanf("%d %d",&a,&b);
			link[a][b] = link[b][a] = 1;
		}

		memset(dp,-1,sizeof dp);

		int mini = N;
		for (int i = 1; i <= N; i++) {
			mini = min(mini,N-makeFullBT(i,0));
		}

		printf("Case #%d: %d\n",tc,mini);
	}
	return 0;
}