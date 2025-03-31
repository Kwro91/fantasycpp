#include "../includes/Basic.hpp"
#include "../includes/AllEntity.hpp"
#include "../includes/AllDamages.hpp"

int	checkFile(std::string fileName){
	std::string end = ".entity";
	int size = fileName.size();
	if (size <= 7)
		return (0);
	std::string cmp = fileName.substr(size - 7);
	// std::cout << cmp << std::endl; // check
	if (cmp == end)
		return (1);
	return (0);
}

Character	*importEntity(std::string fileName){
	if (!checkFile(fileName))
		return (NULL);
	int			race;
	std::string name;
	int			maxHp;
	int 		hp;
	int			lvl;
	int			str;
	int			cons;
	int			armor;

	std::ifstream inFile(fileName.c_str(), std::ios::in | std::ios::out | std::ios::app);
	if (inFile.is_open())
	{

		std::string line;
		std::getline(inFile, line);
		if (line == "Character")
		{
			std::getline(inFile, line);
			race = atoi(line.c_str());
			if (race < HUMAN || race > ZOMBIE)
			{
				std::cout << "non valide" << std::endl;
				inFile.close();
				return (NULL);
			}
			std::getline(inFile, line);
			name = line;
			
			std::getline(inFile, line);
			maxHp = atoi(line.c_str());
			
			std::getline(inFile, line);
			hp = atoi(line.c_str());
			
			std::getline(inFile, line);
			lvl = atoi(line.c_str());
			
			std::getline(inFile, line);
			str = atoi(line.c_str());
			
			std::getline(inFile, line);
			cons = atoi(line.c_str());
			
			std::getline(inFile, line);
			armor = atoi(line.c_str());
			
			Character *c = new Character();
			c->setRace(static_cast<RACE>(race));
			c->setName(name);
			c->setMaxHp(maxHp);
			c->setHp(hp);
			c->setLvl(lvl);
			c->setStr(str);
			c->setConst(cons);
			c->setArmor(armor);
			Damage *d = new Damage(SLASH, 15);
			c->setDmg(*d);
			return (c);
		}
		inFile.close();
	}
	return NULL;
}
