#include "../includes/Basic.hpp"
#include "../includes/AllEntity.hpp"
#include "../includes/Fight.hpp"

int	isNumber(std::string line){
	if (line.empty() || line.size() > 1)
		return (0);
	for (size_t i =0; i < line.size() ; i++)
	{
		if (!isdigit(line[i]))
			return (0);
	}
	return (1);
}

Character	playerCreation(){
	std::string line;
	std::string name;
	RACE race;
	std::cout << "Choose your race :" << std::endl;
	std::cout << "0: HUMAN\n1: ELVE\n2: ORC\n3: ZOMBIE" << std::endl;
	for (;;)
	{
		std::getline(std::cin, line);
		if (line == "exit")
			exit(0);
		if (isNumber(line))
		{
			race = static_cast<RACE>(atoi(line.c_str()));
			if (race >= HUMAN && race <= ZOMBIE)
				break;
			else
				std::cout << "Please entry a good value : 0: HUMAN\n1: ELVE\n2: ORC\n3: ZOMBIE" << std::endl;
		}
	}

	for (;;)
	{
		std::cout << "Choose your name :" << std::endl;
		std::getline(std::cin, line);
		if (line.size() == 0)
			std::cout << "Please choose a name :" << std::endl;
		else
		{
			name = line;
			break;
		}

	}
	Character player(name, race, 1);
	return (player);
}

int main(){
	std::string line;
	// Character	*player = new Character();

	// for (; line != "exit" ;)
	// {
	// 	std::cout << ROSE << "Option: create, exit" << WHITE << std::endl;
	// 	std::getline(std::cin, line);
	// 	if (line == "exit")
	// 		exit(0);
	// 	if (line == "create")
	// 	{
	// 		*player = playerCreation();
	// 		break;
	// 	}
	// }

	// Character *dummy = new Character("Dummy", HUMAN, 1);
	// std::cout << "Your player: " << *player << ", hp: " << player->getHp() << std::endl;
	// std::cout << "Dummy player: " << *dummy << ", hp: " << dummy->getHp() << std::endl;
	// std::cout << ROSE << "Starting fight with " << dummy->getName() << WHITE << std::endl;
	// fightPhase(*player, *dummy);
	// player->levelUp();
	// std::cout << *player << std::endl;
	// delete player;
	// delete dummy;
	Character *p1 = importEntity("test.entity");
	if (p1)
		std::cout << *p1 << std::endl;

	Character *p2 = importEntity("test2.entity");
	if (p2)
		std::cout << *p2 << std::endl;
	autoFight(*p1, *p2);
	if (p1)
		delete p1;
	if (p2)
		delete p2;
	return (0);
}