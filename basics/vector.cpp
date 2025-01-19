#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {

    // Declare vector
    vector<int> v;
    cout << "Size of vector 'V': " << v.size() << endl;
    cout << "Capacity of vector 'V': " << v.capacity() << endl;
    v.push_back(2);
    v.push_back(8);
    v.push_back(10);
    cout << "Size of vector 'V': " << v.size() << endl;
    cout << "Capacity of vector 'V': " << v.capacity() << endl;
    return 0;
}
