#include <iostream>
#include "LinkedList.h"
using namespace std;

/**
 * Default constructor.
 */
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {};

/**
 * Constructor: Create a new list from an existing one.
 * Both lists will share the nodes.
 * @param head the head of the existing list.
 * @param tail the tail of the existing list.
 * @param size the size of the existing list.
 */
LinkedList::LinkedList(Node *head, Node *tail, const int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;
    
    this->size = size;
}

/**
 * Destructor.
 */
LinkedList::~LinkedList() {}

/**
 * Get the head of the list.
 * @return the head.
 */
Node *LinkedList::get_head() const { return head; }

/**
 * Get the tail of the list.
 * @return the tail.
 */
Node *LinkedList::get_tail() const { return tail; }

/**
 * Get the size of the list.
 * @return the size.
 */
int LinkedList::get_size() const { return size; }

/**
 * Set the head, tail, and size of the linked list.
 * @param head the head of the linked list.
 * @param tail the tail of the linked list.
 * @param size the size of the linked list.
 */
void LinkedList::set(Node *head, Node *tail, int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;
    this->size = size;
}

/**
 * Remove the head of the list and return the removed node.
 * @return the removed node.
 */
Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;
    
    Node *removed_head = head;
    head = head->next;
    
    // Is the list now empty?
    if (head == nullptr) tail = nullptr;
    
    size--;
    return removed_head;
}

/**
 * Add a node to the tail of the list.
 * @param value the value of the node to add.
 */
void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

/**
 * Add a node to the tail of the list.
 * @param node the node to add.
 */
void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }
    
    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }
    
    node->next = nullptr;
    size++;
}

/**
 * Delete all the nodes of the list.
 */
void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }
    
    tail = nullptr;
    size = 0;
}

/**
 * Reset the head, tail, and size of the list.
 */
void LinkedList::reset()
{
    head = tail = nullptr;
    size = 0;
}

/**
 * Print the values of the list's nodes.
 */
void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

/**
 * Split this list into two sublists from the middle.
 * @param list1 the first sublist.
 * @param list2 the second sublist.
 */
void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
    int s1, s2;
    if (size == 0 || size == 1) return;
    else if (size % 2 == 0) s1 = s2 = size/2;
    else
    {
        s1 = size/2;
        s2 = size/2 + 1;
    }
    Node *l = head;
    Node *m = l;
    for (int i = 1; i < s1; i++)
    {
        m = m->next;
    }
    Node *n = m->next;
    Node *o = tail;
    
    list1.set(l, m, s1);
    list2.set(n, o, s2);
    return;
}

/**
 * Add another list to the end of this list.
 * @param other_list the other list.
 */
void LinkedList::concatenate(LinkedList& other_list)
{
    Node *other_head = other_list.get_head();
    if (other_head == nullptr) return;
    if (head == nullptr)
    {
        head = other_head;
        tail = other_list.get_tail();
    }
    
    // Subsequent node.
    else
    {
        tail->next = other_head;
        tail = other_list.get_tail();
    }
    
    size += other_list.get_size();
    return;
}
