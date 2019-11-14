class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(size == 0) return true;
        string stk;
        for(int i=0;i<size;++i){
            char t = stk.back();
            switch(s[i]){
                case ')':
                    if(t!='(') return false;
                    stk.pop_back();
                    break;
                case '}':
                    if(t!='{') return false;
                    stk.pop_back();
                    break;
                case ']':
                    if(t!='[') return false;
                    stk.pop_back();
                    break;
                default:
                    stk += s[i];
                    break;
            }
        }
        return (stk.empty())?true:false;
    }
};