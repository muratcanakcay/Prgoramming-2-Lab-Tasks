#pragma once
#include "pet.h"

//---PART 3 - do not change here
class PetShop
{
	static const int MAX_PET_COUNT = 15;
	Food** foodAmount;
	int petCount;
	Pet* pets[MAX_PET_COUNT];
	void RemovePet(int index); //Part 5
	
public:
	PetShop(Food* food[2]);
	~PetShop();

	void AddPet(Pet* pet);
	
	void FeedPets();
	
	void FeedPelicansLast(); //Part 4
	
	void CureCats(); // Part 5

	friend ostream& operator<<(ostream& out, const PetShop& shop);
};

