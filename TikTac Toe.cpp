

//Importing the inbuild libraries in CPP
// Used the code implentation from stechies.com, fixed an error where the game was giving the wrong player as the winner. 
// One of my first code throughs where I typed along more to learn about as I went through the code, and is a better result than the one found on simplearn. 
#include <iostream>

using namespace std;
//Array
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int choice;
int row; 
int column; 
char turn = 'X';
bool draw = false;



    void display_board() {

        

        cout << "PLAYER - 1 [X]  PLAYER - 2 [O]\n ";
        cout << "       |     |     \n";
        cout << "    " << board[0][0] << "  | " << board[0][1] << "  |  " << board[0][2] << " \n";
        cout << "  _____|_____|_____\n";
        cout << "       |     |     \n";
        cout << "    " << board[1][0] << "  | " << board[1][1] << "  |  " << board[1][2] << " \n";
        cout << "  _____|_____|_____\n";
        cout << "       |     |     \n";
        cout << "    " << board[2][0] << "  | " << board[2][1] << "  |  " << board[2][2] << " \n";
        cout << "       |     |     \n";
    }

   

    void player_turn() {
        if (turn == 'X') {
            cout << "\n Player - 1 [X] turn : ";
        }
        else if (turn == 'O') {
            cout << "\n Player - 2 [O] turn : ";
        }
       

        cin >> choice;

        

        switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move";
        }

        if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
           
            board[row][column] = 'X';
            turn = 'O';
        }
        else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
            
            board[row][column] = 'O';
            turn = 'X';
        }
        else {
            
            cout << "Box already filled!n Please choose another!!nn";
            player_turn();
        }
        
        display_board();
    }

    

    bool gameover() {
        
        for (int i = 0; i < 3; i++)
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
                return false;

       

        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
            return false;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return true;

        draw = true;
        return false;
    }
    

//Program Main Method



int main()
{
    cout << "   T I C T A C   T O E ";
    cout << "\n"; 
    cout << "\n"; 
    while (gameover()) {
        display_board();
        player_turn();
        gameover();
    }
    if (turn == 'O' && draw == false) {
        cout << "\n Player 'X' wins";
    }
    else if (turn == 'X' && draw == false) {
        cout << "\n Player 'O' wins";
    }
    else
        cout << "\n Draw \n";
}