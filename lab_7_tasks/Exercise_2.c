#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5;

    // Create first child (C1)
    pid1 = fork();
    if (pid1 == 0) {
        // Child process C1
        printf("C1: I am the first child of the parent, PID: %d, PPID: %d\n", getpid(), getppid());

        // Create child (C3) of C1
        pid3 = fork();
        if (pid3 == 0) {
            // Child process C3
            printf("C3: I am a child of C1, PID: %d, PPID: %d\n", getpid(), getppid());
            sleep(60); 
            exit(0);
        }

        sleep(60); 
        exit(0); 
    } else {
        // Create second child (C2)
        pid2 = fork();
        if (pid2 == 0) {
            // Child process C2
            printf("C2: I am the second child of the parent, PID: %d, PPID: %d\n", getpid(), getppid());

            // Create child (C4) of C2
            pid4 = fork();
            if (pid4 == 0) {
                // Child process C4
                printf("C4: I am a child of C2, PID: %d, PPID: %d\n", getpid(), getppid());
                sleep(60); 
                exit(0);
            }

            // Create child (C5) of C2
            pid5 = fork();
            if (pid5 == 0) {
                // Child process C5
                printf("C5: I am a child of C2, PID: %d, PPID: %d\n", getpid(), getppid());
                sleep(60); 
                exit(0);
            }

            sleep(60); 
            exit(0); 
        }
    }

    // Parent process sleeps to allow child processes to run
    printf("P0: I am the parent process, PID: %d\n", getpid());
    sleep(60);
    return 0;
}
