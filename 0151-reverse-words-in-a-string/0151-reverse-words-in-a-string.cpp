class Solution {
public:
    string reverseWords(string s) {
        int i=0; 
        while(s[i] == ' '){
            i++;
        }
        string ans = "";
        string temp_word = "";
        while(i < s.size()){
            if(s[i] != ' '){
                temp_word += s[i];
            }else{
                if(temp_word.size() > 0){
                    if(ans.size() > 0){
                        ans = temp_word + " " + ans;
                    }else{
                        ans = temp_word;
                    }
                    temp_word = "";
                }  
            }
            i++;
        }
        if(temp_word.size() > 0){ 
            if(ans.size() > 0) ans = temp_word + " " + ans;
            else ans = temp_word;
        }
        return ans;
    }
};