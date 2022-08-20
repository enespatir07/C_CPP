#include <iostream>
#include <time.h>

char user = 'X';
char pc = 'O';
char arr[3][3];

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            arr[i][j] = ' ';
}

void printBoard() {
    std::cout << " " << arr[0][0] << " |" << arr[0][1] << " |" << arr[0][2] << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << " " << arr[1][0] << " |" << arr[1][1] << " |" << arr[1][2] << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << " " << arr[2][0] << " |" << arr[2][1] << " |" << arr[2][2] << std::endl;
}
bool is_empty(int x, int y) {
    return arr[x][y] == ' ';
}

bool check_win(char x) {
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == x)
        return true;
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == x)
        return true;
    else if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2] == x)
        return true;
    else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2] == x)
        return true;
    else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] == x)
        return true;
    else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0] == x)
        return true;
    else if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] == x)
        return true;
    else if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2] == x)
        return true;

    return false;
}

bool is_draw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i][j] == ' ')
                return false;
    
    std::cout<<"It's a draw"<<std::endl;
    return true;
}

int main() {
    resetBoard();
    printBoard();
    srand(time(NULL));
    int user_x, user_y, pc_x, pc_y;
    while (true) {
        do {
            std::cout << "Enter x and y location(1-3): ";
            std::cin >> user_x >> user_y;
            user_x--;
            user_y--;
        } while (!is_empty(user_x, user_y));
        arr[user_x][user_y] = user;
        if(is_draw()){
            printBoard();
            break;}
        if (check_win(user)) {
            std::cout << "Yow win\n";
            printBoard();
            break;
        }
        do {
            pc_x = rand() % 3;
            pc_y = rand() % 3;
        } while (!is_empty(pc_x, pc_y));
        arr[pc_x][pc_y] = pc;
        printBoard();
        if (check_win(pc)) {
            std::cout << "You lost\n";
            break;
        }
    }
}
