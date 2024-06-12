class Solution {
public:

   void solve(int i,string &s,unordered_set<string>&dict,string &currentSentence,
           vector<string>&ans) 
  {
        if(i==s.size())
        {
            ans.push_back(currentSentence);
            return;
        }   

        for(int j=i;j<s.size();j++)
        {
            string sentence=currentSentence;
            string word=s.substr(i,j-i+1);
            if(dict.find(word)!=dict.end())
            {
                if(!currentSentence.empty())
                currentSentence+=" ";

                currentSentence+=word;   // add word
                solve(j+1,s,dict,currentSentence,ans); // try all possibilities
                currentSentence=sentence;   //backtrack
            }
            
        }
   }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);cout.tie(NULL);
    
    string currentSentence="";
    vector<string>ans;

    unordered_set<string>dict;
    for(int i=0;i<wordDict.size();i++)
    dict.insert(wordDict[i]);

    solve(0,s,dict,currentSentence,ans);
    return ans;
  }
};