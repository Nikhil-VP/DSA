class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        vector<int> temp(26,0);
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            temp[s[j]-'a']++;
            while(temp[s[j]-'a']>2){
                temp[s[i]-'a']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};