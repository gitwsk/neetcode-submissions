#include<string>

class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto mystr : strs) {
            int length = mystr.length();
            string code = to_string(length) + "#";
            mystr = code + mystr;
            res.append(mystr);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> vec = {};
        string mystr;
        for (int i=0; i < s.length();) {
            cout<< i << endl;
            size_t pos = s.find('#', i);
            size_t len = stoi(s.substr(i, pos));
            i=pos+1;
            mystr = s.substr(i, len);
            vec.push_back(mystr);
            i+=len;
        }
        return vec;
    }
};
