#include <iostream>
#include <vector>

using namespace std;

class Subject;

class Observer {
private:
	int observerID;
public:
	Observer(int id) {
		observerID = id;
	}
	int getID() {
		return observerID;
	}

	virtual void Update(Subject* subject) = 0;
	virtual int getState() = 0;
};

class Subject {
protected:
	int concreteState;
	vector<Observer*> observerList;
public:
	virtual int GetState() = 0;
	virtual void SetState(int s) = 0;

	void Attach(Observer* observer) {
		this->observerList.push_back(observer);
	}

	void Dettach(int index) {
		observerList.erase(observerList.begin() + index);
	}

	void Notify() {
		for each (Observer* ob in observerList)
		{
			cout <<	"Observer -->" << ob->getID() << " notifyed" << endl;
			ob->Update(this);
		}
	}
};

class ConcreteSubject: public Subject {
public:
	void SetState(int s) {
		concreteState = s;
		Notify();
	}
	int GetState() {
		return this->concreteState;
	}
};



class ConcreteObserver :public Observer {
private:
	int observerState;
public:
	ConcreteObserver(int id):Observer(id) {}

	void Update(Subject* subject) {
		observerState = subject->GetState();
	}

	int getState() {
		return observerState;
	}
};

int main() {
	ConcreteObserver* observer1 = new ConcreteObserver(1);
	ConcreteObserver* observer2 = new ConcreteObserver(2);
	ConcreteObserver* observer3 = new ConcreteObserver(3);

	ConcreteSubject* subject = new ConcreteSubject();

	subject->Attach(observer1);
	subject->Attach(observer2);
	subject->Attach(observer3);

	subject->SetState(5);
	cout << "subject state = " << subject->GetState()  << endl;
	cout << observer2->getID() << " state = " << observer2->getState() << endl;
	cout << observer1->getID() << " state = " << observer1->getState() << endl;
	cout << observer3->getID() << " state = " << observer3->getState() << endl;

	cout << "********************************" << endl;

	subject->SetState(10);
	cout << "subject state = " << subject->GetState() << endl;
	cout << observer1->getID() << " state = " << observer1->getState() << endl;
	cout << observer2->getID() << " state = " << observer2->getState() << endl;
	cout << observer3->getID() << " state = " << observer3->getState() << endl;

	return 0;
}

