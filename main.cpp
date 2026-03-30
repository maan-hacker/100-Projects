#include <iostream>
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main() {

    Player p1("Hero", 100, 1);
    Enemy e1("Goblin", 50, 10);

    cout << "=== Player Info ===" << endl;
    p1.showStatus();
    p1.showLevel();
    p1.attack();

    cout << endl;

    cout << "=== Enemy Info ===" << endl;
    e1.showStatus();
    e1.attack();

    cout << endl;

    cout << "=== Combat ===" << endl;
    e1.takeDamage(20);
    p1.takeDamage(e1.getDamage());

    return 0;
}
