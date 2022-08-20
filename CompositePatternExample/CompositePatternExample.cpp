#include <iostream>
#include <vector>
using namespace std;

class Component {
public:
	virtual ~Component() {}
	virtual void Add(Component* c) = 0;
	virtual void Remove(int index) = 0;
	virtual void Delete(int index) = 0;
	virtual void Operation() = 0;
};