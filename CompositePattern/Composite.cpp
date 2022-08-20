#include <iostream>
#include <vector>
using namespace std;
//Transperancy code 
class Component {
public:
    virtual ~Component() {}
	virtual void Add(Component* c) = 0;
	virtual void Remove(int index) = 0;
	virtual void Delete(int index) = 0;
    virtual void Operation() = 0;
};

class PrimitiveElement:public Component {// LEAF
public:
    PrimitiveElement(){}
    ~PrimitiveElement() {}
    void Add(Component* c)
    {
        cout << "Cannot add to a PrimitiveElement." << endl;
    }
    void Remove(int index)
    {
        cout << "Cannot remove from a PrimitiveElement." << endl;
    }
    void Delete(int index)
    {
        cout << "Cannot delete from a PrimitiveElement." << endl;
    }

    void Operation()
    {
        cout << "primitive class: Do something in this method." << endl;
    }
};

class CompositeElement :public  Component{ //COMPOSITE
private:
    vector<Component*> components;
public:
    ~CompositeElement()
    {
        for (unsigned int i = 0; i < components.size(); i++)
        {
            delete components[i];
        }
    }
    void Add(Component* component)
    {
        components.push_back(component);
    }
    void Remove(int index)
    {
        Component* component = components[index];
        components.erase(components.begin() + index);
        delete component;
    }
    void Delete(int index)
    {
        delete components[index];
    }

    void Operation()
    {
        cout << "-- Composite class: Do something in this method." << endl;
        for (int i = 0; i < components.size(); i++)
        {
            components[i]->Operation();
        }
    }
};

int main() {
    CompositeElement compositeElement;
    CompositeElement *compositeElement2 = new CompositeElement();
    compositeElement.Add(new PrimitiveElement());//add Leaf(primitiveElement) to composite element
    compositeElement.Add(new PrimitiveElement());//add Leaf(primitiveElement) to composite element
    compositeElement.Add(new PrimitiveElement());//add Leaf(primitiveElement) to composite element

    compositeElement2->Add(new PrimitiveElement());//add Leaf(primitiveElement) to composite element
    compositeElement2->Add(new PrimitiveElement());//add Leaf(primitiveElement) to composite element
    compositeElement2->Add(new PrimitiveElement());//add Leaf(primitiveElement) to composite element
    compositeElement.Add(compositeElement2); //add composite element to composite element
    
    compositeElement.Operation();
    
    return 0;
}

