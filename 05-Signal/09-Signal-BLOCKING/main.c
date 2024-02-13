#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
//#include <asm/signal.h>
//#include <asm-generic/signal.h>

#ifndef sigset_t
typedef unsigned long sigset_t; // Định nghĩa sigset_t nếu không được định nghĩa sẵn
#endif

//Không định nghĩa được sigset_t ??

void sig_handler(int num) {
    printf("hung2098 la nhat.\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv) {
    signal(SIGINT, sig_handler);
    sigset_t set;
    sigemptyset(&set);
    //sigaddset(&set);

    if (sigismember(&set, SIGINT)) {
        printf("SIGINT is blocked.\n");
    } else {
        printf("SIGINT is not blocked.\n");
        sigaddset(&set, SIGINT);
        sleep(2);
        if (sigismember(&set, SIGINT)) {
            printf("SIGINT is just blocked");
        }
    }

    while (1) {

    }

    return 0;
}