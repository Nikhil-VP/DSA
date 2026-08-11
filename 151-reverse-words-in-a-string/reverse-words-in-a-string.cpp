class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }
        string str ="";
        int n = words.size();
        for(int i = n-1;i >= 0; i--)
        {
            str = str + words[i];
            if(i>0)
            {
                str += " ";
            }
            
        }
        return str;
    }
};