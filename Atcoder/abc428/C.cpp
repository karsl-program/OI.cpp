#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int q;
        scanf("%d", &q);
        
        std::stack<std::pair<int, int>> st;
        st.push({0, 0});
        
        while (q--) {
            int t;
            scanf("%d", &t);
            
            if (t == 1) {
                char c;
                scanf(" %c", &c);
                int b = st.top().first;
                int m = st.top().second;
                
                if (c == '(') b++;
                else b--;
                
                m = std::min(m, b);
                st.push({b, m});
            } else {
                st.pop();
            }
            
            int b = st.top().first;
            int m = st.top().second;
            
            if (b == 0 && m >= 0) puts("Yes");
            else puts("No");
        }
    }
}

int main () {
    RunCode :: solve ();
    
    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/