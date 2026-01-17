#include <bits/stdc++.h>

struct Node {
    Node *ne[26];
    bool end = false;
};

int ans, n;
std :: string s;
Node *root;

namespace RunCode {
    void add (std :: string s) {
        Node *cur = root; int g = 0;
        for (int i = 0; i < s.size (); i ++) {
            if (!cur -> ne[s[i] - 'a']) cur -> ne[s[i] - 'a'] = new Node ();
            cur = cur -> ne[s[i] - 'a'];
            g += cur -> end;
        }
        cur -> end = true;
        ans = std :: max (ans, g + 1);
    }

    void solve () {
        std :: cin >> n;
        root = new Node ();
        for (int i = 1; i <= n; i ++) std :: cin >> s, add (s);
        std :: cout << ans << std :: endl;
    }
}

int main () {
    std :: ios :: sync_with_stdio (false);
    std :: cin.tie (0); std :: cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/