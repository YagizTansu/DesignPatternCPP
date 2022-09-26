#include <iostream>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
	virtual void visitA(ConcreteElementA* elementA) = 0;
	virtual void visitB(ConcreteElementB* elementB) = 0;
};

class ConcreteVisitor1:public Visitor {
public:
	ConcreteVisitor1() {}
	void visitA(ConcreteElementA* elementA) {
		cout << "VISITOR1 VISIT ELEMENT A" << endl;
	}

	void visitB(ConcreteElementB* elementB) {
		cout << "VISITOR1 VISIT ELEMENT B" << endl;
	}
};

class ConcreteVisitor2 :public Visitor {
public:
	ConcreteVisitor2() {}
	void visitA(ConcreteElementA* elementA) {
		cout << "VISITOR2 VISIT ELEMENT A" << endl;
	}

	void visitB(ConcreteElementB* elementB) {
		cout << "VISITOR2 VISIT ELEMENT B" << endl;
	}
};

class Element {
public:
	virtual void Accept(Visitor* visit) = 0;
};

class ConcreteElementA :public Element {
public:
	void Accept(Visitor* visit) {
		visit->visitA(this);
	}
};

class ConcreteElementB :public Element {
public:
	void Accept(Visitor* visit) {
		visit->visitB(this);
	}
};

int main() {
	ConcreteElementA elementA;
	ConcreteElementB elementB;

	ConcreteVisitor1* visitor1 = new ConcreteVisitor1();
	ConcreteVisitor2* visitor2 = new ConcreteVisitor2();

	elementA.Accept(visitor1);
	elementA.Accept(visitor2);

	elementB.Accept(visitor1);
	elementB.Accept(visitor2);
	return 0;
}