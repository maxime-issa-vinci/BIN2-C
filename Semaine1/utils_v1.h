#ifndef _UTILS_H_
#define _UTILS_H_

/// Module à compiler avec les feature test macros suivantes, selon la machine:
/// (cf. man 7 feature_test_macros)
///
///    -D_DEFAULT_SOURCE
///
/// OU si _DEFAULT-SOURCE n'est pas définie:
///
///    -D_BSD_SOURCE -D_SVID_SOURCE -D_POSIX_C_SOURCE=200809

#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/ipc.h>
#include <poll.h>

//******************************************************
// LECTURE CLAVIER
//******************************************************

int readLimitedLine(char* s, int sz);

char* readLine(void);

//******************************************************
// AFFICHAGE DE MESSAGES EN COULEUR
//******************************************************

enum {
    BLACK_TEXT = 30,
    RED_TEXT,
    GREEN_TEXT,
    YELLOW_TEXT,
    BLUE_TEXT,
    PURPLE_TEXT,
    CYAN_TEXT,
    WHITE_TEXT
};

#define colorOn(mode, textColor) printf("\033[%d;%dm", mode, textColor)
#define colorOff() printf("\033[0m")

void printOk(char* s);
void printError(char* s);
void printColor(char* format, char* s, int color);

//******************************************************
// DATE AND TIME
//******************************************************

char* getTime(void);

//******************************************************
// RANDOM INTEGER
//******************************************************

int randomIntBetween(int valMin, int valMax);

//*****************************************************************************
// Safe SYSCALL functions
//*****************************************************************************

void* smalloc(size_t size);

void checkCond(bool cond, char* msg);
void checkNeg(int res, char* msg);
void checkNull(void* res, char* msg);

//*****************************************************************************
// FORK
//*****************************************************************************

pid_t sfork(void);

pid_t fork_and_run0(void (*run)(void));

pid_t fork_and_run1(void (*run)(void*), void* arg0);

pid_t fork_and_run2(void (*run)(void*, void*), void* arg0, void* arg1);

pid_t fork_and_run3(void (*run)(void*, void*, void*), void* arg0, void* arg1, void* arg2);

pid_t swaitpid(pid_t pid, int* wstatus, int options);

pid_t swait(int* wstatus);

int sexecl(const char* path, const char* arg, ...);

//*****************************************************************************
// IO
//*****************************************************************************

int sopen(const char* pathname, int flags, mode_t mode);

int sclose(int fd);

ssize_t sread(int fd, void* buf, size_t count);

ssize_t swrite(int fd, const void* buf, size_t count);

void nwrite(int fd, const void* buf, size_t count);

int readLimitedLineOnFile(int fd, char* s, int sz);

//*****************************************************************************
// PIPE
//*****************************************************************************

int spipe(int pipefd[2]);

//*****************************************************************************
// SIGNAL
//*****************************************************************************

void ehandler(int signum);

void ssigaction(int signum, void (*handler)(int));

void ssigemptyset(sigset_t* set);

void ssigfillset(sigset_t* set);

void ssigaddset(sigset_t* set, int signum);

void ssigdelset(sigset_t* set, int signum);

void ssigprocmask(int how, const sigset_t* set, sigset_t* oldset);

void skill(pid_t pid, int signum);

void ssigpending(sigset_t* set);

//******************************************************************************
// SHARED MEMORY
//******************************************************************************

int sshmget(key_t key, size_t size, int shmflg);

void* sshmat(int shm_id);

void sshmdt(const void* shmaddr);

void sshmdelete(int shm_id);

//******************************************************************************
// SEMAPHORES
//******************************************************************************

union semun {
   int              val;
   struct semid_ds* buf;
   unsigned short*  array;
   struct seminfo*  __buf;
};

int sem_create(key_t key, int nsems, int perm, int val);

int sem_get(key_t key, int nsems);

void sem_down(int sem_id, int sem_num);

void sem_down0(int sem_id);

void sem_up(int sem_id, int sem_num);

void sem_up0(int sem_id);

void sem_delete(int sem_id);

//******************************************************************************
// Sockets
//******************************************************************************

int ssocket(void);

int sconnect(char* serverIP, int serverPort, int sockfd);

int sbind(int port, int sockfd);

int slisten(int sockfd, int backlog);

int saccept(int sockfd);

void hostname_to_ip(char* hostname, char* ip);

int spoll(struct pollfd* fds, nfds_t nfds, int timeout);

#endif  // _UTILS_H_
