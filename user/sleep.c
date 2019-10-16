#include "kernel/types.h" // User needs this file
#include "user/user.h"

int main(int argc, char *argv[])
{
        if (argc <= 1) {
                printf("You should give me some number\n");
                exit(0);
        }
        sleep(atoi(argv[1]));
        exit(0);
}