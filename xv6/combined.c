#include "types.h"
#include "stat.h"
#include "user.h"

int main() 
{
    for (int i = 0; i < 4; i++) 
    {
        int pid = fork();

        if (pid  == 0) 
        { 
            if (i % 2)
            {
                char *args[] = {"image", 0};
                exec("image", args);
            }
            else
            { 
                char *args[] = {"mat_mul", 0};
                exec("mat_mul", args);
            }
            exit(); 
        }
        if (pid > 0)
        {   
            int wpid;
            while ((wpid = wait()) > 0);
        }
    }
    
    csc(getpid());
    gtat();
    exit();
}