#include "kernel/types.h" // User needs this file
#include "user/user.h"

int main(int argc, char *argv[])
{
        int pipe_father_son[2];
        int pipe_son_father[2];
        pipe(pipe_father_son);
        pipe(pipe_son_father);
        if (fork() == 0) { //Son
                char buf[5];
                close(pipe_father_son[1]);
                read(pipe_father_son[0], buf, 5);
                close(pipe_father_son[0]);
                printf("%d: received %s\n", getpid(), buf);
                close(pipe_son_father[0]);
                write(pipe_son_father[1], "pong", 4);
                close(pipe_son_father[1]);
        } else { //Father
                close(pipe_father_son[0]);
                write(pipe_father_son[1], "ping", 4);
                close(pipe_father_son[1]);
                close(pipe_son_father[1]);
                char buf[5];
                read(pipe_son_father[0], buf, 5);
                printf("%d: received %s\n", getpid(), buf);
                close(pipe_son_father[0]);
        }
        exit(0);
}