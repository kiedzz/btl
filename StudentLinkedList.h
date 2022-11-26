#include <iostream>
#include <vector>
#include "Node.h"
#include "File.h"

using namespace std;

class StudentLinkedList
{
private:
    Node *head;
    File *file;

public:
    /**
     * @brief Construct a new Student Linked List object
     *
     */
    StudentLinkedList()
    {
        this->head = NULL;
        this->file = new File();
    }

    /**
     * @brief Destroy the Student Linked List object
     *
     */
    ~StudentLinkedList()
    {
        this->deleteAllStudents();
        delete this->head;
        delete this->file;
    }

    /**
     * @brief Thêm 1 học sinh vào cuối
     *
     * @param newStudent
     * @return StudentLinkedList&
     */
    StudentLinkedList &pushNewStudent(Student newStudent)
    {
        Node *newNode = new Node();
        newNode->setNodeData(newStudent);

        if (this->head == NULL)
        {
            this->head = newNode;
            return *this;
        }

        Node *currentNode = this->head;

        while (&currentNode->getNextNode() != NULL)
            currentNode = &currentNode->getNextNode();

        currentNode->setNextNode(newNode);
        newNode->setPreviousNode(currentNode);

        return *this;
    }

    /**
     * @brief Thêm 1 học sinh vào vị trí bất kì
     *
     * @param index
     * @param newStudent
     * @return StudentLinkedList&
     */
    StudentLinkedList &insertNewStudentAt(int index, Student newStudent)
    {
        Node *newNode = new Node();
        newNode->setNodeData(newStudent);

        if (this->head == NULL)
        {
            this->head = newNode;
            return *this;
        }

        if (index == 0)
        {
            newNode->setNextNode(this->head);

            this->head->setPreviousNode(newNode);
            this->head = newNode;

            return *this;
        }

        Node *currentNode = this->head;

        int i = 0;

        while (i < index && currentNode != NULL)
        {
            currentNode = &currentNode->getNextNode();
            i++;
        }

        if (currentNode == NULL)
        {
            this->pushNewStudent(newStudent);
            return *this;
        }

        newNode->setPreviousNode(&currentNode->getPreviousNode());

        currentNode->getPreviousNode().setNextNode(newNode);
        currentNode->setPreviousNode(newNode);

        newNode->setNextNode(currentNode);

        return *this;
    }

    /**
     * @brief Xóa các học sinh của 1 lớp
     *
     * @param className
     * @return StudentLinkedList&
     */
    StudentLinkedList &deleteStudent(string className)
    {
        if (this->head != NULL)
        {
            Node *currentNode;
            currentNode = this->head;

            if (currentNode->getNodeData().getClassName() == className)
            {
                this->head = &currentNode->getNextNode();

                if (this->head != NULL)
                    this->head->setPreviousNode(NULL);

                delete currentNode;
                return *this;
            }

            while (currentNode != NULL && (currentNode->getNodeData().getClassName() != className))
                currentNode = &currentNode->getNextNode();

            if (currentNode != NULL)
            {
                currentNode->getPreviousNode().setNextNode(&currentNode->getNextNode());

                if (&currentNode->getNextNode() != NULL)
                    currentNode->getNextNode().setPreviousNode(&currentNode->getPreviousNode());

                delete currentNode;
            }
        }

        return *this;
    }

    /**
     * @brief Tìm kiếm học sinh
     *
     * @param studentName
     * @param className
     * @return vector<Student>
     */
    vector<Student> findStudent(string studentName, string className)
    {
        vector<Student> students;
        Node *currentNode = this->head;

        while (currentNode != NULL)
        {
            if (currentNode->getNodeData().getFullName() == studentName && currentNode->getNodeData().getClassName() == className)
                students.push_back(currentNode->getNodeData());

            currentNode = &currentNode->getNextNode();
        }

        return students;
    }

    /**
     * @brief Sắp xếp học sinh theo điểm TB giảm dần
     *
     * @return StudentLinkedList&
     */
    StudentLinkedList &sortByScoreAvg()
    {
        int hasNextNode;
        Node *currentNode, *nextNode = NULL;

        if (this->head != NULL)
            do
            {
                hasNextNode = 0;
                currentNode = this->head;

                while (&currentNode->getNextNode() != nextNode)
                {
                    if (currentNode->getNodeData().getScoreAvg() < currentNode->getNextNode().getNodeData().getScoreAvg())
                    {
                        hasNextNode = 1;
                        Student temp = currentNode->getNodeData();
                        currentNode->setNodeData(currentNode->getNextNode().getNodeData());
                        currentNode->getNextNode().setNodeData(temp);
                    }

                    currentNode = &currentNode->getNextNode();
                }

                nextNode = currentNode;

            } while (hasNextNode);

        return *this;
    }

    /**
     * @brief In ra list học sinh
     *
     * @param fields
     * @param mode
     */
    void printList(vector<string> fields = {}, int mode = 0)
    {
        Node *currentNode = this->head;
        int counter = 1;

        if (mode = 1)
            while (&currentNode->getNextNode() != NULL)
                currentNode = &currentNode->getNextNode();

        while (currentNode != NULL)
        {
            sprintf(counter++, 5);

            fields.size() == 0
                ? currentNode->getNodeData().getStudentInfo()
                : currentNode->getNodeData().getStudentInfo(fields);

            currentNode = (mode = 1)
                              ? &currentNode->getPreviousNode()
                              : &currentNode->getNextNode();
        }
        cout << endl;
    }

    /**
     * @brief Xóa tất cả học sinh
     *
     */
    void deleteAllStudents()
    {
        Node *currentNode = this->head;

        while (this->head != NULL)
        {
            this->head = &this->head->getNextNode();
            delete currentNode;
            currentNode = this->head;
        }
    }

    /**
     * @brief Cập nhật tất cả dữ liệu vào file
     *
     * @return StudentLinkedList&
     */
    StudentLinkedList &updateToFile()
    {
        Node *currentNode = this->head;

        while (currentNode != NULL)
        {
            Student data = currentNode->getNodeData();

            string dataString = data.getFullName() + "|" + data.getClassName() + "|" + data.getPhoneNumber() + "|" + toString(data.getScoreAvg()) + "|" + data.getClassification();

            file->writeData(dataString);

            currentNode = &currentNode->getNextNode();
        }

        return *this;
    }
};