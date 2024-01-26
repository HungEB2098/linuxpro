/*
BT5. Viết một chương trình A tạo ra một tiến trình con B
rồi in ra PID và PPID của chúng.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char* argv[]) { /* Cấp phát stack frame cho hàm main() */
    pid_t child_pid; /* Lưu trong stack frame của main() */
    int counter = 2;  /* Lưu trong frame của main() */

    child_pid = fork();
    if (child_pid >= 0) {
        if (child_pid == 0) {
            printf("This is a child process.\n");
            printf("My PID and my parent's PID are: %d and %d.\n", getpid(),getppid());
        } else {
        printf("This is a parent process.\n");
        printf("Parent's PID is: %d.\n", getpid());
        }
    } else {
        printf(" fork() unsuccessfully.\n");
    } 
    
    return 0;
}

