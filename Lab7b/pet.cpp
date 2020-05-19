#include "pet.h"

//---PART 1 - implement here
//---abstract pet class and hamster

Pet::Pet(string _name, int _weight) : name(_name), weight(_weight) {}

ostream& operator<<(ostream& out, const Pet& pet)
{
	out << pet.name << endl;
	pet.Print(out);
	return out;
}

Hamster::Hamster(string _name, int _weight, float _hungerGrain) : Pet(_name, _weight), hungerGrain(_hungerGrain) {};

void Hamster::Feed(Food* food[2])
{
	Grain* f = nullptr;
	if (!(f = dynamic_cast<Grain*>(food[0])))
		f = dynamic_cast<Grain*>(food[1]);

	if (!IsSick() && f->GetAmount() >= hungerGrain)
		f->EatFood(hungerGrain);
	else isSick = true;
}

void Hamster::Print(ostream& out) const
{
	out << "Hamster" << endl;
	out << "Eats " << hungerGrain << " of grain" << endl;
	out << "Weight: " << weight << endl;
	out << name << " is " << ((isSick == 1) ? "sick" : "healthy") << endl;
}


//---PART 2 - implement here
//---pelican and cat class


Pelican::Pelican(string _name, int _weight, float _hungerGrain, int _hungerFish) : Pet(_name, _weight), hungerFish(_hungerFish), hungerGrain(_hungerGrain) {};

void Pelican::Feed(Food* food[2])
{
	Grain* g = nullptr;
	if (!(g = dynamic_cast<Grain*>(food[0])))
		g = dynamic_cast<Grain*>(food[1]);

	Fish* f = nullptr;
	if (!(f = dynamic_cast<Fish*>(food[0])))
		f = dynamic_cast<Fish*>(food[1]);

	if (!IsSick() && g->GetAmount() >= (hungerGrain * weight) && f->GetAmount() >= hungerFish)
	{
		g->EatFood(hungerGrain * weight);
		f->EatFood(hungerFish);
	}
	else isSick = true;
}

void Pelican::Print(ostream& out) const
{
	out << "Pelican" << endl;
	out << "Eats " << hungerGrain << " of his weight of grain and " << hungerFish << " fish" << endl;
	out << "Weight: " << weight << endl;
	out << name << " is " << ((isSick == 1) ? "sick" : "healthy") << endl;
}

Cat::Cat(string _name, int _weight, int _hunger) : Pet(_name, _weight), hunger(_hunger) {};

void Cat::Feed(Food* food[2])
{
	Fish* f = nullptr;
	if (!(f = dynamic_cast<Fish*>(food[0])))
		f = dynamic_cast<Fish*>(food[1]);

	if (!IsSick() && f->GetAmount() >= hunger)
	{
		
		f->EatFood(hunger);
	}
	else isSick = true;
}

void Cat::Print(ostream& out) const
{
	out << "Cat eating " << hunger << " fish" << endl;
	out << "Weight: " << weight << endl;
	out << name << " is " << ((isSick == 1) ? "sick" : "healthy") << endl;
}