#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
void sprintf(T data, const int &width = 20)
{
    cout << left << setw(width) << setfill(' ') << data;
}

void pauseScreen()
{
    system("read -p 'Nhan Enter de tiep tuc...' var");
    cout << endl;
}

template <typename T>
string toString(T data)
{
    ostringstream ss;
    ss << data;
    string s(ss.str());
    return s;
}