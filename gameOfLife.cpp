/***********************************************************
 ** Author: Carlos Carrillo                                *
 ** Date:   10/02/2015                                     *
 ** Description: This is a C++ implementation of John      *
 *  Conway's Game of Life. It uses a series of             *
 *  two-dimensional arrays and nested loops to create      *
 *  the grid for the cells in the simulation to interact.  *
 *  The program displays a 20x40 grid, but real size of    *
 *  the arrays used is 32x52 since it makes easier to      *
 *  handle the problem of creating a frame for the actual  *
 *  grid in which the game is visualized. The design idea   *
 *  of having this set of functions was taken from         *
 *  http: //code.runnable.com/UwQvQY99xW5AAAAQ/john-conway *
 *  -s-game-of-life-for-c%2B%2B-nested-for-loops-and-2-    *
 *  dimensional-arrays                                     *
 **********************************************************/

#include <cctype>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*********************************************************
 *                   copyArray function                  *
 * This function just copies one array into another.     *
 ********************************************************/
void copyArray(int copyArray1[32][52], int copyArray2[22][52])
{
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 52; j++)
            copyArray2[i][j] = copyArray1[i][j];
    }
}

/**********************************************************
 *                 rulesOfGame function                   *
 * This function determines the actual rules of the       *
 * game. First, the main array is copied to a temp array  *
 * so the changes made along the function can be entered  *
 * into the grid without affecting the original array.    *
 * This idea and algorithm was taken from:                *
 * http: //code.runnable.com/UwQvQY99xW5AAAAQ/john-conway *
 * -s-game-of-life-for-c%2B%2B-nested-for-loops-and-2-    *
 * dimensional-arrays                                     *
 *********************************************************/
void rulesOfGame(int ruleArray[32][52])
{
    //creates temporary array
    int tempArray[32][52];
    
    //calls the copyArray function
    copyArray(ruleArray, tempArray);
    
    //Loop to apply the rules over every single cell into the grid
    for(int i = 1; i < 31; i++)
    {
        for(int j = 1; j < 51; j++)
        {
            if(j > 0)//trigger to start the calculations
            {
                //checks all 8 cells surrounding the current cell in the array.
                int count = 0;
                count = ruleArray[i-1][j] +
                ruleArray[i-1][j-1] +
                ruleArray[i][j-1] +
                ruleArray[i+1][j-1] +
                ruleArray[i+1][j] +
                ruleArray[i+1][j+1] +
                ruleArray[i][j+1] +
                ruleArray[i-1][j+1];
                
                //The cell dies.
                if(count < 2 || count > 3)
                    tempArray[i][j] = 0;
                //The cell stays the same.
                if(count == 2)
                    tempArray[i][j] = ruleArray[i][j];
                //The cell either stays alive or a new cell is created
                if(count == 3)
                    tempArray[i][j] = 1;
            }
        }
    }
    
    //copy the temporal array back to the ruleArray
    copyArray(tempArray, ruleArray);
}

/*********************************************************
 *                   printGrid function                  *
 * This function prints the 40x20 grid to be visualized  *
 * by the user. "X" represents the live cells and "-"    *
 * represents the dead cells.                            *
 ********************************************************/
void printGrid(int gridArray[32][52])
{
    for(int i = 1; i < 21; i++)
    {
        for(int j = 1; j < 41; j++)
        {
            if(gridArray[i][j] == 1)
                cout << 'X' << " ";
            else
                cout << '-' << " ";
        }
        cout << endl;
    }
}

/************************************************************
 *                     main function                        *
 ************************************************************/

int main()
{
    //Introduce the rules to the user.
    cout <<"\n\n             *** THIS IS THE CONWAY'S GAME OF LIFE ***"<< endl;
    cout <<"    (Please make the console window wide enough to see 40 columns)\n" <<endl;
    cout <<"It is a zero-player game, which means that its evolution is determined "<< endl;
    cout <<"by its initial state, requiring no further input. One interacts with "<< endl;
    cout <<"the Game by creating an initial configuration and observing how it evolves.\n"<< endl;
    cout <<"These are the set of rules that determine the game:\n" << endl;
    cout <<"A) If an occupied cell has zero or one neighbor, it dies of loneliness."<< endl;
    cout <<"B) If an occupied cell has more than three neighbors, it dies of overcrowding."<< endl;
    cout <<"C) If an empty cell has exactly three occupied neighbor cells, there is a"<< endl;
    cout <<"   birth of a new cell to replace the empty cell."<<endl<<endl;
    
    //main variables
    int patternArray[32][52];
    int mainArray[32][52];
    int option;
    int generations;
    int trigger = 0;
    
    //for loop to fill up the patternArray with 0's
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 52; j++)
        {
            patternArray[i][j] = 0;
        }
    }
    
    //main menu to prompt the user to choose the shape and
    //the starting location of the pattern.
    do
    {
        //Displaying Options for the menu
        cout << "Main Menu:" << endl;
        cout << "Enter 1 to select the Fixed Oscillator shape." << endl;
        cout << "Enter 2 to select the Glider shape." << endl;
        cout << "Enter 3 to select the Glider Gun shape." << endl;
        
        //Prompting user to enter an option according to menu
        cout << "\nPlease select an option : ";
        cin >> option;  //taking input value
        
        if(option == 1) // Checking if user selected option 1
        {
            int xCoord1;
            int yCoord1;
            
            cout << "\nEnter the coordinates of the first cell to"<<endl;
            cout << "specify the starting location of the pattern.\n" << endl;
            cout << "Enter a row coordinate in the range of 2 to 19 to see the whole pattern: ";
            cin >> xCoord1;
            cout << endl;
            cout << "Enter a column coordinate in the range of 1 to 38 to see the whole pattern: ";
            cin >> yCoord1;
            cout << endl;
            
            //Coordinates for the Fixed Oscillator shape
            patternArray[xCoord1][yCoord1] = 1;
            patternArray[xCoord1][yCoord1+1] = 1;
            patternArray[xCoord1][yCoord1+2] = 1;
        }
        
        else if(option == 2) // Checking if user selected option 2
        {
            int xCoord2;
            int yCoord2;
            
            cout << "\nEnter the coordinates of the first cell to"<<endl;
            cout << "specify the starting location of the pattern.\n" << endl;
            cout << "Enter a row coordinate in the range of 1 to 18 to see the whole pattern: ";
            cin >> xCoord2;
            cout << endl;
            cout << "Enter a column coordinate in the range of 2 to 39 to see the whole pattern: ";
            cin >> yCoord2;
            cout << endl;
            
            //Coordinates for the Glider shape
            patternArray[xCoord2][yCoord2] = 1;
            patternArray[xCoord2+1][yCoord2+1] = 1;
            patternArray[xCoord2+2][yCoord2-1] = 1;
            patternArray[xCoord2+2][yCoord2] = 1;
            patternArray[xCoord2+2][yCoord2+1] = 1;
        }
        
        else if(option == 3) // Checking if user selected option 3
        {
            int xCoord3;
            int yCoord3;
            
            cout << "\nYOU MUST START AT ROW 6 TO SEE THE WHOLE PATTERN VERTICALLY."<<endl;
            cout << "AFTER COLUMN 5, YOU WILL NOT BE ABLE TO SEE THE WHOLE PATTERN HORIZONTALLY."<<endl;
            
            cout << "\nEnter the coordinates of the first cell to"<<endl;
            cout << "specify the starting location of the pattern.\n" << endl;
            cout << "Enter a row coordinate greater than 5 to see the whole pattern: ";
            cin >> xCoord3;
            cout << endl;
            cout << "Enter a column coordinate fewer than 5 to see the whole pattern: ";
            cin >> yCoord3;
            cout << endl;
            
            //Coordinates for the Glider Gun shape
            
            //left square
            patternArray[xCoord3][yCoord3] = 1;
            patternArray[xCoord3][yCoord3+1] = 1;
            patternArray[xCoord3+1][yCoord3] = 1;
            patternArray[xCoord3+1][yCoord3+1] = 1;
            
            //first cannon
            patternArray[xCoord3][yCoord3+10] = 1;
            patternArray[xCoord3+1][yCoord3+10] = 1;
            patternArray[xCoord3+2][yCoord3+10] = 1;
            patternArray[xCoord3+3][yCoord3+11] = 1;
            patternArray[xCoord3+4][yCoord3+12] = 1;
            patternArray[xCoord3+4][yCoord3+13] = 1;
            patternArray[xCoord3+3][yCoord3+15] = 1;
            patternArray[xCoord3+2][yCoord3+16] = 1;
            patternArray[xCoord3+1][yCoord3+14] = 1;
            patternArray[xCoord3+1][yCoord3+16] = 1;
            patternArray[xCoord3+1][yCoord3+17] = 1;
            patternArray[xCoord3][yCoord3+16] = 1;
            patternArray[xCoord3-1][yCoord3+15] = 1;
            patternArray[xCoord3-2][yCoord3+13] = 1;
            patternArray[xCoord3-2][yCoord3+12] = 1;
            patternArray[xCoord3-1][yCoord3+11] = 1;
            
            //second cannon
            patternArray[xCoord3][yCoord3+20] = 1;
            patternArray[xCoord3][yCoord3+21] = 1;
            patternArray[xCoord3-1][yCoord3+20] = 1;
            patternArray[xCoord3-1][yCoord3+21] = 1;
            patternArray[xCoord3-2][yCoord3+20] = 1;
            patternArray[xCoord3-2][yCoord3+21] = 1;
            patternArray[xCoord3-3][yCoord3+22] = 1;
            patternArray[xCoord3-4][yCoord3+24] = 1;
            patternArray[xCoord3-3][yCoord3+24] = 1;
            patternArray[xCoord3+1][yCoord3+22] = 1;
            patternArray[xCoord3+1][yCoord3+24] = 1;
            patternArray[xCoord3+2][yCoord3+24] = 1;
            
            //right cannon
            patternArray[xCoord3-1][yCoord3+34] = 1;
            patternArray[xCoord3-2][yCoord3+34] = 1;
            patternArray[xCoord3-1][yCoord3+35] = 1;
            patternArray[xCoord3-2][yCoord3+35] = 1;
        }
        
        else if(!isdigit(option)) //conditional to validate the input
        {
            cout << "\nInvalid option entered. Try again!\n" << endl;
            return 0;
        }
        
        else //Displaying error message for invalid choice (other than 1,2 or 3)
        {
            cout << "\nInvalid option entered. Try again!\n" << endl;
        }
        
    }while(option != 1 && option != 2 && option != 3);//condition of do-while loop
    
    
    //for loop to fill up the mainArray with 0's
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 52; j++)
        {
            mainArray[i][j] = 0;
        }
    }
    
    //Prompt the user to choose the number of generations to be simulated
    cout << "How many generations do you want to simulate?\n";
    cout << "More than 100 are recommended for the Glider shapes: ";
    cin >> generations;
    cout << endl;
    
    //This loop performs the the game itself. First, the patternArray is copied to
    //the mainArray. Then the printGrid function is called to print the mainArray
    //that already contains the pattern (which is the first generation). Then the
    //rulesOfGame function is called to apply the rules of the game over the alive
    //cells provided by the pattern chosen by th user. 80% of this idea was taken from
    //http: //code.runnable.com/UwQvQY99xW5AAAAQ/john-conway-s-game-of-life-for
    //-c%2B%2B-nested-for-loops-and-2-dimensional-arrays
    do
    {
        if(trigger == 0)
        {
            copyArray(patternArray, mainArray);
        }
        printGrid(mainArray);
        rulesOfGame(mainArray);
        cout << endl << "Generation "<< trigger+1 << endl;
        trigger++;
        system("sleep .1");
        
    }while(trigger < generations);
    
    return 0;
}
