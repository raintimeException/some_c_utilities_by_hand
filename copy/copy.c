#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char buf[4096];

void copy(int fd_old, int fd_new)
{
    int count;

    while ((count = read(fd_old, buf, sizeof(buf))) > 0)
            write(fd_new, buf, count);
}

int main(int argc, char *const *argv)
{
    int fd_old, fd_new;

    if (argc != 3) {
        fprintf(stderr, "ERROR: copy needs two arguments\n");
        exit(EXIT_FAILURE);
    }
    fd_old = open(argv[1], O_RDONLY);
    if (fd_old == -1) {
        fprintf(stderr, "ERROR: cannot open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fd_new = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd_new == -1) {
        fprintf(stderr, "ERROR: cannot create file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    copy(fd_old, fd_new);
    close(fd_old);
    close(fd_new);
    exit(EXIT_SUCCESS);
}
