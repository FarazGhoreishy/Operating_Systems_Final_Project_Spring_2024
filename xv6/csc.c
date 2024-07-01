#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(2, "Wrong arguments...\n");
        exit();
    }

    csc(atoi(argv[1]));
    exit();
}