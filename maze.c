/**
 * @file maze.c
 * @author (YOUR NAME)
 * @brief Code for the maze game for COMP1921 Assignment 2
 * NOTE - You can remove or edit this file however you like - this is just a provided skeleton code
 * which may be useful to anyone who did not complete assignment 1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

typedef struct __Coord
{
    int x;
    int y;
} coord;

typedef struct __Maze
{
    char map[MAX_DIM][MAX_DIM];
    int height;
    int width;
    coord start;
    coord end;
} maze;

FILE *openFile(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Error: could not open file\n");
        return NULL;
    }
    return file;
}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void freeMaze(maze *this)
{
    free(this);
}

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int createMaze(maze *this, int height, int width)
{
    freeMaze(this);
    for (int i = 0; i < height; i++)
    {
        //  this->map[i] = malloc(width * sizeof(char));
    }
}
/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int loadMaze(maze *this, FILE *file)
{
    char line[MAX_DIM];
    int counter = 0;
    int tempWidth;
    int startFound = 0;
    int endFound = 0;
    int lastLine = 0;

    // int lineCounter = 0;
    //  int lineLength = 0;
    //  while (fgets(line, MAX_DIM, file) != NULL)
    // {
    //     lineCounter++;
    //     lineLength = strlen(line);
    // }
    //  createMaze(this, lineCounter, lineLength + 1);
    // my last attempts to try solve the problem

    if (file != NULL)
    {
        while (fgets(line, MAX_DIM, file) != NULL)
        {
            // valid maze checking
            if (strlen(line) < 5 || strchr(line, '\n') == NULL)
            {
                if (lastLine == 0 && strlen(line) == (int)tempWidth)
                {
                    lastLine = 1;
                }
                else
                {
                    printf("Error: invalid maze format\n");
                    return 3;
                }
            }
            // checking width is consistent
            else if (counter == 0)
            {
                tempWidth = strlen(line) - 1;
            }
            else if (strlen(line) - 1 != tempWidth)
            {

                printf("Error: invalid maze format\n");
                return 3;
            }

            for (int i = 0; i < strlen(line); i++)
            {
                if (line[i] == 'S')
                {
                    startFound++;
                    this->start.x = i;
                    this->start.y = counter;
                }
                else if (line[i] == 'E')
                {
                    endFound++;
                    this->end.x = i;
                    this->end.y = counter;
                }
                // catching invalid characters
                else if (line[i] != ' ' && line[i] != '#' && line[i] != '\n')
                {
                    printf("Error: invalid maze format\n");
                    return 3;
                }
            }
            for (int i = 0; i < strlen(line); i++)
            {
                this->map[counter][i] = line[i];
            }
            //  this->map[counter] = line;
            printf("%s", this->map[counter]);
            counter++;
        }
        // no mroe than one start and end point
        if (endFound != 1 || startFound != 1)
        {
            printf("Error: invalid maze format\n");
            return 3;
        }
        this->height = counter;
        this->width = tempWidth;
    }
    else
    {
        printf("Error: could not open file\n");
        return 2;
    }
    fclose(file);
    return 0;
}

/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void printMaze(maze *this, coord *player)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            // decide whether player is on this spot or not
            if (player->x == j && player->y == i)
            {
                printf("X");
            }
            else
            {
                printf("%c", this->map[i][j]);
            }
        }
        // end each row with a newline.
        printf("\n");
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(maze *this, coord *player, char direction)
{
    switch (direction)
    {
        // case boundary checking for each movement option
    case 'w':
        if (player->y - 1 > -1 && this->map[player->y - 1][player->x] != '#')
        {
            player->y -= 1;
        }
        break;
    case 'a':
        if (player->x - 1 > -1 && this->map[player->y][player->x - 1] != '#')
        {
            player->x -= 1;
        }
        break;
    case 's':
        if (player->y + 1 < this->height && this->map[player->y + 1][player->x] != '#')
        {
            player->y += 1;
        }
        break;
    case 'd':
        if (player->x + 1 < this->width && this->map[player->y][player->x + 1] != '#')
        {
            player->x += 1;
        }
        break;
    default:
        printf("Invalid movement input\n");
        break;
    }
}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int hasWon(maze *this, coord *player)
{
    if (player->x == this->end.x && player->y == this->end.y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argNum, char *args[])
{
    // check args
    if (argNum < 2)
    {
        printf("Please input filename after running /maze.c\n");
        return 1;
    }

    coord *player = malloc(sizeof(coord));
    maze *thisMaze = malloc(sizeof(maze));
    FILE *file = openFile(args[1], "r");
    char input[100];

    //  freeMaze(thisMaze); -> this caused core dumping for some reason
    loadMaze(thisMaze, file);
    player->x = thisMaze->start.x;
    player->y = thisMaze->start.y;
    while (hasWon(thisMaze, player) != 1)
    {
        printMaze(thisMaze, player);
        fgets(input, sizeof(input), stdin);
        move(thisMaze, player, input[0]);
    }
    printf("You completed the maze!!");
    // if player wins, they break out the while loop and 0 is returned
    return 0;
}