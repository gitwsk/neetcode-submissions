class Solution {
public:
    bool isAnagram(string s, string t) {
        if (!s.size() || !t.size()) { //size of either or both strings is 0. 
            return false;
        }
        if (s.size() != t.size()) {//O(n)
            return false;
        }
        std::multiset<char> mset1, mset2;

        for (char c : s) {
            mset1.insert(c); //O(log(n))
        }
        for (char c : t) {
            mset2.insert(c);
        }
        if (mset1 == mset2) {//
            return true;
        }
        return false;
    }
};
