#include <iostream>

using std::cout;
using std::endl;
using std::string;

void stringReverse(string str) {
    int start = 0, end = str.size() - 1;
    while (start < end) {
        std::swap(str[start], str[end]);
        start++, end--;
    }
    cout << str << endl;
}

// reverse a part of string
void reverseStringPart(string &str, int start, int end) {
    while (start < end) {
        std::swap(str[start], str[end]);
        start++, end--;
    }
}

// find size without using builtin function size()
int stringSize(string str) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

bool isPalindrome(string str) {
    int start = 0, end = str.size() - 1;
    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++, end--;
    }
    return 1;
}

void rotateString(string &s) {
    // rotate clockwise by 1 position
    // store last character
    char temp = s[s.size() - 1];
    for (int i = s.size() - 2; i >= 0; i--) {
        s[i + 1] = s[i];
    }
    s[0] = temp;
    cout << s;
}

void rotateStringAnti(string & s) {
    // rotate anti-clockwise by 1 position
    // store 1st character
    char firstChar = s[0];
    for (int i = 1; i < s.size(); i++) {
        s[i - 1] = s[i];
    }
    s[s.size() - 1] = firstChar;
    cout << s << endl;
}

// rotate string clockwise by k position
void rotateStringKPos(string &str, int k) {
    // 1st: reverse the entire string
    reverseStringPart(str, 0, str.size() - 1);
    // 2nd: reverse from 0 to size()-1-k
    reverseStringPart(str, 0, str.size() - 1 - k);
    // 3rd: reverse from size()-k to size()-1
    reverseStringPart(str, str.size() - k, str.size() - 1);
}

// rotate string anti-clockwise by k position
void rotateStringAntiKPos(string &str, int k) {
    // 1st: reverse the entire string
    reverseStringPart(str, 0, str.size() - 1);
    // 2nd: reverse from 0 to k - 1
    reverseStringPart(str, 0, k - 1);
    // 3rd: reverse from k to size()-1
    reverseStringPart(str, k, str.size() - 1);
}

int main() {
    // Initialize string
    // string s = "John";
    // // concatinate two string or append
    // string s1 = "Rohit", s2 = "Mohit";
    // string s3 = s1 + s2; // s1.append(s2);
    // cout << s3 << endl;
    // // add character to a string
    // s1.push_back('p');
    // cout << s1 << endl;
    // // remove last character from string
    // s1.pop_back();
    // cout << s1 << endl;
    // // Escaping characters
    // string s4 = "Rohit is a \"good\" boy";
    // cout << s4 << endl;
    // cout << "\\0" << endl;
    // stringReverse("Rohit");
    // cout << stringSize("Rohit") << endl;
    // cout << isPalindrome("Siddharth") << endl;
    string s = "SIDDHARTH";
    // rotateString(s);
    // rotateStringAnti(s);
    // rotateStringKPos(s, 2);
    rotateStringAntiKPos(s, 2);
    cout << s << endl;
    return 0;
}
