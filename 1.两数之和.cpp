/*
    暴力可通过，时间复杂度O(n2)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    for(int i = 0; i < len; ++i){
        for(int j = i + 1; j < len; ++j){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return {};
}


/*
    可以利用空间换时间，降低时间复杂度，将遍历过的元素保存在一个map中
    时间复杂度为O(nlgn)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    map<int, int> m;
    for(int i = 0; i < nums.size(); ++i){
        if(m.find(target - nums[i]) != m.end())
            return {m[target - nums[i]], i};
        else
            m[nums[i]] = i;
    }
    return {};
}

/* 
    考虑到map查询效率为O(lgn)，可以使用unordered_map来替换map，哈希的查询效率为O(1)
    所以总查询效率为O(n)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); ++i){
        if(m.find(target - nums[i]) != m.end())
            return {m[target - nums[i]], i};
        else
            m[nums[i]] = i;
    }
    return {};
}
