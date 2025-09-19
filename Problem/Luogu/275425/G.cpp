#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int t;
        std :: cin >> t;
        
        struct node {
            std :: string name, doc;
            int apt, reg, chi;
            bool sig, lat;
        };
        
        std :: map<std :: string, node> app;
        std :: map<std :: string, std :: vector<node>> que;
        
        auto cmp = [](const node& a, const node& b) {
            if (a.lat != b.lat) return !a.lat;
            if (!a.lat) {
                if (a.apt != b.apt) return a.apt < b.apt;
                return a.reg < b.reg;
            }
            return a.chi < b.chi;
        };
        
        #define tim(h, m) (h * 60 + m)
        
        auto enc = [](const std :: string& s) {
            if (s.length() <= 2) return s;
            std :: string r = s;
            for (int i = 1; i < r.length() - 1; i++)
                r[i] = '*';
            return r;
        };
        
        for (int i = 0; i < t; i++) {
            int h, m;
            std :: cin >> h >> m;
            int cur = tim(h, m);
            
            std :: string typ;
            std :: cin >> typ;
            
            if (typ == "appointment") {
                std :: string nam, doc;
                int ah, am;
                std :: cin >> nam >> doc >> ah >> am;
                int apt = tim(ah, am);
                
                app[nam] = {nam, doc, apt, cur, 0, false, false};
            }
            else if (typ == "register") {
                std :: string nam;
                std :: cin >> nam;
                
                if (app.find(nam) == app.end() || app[nam].sig) {
                    std :: cout << "Fail\n";
                    continue;
                }
                
                node& p = app[nam];
                if (cur < p.apt - 60) {
                    std :: cout << "Fail\n";
                    continue;
                }
                
                std :: cout << "Success\n";
                p.sig = true;
                p.lat = (cur > p.apt);
                
                que[p.doc].push_back({nam, p.doc, p.apt, p.reg, cur, true, p.lat});
                std :: sort(que[p.doc].begin(), que[p.doc].end(), cmp);
            }
            else {
                std :: string doc;
                std :: cin >> doc;
                
                if (que[doc].empty()) {
                    std :: cout << "No patient\n";
                    continue;
                }
                
                std :: cout << enc(que[doc][0].name) << "\n";
                que[doc].erase(que[doc].begin());
            }
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