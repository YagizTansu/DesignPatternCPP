#include <iostream>
#include <vector>

using namespace std;

class Graphic {
public:
	virtual void Add(Graphic* c) = 0;
	virtual void Remove(int index) = 0;
	virtual void Draw(int indent) = 0;
	virtual ~Graphic() {}
};

class Line : public Graphic {
public:
	void Add(Graphic* c)
	{
		cout << "Cannot add to a Line Object." << endl;
	}
	void Remove(int index)
	{
		cout << "Cannot remove from a Line Object." << endl;
	}
	void Draw(int indent) {
		for (int i = 1; i <= indent; i++) cout << "-";
		cout << "draw Line" << endl;
	}
};

class Rectangle : public Graphic {
public:
	void Add(Graphic* c)
	{
		cout << "Cannot add to a Rectangle Object." << endl;
	}
	void Remove(int index)
	{
		cout << "Cannot remove from a Rectangle Object." << endl;
	}
	void Draw(int indent) {
		for (int i = 1; i <= indent; i++) cout << "-";
		cout << "draw Rectangle" << endl;
	}
};

class Text : public Graphic {
public:
	void Add(Graphic* c)
	{
		cout << "Cannot add to a Text Object." << endl;
	}
	void Remove(int index)
	{
		cout << "Cannot remove from a Text Object." << endl;
	}
	void Draw(int indent) {
		for (int i = 1; i <= indent; i++) cout << "-";
		cout << "draw Text" << endl;
	}
};

class Picture :public Graphic {
private:
	vector<Graphic*> graphics;
public:
	void Add(Graphic* g)
	{
		graphics.push_back(g);
	}
	void Remove(int index)
	{
		Graphic* graphic = graphics[index];
		graphics.erase(graphics.begin() + index);
		delete graphic;
	}
	void Draw(int indent) {

		for (int i = 1; i <= indent; i++) cout << "-";
		cout << "Picture Object" << endl;

		// Display each child element on this node
		for (int i = 0; i < graphics.size(); i++) {
			graphics[i]->Draw(indent + 2);
		}

	}
};

int main() {
	Picture picture;
	Picture* picture2 = new Picture();
	picture.Add(new Line());//add Leaf(primitiveElement) to composite element
	picture.Add(new Rectangle());//add Leaf(primitiveElement) to composite element
	picture.Add(new Text());//add Leaf(primitiveElement) to composite element

	picture2->Add(new Line());//add Leaf(primitiveElement) to composite element
	picture2->Add(new Rectangle());//add Leaf(primitiveElement) to composite element
	picture2->Add(new Text());//add Leaf(primitiveElement) to composite element
	picture.Add(picture2); //add composite element to composite element

	picture.Draw(1);
	return 0;
}