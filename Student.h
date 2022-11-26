#include <iostream>
#include <iomanip>
#include "helpers.h"

using namespace std;

class Student
{
private:
    string fullName;
    string className;
    string phoneNumber;
    float scoreAvg;

public:
    /**
     * @brief Create a New Student object
     *
     */
    void createNewStudent()
    {
        cout << "Nhap thong tin hoc sinh: " << endl;
        cout << "Ten hoc sinh: ";
        getline(cin, this->fullName);
        cout << "Ten lop: ";
        getline(cin, this->className);
        cout << "So dien thoai: ";
        getline(cin, this->phoneNumber);
        cout << "Diem trung binh: ";
        cin >> this->scoreAvg;
    }

    /**
     * @brief Get the Student Info object
     *
     * @param fields
     */
    void getStudentInfo(vector<string> fields = {})
    {
        if (fields.size() == 0)
        {
            sprintf(this->fullName);
            sprintf(this->className);
            sprintf(this->phoneNumber);
            sprintf(this->scoreAvg);
            sprintf(this->getClassification());
        }
        else
        {
            for (int i = 0; i < fields.size(); i++)
            {
                if (fields[i] == "fullName")
                    sprintf(this->getFullName());
                if (fields[i] == "className")
                    sprintf(this->getClassName());
                if (fields[i] == "phoneNumber")
                    sprintf(this->getPhoneNumber());
                if (fields[i] == "scoreAvg")
                    sprintf(this->getScoreAvg());
                if (fields[i] == "classification")
                    sprintf(this->getClassification());
            }
        }
        cout << endl;
    }

    /**
     * @brief Get the Classification object
     *
     * @return string
     */
    string getClassification()
    {
        if (this->scoreAvg >= 3.5 && this->scoreAvg < 5)
            return "Y";

        if (this->scoreAvg >= 5 && this->scoreAvg < 6.5)
            return "TB";

        if (this->scoreAvg >= 6.5 && this->scoreAvg < 8)
            return "K";

        if (this->scoreAvg >= 8)
            return "G";

        return "N";
    }

    /**
     * @brief Get the Full Name object
     *
     * @return string
     */
    string getFullName()
    {
        return this->fullName;
    }

    /**
     * @brief Get the Class Name object
     *
     * @return string
     */
    string getClassName()
    {
        return this->className;
    }

    /**
     * @brief Get the Phone Number object
     *
     * @return string
     */
    string getPhoneNumber()
    {
        return this->phoneNumber;
    }

    /**
     * @brief Get the Score Avg object
     *
     * @return float
     */
    float getScoreAvg()
    {
        return this->scoreAvg;
    }
};