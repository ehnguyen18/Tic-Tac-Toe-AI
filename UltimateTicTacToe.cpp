//Pham Gia Huy Nguyen
//20000820
// Tic Tac Toe Game With Machine
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class TicTacToe {
	int board[3][3];
	
	public:
	TicTacToe();
    int noOfMoves = 0;
	void displayBoard();
	bool isValidMove(int,int);
	void addMove(int,int,int&);
    int checkBlock(int&,int&);
    int checkWin(int&,int&);
	int gameStatus();


};
TicTacToe::TicTacToe(){
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

}
class Game {
public:
void play();
void getXMove(char , int&, int&);
void getOMove(char , int&, int&);
private:
TicTacToe board;
};

void TicTacToe::displayBoard() {
	cout << "   1    2    3" << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		for (int j = 0; j < 3; j++) {
			char playerSymbol = ' ';
			if (board[i][j] == 1)
				playerSymbol = 'X';
			else if (board[i][j] == -1)
				playerSymbol = 'O';
			cout << setw(3) << playerSymbol;
			if (j != 2)
				cout << " |";
		}
		cout << endl;
		if (i != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}
	cout << endl;
}

bool TicTacToe::isValidMove(int x, int y) {
	if (x<0 || x>2 || y<0 || y>2 || board[x][y])
		return false;
	else
		return true;
}

void Game::getOMove(char player,int &x, int &y){
	int row, col;
	cout << "Player "<<player<<" enter move: "<<endl;
	do {
	cin >> row >> col;
	cout << endl;
	} while (!board.isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
}

void Game::getXMove(char player,int &x, int &y){
	int row, col;
	if (board.noOfMoves == 8 ){
			for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board.isValidMove(i,j))
				{
					row = i;
					col = j;
				}
    }
    else do {
			srand (time(NULL));
			row = rand() % 2;
			col = rand() % 2;
		} while (!board.isValidMove(row , col ));
	x = row ;
	y = col ;
}
void TicTacToe::addMove(int x, int y, int& player) {
	board[x][y] = player;
	noOfMoves++;
}

int TicTacToe::gameStatus() {
	
	for (int i=0; i<3; i++) {
		if ((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][0]== 1)) 
			return 1;
		else if ((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][0]== -1)) 
			return -1;

	}

	//Check columns for a win
	for (int i=0; i<3; i++) {
		if (board[0][i]==board[1][i] && board[2][i]==board[0][i] && board[0][i]==1) {
			return 1;
			break;
		}
		else if (board[0][i]==board[1][i] && board[2][i]==board[0][i] && board[0][i]==-1) {
			return -1;
			break;
		}
	}
	//Check diagonals for a win
	if (board[1][1]==board[2][2] && board[2][2]==board[0][0] && board[0][0]==1) 
		return 1;

	if (board[1][1]==board[2][2] && board[2][2]==board[0][0] && board[0][0]==-1) 
		return -1;

	if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]==1) 
		return 1;

	if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]==-1) 
		return -1;
	//Out of move
	if (noOfMoves >= 9)
		return 2;

	return 0;

}
int TicTacToe::checkBlock(int&x,int&y){
    int b,c;
    for (int i=0; i<3; i++){
        if ((board[i][0]==board[i][1]) && (board[i][1]==-1)){
            b = i;
            c = 2;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
        }
        if ((board[i][2]==board[i][1]) && (board[i][1]==-1)){
            b = i;
            c = 0;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
        }
        if ((board[i][0]==board[i][2]) && (board[i][0]==-1)){
            b = i;
            c = 1;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
        }
    }
    //Check columns 
    for (int i=0; i<3; i++){
        if ((board[0][i]==board[1][i]) && (board[1][i]==-1)){
            b=2;
            c = i;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
        }
        if ((board[2][i]==board[1][i]) && (board[1][i]==-1)){
            b=0;
            c = i;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
        }
        if ((board[0][i]==board[2][i]) && (board[0][i]==-1)){
			b=1;
            c = i;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
		}
    }
    //check diagonals
    if (board[1][1]==board[2][2] && board[1][1]==-1 ){
        b = 0;
        c = 0;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
    }
    if (board[1][1]==board[0][0] && board[0][0]==-1 ){
        b = 2;
        c = 2;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
    }
    if (board[0][0]==board[2][2] && board[0][0]==-1 ){
        b = 1;
        c = 1;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
    }

    if (board[0][2]==board[1][1] && board[1][1]==-1){ 
		b = 2;
        c = 0;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
    }
    if (board[0][2]==board[2][0] && board[2][0]==-1){ 
		b = 1;
        c = 1;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
    }
    if (board[2][0]==board[1][1] && board[1][1]==-1){ 
		b = 0;
        c = 2;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return -1;
                }
    }
    return 0;
}
int TicTacToe::checkWin(int &x, int &y){
	int b,c;
    for (int i=0; i<3; i++) {
        if ((board[i][0]==board[i][1]) && (board[i][1]==1))
        {
                b = i;
                c = 2;
                if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
                
        }
        if ((board[i][2]==board[i][1]) && (board[i][1]==1))
        {
                b = i;
                c = 0;
                if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
        } 
        if ((board[i][0]==board[i][2]) && (board[i][0]==1))
        {
                b = i;
                c = 1;
                if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
         }
	}
	//Check columns for a win
	for (int i=0; i<3; i++){
        if ((board[0][i]==board[1][i]) && (board[1][i]==1)){
            b=2;
            c = i;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
        }
        if ((board[2][i]==board[1][i]) && (board[1][i]==1)){
            b=0;
            c = i;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
        }
        if ((board[0][i]==board[2][i]) && (board[0][i]==1)){
			b=1;
            c = i;
            if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
		}
    }
	//Check diagonals for a win
	    if (board[1][1]==board[2][2] && board[1][1]==1 ){
        b = 0;
        c = 0;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
    }
    if (board[1][1]==board[0][0] && board[0][0]==1 ){
        b = 2;
        c = 2;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
    }
    if (board[0][0]==board[2][2] && board[0][0]==1 ){
        b = 1;
        c = 1;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
    }

    if (board[0][2]==board[1][1] && board[1][1]==1){ 
		b = 2;
        c = 0;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
    }
    if (board[0][2]==board[2][0] && board[2][0]==1){ 
		b = 1;
        c = 1;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
    }
    if (board[2][0]==board[1][1] && board[1][1]==1){ 
		b = 0;
        c = 2;
        if (isValidMove(b, c)){
                    x = b;
                    y = c;
                    return 1;
                }
    }
    return 0;
}

void Game::play(){
	int status = 0;
    char turn;
    int player=1;
    do {
    cout<<"Do you want to go first? [Y/N]: ";
    cin >> turn;
    turn = tolower(turn);
    
    }while((turn != 'y'  )&& (turn != 'n'));

    if (turn == 'y')
        player = -1;

    int x,y;
    board.displayBoard();
    while (status==0){
        char playchar = (player == 1) ? 'X' : 'O';
        if (player==1) {
            status = board.checkWin(x,y);
            if (status==0)
                status = board.checkBlock(x,y);
            if (status==0) 
                getXMove(playchar,x,y);
            }
        else{
            getOMove(playchar,x,y);
        }

        board.addMove(x,y,player);
        board.displayBoard();
        status = board.gameStatus();
        if (player == 1)
			player = -1;
		    else
			player = 1;
    }
        
    if (status == 1) {
            cout << "Player X (AI) wins!" << endl;
        } else if (status == -1) {
            cout << "Player O (Human) wins!" << endl;
        } else if (status == 2) {
            cout << "Draw game!" << endl;
        }
    
}

int main() {

	Game newgame;
	newgame.play();

    
	cout <<"End Program"<<endl;
    system("pause");
	return 0;
}
