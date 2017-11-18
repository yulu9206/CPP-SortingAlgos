#include <iostream>
#include "Element.h"

using namespace std;

 long Element::copy;
 long Element::destructor;
//long Element::get_copy_count();
//long Element::get_destructor_count();
/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    value = other.get_value();
    copy++;
//    cout << "copy is " << copy;
}

/**
 * Destructor.
 */
Element::~Element()
{
	destructor++;
//    cout << "destructor is " << destructor;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }


long Element::get_copy_count() { return copy; }
//
///**
// * @return the element destructor count.
// */
long Element::get_destructor_count() { return destructor; }

void Element::reset()
{
	copy = destructor = 0;
	return;
}

bool Element::operator < (const Element& other)
{
	return value < other.get_value();
}

bool Element::operator > (const Element& other) const
{
	return value > other.get_value();
}

bool Element::operator == (const Element& other)
{
	return value == other.get_value();
}

bool Element::operator <= (const Element& other)
{
	return value <= other.get_value();
}

ostream& operator<< (ostream& out, const Element& e)
{
   out << e.get_value();
   return out;
}
