#include<iostream>
using namespace std;

class Player {
private:
    char pla;
    int i, j;

public:
    void getChar(char& c1) {
        pla = c1;
    }
    
    void printChar() {
        cout << pla;
    }

    bool printBoard(int& posX, int& posY, char arr[3][3]) {
        if (arr[posX][posY] != ' ') {
            cout << "\nPosition Occupied, Enter another position";
            return false;
        }
        arr[posX][posY] = pla;
        system("cls");
        cout << "\n  1 2 3" << endl;
        for (i=0 ; i<3 ; i++) {
            cout << i+1 << "|";
            for (j=0 ; j<3 ; j++) {
                cout << arr[i][j] << "|";
            }
            cout << endl;
        }
        return true;
    }

    void initBoard(char arr[3][3]) {
        system("cls");
        cout << "\n  1 2 3" << endl;
        for (i=0 ; i<3 ; i++) {
            cout << i+1 << "|";
            for (j=0 ; j<3 ; j++) {
                cout << arr[i][j] << "|";
            }
            cout << endl;
        }
    }

    bool checkWin(char arr[3][3]) {
        for (i=0 ; i<3 ; i++) {
            if (arr[i][0] == pla && arr[i][1] == pla && arr[i][2] == pla) {
                return true;
            }
        }

        for (i=0 ; i<3 ; i++) {
            if (arr[0][i] == pla && arr[1][i] == pla && arr[2][i] == pla) {
                return true;
            }
        }

        if ((arr[0][0] == pla && arr[1][1] == pla && arr[2][2] == pla) || (arr[0][2] == pla && arr[2][2] == pla && arr[2][0] == pla)) {
            return true;
        }

        return false;
    }
};

void startGame(char* ch1, char* ch2) {
    cout << "Tic Tac Toe\n" << endl;
    cout << "Choose sign (X, O):\n";

    while ((*ch1 != 'X' && *ch1 != 'O') || (*ch2 != 'X' && *ch2 != 'O')) {
        cout << "Player 1: ";
        cin >> *ch1;
        if (*ch1 != 'X' && *ch1 != 'O') {
            cout << "Enter Valid Character for Player 1\n";
            continue;
        }

        cout << "Player 2: ";
        cin >> *ch2;
        if (*ch2 != 'X' && *ch2 != 'O') {
            cout << "Enter Valid Character for Player 2\n";
            continue;
        }
    }
}

int main() {
    class Player Player[2];
    char arr[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    char ch1, ch2;
    int posX, posY, i, flag = 0;

    startGame(&ch1, &ch2);

    Player[0].getChar(ch1);
    Player[1].getChar(ch2);

    Player[0].initBoard(arr);
    while (1) {
        for (i=0 ; i<2 ; i++) {
        again:
            cout << "\nPlayer " << i+1 << " :\n";
            cout << "Enter position (X, Y):\n";
            cin >> posX >> posY;
            posX--;
            posY--;
            if (Player[i].printBoard(posX, posY, arr) == false) {
                goto again;
            }

            if (Player[i].checkWin(arr) == true) {
                cout << "\nPlayer " << i+1 << " Won!\n";
                flag++;
                break;
            }
        }
        if (flag > 0)
            break;
    } 

    system("pause");

    return 0;
}
