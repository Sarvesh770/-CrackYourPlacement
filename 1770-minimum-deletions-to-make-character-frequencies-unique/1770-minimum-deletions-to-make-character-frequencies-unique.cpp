class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;

        for (auto &it : s) {
            mp[it]++;
        }

        priority_queue<int> pq;

        for (auto &it : mp) {
            pq.push(it.second);
        }
        
        int count = 0;

        while (pq.size() != 1) {
            int top = pq.top(); 
            pq.pop(); 
            if (pq.top() == top && top != 0) {
                count++; 
                pq.push(top - 1); 
            }
        }

        return count;

    }
};