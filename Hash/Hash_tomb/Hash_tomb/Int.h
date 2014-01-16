#ifndef _Hash_tomb_hpp_
#define _Hash_tomb_hpp_


#include <iostream>
class Int {
private:
	int val;
public:
	Int(int input=0) { val = input; }

	int key() const { return val; }

	int operator = (int input) { val = input; }
};


std::ostream& operator<<(std::ostream& s, const Int& i)
{ return s << i.key(); }
std::ostream& operator<<(std::ostream& s, const Int* i)
{ return s << i->key(); }

#endif