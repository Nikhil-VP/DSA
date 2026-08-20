class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string digits = "123456789";

        // Length of sequential digits can range from 2 to 9
        for (int length = 2; length <= 9; ++length) {
            for (int start = 0; start <= 9 - length; ++start) {
                int num = stoi(digits.substr(start, length));
                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};