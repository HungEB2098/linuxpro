/*
Viết một chương trình A tạo ra một tiến trình con B, 
in ra PID và PPID của chúng.  Sử dụng system waitpid() 
để lấy được trạng thái kết thúc của tiến trình con B.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]) {
    pid_t child_pid;
    child_pid = fork();
    int status;

    if (child_pid >= 0) {
        if (child_pid == 0) {

            printf("This is child process.\n");
            printf("Child PID and parent's PID are: %d and %d\n", getpid(), getppid());
        
        } else if (child_pid > 0) {

            printf("This is a parent process.\n");
            printf("Child PID and parent's PID are: %d and %d\n", getpid(), getppid());
            waitpid(child_pid, &status, 0);
            
            if (WIFEXITED(status) == 1) {
                printf("Child process was normally terminated, status = %d.\n", WIFEXITED(status));
            } else if (WIFSIGNALED(status) == 1) {
                printf("Child process was terminated by signal, value = %d.\n", WTERMSIG(status));
            } 
        }

    } else {
        printf("Fork() unsuccessfully.\n");
    }

    close(child_pid);
    return 0;
}