#include "../../cppHeaders.h"

class Character 
{
	protected:
		std::string name;
		double damage;
		IAttackBehavior* behavior;
	public:
		//Constructor
		Character(std::string name, double damage) : name(name), damage(damage), behavior(0) {}
		
		void attack(Character *enemy){
            if(this->behavior)
                this->behavior->performAttack(this, enemy);
        }

		void setAttackBehavior(IAttackBehavior* behavior);
		
		const std::string& getName() const { return this->name; }
		void setDamage(double damage) { this->damage = damage; }
		double getDamage() const { return this->damage; }
};

class IAttackBehavior
{
	public:
		virtual void performAttack(Character* attacker, Character* enemy) = 0;
};

class AxeAttack : public IAttackBehavior
{
	public:
		virtual void performAttack(Character* attacker, Character* enemy){
	        std::cout << attacker->getName() << " crushes " << enemy->getName() << std::endl;
        };
};

class SwordAttack : public IAttackBehavior
{
	public:
		virtual void performAttack(Character* attacker, Character* enemy){
	        std::cout << attacker->getName() << " slashes " << enemy->getName() << std::endl;
        }
};


int main(int argc, char **argv)
{
	Character orc("Urbul", 5.0);
	AxeAttack axe;
	orc.setAttackBehavior(&axe);
	
	Character dragon("Bymarth, The Deathlord", 500.0);
	FireAttack fire;
	dragon.setAttackBehavior(&fire);
	
	Player player("Gandalf", 10.0);
	SwordAttack sword;
	player.setAttackBehavior(&sword);
	
	orc.attack(&player);
	dragon.attack(&player);
	
	player.attack(&dragon);
	
	//the dragon is hard to defeat -> switch weapon at runtime
	player.setAttackBehavior(&axe);
	player.attack(&dragon);
	
	return 0;
}