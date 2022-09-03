#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Rooms;

class Sensors {
private:
	string name;
public:
	Sensors(string name) {
		this->name = name;
	}
	virtual void Update(Rooms* room) = 0;
	virtual double GetState() = 0;
	string GetName() {
		return name;
	}
};
class Thermometer;

class Rooms {
protected:
	double temperature;
	double moisture;
	map<Sensors*, string> sensorList;
public:
	virtual void SetTemp(double temp) = 0;
	virtual  double GetTemp() = 0;

	virtual void SetMois(double mois) = 0;
	virtual  double GetMois() = 0;
	
	void Attach(Sensors* sensor,string type) {

		if (type == "T") {
			sensorList.insert(pair<Sensors*,string>(sensor, "T"));
		}
		else if(type == "M") {
			sensorList.insert(pair<Sensors*, string>(sensor, "M"));
		}
		else {
			cout << "wront type to attach" << endl;
		}
	}

	void Dettach(int index) {}

	void Notify(string type) {
		for each (pair<Sensors*, string> sensor in sensorList)
		{
			if (sensor.second == type)
			{
				cout << "Sensor " << sensor.first->GetName() << " --> notifyed" << endl;
				sensor.first->Update(this);
			}
		}
	}
};

class Room: public Rooms {
public:
	void SetTemp(double temp) {
		temperature = temp;
		Notify("T");
	}
	double GetTemp() {
		return this->temperature;
	}

	void SetMois(double mois) {
		moisture = mois;
		Notify("M");
	}
	double GetMois() {
		return this->moisture;
	}
};


class Thermometer:public Sensors{
private:
	double state;
public:
	Thermometer(string name):Sensors(name) {}

	void Update(Rooms* room) {
		state = room->GetTemp();
	}
	double GetState() {
		return this->state;
	}
};

class Moisturemeter:public Sensors {
private:
	double moistureState;
public:
	Moisturemeter(string name) :Sensors(name) {}

	void Update(Rooms* room) {
		moistureState = room->GetTemp();
	}
	double GetState() {
		return this->moistureState;
	}
};

int main() {
	Thermometer* temp1 = new Thermometer("temp1");
	Thermometer* temp2 = new Thermometer("temp2");
	Moisturemeter* mois1 = new Moisturemeter("mois1");
	Moisturemeter* mois2 = new Moisturemeter("mois2");

	Room* room = new Room();
	room->Attach(temp1,"T");
	room->Attach(temp2,"T");
	room->Attach(mois1,"M");
	room->Attach(mois2,"M");

	room->SetTemp(15.5);
	cout << "***********" << endl;
	room->SetMois(95.0);

	cout << "Room temperature : " << room->GetTemp() << " // Room Moisture : " << room->GetMois() << endl;
	
	return 0;
}