#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class sub_base_Door {
public:
	virtual void heyhey() = 0;
};

class sub_nd_door : sub_base_Door {
	void heyhey() {
		cout << "heyhey , the door is here." << endl;
	}
};

class Door {
public:
	virtual void open() const {
	    cout << "open horizontally" << endl;
	}
	virtual void close() const {
		cout << "close horizontally" << endl;
	}
};

class HorizontalDoor : public Door {
	void close() {
		cout << "haha close horizontally." << endl;
	}
};
class VerticalDoor : public Door {
	void open() const {
		cout << "open vertically" << endl;
	}
	void close() const {
		cout << "close vertically" << endl;
	}
};

class IAlarm {
public:
	virtual void alert() const = 0;
};

class Alarm : public IAlarm {
public:
	void alert() const {
		cout << "ring,ring,ring" << endl;
	}
};

class AlarmDoor : public Door {
protected:
	IAlarm * _alarm;
	//sub_nd_door* bdd;

public:
	AlarmDoor() {
		_alarm = new Alarm;
		//bdd = new sub_nd_door;
	}
	~AlarmDoor() {
		delete _alarm;
	}

	public:
		void alert() {
			_alarm->alert();
	}
};

class DoorController {
protected:
	vector<Door*> _doorVec;

public:
	void addDoor(Door & aDoor) {
		_doorVec.push_back(&aDoor);
	}
	void openDoor() {
		for_each(_doorVec.begin(), _doorVec.end(), mem_fun(&Door::open));
		//for_each(_doorVec.begin(), _doorVec.end(), mem_fun(&Door::close));
	}
};


void IF_Implement()
{
	DoorController dc;
	HorizontalDoor hd;
	VerticalDoor vd;
	AlarmDoor ad;
	dc.addDoor(hd);
	dc.addDoor(vd);
	dc.addDoor(ad);
	dc.openDoor();
	

	AlarmDoor add;
	Door& door = add;
	dynamic_cast<AlarmDoor&>(door).alert();

	sub_nd_door nd;
}