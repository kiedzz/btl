#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @brief Định dạng cột khi in ra
 *
 * @tparam T
 * @param data
 * @param width
 */
template <typename T>
void sprintf(T data, const int &width = 20)
{
    cout << left << setw(width) << setfill(' ') << data;
}

/**
 * @brief Dừng màn hình
 *
 */
void pauseScreen()
{
    system("read -p 'Nhan Enter de tiep tuc...' var");
    cout << endl;
}

/**
 * @brief Convert sang string
 *
 * @tparam T
 * @param data
 * @return string
 */
template <typename T>
string toString(T data)
{
    ostringstream ss;
    ss << data;
    string s(ss.str());
    return s;
}