#include <iostream>

#include "petShop.h"

void Print(Food* food[2])
{
	cout << "Amount of food:" << endl;
	Fish* fish;
	if (fish = dynamic_cast<Fish*>(food[0]));
	else (fish = dynamic_cast<Fish*>(food[1]));
	Grain* gr;
	if (gr = dynamic_cast<Grain*>(food[0]));
	else (gr = dynamic_cast<Grain*>(food[1]));
	cout << "Grain: " << gr->GetAmount() << " Fish: " << fish->GetAmount() << endl << endl;
}

int main()
{
	cout << "***** Part 0 - (2 points) *****" << endl << endl;

	Grain g1 = Grain(6);
	g1.EatFood(2.4f);
	cout << "Left " << g1.GetAmount() << " of grain     Expected: 3.6" << endl;

	Fish f1 = Fish(12);
	f1.EatFood(5);
	cout << "Left " << f1.GetAmount() << " of grain     Expected: 7" << endl << endl;
	
	cout << "***** Part 1 - (2 points) *****" << endl << endl;
	
	Food* food[2] = { new Grain(12), new Fish(10) };
	Pet *h1 = new Hamster("Rusalka", 46, 3.6);
	Pet* h2 = new Hamster("Gruby", 108, 8);

	cout << *h1 << endl;
	Print(food);
	
	cout << "Feeding Gruby 2 times" << endl << endl;
	h2->Feed(food);
	h2->Feed(food);
	cout << *h2 << endl;
	Print(food);
			
	cout << "Feeding Rusalka" << endl << endl;
	h1->Feed(food);
	cout << *h1 << endl;
	Print(food);
	
	delete h1;
	delete h2;
	delete food[0];
	delete food[1];

	cout << "***** Part 2 - (1 points) *****" << endl << endl;

	food[0] = new Grain(10);
	food[1] = new Fish(10);
	
	Pet *p1 = new Pelican("Jago", 68, 0.02, 2);
	Pet* p2 = new Pelican("Bird", 74, 0.01, 2);
	Pet* c1 = new Cat("Kitku", 230, 4);
	Pet* c2 = new Cat("Nyan", 202, 3);
	Print(food);
	
	cout << "Feeding pelicans" << endl << endl;
	p1->Feed(food);
	p2->Feed(food);

	cout << *p1 << endl;
	cout << *p2 << endl;
	Print(food);

	cout << "Feeding Nyan 1 time and Kitku 2 times" << endl << endl;
	c2->Feed(food);
	c1->Feed(food);
	c1->Feed(food);

	cout << *c1 << endl;
	cout << *c2 << endl;
	Print(food);

	delete p1;
	delete p2;
	delete c1;
	delete c2;
	delete food[0];
	delete food[1];

	cout << "***** Part 3 - (1 points) *****" << endl << endl;
	
	h1 = new Hamster("Rusalka", 46, 3.6);
	h2 = new Hamster("Gruby", 108, 8);
	p1 = new Pelican("Jago", 68, 0.02, 2);
	p2 = new Pelican("Bird", 74, 0.01, 2);
	c1 = new Cat("Kitku", 230, 4);
	c2 = new Cat("Nyan", 202, 3);
	Food* food2[2] = { new Fish(14), new Grain(26) };

	Print(food2);
	
	PetShop s1 = PetShop(food2);
	s1.AddPet(p1);
	s1.AddPet(c1);
	s1.AddPet(h1);
	s1.AddPet(p2);
	s1.AddPet(h2);
	s1.AddPet(c2);
	
	cout << "Feeding all animals" << endl << endl;
	s1.FeedPets();
	cout << s1 << endl;

	cout << "Feeding all animals" << endl << endl;
	s1.FeedPets();
	cout << s1 << endl;

	cout << "***** Part 4 - (1 points) *****" << endl << endl;


	h1 = new Hamster("Rusalka", 46, 3.6);
	h2 = new Hamster("Gruby", 108, 8);
	p1 = new Pelican("Jago", 68, 0.02, 2);
	p2 = new Pelican("Bird", 74, 0.01, 2);
	c1 = new Cat("Kitku", 230, 4);
	c2 = new Cat("Nyan", 202, 3);
	
	Print(food2);
	
	PetShop s2 = PetShop(food2);
	s2.AddPet(p1);
	s2.AddPet(c1);
	s2.AddPet(h1);
	s2.AddPet(p2);
	s2.AddPet(h2);
	s2.AddPet(c2);

	cout << "Feeding all animals, but pelicans last" << endl << endl;
	s2.FeedPelicansLast();
	cout << s2 << endl;

	cout << "Feeding all animals, but pelicans last" << endl << endl;
	s2.FeedPelicansLast();
	cout << s2 << endl;

	cout << "***** Part 5 - (2 points) *****" << endl << endl;

	cout << "Let cats cure themselfs in part 3 shop" << endl << endl;
	s1.CureCats();
	cout << s1 << endl;

	cout << "Let cats cure themselfs in part 4 shop" << endl << endl;
	s2.CureCats();
	cout << s2 << endl;

	delete food2[0];
	delete food2[1];
}