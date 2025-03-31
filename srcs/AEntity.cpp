#include "../includes/AEntity.hpp"


const char	*AEntity::NoDamageException::what() const throw() {
	return ("Exception: no damage in class");
}

////////////////////////////////////

AEntity::AEntity() : _name("default"), _maxHp(1), _hp(1), _lvl(1), _str(1), _const(1), _armor(0) {
	_dmg = new Damage(BLUDGE, 1);
}

AEntity::~AEntity() {
	if (_dmg != NULL)
		delete _dmg;
}

AEntity::AEntity(const AEntity &a) {
	_maxHp = a._maxHp;
	_hp = a._hp;
	_dmg = a._dmg;
	_lvl = a._lvl;
	_str = a._str;
	_const = a._const;
	_armor = a._armor;
}

AEntity	&AEntity::operator=(const AEntity &a) {
	_maxHp = a._maxHp;
	_hp = a._hp;
	_dmg = a._dmg;
	_lvl = a._lvl;
	_str = a._str;
	_const = a._const;
	_armor = a._armor;
	return (*this);
}

// GETTER SETTER

const Damage	&AEntity::getDmg() const{
	if (!_dmg)
		throw NoDamageException();
	return (*_dmg);
}

const int	&AEntity::getHp() const{return (_hp);}

const int	&AEntity::getMaxHp() const{return (_maxHp);}

const int	&AEntity::getLvl() const{return (_lvl);}

const int	&AEntity::getStr() const{return (_str);}

const int	&AEntity::getConst() const{return (_const);}

const int	&AEntity::getArmor() const{return (_armor);}

void	AEntity::setName(std::string name){_name = name;}

void	AEntity::setHp(int nb){_hp = nb;}

void	AEntity::setMaxHp(int nb){_maxHp = nb;}

void	AEntity::setLvl(int nb){_lvl = nb;}

void	AEntity::setStr(int nb){_str = nb;}

void	AEntity::setConst(int nb){_const = nb;}

void	AEntity::setArmor(int nb){_armor = nb;}

void	AEntity::setDmg(Damage &d){
	if (!_dmg)
		_dmg = new Damage(d);
	else
		*_dmg = d;
}


// FUNCTION

int	AEntity::isAlive(){
	if (_hp > 0)
		return (1);
	return (0);
}

void	AEntity::takeDamage(AEntity &e, const Damage &a){
	if (!isAlive())
		return ;
	int amount = e.getStr() + a.getAmount() - _armor;
	if (amount < 0)
		amount = 0;
	_hp -= amount;
	printDamage(e, a, amount);
}

void	AEntity::doDamage(AEntity &a){
	if (!isAlive())
		return ;
	if (_dmg)
		a.takeDamage(*this, getDmg());
}

void	AEntity::printDamage(AEntity &e, const Damage &a, int value){
	(void)e;
	(void)a;
	(void)value;
}

void	AEntity::levelUp(){
	if (!isAlive())
		return ;
	_lvl += 1;
	std::cout << GREEN << _name << " leveled up !" << WHITE << std::endl;
}
