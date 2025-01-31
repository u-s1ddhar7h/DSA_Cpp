#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() {
    // Initialize string
    string s = "John";
    // concatinate two string or append
    string s1 = "Rohit", s2 = "Mohit";
    string s3 = s1 + s2; // s1.append(s2);
    cout << s3 << endl;
    // add character to a string
    s1.push_back('p');
    cout << s1 << endl;
    // remove last character from string
    s1.pop_back();
    cout << s1 << endl;
    // Escaping characters
    string s4 = "Rohit is a \"good\" boy";
    cout << s4 << endl;
    cout << "\\0" << endl;
    return 0;
}
