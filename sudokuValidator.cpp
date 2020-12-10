#include <unordered_set>
#include <string>
#include <iostream>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (checkHorizontals(board) && checkVerticals(board) && checkSquares(board)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool checkHorizontals(vector<vector<char>>& board) {
        std::unordered_set<char> alreadyPresent;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    if (alreadyPresent.find(board[i][j]) == alreadyPresent.end()) {
                        alreadyPresent.insert(board[i][j]);
                    } else {
                        return false;
                        std::cout << "horizontals" << "i: " << i << ", j: " << j<< std::endl;

                    }
                }
            }
            alreadyPresent.clear();
        }
        return true;
    }
    bool checkVerticals(vector<vector<char>>& board) {
        std::unordered_set<char> alreadyPresent;
        for (int i = 0; i < board[i].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] != '.') {
                    if (alreadyPresent.find(board[j][i]) == alreadyPresent.end()) {
                        alreadyPresent.insert(board[j][i]);
                    } else {
                        std::cout << "verticals" << "i: " << i << ", j: " << j<< std::endl;
                        return false;
                    }
                }
            }
            alreadyPresent.clear();
        }
        return true;
    }
    bool checkSquares(vector<vector<char>>& board) {
        std::unordered_set<char> alreadyPresent = {};
        for (int i = 0; i < 9; i++) {
            int col = (int) (i / 3) * 3;
            int row = (i % 3) * 3;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int newCol = col+j;
                    int newRow = row+k;
                    if (board[newCol][newRow] != '.') {
                        if (alreadyPresent.find(board[newCol][newRow]) == alreadyPresent.end()) {
                            alreadyPresent.insert(board[newCol][newRow]);
                        } else {
                            std::cout << "squares" << "i: " << i << std::endl;
                            return false;
                        }
                    }
                }
            }
            alreadyPresent.clear();
        }
        return true;
    }
};