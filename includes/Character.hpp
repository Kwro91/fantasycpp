#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AEntity.hpp"
#include "AllDamages.hpp"

enum RACE {
	HUMAN,
	ELVE,
	ORC,
	ZOMBIE
};

class Character : public AEntity {
	private :
		std::string		_name;
		RACE			_race;
		unsigned int	_energy;

	public :
		Character();
		Character(std::string name, RACE race, int lvl);
		~Character();
		Character(const Character &c);
		Character &operator=(const Character &c);

		const std::string	&getName() const;
		const unsigned int	&getEnergy() const;
		const RACE			&getRace() const;
		std::string			getRaceString() const;
		
		void				setRace(RACE nb);
		void				setName(std::string name);
		void				setEnergy(unsigned int energy);
		void				setRaceStats();
		void				levelUp();
		void				printDamage(AEntity &e, const Damage &a, int value);

};

std::ostream &operator<<(std::ostream &out, const Character &c);

#endif