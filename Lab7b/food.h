#pragma once
using namespace std;


class Food
{
public:
	static const int TYPE_COUNT = 2;
	virtual ~Food() = default;
	
	virtual Food* clone() const = 0;
};

//---PART 0 - implement here
//---Create Grain and Fish classes

class Grain : public Food
{
private:
	float amount;
public:
	Grain(float amount) : amount(amount) {};
	float GetAmount() {return amount;};
	void EatFood(float howMuch) { amount -= howMuch; };
	virtual Grain* clone() const override { return new Grain(*this); };
};

class Fish : public Food
{
private:
	int amount;
public:
	Fish(int amount) : amount(amount) {};
	int GetAmount() { return amount; } ;
	void EatFood(int howMuch) { amount -= howMuch; };
	virtual Fish* clone() const override { return new Fish(*this); };
};
