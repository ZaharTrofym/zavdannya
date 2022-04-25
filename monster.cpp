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
        string saver;
        bool win_or_lose;
    public:
        void generate() {
            lvl_monster = rand() % 10;
            hp_monster = lvl_monster * 25;
            saver = "abcdefgABCDEFG";
            win_or_lose = false;
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

            if (hp_monster < 0) {
                hp_monster = 0;
            }

            cout << "\nВи нанесли монстру " << attack_on_monster_hp << " ХП, в нього залишилося " << hp_monster << "ХП";
        }

        int savePlayer() {
            string code;
            string save;
            for (int i = 0; i < 7; i++) {
                code += saver[rand() % saver.length()];
            }
            cout << "\nВведіть код для того щоб спастись від атаки(" << code << "): ";
            cin >> save;

            system("clear");
            paintArena(1, 0);

            if (code == save) {
                if (rand() % 2 == 1) {
                    cout << "\nВи зробили все правильно, але атака була дуже сильною, вам нанесли 5 ХП";
                    return 5;
                }
                else {
                    cout << "\nВи спаслись від атаки";
                    return 0;
                }
            }
            else {
                int damage = rand() % 21 + 20;
                cout << "\nВи ввели код неправильно, вам нанесено " << damage << "ХП";
                return damage;
            }
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

        void addDamage(int damage) {
            hp -= damage;
            if (hp < 0) {
                hp = 0;
            }
        }
};

int main() {
    srand(time(NULL));
    Engine Game;
    Player Player;
    Player.createPlayer();
    Game.generate();
    bool win_or_lose = false;
    int player_hp;

    cout << "Згенеровано плеєра(позначка %). Його ХП - " << Player.getPlayerHp() << ". А також монстра(позначка $) " << Game.getMonsterLvl() << " рівню. Його ХП - " << Game.getMonsterHp() << endl;

    pause("Для того щоб гра працювала нажимайте Enter");

    while(win_or_lose == false) {
        Game.paintArena();

        pause("Ви атакуєте");

        Game.paintArena(0, 1);

        pause("");

        Game.paintArena();
        Game.attackOnMonster();

        if (Game.getMonsterHp() == 0) {
            cout << "\nВи виграли монстра, для виходу нажміть Enter ";
            pause("");
            exit(0);
        }
        
        pause("Зараз на вас буде атакувати монстр");

        Game.paintArena(1, 0);

        player_hp = Game.savePlayer();
        Player.addDamage(player_hp);

        if (Player.getPlayerHp() == 0) {
            cout << "\nВи програли, для виходу нажміть Enter ";
            pause("");
            exit(0);
        }

        cout << "\nУ вас залишилося " << Player.getPlayerHp() << " ХП";

        pause("");
    }
}