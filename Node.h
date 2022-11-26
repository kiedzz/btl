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
    /**
     * @brief Construct a new Node object
     *
     */

    Node()
    {
        this->nextNode = NULL;
        this->previousNode = NULL;
    }

    /**
     * @brief Set the Node Data object
     *
     * @param data
     */

    void setNodeData(Student data)
    {
        this->data = data;
    }

    /**
     * @brief Get the Node Data object
     *
     * @return Student
     */

    Student getNodeData()
    {
        return this->data;
    }

    /**
     * @brief Set the Next Node object
     *
     * @param node
     */

    void setNextNode(Node *node)
    {
        this->nextNode = node;
    }

    /**
     * @brief Get the Next Node object
     *
     * @return Node&
     */

    Node &getNextNode()
    {
        return *this->nextNode;
    }

    /**
     * @brief Set the Previous Node object
     *
     * @param node
     */

    void setPreviousNode(Node *node)
    {
        this->previousNode = node;
    }

    /**
     * @brief Get the Previous Node object
     *
     * @return Node&
     */

    Node &getPreviousNode()
    {
        return *this->previousNode;
    }
};