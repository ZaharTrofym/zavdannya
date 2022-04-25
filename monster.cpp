#include <iostream>
#include <ctime>

using namespace std;

class Monster {
    protected:
        int lvl_monster;
        int hp_monster;
};

class Engine : Monster {
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
};

class Player {
    private:
        int hp;
    public:
        void createPlayer() {
            hp = 100;
        }
};

int main() {
    srand(time(NULL));
    Engine Game;
    Player Player;
    Player.createPlayer();
}