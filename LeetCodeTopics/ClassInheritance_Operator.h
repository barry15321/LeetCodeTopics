#pragma once
#include <iostream>
#include <cstdlib>
#include <string> 
using namespace std;

class Vehicle
{
public:
	int speed;
	int age;
	static int produce_num;
};

class Car : public Vehicle
{
public:
	bool isBroken;
};

class Truck : public Vehicle
{
public:
	char truckChar;
};

int Vehicle::produce_num = 0;

void TestInheritnaceClass()
{
	Vehicle init_Vehicle;
	init_Vehicle.produce_num = 1; // static variable => variable for every class 

	Car bmw;
	Truck Sck;

	bmw.speed = 100;
	bmw.age = 20;
	bmw.isBroken = true;

	cout << "bmw.produce_num : " << bmw.produce_num << endl;
	bmw.produce_num++;

	cout << "Sck.produce_num : " << Sck.produce_num << endl; 
	Sck.produce_num++;
}

class car
{
	public:
		car();
		car(int speed, float temp);
		car operator +(const car& opa);

		int speed;
		float temp;
};

car::car()
{
	speed = 60;
	temp = 10;
}

car::car(int speed, float temp)
{
	this->speed = speed;
	this->temp = temp;
}

car car::operator +(const car& opa)
{
	car tmpcar;
	tmpcar.speed = speed + opa.speed;
	tmpcar.temp = temp + opa.temp;
	return tmpcar;
}

void plus_car()
{
	car a(50, 10);
	car b(30, 15);
	car c = a + b;

	cout << c.speed << " " << c.temp << endl;
}
