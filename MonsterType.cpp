#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Monster {
public:
	enum MonsterType {
		Dragon,
		Goblin,
		Orge,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};
private:
	MonsterType m_type;
	std::string m_name;
	int m_health;
public:
	Monster(MonsterType type, const std::string name, int health) :
		m_type(type), m_name(name), m_health(health)
	{
	}
	std::string getTypeString() {
		std::string typeOfMonster;
		switch (m_type)
		{
		case Monster::Dragon:
			typeOfMonster = "Dragon";
			return typeOfMonster;
		case Monster::Goblin:
			typeOfMonster = "Goblin";
			return typeOfMonster;
		case Monster::Orge:
			typeOfMonster = "Orge";
			return typeOfMonster;
		case Monster::Orc:
			typeOfMonster = "Orc";
			return typeOfMonster;
		case Monster::Skeleton:
			typeOfMonster = "Skeleton";
			return typeOfMonster;
		case Monster::Troll:
			typeOfMonster = "Troll";
			return typeOfMonster;
		case Monster::Vampire:
			typeOfMonster = "Vampire";
			return typeOfMonster;
		case Monster::Zombie:
			typeOfMonster = "Zombie";
			return typeOfMonster;
		default:
			typeOfMonster = "Unknown type";
			return typeOfMonster;
		}
	}
	void print() {
		//Jack is the orc that has 90 health points.
		std::cout << m_name << " is the " << getTypeString() << " that has " << m_health << " health points." << std::endl;
	}
};

class MonsterGenerator{
public:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
		// Равномерно распределяем вычисление значения из нашего диапазона
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
		int health = getRandomNumber(1, 100);

		static std::string s_names[6]{ "Mypka", "Kilu", "Thor", "Halk", "Bulka", "Anlika" };
		return Monster(type, s_names[getRandomNumber(0, 5)], health);
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}
