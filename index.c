#include <stdio.h>
#include <signal.h>

volatile int stop = 0;

void interruptHandler(int signum) {
    if (signum == SIGINT) {
        stop = 1;
    }
}

int main() {
    char input;
    printf("Press Ctrl + C to quit:\n");

    signal(SIGINT, interruptHandler);

    while (!stop) {
        input = getchar();
        printf("You pressed: %c\n", input);
    }

    printf("Program terminated.\n");

    return 0;
}
