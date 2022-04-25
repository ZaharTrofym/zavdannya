#include <iostream>
#include <ctime>

using namespace std;

void pause(string text) {
    cout << "\n" << text << "\n";
    fflush(stdin);
    cin.get();
    system("clear");
}

class Monster {
    protected:
        int lvl_monster;
        int hp_monster;
        int attack_on_monster_hp;
};

class Engine : Monster {
    private:
        
    public:
        void generateMonster() {
            lvl_monster = rand() % 10;
            hp_monster = lvl_monster * 25;
        }

        void paintArena(int m = 0, int p = 0) {
            for (int i = 0; i < 9; i++) {
                cout << "#";
            }

            cout << endl;

            for (int i = 0; i < 7; i++) {
                cout << "#";
                for (int j = 0; j < 7; j++) {
                    if (i == 2 + m && j == 3) {
                        cout << "$";
                    }
                    else if (i == 4 - p && j == 3) {
                        cout << "%";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << "#" << endl;
            }

            for (int i = 0; i < 9; i++) {
                cout << "#";
            }
        }

        int getMonsterHp() {
            return hp_monster;
        }

        int getMonsterLvl() {
            return lvl_monster;
        }

        void attackOnMonster() {
            attack_on_monster_hp = rand() % 16 + 15;
            hp_monster -= attack_on_monster_hp;
            cout << "\nВи нанесли монстру " << attack_on_monster_hp << " ХП, в нього залишилося " << hp_monster << "ХП";
        }

        int savePlayer() {
            
        }
};

class Player {
    private:
        int hp;
    public:
        void createPlayer() {
            hp = 100;
        }

        int getPlayerHp() {
            return hp;
        }
};

int main() {
    srand(time(NULL));
    Engine Game;
    Player Player;
    Player.createPlayer();
    Game.generateMonster();
    bool win_or_lose = false;

    cout << "Згенеровано плеєра(позначка %). Його ХП - " << Player.getPlayerHp() << ". А також монстра(позначка $) " << Game.getMonsterLvl() << " рівню. Його ХП - " << Game.getMonsterHp() << endl;

    pause("Для того щоб гра працювала нажимайте Enter");

    while(win_or_lose == false) {
        Game.paintArena();

        pause("Ви атакуєте");

        Game.paintArena(0, 1);

        pause("");

        Game.paintArena();
        
        Game.attackOnMonster();

        pause("Зараз на вас буде атакувати монстр");

        Game.paintArena(1, 0);


    }
}