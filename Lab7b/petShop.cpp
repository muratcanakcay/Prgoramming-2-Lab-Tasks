#include "petShop.h"

//---PART 3 - implement here
//---constructor, destructor, Add Pet
//---Feed pets and operator<<
//

PetShop::PetShop(Food* food[2]) : petCount(0)
{
	for (int i = 0; i < MAX_PET_COUNT; i++)
		pets[i] = nullptr;
	
	foodAmount = new Food*[2];

	Grain* g = nullptr;
	if (!(g = dynamic_cast<Grain*>(food[0])))
		g = dynamic_cast<Grain*>(food[1]);

	Fish* f = nullptr;
	if (!(f = dynamic_cast<Fish*>(food[0])))
		f = dynamic_cast<Fish*>(food[1]);

	foodAmount[0] = g->clone();
	foodAmount[1] = f->clone();

}

PetShop::~PetShop()
{
	if (pets)
		for (int i = 0; i < petCount; i++)
			delete pets[i];
	delete foodAmount[0];
	delete foodAmount[1];
	delete foodAmount;
}

void PetShop::AddPet(Pet* pet)
{
	if (petCount < MAX_PET_COUNT)
	{
		Hamster* h = nullptr;
		Pelican* p = nullptr;
		Cat* c = nullptr;

		//if (h = dynamic_cast<Hamster*>(pet)) pets[petCount] = h;
		//if (p = dynamic_cast<Pelican*>(pet)) pets[petCount] = p;
		//if (c = dynamic_cast<Cat*>(pet)) pets[petCount] = c;

		pets[petCount] = pet;
		petCount++;
	}
}

ostream& operator<<(ostream& out, const PetShop& shop)
{
	out << "Pet shop with " << shop.petCount << " animals" << endl;
	out << "Amount of food:" << endl;
	out << "Grain: " << dynamic_cast<Grain*>(shop.foodAmount[0])->GetAmount();
	out << " Fish: " << dynamic_cast<Fish*>(shop.foodAmount[1])->GetAmount() << endl << endl;
	
	for (int i = 0; i < shop.petCount; i++)
		cout << *(shop.pets[i]) << endl;

	return out;
}

void PetShop::FeedPets()
{
	for (int i = 0; i < petCount; i++)
		pets[i]->Feed(foodAmount);
}

//---PART 4 - implement here
//---feeding pelicans after others

void PetShop::FeedPelicansLast()
{
	Pelican* p = nullptr;

	for (int i = 0; i < petCount; i++)
		if (!(p = dynamic_cast<Pelican*>(pets[i]))) pets[i]->Feed(foodAmount);

	for (int i = 0; i < petCount; i++)
		if (p = dynamic_cast<Pelican*>(pets[i])) pets[i]->Feed(foodAmount);
}

//---PART 5 - implement here
//---Curing cats by removing hamsters

void PetShop::RemovePet(int index)
{
	petCount--;
	delete pets[index];
	for (int i = index; i < petCount - 1; i++)
		pets[i] = pets[i + 1];
	pets[petCount] = nullptr;
}

void PetShop::CureCats()
{
	bool hamsterFound, sickCatFound;
	int c_idx, h_idx, idx;
	c_idx = h_idx = idx = 0;
	
	do
	{
		hamsterFound = sickCatFound = false;
		Hamster* h = nullptr;
		Cat* c = nullptr; 
		
		for (int i = idx; i < petCount; i++)
		{
			// find sick cat 
			if (!sickCatFound && (c = dynamic_cast<Cat*>(pets[i])) && pets[i]->IsSick())
			{
				c_idx = i;
				sickCatFound = true;				
			}

			// find hamster
			if (!hamsterFound && (h = dynamic_cast<Hamster*>(pets[i]))) 
			{
				h_idx = i;
				hamsterFound = true;
			}

			// if both exist cure cat and remove hamster
			// restart iteration from lower index
			if (sickCatFound && hamsterFound)
			{
				c->Cure();
				RemovePet(h_idx);
				idx = (c_idx < h_idx) ? c_idx : h_idx; 
				break;
			}
		}

	// if sick cat or a hamster does not exist, exit while loop
	} while (!sickCatFound || !hamsterFound);
}
