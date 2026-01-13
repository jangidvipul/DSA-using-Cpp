class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;

        // Iterate through string 1
        for(auto i : s){
            freq[i]++;
        }

        // iterate 
        for(auto i : t){
            freq[i]--;
        }

        for(auto i : freq){
            if(i.second != 0){
                return false;
            }
        }

        return true;
    }
};