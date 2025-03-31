#include "../includes/Fight.hpp"

void	fightBack(Character &player, Character &target){
	target.doDamage(player);
}

void	autoFight(Character &p1, Character &p2){
	for (;p1.isAlive() && p2.isAlive();)
	{
		std::cout << ROSE << p1 << WHITE << std::endl;
		std::cout << ROSE << p2 << WHITE << std::endl;
		fightBack(p1, p2);
		fightBack(p2, p1);
		std::cout << std::endl;
	}
	if (!p1.isAlive())
		std::cout << RED << p1.getName() << " is defeated." << WHITE << std::endl;
	else if (!p2.isAlive())
		std::cout << RED << p2.getName() << " is defeated." << WHITE << std::endl;
}


void	fightPhase(Character &player, Character &target){
	std::string line;
	for (;line != "leave" && player.isAlive() && target.isAlive();)
	{
		std::cout << ROSE << "Options: hit, leave" << WHITE << std::endl;
		getline(std::cin, line);
		if (line == "leave")
			return ;
		if (line == "hit")
			player.doDamage(target);
		fightBack(player, target);
		std::cout << player << std::endl;
		std::cout << target << std::endl;
	}
	if (!player.isAlive())
		std::cout << RED << player.getName() << " is defeated." << WHITE << std::endl;
	else if (!target.isAlive())
		std::cout << RED << target.getName() << " is defeated." << WHITE << std::endl;
}
