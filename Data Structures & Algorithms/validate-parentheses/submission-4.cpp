class Solution {
public:
    bool isValid(string s) {
        auto length  = s.size();
        if (length <= 1) {
            return false;
        }
        stack<char> myStack;
        char top;
        for (auto i = 0; i < length; i++) {
            if ( (s[i] == '(') || (s[i] == '{') || (s[i] == '[') ) {
                myStack.push(s[i]);
            } else {
                if (!myStack.empty()) {
                    top = myStack.top();
                    myStack.pop();
                    switch (s[i]) {
                        case ')':
                            if (top == '(') {
                                break;
                            }
                            return false;
                        case '}':
                            if (top == '{') {
                                break;
                            }
                            return false;
                        case ']':
                            if (top == '[') {
                                break;
                            }
                            return false;
                    }
                } else {
                    std::cout << "Stack is empty! Cannot pop." << std::endl;
                    return false;
                }
            }
        }
        if (myStack.empty()) {
            cout<< "Here"<<endl;
            return true;
        }
        return false;
    }
};
