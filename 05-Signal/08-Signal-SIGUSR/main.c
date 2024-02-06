#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sig_handler1(int num) {
    printf("Hung2098 la nhat.\n");
}

void sig_handler2(int num) {
    printf("Test SIGUSR1.\n");
}

void sig_handler3(int num) {
    printf("Test SIGUSR2.\n");
}

int main() {
    signal(SIGINT, sig_handler1);
    signal(SIGUSR1, sig_handler2);
    signal(SIGUSR2, sig_handler3);

    while(1) {

    }

    return 0;
}
