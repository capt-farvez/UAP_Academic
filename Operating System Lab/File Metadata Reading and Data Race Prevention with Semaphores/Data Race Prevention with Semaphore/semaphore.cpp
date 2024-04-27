#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>
using namespace std;

sem_t mutex; // Declaration of semaphore variable

int main(int argc, char *argv[]) {
    sem_init(&mutex, 1, 1); // Initializing the semaphore with initial value 1, indicating mutual exclusion. The second parameter '1' indicates that it's a semaphore used for process synchronization.
    int rc1 = fork();   // Creating first child process
    int rc2 = fork();   // Creating second child process
    sem_wait(&mutex);   // Acquiring the semaphore lock to enter the critical section

    // Printing process ID twice to show both child processes and their parent
    printf("printing from process id (pid = %d)\n", (int)getpid());
    printf("printing from process id (pid = %d)\n", (int)getpid());

    sem_post(&mutex);   // Releasing the semaphore lock, allowing other processes to enter the critical section
    return 0;
}
