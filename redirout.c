#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc <2){
        printf("Usage: %s <file> <command> <opt1> <opt2> ...\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0){
        perror("open");
        return 1;
    }
    dup2(fd, 1);
    execvp(argv[2], &argv[2]+1);
    
        
}