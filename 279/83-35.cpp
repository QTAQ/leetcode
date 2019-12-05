class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n+1,INT32_MAX);
        v[0]=0; v[1]=1;
        for(int i=2;i<v.size();++i){
            int t=sqrt(i);
            if(t*t==i){
                v[i]=1;
                continue;
            }
            while(t>0){
                int s = v[i-t*t]+1;
                if(s<v[i]) v[i]=s;
                --t;
            }
        }
        return v[n];
    }
};