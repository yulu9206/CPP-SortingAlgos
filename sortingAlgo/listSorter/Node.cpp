#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/
//class Node
//{
//public:
//    Node();
//    Node(Element e_);
//    Node(const Node& other);
//    virtual ~Node();
//    Node *next;
//
//    Element get_e() const;
//private:
//    Element e;
//};

Node::Node() : element(Element()), next(nullptr) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Node::Node(Element e_) : element(e_), next(nullptr) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Node::Node(const Node& other)
{
    element = other.element;
    next = other.next;
}

/**
 * Destructor.
 */
Node::~Node()
{
    /***** Complete this class. *****/
}

/**
 * Getter.
 * @return the value.
 */
bool Node::operator <= (const Node& other)
{
	if (element < other.element || element == other.element) return true;
	else return false;
}

bool Node::operator > (const Node& other)
{
	return element > other.element;
}

