#ifndef BASIC_HPP
#define BASIC_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <fstream>

#define WHITE "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define ROSE "\033[1;35m"
#define CYAN "\033[1;36m"

class AEntity;
class Character;

int			checkFile(std::string fileName);
Character	*importEntity(std::string fileName);
void		autoFight(Character &p1, Character &p2);
#endif