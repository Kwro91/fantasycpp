#include "../includes/Damage.hpp"

Damage::Damage() : _type(NONE), _amount(0) {}

Damage::Damage(DMG type, int amount) : _type(type), _amount(amount) {}

Damage::~Damage() {}

Damage::Damage(const Damage &a) {
	_type = a._type;
	_amount = a._amount;
}

Damage	&Damage::operator=(const Damage &a) {
	_type = a._type;
	_amount = a._amount;
	return (*this);
}

// GETTER SETTER

const int	&Damage::getAmount() const {return (_amount);}

const DMG	&Damage::getType() const {return (_type);}

void		Damage::setType(DMG type){_type = type;}

void		Damage::setAmount(int amount){_amount = amount;}