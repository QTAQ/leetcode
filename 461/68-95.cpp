class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=0;
        for(int i=x^y;i>0;i>>=1){
            res+= ((i&1)?1:0);
        }
        return res;
    }
};