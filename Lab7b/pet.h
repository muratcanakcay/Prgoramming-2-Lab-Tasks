#pragma once
#include <iostream>
#include <string>
#include "food.h"


//---PART 1 - do not change here
class Pet
{	
protected:
	int weight;
	bool isSick = false;
	string name;
	
	
public:
	
	Pet(string _name, int _weight);
	virtual ~Pet() {}

	bool IsSick() { return isSick; } const
	void Cure() { isSick = false; }
	virtual void Feed(Food* food[2]) = 0;
	virtual void Print(ostream& out) const = 0;
	
	friend ostream& operator<<(ostream& out, const Pet& pet);
};

class Hamster :
	public Pet
{
	float hungerGrain;

public:
	Hamster(string _name, int _weight, float _hungerGrain);
	void Feed(Food* food[2]) override;

	void Print(ostream& out) const override;
};


//---PART 2 - do not change here

class Pelican :
	public Pet
{
	float hungerGrain;
	float hungerFish;

public:
	Pelican(string _name, int _weight, float _hungerGrain, int _hungerFish);
	
	void Feed(Food* food[2]) override;
	void Print(ostream& out) const override;
};

class Cat :
	public Pet
{
	int hunger;

public:
	Cat(string _name, int _weight, int _hunger);

	void Feed(Food* food[2]) override;
	void Print(ostream& out) const override;
};
