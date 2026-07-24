# Question 2 — Process Management: Web Server Monitor

## 📝 Problem Statement

Write a C program that simulates a web server process monitor. The program uses `fork()` to create a child process, monitors it with a non-blocking `waitpid()`, and terminates an unresponsive child using `SIGTERM` — properly reaping it to prevent zombie processes.

---

## 🎯 Objectives

- Create child processes using `fork()`
- Monitor child status with non-blocking `waitpid(WNOHANG)`
- Terminate unresponsive processes with `kill()` and `SIGTERM`
- Prevent zombie processes by reaping terminated children
- Compile C programs with GCC using `-Wall -Wextra` flags

---

## 📂 Directory Structure

```
Question-2/
├── README.md
├── src/
│   └── process_monitor.c      ← Source code
├── process_monitor             ← Compiled binary
├── commands.txt
├── output.txt
└── screenshots/                ← Q2_1 through Q2_5
```

---

## 📄 Source Code — `src/process_monitor.c`

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(void)
{
    printf("Web server process monitor started.\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child process started: PID=%d\n", getpid());
        sleep(10);  /* Simulate long-running/unresponsive child */
        printf("Child process completed: PID=%d\n", getpid());
        return 0;
    }

    printf("Parent created child: PID=%d\n", pid);

    int status;
    pid_t result = waitpid(pid, &status, WNOHANG);

    if (result == 0) {
        printf("Child process is still running.\n");
        printf("Waiting before terminating unresponsive child...\n");
        sleep(3);
        printf("Sending SIGTERM to child PID=%d\n", pid);

        if (kill(pid, SIGTERM) == -1) {
            perror("kill");
            return 1;
        }

        waitpid(pid, &status, 0);  /* Reap to prevent zombie */
        printf("Child process terminated and collected successfully.\n");
    } else if (result == pid) {
        printf("Child process finished and was collected.\n");
    } else {
        perror("waitpid");
        return 1;
    }

    return 0;
}
```

---

## 🔧 Commands Used

### 1. Verify GCC and directory setup
```bash
cd /workspaces/cli-scripting-lab-2/Question-2
pwd
gcc --version
ls -la
```

### 2. View/edit the source code
```bash
nano src/process_monitor.c
cat src/process_monitor.c
```

### 3. Compile with warnings enabled
```bash
gcc -Wall -Wextra src/process_monitor.c -o process_monitor
ls -l process_monitor
```

### 4. Run the program
```bash
./process_monitor
```

**Expected Output:**
```
Web server process monitor started.
Parent created child: PID=22216
Child process started: PID=22216
Child process is still running.
Waiting before terminating unresponsive child...
Sending SIGTERM to child PID=22216
Child process terminated and collected successfully.
```

---

## 🔄 Program Flow

```
Parent Process
    │
    ├── fork() ──────────────────► Child Process
    │                                  │
    │   waitpid(WNOHANG)              sleep(10)  ← simulates unresponsive
    │   → returns 0 (still running)    │
    │                                  │
    │   sleep(3)  ← grace period       │
    │                                  │
    │   kill(pid, SIGTERM) ──────────► Child terminated
    │                                  │
    │   waitpid(pid, 0) ←───────────── Reaped (no zombie)
    │
    └── Exit
```

---

## 📸 Screenshots

| Screenshot | Description |
|------------|-------------|
| Q2_1.png | Directory listing, GCC version check |
| Q2_2.png | Source code displayed via `cat` |
| Q2_3.png | Compilation & first run (child completes immediately) |
| Q2_4.png | Second run showing process execution |
| Q2_5.png | Final run — child monitored, SIGTERM sent, reaped successfully |

---

## 💡 Key Concepts Demonstrated

| Concept | System Call / Signal |
|---------|---------------------|
| Process creation | `fork()` |
| Process ID retrieval | `getpid()` |
| Non-blocking wait | `waitpid(pid, &status, WNOHANG)` |
| Blocking wait (reap) | `waitpid(pid, &status, 0)` |
| Signal-based termination | `kill(pid, SIGTERM)` |
| Zombie prevention | Reaping with `waitpid()` after `kill()` |
| Compilation flags | `gcc -Wall -Wextra` |
