class Solution {
    
    class UF{
        vector<int> par;
    public:
        UF() {
            par = vector<int>(26);
            for(int i=0; i<par.size(); ++i) par[i] = i;
        }
        
        int Find(int x) {
            if(par[x] != x) par[x] = Find(par[x]);
            return par[x];
        }
        
        void Union(int x, int y) {
            x = Find(x);
            y = Find(y);
            if(x != y) {
                par[x] = y;
            }
        }        
    };
    
public:
    bool equationsPossible(vector<string>& eq) {
        UF uf;
        for(string& s : eq) {
            if(s[1] == '=') {
                int x = s[0] - 'a';                
                int y = s[3] - 'a';
                uf.Union(x, y);
            }
        }
        
        for(string& s : eq) {
            if(s[1] == '!') {
                if(uf.Find(s[0]-'a') == uf.Find(s[3]-'a')) return false;
            }
        }
        
        return true;
    }
};