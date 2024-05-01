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
    char **map;
    int height;
    int width;
    coord start;
    coord end;
} maze;

FILE *open_file(char *filename, char *mode)
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
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int create_maze(maze *this, int height, int width)
{
}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void free_maze(maze *this)
{
    free(this);
}

/**
 * @brief Validate and return the width of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid width (5-100)
 */
int get_width(FILE *file)
{
}

/**
 * @brief Validate and return the height of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid height (5-100)
 */
int get_height(FILE *file)
{
}

/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int read_maze(maze *this, FILE *file)
{
    char line[MAX_DIM];
    int counter = 0;
    int tempWidth;
    int startFound = 0;
    int endFound = 0;
    if (file != NULL)
    {
        while (fgets(line, MAX_DIM, file) != NULL)
        {

            if (strlen(line) < 5 || strchr(line, '\n') == NULL)
            {
                printf("Error: invalid maze format\n");
                return 3;
            }
            else if (counter == 0)
            {
                tempWidth = strlen(line);
            }
            else if (strlen(line) != tempWidth)
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
                else if (line[i] != ' ' || line[i] != '#' || line[i] != '\n')
                {
                    printf("Error: invalid maze format\n");
                    return 3;
                }
            }

            this->map[counter] = line;
            counter++;
        }
        if (endFound != 1 || startFound != 1)
        {
            printf("Error: invalid maze format\n");
            return 3;
        }
        counter = this->height;
        tempWidth = this->width;
    }
    else
    {
        printf("Error: could not open file\n");
        return 2;
    }
}

/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(maze *this, coord *player)
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
}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(maze *this, coord *player)
{
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
    coord *player;
    maze *thisMaze = malloc(sizeof(maze));
    FILE *file = open_file(args[1], "r");
    read_maze(thisMaze, file);

    // open and validate mazefile

    // read in mazefile to struct

    // maze game loop

    // win

    // return, free, exit
}