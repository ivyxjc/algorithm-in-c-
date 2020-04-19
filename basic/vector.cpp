#include <iostream>

#include <vector>

using namespace std;
using std::vector;
int main(int argc, char const *argv[])
{
    vector<string> svec1 = {"abc", "bcd"};
    vector<string> svec2(svec1);
    for (auto &i : svec1[0])
    {
        i = toupper(i);
    }
    vector<string>::size_type a = svec1.size();
    cout << a << endl;
    cout << svec1[0] << endl;
    cout << svec2[0] << endl;

    vector<int> ivec1(10);
    for (int i = 0; i < 100; i++)
    {
        ivec1.push_back(i);
    }
    cout << ivec1.size() << endl;

    auto b = ivec1.begin(), e = ivec1.end();
    while (b != e)
    {
        cout << *b << endl;
        b++;
    }

    return 0;
}
