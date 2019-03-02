#include <iostream>
#include <string.h>

using namespace std;
#define R 15
#define C 15

void removeComma(char *s){ 
  
    int j, n = strlen(s); 
    for (int i=j=0; i<n; i++) 
       if (s[i] != 44) // 44 ascii of comma
          s[j++] = s[i]; 
      
    s[j] = '\0'; 
} 

class WordMatrix {
    public:
    int** solution;
	int path = 1;
	int NUM_OF_ROWS; // For Desruction of 2D Array
    public :
	

	WordMatrix(int RW , int CL) 
	{
	    NUM_OF_ROWS = RW;
		solution = new int*[RW];
        for(int i = 0; i < RW; ++i)
        solution[i] = new int[CL];
        
		for (int i = 0; i < RW; i++) 
		{
			for (int j = 0; j < CL; j++) 
			{
				solution[i][j] = 0;
			}
		}
	}
	~WordMatrix() 
	{
	     for( int i = 0 ; i < NUM_OF_ROWS; i++ )
            delete [] solution[i] ;
        delete [] solution;
	}
	friend void deallocateMem(WordMatrix *ptr)
	{
	    delete ptr;
	}

	bool searchWord(char matrix[R][C], string word ,int RW , int CL ) 
	{
		for (int i = 0; i < RW; i++) {
			for (int j = 0; j < CL; j++) {
				if (search(matrix, word, i, j, 0, RW , CL)) {
					return true;
				}
			}
		}
		return false;
	}

	bool search(char matrix[R][C], string word, int row, int col, int index, int RW , int CL) 
	{

		if (solution[row][col] != 0 || word.at(index) != matrix[row][col]) {
			return false;
		}

		if (index == word.length() - 1) {
			solution[row][col] = path++;
			return true;
		}
		solution[row][col] = path++;		
		// check if cell is already used

		if (row + 1 < RW && search(matrix, word, row + 1, col, index + 1, RW , CL)) { // go
																				// down
			return true;
		}
		if (row - 1 >= 0 && search(matrix, word, row - 1, col, index + 1, RW, CL)) { // go
																				// up
			return true;
		}
		if (col + 1 < RW && search(matrix, word, row, col + 1, index + 1, RW, CL)) { // go
																				// right
			return true;
		}
		if (col - 1 >= 0 && search(matrix, word, row, col - 1, index + 1, RW, CL)) { // go
																				// left
			return true;
		}
		if (row - 1 >= 0 && col + 1 < CL
				&& search(matrix, word, row - 1, col + 1, index + 1, RW, CL)) {
			// go diagonally up right
			return true;
		}
		if (row - 1 >= 0 && col - 1 >= 0
				&& search(matrix, word, row - 1, col - 1, index + 1, RW, CL)) {
			// go diagonally up left
			return true;
		}
		if (row + 1 < RW && col - 1 >= 0
				&& search(matrix, word, row + 1, col - 1, index + 1, RW, CL)) {
			// go diagonally down left
			return true;
		}
		if (row + 1 < RW && col + 1 < CL
				&& search(matrix, word, row + 1, col + 1, index + 1, RW, CL)) {
			// go diagonally down right
			return true;
		}

		// if none of the option works out, BACKTRACK and return false
		solution[row][col] = 0;
		path--;
		return false;
	}

	void print(int RW, int CL) 
	{
		for (int i = 0; i < RW; i++) 
		{
			for (int j = 0; j < CL; j++) 
			{
				cout<<" "<<solution[i][j];
			}
			cout<<endl;
		}
	}
    void resetSol(int RW , int CL) 
	{
		for (int i = 0; i < RW; i++) 
		{
			for (int j = 0; j < CL; j++) 
			{
				solution[i][j] = 0;
			}
		}
	}

};

int main() 
{
    int numOfTest;
    cin>>numOfTest;
    for(int t = 0 ; t<numOfTest ; ++t )
    {
       int RW,CL;
       cin>>RW>>CL;
       char grid [R][C];
       char search[RW*CL];
       cin>>search;
       removeComma(search);
       for(int i=0; i<RW ; i++)
       {
          cin>>grid[i];
          removeComma(grid[i]);
       }                            
		WordMatrix *w = new WordMatrix(RW,CL);
		string duplicate = search;
		int ans;
		for(ans=0;(w->searchWord(grid,duplicate,RW,CL)) ; ans++ )
		{
		    w->resetSol(RW,CL);
		    duplicate+=search;
		}
		cout<<ans<<endl;
		deallocateMem(w);
		
    }
}
