#include <iostream>
#include "Student.h"

using namespace std;

class Node
{
private:
    Student data;
    Node *nextNode;
    Node *previousNode;

public:
    Node()
    {
        this->nextNode = NULL;
        this->previousNode = NULL;
    }

    void setNodeData(Student data)
    {
        this->data = data;
    }

    Student getNodeData()
    {
        return this->data;
    }

    void setNextNode(Node *node)
    {
        this->nextNode = node;
    }

    Node &getNextNode()
    {
        return *this->nextNode;
    }

    void setPreviousNode(Node *node)
    {
        this->previousNode = node;
    }

    Node &getPreviousNode()
    {
        return *this->previousNode;
    }
};