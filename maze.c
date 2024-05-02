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
    char *map[MAX_DIM * 2];
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

    if (file != NULL)
    {
        while (fgets(line, MAX_DIM, file) != NULL)
        {
            this->map[counter] = malloc(MAX_DIM * sizeof(char));
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
                else if (line[i] != ' ' && line[i] != '#' && line[i] != '\n')
                {
                    printf("Error: invalid maze format\n");
                    return 3;
                }
            }
            this->map[counter] = line;
            printf("%s", this->map[counter]);
            counter++;
        }
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
                printf("%s", this->map[i]);
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

    // set up some useful variables (you can rename or remove these if you want)
    coord *player = malloc(sizeof(coord));
    maze *thisMaze = malloc(sizeof(maze));
    freeMaze(thisMaze);
    FILE *file = openFile(args[1], "r");
    char input[100];
    loadMaze(thisMaze, file);
    player->x = thisMaze->start.x;
    player->y = thisMaze->start.y;
    while (hasWon(thisMaze, player) != 1)
    {
        printMaze(thisMaze, player);
        fgets(input, sizeof(input), stdin);
        move(thisMaze, player, input[0]);
    }

    // open and validate mazefile

    // read in mazefile to struct

    // maze game loop

    // win

    // return, free, exit
}