class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s;
        while(x) {
            int t = x % 10 + '0';
            x = x / 10;
            s.push_back(t);
        }
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};