class Solution {
public:
      bool solve(int i,string &s,unordered_set<string>&dict,unordered_map<int,bool>&dp) 
  {
        if(i==s.size())
        {
            return dp[i]=true;
        }   
        if(dp.find(i)!=dp.end()) return dp[i];
        for(int j=i;j<s.size();j++)
        {
            string word=s.substr(i,j-i+1);
            if(dict.find(word)!=dict.end())
            {
              bool ans= solve(j+1,s,dict,dp); // try all possibilities
                if(ans==true)
                return dp[i]=true;
            }
            
        }
        return dp[i]=false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
         ios::sync_with_stdio(NULL);
         cin.tie(NULL);cout.tie(NULL);

        unordered_set<string>dict;
        for(int i=0;i<wordDict.size();i++)
        dict.insert(wordDict[i]);
        unordered_map<int,bool>dp;
        return solve(0,s,dict,dp);
    
    }
    
};