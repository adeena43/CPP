#include <iostream>
#include <vector>
using namespace std;

class Weapon {
protected:
    string weaponsList[7];
public:
    Weapon() {
        weaponsList[0] = "Sword";
        weaponsList[1] = "Axe";
        weaponsList[2] = "Bow";
        weaponsList[3] = "Dagger";
        weaponsList[4] = "Staff";
        weaponsList[5] = "Hammer";
        weaponsList[6] = "Knife";
    }

    string use() {
        int choice;
        cout << "Available weapons (Enter a number between 0 and 6): ";
        cin >> choice;
        cout << endl;
        if (choice >= 0 && choice <= 6) {
            return weaponsList[choice];
        }
        else {
            cout << "Invalid choice" << endl;
            return "";
        }
    }
};

class Player {
protected:
    int playerID;
    string playerName;
    int health;

public:
    Player(int Id, string name) : playerID(Id), playerName(name), health(100) {}

    int getPlayerID() {
        return playerID;
    }

    string getPlayerName() {
        return playerName;
    }

    int getPlayerHealth() {
        return health;
    }

    void setPlayerHealth(int newHealth) {
        
        health = max(0, newHealth);
    }
};

class Character : public Player {
protected:
    int level;
    string experience;
    int points;

public:
    Character(string name, int ID, int level = 0, int points = 0, string experience = "Beginner") : Player(ID, name), level(level), points(points), experience(experience) {}
	
	
    int getLevel() {
        return level;
    }

    void setLevel(int newLevel) {
        level = newLevel;
    }

    void levelUp() {
        points += 10;
        setLevel(++level);
        if (points >= 10) {
            if (experience == "Beginner") {
                experience = "Intermediate";
            }
            else if (experience == "Intermediate") {
                experience = "Advanced";
            }
            else if (experience == "Advanced") {
                experience = "Expert";
            }
        }
    }

    void playGame(Weapon& weapon) {
        string weaponName = weapon.use();
        cout << endl << "Playing with " << experience << " level: " << level << " using " << weaponName << endl;
    }

    string getExperience() {
        return experience;
    }

    void setExperience(string newExperience) {
        experience = newExperience;
    }
};

class Enemy : public Character {
protected:
    int damage;
    string name;
    int ID;
public:
    Enemy(int dmg, string name, int id) : Character(name, id), damage(dmg) {}

    void attack(Player& player) {
        int oldHealth = player.getPlayerHealth();
        int newHealth = oldHealth - damage;
        player.setPlayerHealth(newHealth);
        cout << "Enemy attacked --> " << player.getPlayerName() << "'s health decreased by " << damage << endl;
    }
};

int main() {
    cout << "Adina Faraz" << endl << "23k-0008" << endl;
    Player player(1, "Player1");
    Character character("Character1", 2);
    Weapon weapon;
    Enemy enemy(5, "Enemy", 23);

    cout << "Experience progression:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Current Experience: " << character.getExperience() << endl;
        character.levelUp();
        character.playGame(weapon);
        enemy.attack(player);
    }

    cout << player.getPlayerName() << "'s final health: " << player.getPlayerHealth() << endl;

    return 0;
}
