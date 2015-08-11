/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// special character/value for empty space
#define UNDERSCORE 95

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int dim;

// position of special "space" tile
int x_pos, y_pos;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen dimension\n");
        return 1;
    }

    // ensure valid dimensions
    dim = atoi(argv[1]);
    if (dim < MIN || dim > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // int board[MAX][MAX]
    int value = dim * dim - 1;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            board[i][j] = value;
            value--;
        }
    } 
    
    // Lets change our blank space from 0 to 95 (ascii of underscore)
    board[dim - 1][dim - 1] = UNDERSCORE;
    
    // Lets remember the position of our special blank space tile
    x_pos = dim - 1;
    y_pos = dim - 1;
    
    // And lastly, if d is even we need to swap 1 & 2 cuz Zamyla
    if (dim % 2 == 0)
    {
        int temp = board[dim - 1][dim - 3];
        board[dim - 1][dim - 3] = board[dim - 1][dim - 2];
        board[dim - 1][dim - 2] = temp;
    }
}
/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // Go through the array and print the board 
    printf("\n");
    for (int i = 0; i < dim; i++)
    {
        printf(" ");
        for (int j = 0; j < dim; j++)
        {
            if (board[i][j] == UNDERSCORE)
            {
                printf(" %c ", UNDERSCORE);
            }
            else
            {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // maximum four possible legal moves
    // x_pos -1, y_pos
    if (x_pos - 1 >= 0)
    {
        if (board[x_pos - 1][y_pos] == tile)
        {
            // swap
            int temp = board[x_pos][y_pos];
            board[x_pos][y_pos] = board[x_pos - 1][y_pos];
            board[x_pos - 1][y_pos] = temp;
            
            // update empty tile position & return true
            x_pos -= 1;
            return true;
        } 
    }
    // x_pos, y_pos -1
    if (y_pos - 1 >= 0)
    {
        if (board[x_pos][y_pos - 1] == tile)
        {
            // swap
            int temp = board[x_pos][y_pos];
            board[x_pos][y_pos] = board[x_pos][y_pos - 1];
            board[x_pos][y_pos - 1] = temp;
            
            // update empty tile position & return true
            y_pos -= 1;
            return true;
        } 
    }
    
    // x_pos +1, y_pos
    if (x_pos + 1 < dim)
    {
        if (board[x_pos + 1][y_pos] == tile)
        {
            // swap
            int temp = board[x_pos][y_pos];
            board[x_pos][y_pos] = board[x_pos + 1][y_pos];
            board[x_pos + 1][y_pos] = temp;
            
            // update empty tile position & return true
            x_pos += 1;
            return true;

        }
    }
    
    // x_pos, y_pos +1
    if (y_pos + 1 < dim)
    {
        if (board[x_pos][y_pos + 1] == tile)
        {
            // swap
            int temp = board[x_pos][y_pos];
            board[x_pos][y_pos] = board[x_pos][y_pos + 1];
            board[x_pos][y_pos + 1] = temp;
            
            // update empty tile position & return true
            y_pos += 1;
            return true;
        } 
    
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // check to see if the player one... exit check as soon as 
    // its clear they haven't yet won
    int check = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (board[i][j] > check)
            {
                check = board[i][j];
            }
            else
            {
                return false;
            }
        }
    } 
     
    return true;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < dim; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < dim; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < dim - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < dim - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
