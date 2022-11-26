#include <iostream>
#include <fstream>

using namespace std;

class File
{
private:
    ofstream writeFile;
    ifstream readFile;

public:
    /**
     * @brief Ghi dữ liệu vào file
     *
     * @param data
     */
    void writeData(string data)
    {
        this->writeFile.open("students.txt", ios_base::app);
        this->writeFile << data << endl;
        this->writeFile.close();
    }
};