#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
int main()
{
printf("Hello");
kill(getpid(), 9);
printf("Goodbye");
}