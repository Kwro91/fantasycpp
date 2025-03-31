#include "../includes/Character.hpp"

Character::Character(): _name("default"), _energy(10) {}

Character::Character(std::string name, RACE race, int lvl) : _name(name), _race(race), _energy(10) {
	setRaceStats();
	setLvl(lvl);
}

Character::~Character() {}

Character::Character(const Character &c) : AEntity(c) {
	_name = c._name;
	_energy = c._energy;
	_race = c._race;
	setMaxHp(c.getMaxHp());
	setHp(c.getHp());
	setLvl(c.getLvl());
	setDmg(*c._dmg);
	setArmor(c.getArmor());
	setStr(c.getStr());
	setConst(c.getConst());
}

Character	&Character::operator=(const Character &c) {
	_name = c._name;
	_energy = c._energy;
	_race = c._race;
	setHp(c.getHp());
	setLvl(c.getLvl());
	setDmg(*c._dmg);
	setArmor(c.getArmor());
	setStr(c.getStr());
	setConst(c.getConst());
	return (*this);
}

// GETTER SETTER

const std::string	&Character::getName() const {
	return (_name);
}

const unsigned int	&Character::getEnergy() const {
	return (_energy);
}

const RACE	&Character::getRace() const {
	return (_race);
}

std::string	Character::getRaceString() const {
	std::string race;
	switch (_race){
		case HUMAN :
			race = "HUMAN";
			break;
		case ELVE :
			race = "ELVE";
			break;
		case ORC :
			race = "ORC";
			break;
		case ZOMBIE :
			race = "ZOMBIE";
			break;
	}
	return (race);
}

void	Character::setRace(RACE nb) {_race = nb;}

void	Character::setName(std::string name) {_name = name;}

void	Character::setEnergy(unsigned int energy) {_energy = energy;}

void	Character::setRaceStats(){
	int str;
	int cons;

	switch (_race){
		case HUMAN :
			str = 2;
			cons = 5;
			break;
		case ELVE :
			str = 2;
			cons = 6;
			break;
		case ORC :
			str = 3;
			cons = 7;
			break;
		case ZOMBIE :
			str = 2;
			cons = 4;
			break;
	}
	setMaxHp(cons * getLvl());
	setHp(cons * getLvl());
	setStr(str * getLvl());
	setConst(cons * getLvl());
}

// FUNCTION


void	Character::printDamage(AEntity &e, const Damage &a, int value){
	Character *c = dynamic_cast<Character *>(&e);
	if (c)
		std::cout << c->_name << " hit " << _name << " and do " << value << " " << a.getType() << "dmg." << std::endl;
	else
		std::cout << "Default Entity hit " << _name << " and do " << value << " " << a.getType() << "dmg." << std::endl;
}

void	Character::levelUp(){
	if (!isAlive())
		return ;
	setLvl(getLvl() + 1);
	setRaceStats();
	std::cout << GREEN << _name << " leveled up !" << WHITE << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Character &c){
	out << c.getName() << " race: " <<  c.getRaceString() << ", hp: " << c.getHp() << "/" << c.getMaxHp();
	return (out);
}
