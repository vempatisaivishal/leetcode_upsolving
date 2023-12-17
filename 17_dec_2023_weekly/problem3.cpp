class Solution {
public:
    bool isPalindrome(int num) {
       string s=to_string(num);
        int l=0;
        int r=s.size()-1;
        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l+=1;
            r-=1;
        }
        return true;
    }
    
    long long minimumCost(vector<int>& a) {
        sort(a.begin(), a.end());
        
        int n=a.size();
        
        int k=a[n/2];
        
        int lo=k, hi=k+1;
        
        
        while (!isPalindrome(lo)) {
            lo--;
        }

        while (!isPalindrome(hi)) {
            hi++;
        }
        
        long long a1=0, b=0;
        
        for(int i: a) 
        {
            a1+=abs(lo-i);
        }
        
        for(int i: a)
        {
            b+=abs(hi-i);
        }

        return min(a1,b);

    }
};

