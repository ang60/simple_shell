#include "main.h"

/**
* main - main function
* @ac: - argument counter
* @av: - argument vector
* @env: - enviromental variable
* Return: 0 - success.
*/

int main(int ac, char **av, char **env)
{
    if (ac == 1)
    {
        turtleShell(av, env);
    }
    return (0);
}
