#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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

// sorting the sentence
void sortSentence(string &s) {
    // TC: O(n) & SC: O(n)
    vector<string> ans(10);
    string word;
    int totalIndex = 0;
    s += ' ';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            int pos = word[word.size() - 1] - '0';
            word.pop_back();
            ans[pos] = word;
            word.clear();
            totalIndex++;
        } else
            word += s[i];
    }
    s.clear();
    for (int i = 1; i <= totalIndex; i++) {
        s += ans[i] + ' ';
    }
    s.pop_back();
}

// sort the vowels in string
void sortVowelInString(string &s) {
    // 1st: Extract vowels
    string vowels;
    for (char &c : s) {
        switch (c) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
                vowels += c;
                c = '#';  // Mark position
                break;
        }
    }
    // 2nd: sort the vowels string
    // bubble sort -> TC: O(n^2)
    for (int i = 0; i < vowels.size() - 1; i++) {
        for (int j = 0; j < vowels.size() - 1 - i; j++) {
            if (vowels[j] > vowels[j + 1])
                std::swap(vowels[j], vowels[j + 1]);
        }
    }
    // 3rd: insert the sorted-vowels into their correct position
    int vowelIndex = 0;
    for (char &c : s) {
        if (c == '#') {
            c = vowels[vowelIndex++];
        }
    }
    cout << s << endl;
}

// add two string as integer
string addStringInteger(string& num1, string& num2) {
    // TC: O(N) & SC: O(N)
    string ans;
    int i = num1.size() - 1, j = num2.size() - 1;
    int sum = 0, carry = 0;
    while (j >= 0) {
        sum = (num1[i] - '0') + (num2[j] - '0') + carry;
        carry = sum / 10;
        char ch = '0' +  sum % 10;
        ans += ch;
        i--, j--;
    }
    while (i >= 0) {
        sum = (num1[i] - '0') + carry;
        carry = sum / 10;
        char ch = '0' + sum % 10;
        ans += ch;
        i--;
    }
    if (carry) ans += '1';
    std::reverse(ans.begin(), ans.end());
    return ans;
}

// roman to integers
int num(const char& ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
int romanToIntegers(const string& s) {
    // TC: O(N) & SC: O(1)
    int i = 0, sum = 0;
    while (i < s.size() - 1) {
        if (num(s[i]) < num(s[i + 1]))
            sum -= num(s[i]);
        else sum += num(s[i]);
        i++;
    }
    sum += num(s[i]);
    return sum;
}

// unit-place
string unitPlaceString(int n) {
    switch (n) {
        case 1: return "I";
        case 2: return "II";
        case 3: return "III";
        case 4: return "IV";
        case 5: return "V";
        case 6: return "VI";
        case 7: return "VII";
        case 8: return "VIII";
        case 9: return "IX";
    }
    return "";
}
// tens-place
string tensPlaceString(int n) {
    switch (n) {
        case 1: return "X";
        case 2: return "XX";
        case 3: return "XXX";
        case 4: return "XL";
        case 5: return "L";
        case 6: return "LX";
        case 7: return "LXX";
        case 8: return "LXXX";
        case 9: return "XC";
    }
    return "";
}
// hundreds-place
string hundredsPlaceString(int n) {
    switch (n) {
        case 1: return "C";
        case 2: return "CC";
        case 3: return "CCC";
        case 4: return "CD";
        case 5: return "D";
        case 6: return "DC";
        case 7: return "DCC";
        case 8: return "DCCC";
        case 9: return "CM";
    }
    return "";
}
// thousands-place
string thousandsPlaceString(int n) {
    switch (n) {
        case 1: return "M";
        case 2: return "MM";
        case 3: return "MMM";
    }
    return "";
}
void intToRoman(int num) {
    // TC: O(1) & SC: O(1)
    string ans;
    if (num >= 1000) {
        ans += thousandsPlaceString(num/1000);
        num %= 1000;
    }
    if (num >= 100) {
        ans += hundredsPlaceString(num/100);
        num %= 100;
    }
    if (num >= 10) {
        ans += tensPlaceString(num/10);
        num %= 10;
    }
    ans += unitPlaceString(num);
    cout << ans << endl;
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
    // string s = "aaAbAcbd";
    // cout << longestPalindrome(s) << endl;
    // string s = "is2 sentence4 This1 a3";
    // sortSentence(s);
    // cout << s << endl;
    // string s = "lEetcOde";
    // sortVowelInString(s);
    // string num1 = "10", num2 = "3689";
    // if (num1.size() < num2.size())
    //     cout << addStringInteger(num2, num1) << endl;
    // else cout << addStringInteger(num1, num2) << endl;
    // string s = "MCCXLVIII";
    // cout << romanToIntegers(s) << endl;
    int num = 3749;
    intToRoman(num);
    return 0;
}
