#include <bits/stdc++.h>
using namespace std;

int n, k;
int nums[1001];
int trees[1001];
int maxT = -1;
int ans = 0;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        maxT = max(maxT, trees[i]);
    }
    for (int forE = 1; forE <= maxT; forE++) {
        memset(nums, 0, sizeof(nums));
        for (int i = 0 ; i < n; i++) {
            nums[forE] += trees[i] / forE;
            nums[trees[i] % forE] ++;
        }
        if (nums[forE] < k/2) {
            continue;
        }
        nums[forE] -= k/2;
        int given = 0;
        int total = 0;
        int atter = forE;
        while (atter > 0 && given < k/2) {
            if (nums[atter] > 0) {
                given ++;
                total += atter;
                nums[atter] --;
            } else {
                atter --;
            }
        }
        if (given == k/2) {
            ans = max(ans, total);
        }
    }
    cout << ans;
}