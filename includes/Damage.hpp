#ifndef ADMAGE_HPP
#define DAMAGE_HPP

#include "Basic.hpp"

enum DMG {
	NONE,
	SLASH,
	PIERCE,
	BLUDGE
};

class Damage {
	private :
		DMG	_type;
		int _amount;

	protected :

	public :
		Damage();
		Damage(DMG type, int amount);
		~Damage();
		Damage(const Damage &a);
		Damage	&operator=(const Damage &a);

		const int			&getAmount() const;
		const DMG			&getType() const;

		void				setType(DMG type);
		void				setAmount(int amount);
};

#endif