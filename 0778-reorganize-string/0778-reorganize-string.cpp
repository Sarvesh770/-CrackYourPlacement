class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        map<char,int>mp;
        for(int i=0; i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>p;
        for(auto i:mp){
            p.push({i.second,i.first});
        }
        while(p.size()>1){
            char current = p.top().second;
            int c = p.top().first;
            c--;
            p.pop();
            char next = p.top().second;
            int n = p.top().first;
            n--;
            p.pop();
            ans.push_back(current);
            ans.push_back(next);
            if(c>0) p.push({c,current});
            if(n>0) p.push({n,next});
        }
        if(p.top().first > 1) return "";
        if(p.size()) ans.push_back(p.top().second);
        for(int i=0; i<s.size()-1;i++){
            if(ans[i] == ans[i+1]){
                return "";
            }
        }
        return ans;
    }
};