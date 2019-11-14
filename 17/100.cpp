class Solution {
public:
    vector<string> r;
    string m[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int i, int size, string &s, string d){
        if(i==size){
            r.push_back(s);
            return;
        }
        string t = m[d[i]-48];
        int tsize = t.size(); 
        for(int j=0;j<tsize;++j){
            s.push_back(t[j]);
            dfs(i+1,size,s,d);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return r;
        int digitsSize = digits.size();
        string s;
        dfs(0,digitsSize,s,digits);
        return r;
    }
};