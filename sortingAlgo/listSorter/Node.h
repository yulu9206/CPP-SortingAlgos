#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    Node();
    Node(Element e_);
    Node(const Node& other);
    virtual ~Node();
    Node *next;
    bool operator <= (const Node& other);
    bool operator > (const Node& other);
//    Element get_e() const;
//private:
    Element element;
};

#endif /* NODE_H_ */
