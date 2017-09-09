/*Ian Smith 12442396 insd45*/
//After trying for a long time to do this with some type of matrix and graphs, i tried doing it simply. It works! Just a couple while loops and it's good to go 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global variables
int visited[101]; //101 so I don't have to worry about indexing at s-1 or anything
//int matrix[100][100];

//Prototypes
//void fillMatrix(int f, int u, int d);
int pathExists(int f, int s, int g, int u, int d);
void printPath(int f, int s, int g, int u, int d);

int main()
{
    int f, s, g, u, d, clear;
    f = -1;
    s = -1;
    g = -1;
    u = -1;
    d = -1;
    clear = -1;
    printf("Enter ints in a line with a space in between like so: <floors> <start> <goal> <up> <down>\n");
    
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    
    while(clear < 0)
    {
        if(f < 1 || f > 100){
            printf("Invalid entry. Enter again\n");
            scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
        }
        else if(s < 1 || s > f){
            printf("Invalid entry. Enter again\n");
            scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
        }
        else if(g > f){
            printf("Invalid entry. Enter again\n");
            scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
        }
        else if(u < 0 || d > 100)
        {
            printf("Invalid entry. Enter again\n");
            scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
        }
        else{
            clear = 1;
        }
    }
    
    //Valid entry of numbers. Calculate path of elevator
    //int matrix[100][100];
    
    //fillMatrix(f, u, d);
    int yup = pathExists(f, s, g, u, d);
    
    if(yup == 0)
    {
        printf("Take the stairs\n");
    }
    else
    {
        //Path exists. Print it, but first reset visited
        int i;
        for(i = 0; i < 101; i++)
        {
            visited[i] = 0;
        }
        
        printPath(f, s, g, u, d);
    }
    
    return 0;
}

/*void fillMatrix(int f, int u, int d)
{
    //If the value can be reached going up, put a 1. If the value can be reached going down, put a 2
    int i;
    for(i = 1; i <= f; i++)
    {
        if((i + u) <= f)
        {
            matrix[i][i + u] = 1;
        }
        if((i - d) >= 1)
        {
            matrix[i][i - d] = 2;
        }
    }
}*/

int pathExists(int f, int s, int g, int u, int d)
{
    //If a path exists, return 1. If not, return 0   <------- Recursive?
    /*if(visited[s] != 1)
    {
        //Not visited
        if(s == g)
        {
            return 1;
        }
    }
    else
    {
        //visited, loop, path doesn't exist
        return 0;
    }*/
    while(visited[s] != 1)
    {
        visited[s] = 1; //How to ensure it will eventually exit the while loop if path doesn't exist
        //While the node has not been visited...
        if(s == g)
        {
            return 1;
        }
        else if(s < g)
        {
            if((s + u) <= f)
            {
                //s is lower than g, increment it by u
                s += u;
            }
            else
            {
                //s + u is too high, lower it. Hopefully this either repeats a value or allows for further incrementation 
                s -= d;
            }
        }
        else if(s > g)
        {
            if((s - d) > 0)
            {
                //s is higher than g, decrement it by d
                s -= d;
            }
            else
            {
                //s - d is too low, increase it. Hopefully this either repeats a value or allows for further decrementation
                s += u;
            }
        }
    }
    //g was never found by going up u or down d so therefore path DNE
    return 0;
}

void printPath(int f, int s, int g, int u, int d)
{
    while(visited[s] != 1)
    {
        visited[s] = 1; //How to ensure it will eventually exit the while loop if path doesn't exist
        //While the node has not been visited...
        if(s == g)
        {
            printf("%d\n", s);
            return;
        }
        else if(s < g)
        {
            if((s + u) <= f)
            {
                //s is lower than g, increment it by u
                printf("%d -> ", s);
                s += u;
            }
            else
            {
                //s + u is too high, lower it. Hopefully this either repeats a value or allows for further incrementation
                printf("%d -> ", s);
                s -= d;
            }
        }
        else if(s > g)
        {
            if((s - d) > 0)
            {
                //s is higher than g, decrement it by d
                printf("%d -> ", s);
                s -= d;
            }
            else
            {
                //s - d is too low, increase it. Hopefully this either repeats a value or allows for further decrementation
                printf("%d -> ", s);
                s += u;
            }
        }
    }
}