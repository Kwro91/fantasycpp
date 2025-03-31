#ifndef AENTITY_HPP
#define AENTITY_HPP

#include "Basic.hpp"
#include "AllDamages.hpp"

class Damage;

class AEntity {
	private :
		std::string	_name;
		int			_maxHp;
		int 		_hp;
		int			_lvl;
		int			_str;
		int			_const;
		int			_armor;
		
	protected :
		Damage	*_dmg;

	public :
		AEntity();
		virtual ~AEntity() = 0;
		AEntity(const AEntity &a);
		AEntity	&operator=(const AEntity &a);
		
		const Damage	&getDmg() const;
		const int		&getHp() const;
		const int		&getMaxHp() const;
		const int		&getLvl() const;
		const int		&getStr() const;
		const int		&getConst() const;
		const int		&getArmor() const;
		
		void			setName(std::string name);
		void			setHp(int nb);
		void			setMaxHp(int nb);
		void			setLvl(int nb);
		void			setStr(int nb);
		void			setConst(int nb);
		void			setArmor(int nb);
		void			setDmg(Damage &d);
		
		void			takeDamage(AEntity &e, const Damage &a);
		void			doDamage(AEntity &a);
		int				isAlive();
		virtual void	printDamage(AEntity &e, const Damage &a, int value);
		virtual void	levelUp();

		class NoDamageException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

#endif