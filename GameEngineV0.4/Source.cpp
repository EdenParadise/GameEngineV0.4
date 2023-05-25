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
int Object::count = 0;	//Static variable count = 0

class Creature:public Object
{		//Class Creature is made out of Object. It adds such parameters as damage, level and methods to use them
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
{				//Class Humanoid is really complicated class made of Creature and additional parameters such as strenght, inventory, equipment, etc.
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

		*inventorySpace = strenght * 3;		//Space of Humanoid object inventory is strenght multiplied by 3
	
		inventorySpaceLeft = *inventorySpace;
		count++;
	}

	//Getters

	//Get Humanoid object strenght
	int GetStrenght()
	{
		return strenght;
	}
	//Get total capacity of inventory
	int GetInventorySpace()
	{
		return *inventorySpace;
	}
	//Get value form Inventory array by array element number
	int GetInventoryCell(int CellValue)
	{
		return Inventory[CellValue];
	}	   //Get value form Inventory array by array element number
	//Get value form Equipment array by array element number
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
	//Get value of left inventory capacity
	int GetInvSpaceLeft()
	{
		return inventorySpaceLeft;
	}

	//Setters

	//Set Humanoid object strenght
	void SetStrenght(int str)
	{
		this->strenght = str;
	}
	//Set left inventory space
	void SetInvSpaceLeft(int SpaceLeft)
	{
		this->inventorySpaceLeft = SpaceLeft;
	}
	//Set parameter in inventory cell by number of cell and input parameter
	void SetInventoryCell(int cellNum,int inputValue)
	{
		Inventory[cellNum] = inputValue;
	}
	//Set parameter in Equipment cell by number of cell and input parameter
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

	//Print value of every inventory cell
	void PrintArrayInfo()
	{
		for (int i = 0; i < strenght * 3; i++)
		{
			cout << Inventory[i] << " ";
		}
	}

	//Print value of every Equipment array cell
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
	int* Inventory = new int[100];			//Dynamic array for inventory
	int* EquippedItems = new int[5];		//Dynamic array for equipment          (FirstHand, Second Hand, Head, Body, Legs) 
	
};

class Equipment :public Object
{		//Class that creates from object and includes new parameters such bonusHp, bonusDmg, Weight, Space and Type and methods to operate them
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

	// Get Equipment object bonushp
	int GetBonusHp()
	{
		return bonusHp;
	}
	// Get Equipment object bonusDmg
	int GetBonusDmg()
	{
		return bonusDmg;
	}
	// Get Equipment object Weight 
	int GetWeight()
	{
		return weight;
	}
	// Get Equipment object Space that object requires
	int GetSpace()
	{
		return space;
	}
	// Get Equipment object Status (true) if equipped and (false) if not
	bool GetEqpStatus()
	{
		return Equipped;
	}
	// Get Equipment object Status (true) if object is in inventory of Humanoid and (false) if not
	bool GetInvStatus()
	{
		return PickedUp;
	}
	// Get type of Equipment object (watch Humanoid Equipment array comment)
	int GetType()
	{
		return type;
	}

	//Setters

	// Set Equipment object bonushp
	void SetBonusHp(int bonusHp)
	{
		this->bonusHp = bonusHp;
	}
	// Set Equipment object bonusDmg
	void SetBonusDmg(int bonusDmg)
	{
		this->bonusDmg = bonusDmg;
	}
	// Set Equipment object weight
	void SetWeight(int weight)
	{
		this->weight = weight;
	}
	// Set Equipment object space that object requires
	void SetSpace(int space)
	{
		this->weight = weight;
	}
	// Get Equipment object Status (true) if equipped and (false) if not
	void SetEqpStatus(bool value)
	{
		this->Equipped = value;
	}
	// Get Equipment object Status (true) if object is in inventory of Humanoid and (false) if not
	void SetInvStatus(bool value)
	{
		this->PickedUp = value;
	}
	//Set type of Equipment object  (FirstHand(0), Second Hand(1), Head(2), Body(3), Legs(4)) 
	void SetType(int type)
	{
		if (type >= 0 && type <= 5)
		{
			this->type = type;
		}
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


//Function to take Equipment object to inventory of Humanoid object
void TakeItem(Humanoid& Human, Equipment& Item)
{			//Function checks if item weight <= Humanoid strenght, and if Humanoid inventory space left is <=item space. Aslo item isnt equipped or hasnt been taken to inventory yet
	if (Item.GetWeight() <= Human.GetStrenght() && Human.GetInvSpaceLeft() >= Item.GetSpace() && Item.GetInvStatus() == false&&Item.GetEqpStatus()==false)
	{
		int count = 0;		//Temporary variable count to break for loop when cells are filled with taken object id
		for (int i = 0; i < Human.GetStrenght() * 3; i++)	//Upper for loop is created to check on all the inventory of Humanoid
		{
			for (int j = i; j < Item.GetSpace() + i; j++)		//This incapsulated loop is created to fill as many inventory cells as Item space
			{
				if (Human.GetInventoryCell(j) == 0)		//Fill cell only if its empty
				{
					Human.SetInventoryCell(j, Item.GetId());	//Here we use Humanoid method SetInventoryCell (check on function comment in class Humanoid)
					count++;		//count increments if cell is filled
				}
			}
			if (count == Item.GetSpace())	//when item fills all the needed cells in inventory we break the loop
			{
				break;
			}
		}
		Item.SetInvStatus(true);	//Item inventory status become true
		Human.SetInvSpaceLeft(Human.GetInvSpaceLeft() - Item.GetSpace());		//Humanoid inventory space left = Humanoid inventory space left - item space
	}

	//Additionals to use if something went wrong
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

//Function to drop item that is in inventory
void DropItem(Humanoid& human, Equipment& Item)
{	
	bool temp = false;		//Create temporary bool variable
	for (int i = 0; i < human.GetInventorySpace(); i++)		//In this loop we check if item is in inventory of Humanoid
	{
		if (human.GetInventoryCell(i) == Item.GetId())		//We check if any of inventory cells contains item id
		{
			temp = true;	//If so, then temp = true
			break;			//and we break the loop
		}
	}
	//Function checks if item is in inventory of Humanoid
	if (Item.GetInvStatus() == true&&temp==true)
	{
		int count = 0;		//Temporary variable count to break for loop when cells which have item id are filled with 0
		for (int i = 0; i < human.GetStrenght() * 3; i++)		//Upper for loop is created to check on all the inventory of Humanoid
		{
			for (int j = i; j < Item.GetSpace() + i; j++)			//This incapsulated loop is created to clear as many inventory cells as Item space 
			{
				if (human.GetInventoryCell(j) == Item.GetId())		//Clear cell only if it contains item id
				{
					human.SetInventoryCell(j, 0);		//Here we use Humanoid method SetInventoryCell (check on function comment in class Humanoid)
					count++;		//count increments if cell is cleared
				}
			}
			if (count == Item.GetSpace())		//when all the item ids in inventory array is cleared we break the loop
			{
				break;
			}
		}
		Item.SetInvStatus(false);		//Item inventory status become false
		human.SetInvSpaceLeft(human.GetInvSpaceLeft() + Item.GetSpace());		//Humanoid inventory space left = Humanoid inventory space left + item space
	}

	temp = false;
	for (int i = 0; i < 5;i++)
	{
		if (Item.GetId() == human.GetEquipmentCell(i))
		{
			temp = true;
		}
	}

	if (Item.GetEqpStatus() == true && temp == true)
	{
		human.SetEquipmentCell(Item.GetType(), 0);		//Use Humanoid method SetEquipmentCell (check class Humanoid) by item type and 0, to clear Humanoid equipment cell
		human.SetDmg(human.GetDmg() - Item.GetBonusDmg());		//Humanoid dmg decreases by item bonusDmg
		human.SetHp(human.GetHp() - Item.GetBonusHp());			//Humanoid hp decreases by item bonusHp

		Item.SetInvStatus(false);	//Item inventory status changes to false
		Item.SetEqpStatus(false);	//Item equipment status changes to false
	}
}

//Function to equip item to humanoid
void EquipItem(Humanoid &human, Equipment &item)
{		//Function checks if item already is in inventory and not equipped on humanoid or item is not in inventory and not equipped either. Also checks if item weight<=humanoid strenght if item isnt on inventory
	if ((item.GetInvStatus() == true && human.GetEquipmentCell(item.GetType())!=item.GetId())||(item.GetInvStatus()==false&&item.GetEqpStatus()==false&&item.GetWeight()<=human.GetStrenght()))
	{
		int count = 0;		//Temporary variable count to break for loop when cells which have item id are filled with 0
		if (item.GetInvStatus() == true)		//Check if item is in inventory
		{
			for (int i = 0; i < human.GetInventorySpace(); i++)			//For loop is created to check on all the inventory of Humanoid
			{
				if (human.GetInventoryCell(i) == item.GetId())			//If Humanoid inventory cell is equal to item id 
				{
					human.SetInventoryCell(i, 0);		//We use Humaqnoid method (check on this method in class humanoid) to clear this cell
					count++;		//count increments if cell is cleared
				}
				if (count == item.GetSpace())	//when all the item ids in inventory array is cleared we break the loop
				{
					break;
				}
			}
		}
		human.SetEquipmentCell(item.GetType(), item.GetId());		//Use Humanoid method SetEquipmentCell (check class Humanoid) by item type and item id
		if (item.GetInvStatus() == true)		//If item were in inventory
		{
			human.SetInvSpaceLeft(human.GetInvSpaceLeft() + item.GetSpace());		//We restore inventory space
		}

		human.SetDmg(human.GetDmg() + item.GetBonusDmg());		//Humanoid gets bonus dmg
		human.SetHp(human.GetHp() + item.GetBonusHp());		//Humanoid gets bonus hp

		item.SetEqpStatus(true);		//item equipment status = true
		item.SetInvStatus(false);		//item inventory status = false
	}
}

//Function to unequip item
void UnEquipItem(Humanoid& human, Equipment& item)
{		//Function checksw if item is equipped and if its equipped on this Humanoid
	if (item.GetEqpStatus() == true && human.GetEquipmentCell(item.GetType()) == item.GetId())
	{
		int count = 0;		//Temporary variable count to break for loop when empty cells fills item id item.Space times
		if (item.GetSpace() <= human.GetInvSpaceLeft())		//If there is space in inventory left for item
		{
			for (int i = 0; i < human.GetStrenght() * 3; i++)		//Upper for loop is created to check on all the inventory of Humanoid
			{
				for (int j = i; j < item.GetSpace() + i; j++)		//This incapsulated loop is created to fill as many inventory cells as Item space
				{
					if (human.GetInventoryCell(j) == 0)		//Fill cell only if its empty
					{
						human.SetInventoryCell(j, item.GetId());	//Here we use Humanoid method SetInventoryCell (check on function comment in class Humanoid)
						count++;		//count increments if cell is filled
					}
				}
				if (count == item.GetSpace())		//When item fills all the needed cells in inventory we break the loop
				{
					break;
				}
			}
			human.SetEquipmentCell(item.GetType(), 0);		//Use Humanoid method SetEquipmentCell (check class Humanoid) by item type and 0, to clear Humanoid equipment cell

			human.SetDmg(human.GetDmg() - item.GetBonusDmg());		//Humanoid dmg decreases by item bonusDmg
			human.SetHp(human.GetHp() - item.GetBonusHp());			//Humanoid hp decreases by item bonusHp

			item.SetInvStatus(true);	//Item inventory status changes to true
			human.SetInvSpaceLeft(human.GetInvSpaceLeft() - item.GetSpace());		//Item fills invenory by item.Space points
		}
		else       //We drop item
		{
			human.SetEquipmentCell(item.GetType(), 0);		//Use Humanoid method SetEquipmentCell (check class Humanoid) by item type and 0, to clear Humanoid equipment cell
			human.SetDmg(human.GetDmg() - item.GetBonusDmg());		//Humanoid dmg decreases by item bonusDmg
			human.SetHp(human.GetHp() - item.GetBonusHp());			//Humanoid hp decreases by item bonusHp

			item.SetInvStatus(false);	//Item inventory status changes to false
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	Humanoid Eden("Eden", 60, 13, 1, 4);
	Equipment Sword("Widowmaker", 10, 0, 8, 4, 6, 0);

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	EquipItem(Eden, Sword);
	cout << endl << endl;

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	DropItem(Eden, Sword);
	cout << endl << endl;

	Eden.PrintArrayInfo();
	cout << endl;
	Eden.PrintEqpArrayInfo();

	return 0;
}
