#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll P;
int Y;
ll T;

bool works(ll x) {
    ll sumer = 0;
    for (int i = 0; i < Y; i++) {
        sumer += x;
        sumer += (sumer*P)/100;
        if (sumer >= T) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> P;
    cin >> Y >> T;
    ll now = 1;
    ll finish = T;
    while (now < finish) {
        ll x = (now + finish-1)/2;
        if (works(x)) {
            finish = x;
        } else {
            now = x+1;
        }
    }
    cout << now << endl;
}
