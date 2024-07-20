class Solution {
    vector<int> NSL(vector<int>arr){
        vector<int>v;
        stack<pair<int,int>>s;
        for(int i=0; i<arr.size(); i++){
            if(s.empty()){
                v.push_back(-1);
            }else if(s.size()>0 && s.top().first<arr[i]){
                v.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(-1);
                }else{
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        return v;
    }
    vector<int> NSR(vector<int>arr){
        vector<int>v;
        stack<pair<int,int>>s;
        for(int i=arr.size()-1; i>=0; i--){
            if(s.empty()){
                v.push_back(arr.size());
            }else if(s.size()>0 && s.top().first<arr[i]){
                v.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(arr.size());
                }else{
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl = NSL(heights);
        vector<int> nsr = NSR(heights);
        vector<int> width(n,0),area(n,0);
        for(int i=0; i<n; i++){
            width[i] = nsr[i]-nsl[i]-1;
        }
        for(int i=0; i<n; i++){
            area[i] = width[i]*heights[i];
        }
        int ans = *max_element(area.begin(),area.end());
        return ans;
    }
};