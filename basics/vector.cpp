#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

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

    return 0;
}
