#include <bits/stdc++.h>
using namespace std;

/*
题目都没认真看，以为在问最大最大和。。。
*/

int arr[(int)1e5 + 1];
int N, M;
bool suc(int x) {
    int cnt = 1;
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += arr[i];
        /*
        这里是最重要的一行代码，虽说整个算下来（如x=10）有可能没有和是10的，但是问题是如果和要小于10，那么肯定是能接受的，因为10是这种情况下的最差解
        */
        if (total > x) {
            total = arr[i];
            cnt ++;
            if (cnt > M) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    int lower = -1;
    int higher = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        lower = max(arr[i], lower);
        higher += arr[i];
    }
    while (lower < higher){
        int mid = (lower + higher) / 2;
        if (suc(mid)) {
            higher = mid;
        } else {
            // 标记一下：这里已经不success了，所以肯定是加1去保证lower尽可能success
            lower = mid+1;
        }
    }
    cout << lower << endl;
}