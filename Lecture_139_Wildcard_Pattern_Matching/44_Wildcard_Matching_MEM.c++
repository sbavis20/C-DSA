class Solution {
public:
    bool solve(string&str,string& pattern,int i,int j){
        if(i<0&&j<0){
            return true;
        }
        if(i>=0&&j<0){
            return false;
        }

        if(i<0&&j>=0){
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        if(str[i]==pattern[j]||pattern[j]=='?')
        return solve(str,pattern,i-1,j-1);
        else if(pattern[j]=='*')
        return (solve(str,pattern,i-1,j)||solve(str,pattern,i,j-1));
        else
        return false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }
};
