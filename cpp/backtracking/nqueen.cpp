#include<iostream>
#include<vector>

using namespace std; 

class Queens {
    private: 
        vector<vector<vector<int>>> solutions; 
        int N; 
        vector<vector<int>> board; 
    public: 
        Queens(int n) {
           this->N = n; 
           this->board = vector<vector<int>>(N, vector<int>(N, 0)); 
        }

        void QueenI() {
            placeQueens(0); 
            printboard(); 
        }

        bool IsvalidSpot(int row, int col) {
            int x, y; 

            // upper left diagonal 
            x = row; 
            y = col; 
           
            while(x >=0 && y>=0) {
                if(board[x][y] == 1) {
                    return false; 
                }
                x--; y--; 
            }

            // lower left diagonal 
            x = row; y = col; 
            while(x < N && y >= 0 ) {
                if(board[x][y] == 1) {
                    return false; 
                }
                x++; 
                y--; 
            }
           
            // left horizontal 
            y  = col; 
            while(y>=0) {
                if(board[row][y] == 1) {
                    return false; 
                }
                y--; 
            }

            return true; 
        }

        void placeQueens(int col) {
            if (col == N) {
                solutions.push_back(board); 
                return; 
            }

            for(int row = 0; row < N; row ++) {
                if(IsvalidSpot(row, col)) {
                    board[row][col] = 1; 
                    placeQueens(col+1); 
                    board[row][col] = 0; 
                }
            }
        }

        void printboard() {
            cout<<"POssible solutions : "<< solutions.size()<<endl; 
            for(auto board : solutions) {
                for(auto row : board) {

                    for(auto val : row) {
                        cout<<val<<" "; 
                    }

                    cout<<endl; 
                    
                }
                cout<<"-------------"<<endl; 
            }
        }
}; 


int main() {

    Queens q(4); 

    q.QueenI(); 

    return 0; 
}