#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();
    static void reset();
    long get_value() const;
    static long get_copy_count();
    static long get_destructor_count();
    bool operator < (const Element& other);
    bool operator > (const Element& other) const;
    bool operator == (const Element& other);
    bool operator <= (const Element& other);
    friend ostream& operator<< (ostream& out, const Element& e);
    static long copy;
    static long destructor;
private:
    long value;

};

#endif /*ELEMENT_H_*/
