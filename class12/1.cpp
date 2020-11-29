#include <bits/stdc++.h>
using namespace std;
int M, N, U, D, F;
int psaForward[(int) 1e5+1];
int psaBack[(int) 1e5+1];
char temp;
int main() {
    cin >> M >> N >> U >> F >> D;
    int k;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (temp == 'u') {
            psaForward[i] = psaForward[i-1] + U;
            psaBack[i] = psaBack[i-1] + D;
        } else if (temp == 'd') {
            psaForward[i] = psaForward[i-1] + D;
            psaBack[i] = psaBack[i-1] + U;
        } else {
            psaForward[i] = psaForward[i-1] + F;
            psaBack[i] = psaBack[i-1] + F;
        }
        if (psaForward[i] + psaBack[i] <= M) {
            k = i;
        }
    }
    cout << k << endl;
}