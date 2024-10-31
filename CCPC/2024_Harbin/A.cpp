#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int l, r;
    cin >> l >> r;
    vector<int> bl(30, 0),br(30, 0);
    for (int i=0; l; i++) {
        if (l & 1) {
            bl[i] = 1;
        }
        l >>= 1;
    }
    for (int i=0; r; i++) {
        if (r & 1) {
            br[i] = 1;
        }
        r >>= 1;
    }
    vector<int> lid(30, 0),rid(30, 0);
    int id = 2;
    int idbe = 0, beid = 0;
    for (int i=20; i>=0; i--) {
        if (br[i] ) {
            idbe = i;  break;
        }
    }
    for (int i=20; i>=0; i--) {
        if (bl[i] != br[i]) {
            beid = i;
            break;
        }
    }
    for (int i=idbe; i>=1; i--) {
        rid[i] = id;
        id ++;
    }
    int lidbe = 0;
    for (int i=20; i>=0; i--) {
        if (bl[i] == 1) {
            lidbe = i;  break;
        }
    }
    for (int i=lidbe; i>=1; i--) {
        lid[i] = id;
        id ++;
    }
    id --;
    // cout << id << ' ' << idbe << '\n';
    int num = id + idbe;
    int end = num;
    lid[0] = end;  rid[0] = end;
    vector<pair<int, int> > bian(id+10);
    for (int i=beid-1; i>=0; i--) {
        if (i < idbe && bl[i] == 0) {
            bian[lid[i+1]] = {id + beid - i, 1};
            if (i == 0) {
                bian[lid[i+1]] = {end, 1};
            }
        }
        if (br[i] == 1) {
            bian[rid[i+1]] = {id + beid - i, 0};
            if (i == 0) {
                bian[rid[i+1]] = {end, 0};
            }
        }
    }
    cout << num << '\n';
    //be
    vector<pair<int, int> > beans;
    beans.push_back({rid[idbe], 1});
    if (lid[lidbe] != end) beans.push_back({lid[lidbe], 1});
    for (int i=idbe - 1; i>=lidbe; i--) {
        beans.push_back({id + idbe - i, 1});
    }
    // cout << 1 << ' ';
    cout << beans.size() << ' ';
    for (int i=0; i<beans.size(); i++) {
        cout << beans[i].first << ' ' << beans[i].second << ' ';
    }
    cout << '\n';
    //r
    // cout << idbe << endl;
    for (int i=idbe; i>=1; i--) {
        // cout << rid[i] << "  ";
        int m = 1;
        if (bian[rid[i]].first != 0) m ++;
        cout << m << ' ' << rid[i-1] << ' ' << br[i-1] << ' ';
        if (bian[rid[i]].first != 0) {
            cout << bian[rid[i]].first << ' ' << bian[rid[i]].second;
        }
        cout << '\n';
    }
    //l
    for (int i=lidbe; i>=1; i--) {
        // cout <<lid[i] << "   ";
        int m = 1;
        if (bian[lid[i]].first != 0) m ++;
        cout << m << ' ' << lid[i-1] << ' ' << bl[i-1] << ' ';
        if (bian[lid[i]].first != 0) {
            cout << bian[lid[i]].first << ' ' << bian[lid[i]].second;
        }
        cout << '\n';
    }
    //l-r
    for (int i=idbe-2; i>0; i--) {
        // cout << id + idbe - i << ' ';
        if (i == 1) {
            cout << 2 << ' ' << end << ' ' << 1 << ' ';
            cout << end << ' ' << 0 << '\n';
            break;
        }
        cout << 2 << ' ' << id + idbe - i + 1 << ' ' << 0 << ' ';
        cout << id + idbe - i + 1 << ' ' << 1 << '\n';
    }
    //end
    cout << 0 << '\n';
}
int main()
{
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}