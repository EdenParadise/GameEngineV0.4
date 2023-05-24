#include<iostream>
#include<ctime>
#include<iostream>
using namespace std;

class Object;
class Creature;
class Humanoid;
class Equipment;



class Object
{		//Object includes such parameters as "name" and "hp". This class
public:

	

	//Empty constructor
	Object()
	{
		
	}	

	//Default constructor with parameters
	Object(string name, int hp)
	{
		this->id = count+1000;
		this->name = name;
		this->hp = hp;
		count++;
	}

	//Getters
	string GetName()
	{
		return this->name;
	}
	int GetHp()
	{
		return this->hp;
	}
	int GetId()
	{
		return id;
	}
	static int GetCount()
	{
		return count;
	}
	
	//Setters
	void SetName(string name)
	{
		this->name = name;
	}
	void SetHp(int hp)
	{
		this->hp = hp;
	}


	//Methods:

protected:
	string name;
	int hp = 0;
	int id = 0;
	int static count;
	
};
int Object::count = 0;

class Creature:public Object
{
public:
	//Empty constructor
	Creature()
	{
		
	}

	//Default constructor with parameters
	Creature(string name, int hp, int dmg,int lvl)
	{
		id = GetCount()+2000;
		this->name = name;
		this->hp = hp;
		this->dmg = dmg;
		this->lvl = lvl;
		count++;
	}


	//Getters
	int GetDmg()
	{
		return this->dmg;
	}
	int GetLvl()
	{
		return this->lvl;
	}


	//Setters
	void SetDmg(int dmg)
	{
		this->dmg = dmg;
	}
	void SetLvl(int lvl)
	{
		this->lvl = lvl;
	}
	
	//Methods:

	//LevelUp >1 times
	void LvlUp(int times)
	{
		for (int i = 0; i < times; i++)
		{
			lvl++;
			this->hp += 4 + this->lvl;
			this->dmg += 1 + this->lvl;
		}
	}

	//LevelUp 1 time
	void LvlUp()
	{
		lvl++;
		this->hp += 4 + this->lvl;
		this->dmg += 1 + this->lvl;
	}

protected:
	
	int dmg = 0;
	int lvl = 1;
};

class Humanoid :public Creature
{
public:
	//Empty constructor
	Humanoid()
	{
		
	}

	//Default constructor with parameters
	Humanoid(string name, int hp, int dmg, int lvl, int str)
	{
		id = count+3000;
		this->name = name;
		this->hp = hp;
		this->dmg = dmg;
		this->lvl = lvl;
		this->strenght = str;

		FillArrayWithZero();

		this->Inventory[str * 3];

		*inventorySpace = strenght * 3;
	
		inventorySpaceLeft = *inventorySpace;
		count++;
	}

	//Getters
	int GetStrenght()
	{
		return strenght;
	}
	int GetInventorySpace()
	{
		return *inventorySpace;
	}
	int GetInventoryCell(int CellValue)
	{
		return Inventory[CellValue];
	}
	int GetEquipmentCell(int CellValue)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == CellValue) {
				return EquippedItems[i];
				break;
			}
		}
	}
	int GetInvSpaceLeft()
	{
		return inventorySpaceLeft;
	}

	//Setters
	void SetStrenght(int str)
	{
		this->strenght = str;
	}
	void SetInvSpaceLeft(int SpaceLeft)
	{
		this->inventorySpaceLeft = SpaceLeft;
	}
	void SetInventoryCell(int cellNum,int inputValue)
	{
		Inventory[cellNum] = inputValue;
	}
	void SetEquipmentCell(int CellValue,int inputValue)
	{
		EquippedItems[CellValue] = inputValue;
	}
	//Methods:

	//Fill Inventory and Equipment array with 0
	void FillArrayWithZero()
	{
		for (int i = 0; i < strenght*3; i++)
		{
			Inventory[i] = 0;
			if (i <= 4)
			{
				EquippedItems[i] = 0;
			}
		}
	}

	void PrintArrayInfo()
	{
		for (int i = 0; i < strenght * 3; i++)
		{
			cout << Inventory[i] << " ";
		}
	}

	void PrintEqpArrayInfo()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << EquippedItems[i] << " ";
		}
	}

	//Destructor
	~Humanoid()
	{
		delete[]Inventory;
		delete inventorySpace;
		delete[]EquippedItems;
	}
protected:
	int* inventorySpace = new int;
	int inventorySpaceLeft = 0;
	int strenght = 0;
	int* Inventory = new int[100];
	int* EquippedItems = new int[5];		//FirstHand, Second Hand, Head, Body, Legs 
	
};

class Equipment :public Object
{
public:
	//Empty constructor
	Equipment()
	{

	}

	//Default constructor with parameters
	Equipment(string name, int hp, int bonusHp, int bonusDmg, int weight, int space, int type)
	{
		id = count+4000;
		this->name = name;
		this->hp = hp;
		this->bonusHp = bonusHp;
		this->bonusDmg = bonusDmg;
		this->weight = weight;
		this->space = space;
		this->type = type;
		
		count++;
	}


	//Getters
	int GetBonusHp()
	{
		return bonusHp;
	}
	int GetBonusDmg()
	{
		return bonusDmg;
	}
	int GetWeight()
	{
		return weight;
	}
	int GetSpace()
	{
		return space;
	}
	bool GetEqpStatus()
	{
		return Equipped;
	}
	bool GetInvStatus()
	{
		return PickedUp;
	}
	int GetType()
	{
		return type;
	}

	//Setters
	void SetBonusHp(int bonusHp)
	{
		this->bonusHp = bonusHp;
	}
	void SetBonusDmg(int bonusDmg)
	{
		this->bonusDmg = bonusDmg;
	}
	void SetWeight(int weight)
	{
		this->weight = weight;
	}
	void SetSpace(int space)
	{
		this->weight = weight;
	}
	void SetEqpStatus(bool value)
	{
		this->Equipped = value;
	}
	void SetInvStatus(bool value)
	{
		this->PickedUp = value;
	}


protected:
	int bonusHp = 0;
	int bonusDmg = 0;
	int weight = 0;
	int space = 0;
	bool PickedUp = false;
	bool Equipped = false;
	int type = 0;
};



void TakeItem(Humanoid& Human, Equipment& Item)
{
	if (Item.GetWeight() <= Human.GetStrenght() && Human.GetInvSpaceLeft() >= Item.GetSpace() && Item.GetInvStatus() == false)
	{
		int count = 0;
		for (int i = 0; i < Human.GetStrenght() * 3; i++)
		{
			for (int j = i; j < Item.GetSpace() + i; j++)
			{
				if (Human.GetInventoryCell(j) == 0)
				{
					Human.SetInventoryCell(j, Item.GetId());
					count++;
				}
			}
			if (count == Item.GetSpace())
			{
				break;
			}
		}
		Item.SetInvStatus(true);
		Human.SetInvSpaceLeft(Human.GetInventorySpace() - Item.GetSpace());
	}
	else if (Item.GetWeight() > Human.GetStrenght())
	{

	}
	else if (Human.GetInvSpaceLeft() < Item.GetSpace())
	{

	}
	else if (Item.GetInvStatus() == false)
	{

	}
}

void DropItem(Humanoid& human, Equipment& Item)
{
	if (Item.GetInvStatus() == true)
	{
		int count = 0;
		for (int i = 0; i < human.GetStrenght() * 3; i++)
		{
			for (int j = i; j < Item.GetSpace() + i; j++)
			{
				if (human.GetInventoryCell(j) == Item.GetId())
				{
					human.SetInventoryCell(j, 0);
					count++;
				}
			}
			if (count == Item.GetSpace())
			{
				break;
			}
		}
		Item.SetInvStatus(false);
		human.SetInvSpaceLeft(human.GetInventorySpace() + Item.GetSpace());
	}
}

void EquipItem(Humanoid &human, Equipment &item)
{
	if ((item.GetInvStatus() == true && human.GetEquipmentCell(item.GetType())!=item.GetId())||(item.GetInvStatus()==false&&item.GetEqpStatus()==false&&item.GetWeight()<=human.GetStrenght()))
	{
		int count = 0;
		if (item.GetInvStatus() == true)
		{
			for (int i = 0; i < human.GetInventorySpace(); i++)
			{
				if (human.GetInventoryCell(i) == item.GetId())
				{
					human.SetInventoryCell(i, 0);
					count++;
				}
				if (count == item.GetSpace())
				{
					break;
				}
			}
		}
		human.SetEquipmentCell(item.GetType(), item.GetId());
		if (item.GetInvStatus() == true)
		{
			human.SetInvSpaceLeft(human.GetInventorySpace() + item.GetSpace());
		}

		human.SetDmg(human.GetDmg() + item.GetBonusDmg());
		human.SetHp(human.GetHp() + item.GetBonusHp());

		item.SetEqpStatus(true);
		item.SetInvStatus(false);
	}
}

void UnEquipItem(Humanoid& human, Equipment& item)
{
	if (item.GetEqpStatus() == true && human.GetEquipmentCell(item.GetType()) == item.GetId())
	{
		int count = 0;
		for (int i = 0; i < human.GetStrenght() * 3; i++)
		{
			for (int j = i; j < item.GetSpace() + i; j++)
			{
				if (human.GetInventoryCell(j) == 0)
				{
					human.SetInventoryCell(j, item.GetId());
					count++;
				}
			}
			if (count == item.GetSpace())
			{
				break;
			}
		}
		human.SetEquipmentCell(item.GetType(), 0);

		human.SetDmg(human.GetDmg() - item.GetBonusDmg());
		human.SetHp(human.GetHp() - item.GetBonusHp());

		item.SetInvStatus(true);
		human.SetInvSpaceLeft(human.GetInventorySpace() - item.GetSpace());
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	Humanoid Eden("Eden", 60, 13, 1, 4);
	Equipment Sword("Widowmaker", 10, 0, 8, 4, 6, 0);

	TakeItem(Eden, Sword);

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	cout << endl;

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	EquipItem(Eden, Sword);

	cout << endl;

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	UnEquipItem(Eden, Sword);

	cout << endl;

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	DropItem(Eden, Sword);

	cout << endl;

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	return 0;
}
