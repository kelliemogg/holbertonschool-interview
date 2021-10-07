#include "menger.h"

/**
* menger - function to produce a 2D menger sponge
* @level: level to be drawn
* Return: 2D 
*/

void menger(int level)
{
    if (level < 0)
        return;
    if (level == 0)
        printf("#\n");
    if (level == 1)
        printf("###\n# #\n###\n");
    if (level == 2)
    {
        printf("#########\n# ## ## #\n#########\n###   ###\n");
        printf("# #   # #\n###   ###\n#########\n# ## ## #\n#########\n");
    }
}
