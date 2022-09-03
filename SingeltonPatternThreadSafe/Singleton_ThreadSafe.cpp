#include <iostream>
#include <vector>
#include <mutex>

using namespace std;

class Singleton {
private:
	static Singleton* singleInstance; //// The private reference to the one and only instance.
	static mutex lock;
	Singleton() {}// No client can instantiate a Singleton object!
public:

	// Creates the instance if it does not yet exist.
	// Returns a reference to the single instance.
	static Singleton* getInstance() {

		if (singleInstance == NULL) {
			lock.lock();
			if (singleInstance == NULL)
				singleInstance = new Singleton();

			lock.unlock();
		}
		return singleInstance;
	}
};

Singleton* Singleton::singleInstance = NULL;
mutex Singleton::lock;


int main() {

	Singleton* instance1;
	Singleton* instance2;
	Singleton* instance3;

	instance1 = Singleton::getInstance();
	instance2 = Singleton::getInstance();
	instance3 = Singleton::getInstance();

	if (instance1 == instance2 && instance1 == instance3 && instance2 == instance3)
		cout << "Singleton Pattern Worked" << endl;

	return 0;
}