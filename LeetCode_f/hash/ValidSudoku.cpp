/*LeetCode T36 :Valid Sudoku
 *fs
 *2021.7.25
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>>horizontal (9,vector<char>(9,0));  // 一
        vector<vector<char>>vertial    (9,vector<char>(9,0));  // |
        vector<vector<char>>block      (9,vector<char>(9,0));  // 口
        
        for(int i=0 ;i<9 ;++i ){
            for(int j=0 ;j<9 ;++j){
                if(board[i][j] == '.')
                    continue;
                
                    int value= board[i][j]-'1';   
                    int block_place= j/3 + (i/3) * 3;
              
                    if(   horizontal[i][value]==0  
                       && vertial[j][value]==0
                       && block[block_place][value]==0){
                       
                        horizontal[i][value]=1;
                        vertial[j][value]=1;
                        block[block_place][value]=1;
                    }
                    else
                        return false;
                
            }
        }
        return true;
    }
};
