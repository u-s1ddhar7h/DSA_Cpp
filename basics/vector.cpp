#include <iostream>
#include <vector>
#include <algorithm> // for std::sort and std::greater

using std::cout;
using std::endl;
using std::vector;

// Print Vector
void printVector(vector<int> vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// Vector Iteration
void printVectorNWays(vector<int> vec) {
    // 1: Simple for loop
    cout << "Simple for-loop: ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    // 2: Range-Based for loop
    cout << "Range-Based for loop: ";
    for (int val : vec)
        cout << val << " ";
    cout << endl;

    // 3: Forward-Iteration
    cout << "Forward-Iteration: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;

    // 4: Reverse-Iteration
    cout << "Reverse-Iteration: ";
    for (vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        cout << *rit << " ";
    cout << endl;
}

int main() {
    vector<int> v;
    vector<int> v1(5, 1);
    vector<int> v2 = {1, 2, 3, 4, 5};
    cout << "Size of vector 'V': " << v.size() << endl;
    cout << "Capacity of vector 'V': " << v.capacity() << endl;
    v.push_back(2);
    v.push_back(8);
    v.push_back(10);
    cout << "Size of vector 'V': " << v.size() << endl;
    cout << "Capacity of vector 'V': " << v.capacity() << endl;

    cout << "Size of vector 'V1': " << v1.size() << endl;
    cout << "Capacity of vector 'V1': " << v1.capacity() << endl;
    v1.push_back(8);
    cout << "Size of vector 'V1': " << v1.size() << endl;
    cout << "Capacity of vector 'V1': " << v1.capacity() << endl;

    cout << "Size of vector 'V2': " << v2.size() << endl;
    cout << "Capacity of vector 'V2': " << v2.capacity() << endl;

    // Update value in vector
    v[1] = 5;

    // Delete value from vector
    vector<int> vecNew = {4, 41, 82, 77, 28};
    cout << vecNew.size() << endl;
    vecNew.pop_back(); // removes the last element
    cout << vecNew.size() << endl;
    cout << vecNew.capacity() << endl;
    // remove at particular index = 2
    vecNew.erase(vecNew.begin() + 2); // this will remove 82 from the vector
    cout << vecNew.size() << " " << vecNew.capacity() << endl;

    // insert element at particular index = 1
    vecNew.insert(vecNew.begin() + 1, 50);
    printVector(vecNew);
    // update the value
    vecNew[1] = 100;
    printVector(vecNew);

    // remove all the element
    vecNew.clear();
    cout << "Size of vecNew: " << vecNew.size() << endl;
    cout << "Capacity of vecNew: " << vecNew.capacity() << endl;

    vector<int> v3 = {8, 2, 3, 9, 15, 89, 77, 30};
    printVector(v3);

    // print 1st element
    cout << v3.front() << endl;
    // print last element
    cout << v3.back() << endl;

    // copy value of one vector into another
    vector<int> vec4;
    vec4 = v3;
    printVector(vec4);

    // sort vector
    // ascending order
    std::sort(vec4.begin(), vec4.end());
    printVector(vec4);
    // descending order
    std::sort(vec4.begin(), vec4.end(), std::greater<int>());
    printVector(vec4);
    std::sort(vec4.rbegin(), vec4.rend());
    printVector(vec4);

    return 0;
}
