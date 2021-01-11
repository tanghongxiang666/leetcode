/*
    使用快慢下标，遍历字符串复杂度为O(n),集合查找为O(logn)，所以总效率为O(nlogn)
    
*/

int lengthOfLongestSubstring(string s) {
    set<char> st;
    int slow = 0, fast = 0;
    int res = 0;
    while(slow <= fast && fast < s.length()){
        if(st.find(s[fast]) == st.end()){
            res = max(res, fast - slow + 1);
            st.insert(s[fast]);
            fast++;
        }else{
            while(slow <= fast && s[slow] != s[fast]){
                st.erase(s[slow]);
                slow++;
            }
            slow++;
            fast++;
        }
    }
    return res;
}


//可以使用unordered_map代替set，复杂度为O(n)
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> um;
    int slow = 0, fast = 0;
    int res = 0;
    while(slow <= fast && fast < s.length()){
        if(um[s[fast]] == 0){
            res = max(res, fast - slow + 1);
            um[s[fast]]++;
            fast++;
        }else{
            while(slow <= fast && s[slow] != s[fast]){
                um[s[slow]]--;
                slow++;
            }
            slow++;
            fast++;
        }
    }
    return res;
}