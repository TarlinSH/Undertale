// mainyr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Player {
public:
    std::string name;
    int health;

    Player(std::string playerName) : name(playerName), health(100) {}

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() {
        return health > 0;
    }
};

class Enemy {
public:
    std::string name;
    int health;

    Enemy(std::string enemyName) : name(enemyName), health(50) {}

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() {
        return health > 0;
    }
};

void encounter(Player& player, Enemy& enemy) {
    std::cout << "You encountered a " << enemy.name << "!\n";

    while (player.isAlive() && enemy.isAlive()) {
        std::cout << "Your health: " << player.health << "\n";
        std::cout << enemy.name << "'s health: " << enemy.health << "\n";

        std::cout << "Choose an action:\n1. Attack\n2. Heal\n";
        int action;
        std::cin >> action;

        if (action == 1) {
            int damage = rand() % 20 + 5;
            enemy.takeDamage(damage);
            std::cout << "You attacked " << enemy.name << " for " << damage << " damage!\n";
        }
        else if (action == 2) {
            int heal = rand() % 15 + 5;
            player.health += heal;
            std::cout << "You healed for " << heal << " health!\n";
        }

        if (enemy.isAlive()) {
            int enemyDamage = rand() % 15 + 5;
            player.takeDamage(enemyDamage);
            std::cout << enemy.name << " attacked you for " << enemyDamage << " damage!\n";
        }
    }

    if (player.isAlive()) {
        std::cout << "You defeated " << enemy.name << "!\n";
    }
    else {
        std::cout << "You were defeated...\n";
    }
}

int main() {
    std::srand(std::time(0));

    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Player player(playerName);
    Enemy enemy("Froggit");

    while (player.isAlive()) {
        encounter(player, enemy);
        std::cout << "Do you want to continue? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y') break;
    }

    std::cout << "Game Over. Thanks for playing!\n";
    return 0;
}
*/
#include <iostream>
#include <vector>

using namespace std;

class Player {
public:
    int x, y;

    Player(int startX, int startY) : x(startX), y(startY) {}

    void move(char direction) {
        switch (direction) {
        case 'w': // Move up
            y--;
            break;
        case 's': // Move down
            y++;
            break;
        case 'a': // Move left
            x--;
            break;
        case 'd': // Move right
            x++;
            break;
        default:
            cout << "Invalid move!" << endl;
        }
    }
};

class Game {
public:
    int width, height;
    Player player;
    vector<vector<char>> grid;

    Game(int w, int h) : width(w), height(h), player(w / 2, h / 2) {
        grid.resize(height, vector<char>(width, '.')); // '.' represents empty space
        grid[player.y][player.x] = 'P'; // 'P' represents the player
    }

    void display() {
        system("cls"); // Use "cls" on Windows
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void update() {
        grid[player.y][player.x] = '.'; // Clear the previous position
        player.move('d'); // Temporary movement for demonstration
        grid[player.y][player.x] = 'P'; // Update to new position
    }

    void run() {
        char input;
        while (true) {
            display();
            cout << "Move (w/a/s/d to move, q to quit): ";
            cin >> input;
            if (input == 'q') break;

            player.move(input);
            // Ensure player stays within bounds
            player.x = max(0, min(player.x, width - 1));
            player.y = max(0, min(player.y, height - 1));
            update();
        }
    }
};

int main() {
    Game game(10, 10); // Create a 10x10 game grid
    game.run();
    return 0;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
