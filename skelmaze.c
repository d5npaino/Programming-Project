#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
   /*This structure stores the 'x and y' position of the player relative to the maze
   character is defined so that it can be displayed and used to verwrite maze to show where player respectively is*/
} Character;

typedef struct 
{
    /*Stores the 2D array of characters for the maze
    Also stores the che character of the space the player is currently occupying temporarily, so that when the player oves off this space
    the maze space can be reprinted correcly without losing what that spaced used to be beforehad, as the player position overwrites that space when it moves there
    maze height and width can also be stored as a numerical value which i useful for loops and iterations and boundary checking for the player etc*/
} Maze;


int main()
{
/*Starts by asking user to input filename to load maze file, takes their input and stores it as 'filename'
Calls the 'loadMaze' function, passing the 'filename' through. When done, this should return with a 2D array that tsores the layout of the specified maze
- now that maze is loaded into a 2D character array and validated, we can begin to use the maze
While loop with the condition that the maze has not been completed yet (player has not reached the 'E' character)
Calls the 'displayMaze; function to display the current state of the maze before the player decides where to move if the player wishes to view the map by pressing 'm'
Calls the 'playerMove' function to move the player. Passed through the current player variable, which is the Character type structure variable
- Returns from subroutine with an updated character position (most the time).
If the player has successfully reached the end of the maze in the last movement then the conditional while loop this function is called inside shall be broken as the player has finished
This should then finish executing the program*/
}

void loadMaze ()
{
/*
Calls 'openFile' function with inputted text file to open it so we can access it, pasing 'filename' through and returning a file variable
Calls 'validateMazeFile' function which passed through the file, and returns the file in a 2D array of characters
Returns this 2D array from where this function was called
*/
}

FILE *openFile(char *filename, char *mode){
/*Attemps to open file with passed filename and mode to specify usage
Error handling such that if filename is invalid, an exception is thrown 
If file sucessfully opened and read, it is returned*/
}

char* validateMazeFile (FILE *file)
{
/*Begins by opening and reading first line of file inside of a while loop
First check height/width of maze against desired parameters (between 5-100 characters)
Checks that each character is valid, and records lenght of row, if an S/E character as been used etc
Validates each line through specified rules, such as making sure each row is the same character lenghth
Checks that the S/E char havent been used more than once
--> note that when S character has been read, its 'position' is saved and stored inside the players initial starting position 
This repeats inside the while loop for each line until the file ha been completely read
then completes check that each column has teh same number of characters (make sure each line is the same length)
Exception is thrown if any of these conditions arent met, but if maze file is valid, it is stored inside a 2D character array
this array is then returned back to the main function*/
}

void playerMove (Character player, Maze maza)
{
    /*Takes user input as 'movement' in the form of W/A/S/D key input. Validates correct character input otherwise an exception is thrown
    dependant on the users inputted 'movement', the players x and y values are updated (incrementation) depewndant on their move choice
    This new movement is then checked against the maze, and if the move is invalid an appropriate message shall appear
    telling the player they cannot move to that space (e.g. tried to move onto a # space)
    Given the move is valid, the players 'X' character should be updated on the maze, and the space they were previously on restored
    back to the character it was (this is stored temporarily inside a variable inside the 'Maze' structure)
    Finally, if the player has successfully moved onto the end position of the maze, a variable shoudl be returned/updated to show that
    the maze has been completed (alike a boolean) which is linked to the conditional while loop inside the main function*/
}

void displayMaze (Maze maze)
{
/*Prints the 2D array of characters on the screen in the correct maze format so the player can see a
visual representation of not only the maze, but where there character currently is respective to the maze layout
- Reminder: This should only display upon the players input of 'm'*/
}

