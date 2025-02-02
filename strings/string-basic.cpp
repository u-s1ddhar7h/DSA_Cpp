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

bool isPangram(string &s) {
    // TC: O(n) & SC: O(1)
    // char ch = 'a';
    // while (ch < 123) {
    //     bool isPresent = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (ch == s[i]) {
    //             isPresent = 1;
    //             break;
    //         }
    //     }
    //     if (isPresent == 0) return 0;
    //     ch++;
    // }
    // return 1;

    // TC: O(n) & SC: O(1)
    int alphabet[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        alphabet[s[i] - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0)
            return 0;
    }
    return 1;
}

void sortString(string &s) {
    // bubble sort: TC: O(n^2) & SC: O(1)
    // for (int i = 0; i < s.size() - 1; i++) {
    //     for (int j = 0; j < s.size() - 1 - i; j++) {
    //         if (s[j] > s[j + 1])
    //             std::swap(s[j], s[j + 1]);
    //     }
    // }

    // TC: O(n) & SC: O(1)
    int alphaCount[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        alphaCount[s[i] - 'a']++;
    }
    s.clear();
    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        while (alphaCount[i]) {
            s += ch;
            alphaCount[i]--;
        }
    }
}

// longest palindrome
int longestPalindrome(string s) {
    int lowerAlpha[26] = {0}, upperAlpha[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a') {
            lowerAlpha[s[i] - 'a']++;
        } else {
            upperAlpha[s[i] - 'A']++;
        }
    }
    int ans = 0;
    bool isOdd = 0;
    for (int i = 0; i < 26; i++) {
        if (lowerAlpha[i] % 2 == 0)
            ans += lowerAlpha[i];
        else {
            ans += lowerAlpha[i] - 1;
            isOdd = 1;
        }
        if (upperAlpha[i] % 2 == 0)
            ans += upperAlpha[i];
        else {
            ans += upperAlpha[i] - 1;
            isOdd = 1;
        }
    }
    return ans + isOdd;
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
    // string s = "SIDDHARTH";
    // rotateString(s);
    // rotateStringAnti(s);
    // rotateStringKPos(s, 2);
    // rotateStringAntiKPos(s, 2);
    // cout << s << endl;
    // string s = "thequickbrownfoxjumpsoverlazydog";
    // string s = "siddharth";
    // cout << isPangram(s) << endl;
    // string s = "eabcabd";
    // string s = "siddharth";
    // sortString(s);
    // cout << s << endl;
    string s = "aaAbAcbd";
    cout << longestPalindrome(s) << endl;
    return 0;
}
