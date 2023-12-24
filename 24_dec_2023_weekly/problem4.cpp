class Solution {
public:
    typedef long long LL;
    int n = 0;
    struct TrieNode {
        TrieNode * vec[26];
        int idx;
        TrieNode() {
            memset(vec, 0, sizeof vec);
            idx = -1;
        }
    };
    
    int add(string & str, TrieNode * node) {
        for (char c : str) {
            if (node->vec[c-'a'] == NULL) {
                node->vec[c-'a'] = new TrieNode;
            }
            
            node = node->vec[c-'a'];
        }
            
        if (node->idx == -1) {
            node->idx = n++;
        }
        
        return node->idx;
    }
    
    int find(string & str, TrieNode * node) {
        for (char c : str) {
            if (node->vec[c-'a'] == NULL) {
                return -1;
            }
            
            node = node->vec[c-'a'];
        }
        
        return node->idx;
    }
    
    long long minimumCost(string s, string t, vector<string>& o, vector<string>& c, vector<int>& cost) {
        for (string & str : o) {
            reverse(str.begin(), str.end());
        }
        for (string & str : c) {
            reverse(str.begin(), str.end());
        }

        int o1[101], c1[101];
        
        TrieNode * root = new TrieNode;
        for (int i = 0; i < o.size(); i++) {
            o1[i] = add(o[i], root);
        }
        for (int i = 0; i < c.size(); i++) {
            c1[i] = add(c[i], root); 
        }
        
    
        LL dist[201][201];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = 1e18;
            }
        }
        for (int i = 0; i < o.size(); i++) {
            int x = o1[i], y = c1[i];
            
            dist[x][y] = min(dist[x][y], 0LL+cost[i]);
        }

       
        for (int k = 0; k < n; k++) {
            dist[k][k] = 0;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int m = s.size();
        vector<LL> dp(m, 1e18);
        
        for (int i = 0; i < m; i++) {
            if (s[i] == t[i]) {
                if (i)
                    dp[i] = dp[i-1];
                else 
                    dp[i] = 0;
            }
            TrieNode * n1 = root;
            TrieNode * n2 = root;
            for (int j = i; j >= 0; j--) {
                n1 = n1->vec[s[j]-'a'];
                n2 = n2->vec[t[j]-'a'];
                
                if (n1 == NULL || n2 == NULL)
                    break;
                
                if (n1->idx == -1 || n2->idx == -1)
                    continue;
                
                    LL d = dist[n1->idx][n2->idx];
                    
                    if (d != INT_MAX) {
                        if (j == 0)
                            dp[i] = min(dp[i], d);
                        else
                            dp[i] = min(dp[i], dp[j-1] + d);
                    }
                
            }
            
            
        }
        
        if (dp[m-1] == 1e18)
            return -1;
        
        return dp[m-1];
    }
};
