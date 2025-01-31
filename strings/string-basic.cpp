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
    cout << isPalindrome("Siddharth") << endl;
    return 0;
}
