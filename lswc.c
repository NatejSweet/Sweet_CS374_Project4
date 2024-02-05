#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int pfd[2]; 
    pipe(pfd);
    int pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    
    if (pid == 0) {
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        execlp("wc", "wc","-l",(char *) NULL);
        exit(0);

    }else{
        close(pfd[0]); 
        dup2(pfd[1], 1);
        execlp("ls", "ls", "-1a",(char *) NULL);
        exit(0);

    }
        
}