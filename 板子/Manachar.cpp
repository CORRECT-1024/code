int manachar(string s) {
    int len = s.size();
    vector<int> ans1(len+10, 0), ans2(len+10, 0);
    int r1 = -1, id1 = 0;
    int r2 = -1, id2 = 0;
    for (int i=0; i<len; i++) {
        int k = i > r1 ? 1 : min(r1 - i, ans1[id1 - (i - id1)]);
        while (i + k < len && i - k >= 0) {
            if (s[i + k] == s[i - k] ) k ++;
            else break;
        }
        ans1[i] = k;
        if (i + k > r1) {
            r1 = i + k - 1;  id1 = i;
        }

        if (i == len - 1 || s[i] != s[i+1])  continue;
        k = i >= r2 ? 1 : min(r2 - i - 1, ans2[id2 - (i + 1 - id2)]);
        while (i + 1 + k < len && i - k >= 0) {
            if (s[i + 1 + k] == s[i - k] ) k ++;
            else break;
        }
        ans2[i] = k;
        if (i + k > r2) {
            r2 = i + k;  id2 = i;
        }
    }
    LL sum = 0;
    for (int i=0; i<len; i++) {
        sum += ans1[i];
        sum += ans2[i];
    }
    return ma;
}