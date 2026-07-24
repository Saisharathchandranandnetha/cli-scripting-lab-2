# Question 3 — Low-Level File I/O: Employee Records

## 📝 Problem Statement

Write a C program that manages employee records using **low-level POSIX file I/O** system calls (`open`, `read`, `write`, `lseek`, `close`). The program creates a binary data file, writes employee structs, updates a specific record using `lseek()` for random access, and retrieves it back to verify the update.

---

## 🎯 Objectives

- Create files using `open()` with `O_CREAT | O_RDWR | O_TRUNC`
- Write structured binary data using `write()`
- Perform random-access updates using `lseek()` with `SEEK_SET`
- Read specific records using `read()` with file offset positioning
- Close file descriptors properly with `close()`
- Understand file permissions (`0644`)

---

## 📂 Directory Structure

```
Question-3/
├── README.md
├── src/
│   └── employee_records.c      ← Source code
├── employee_records            ← Compiled binary
├── files/
│   └── employees.dat           ← Binary data file (120 bytes)
├── commands.txt
├── output.txt
└── screenshots/                ← Q3_1 through Q3_5
```

---

## 📄 Source Code — `src/employee_records.c`

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main(void)
{
    int fd;

    /* Create/open the employee file */
    fd = open("files/employees.dat", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1) { perror("open"); return 1; }
    printf("File created successfully.\n");

    /* Initial employee records */
    struct Employee employees[] = {
        {101, "Arun",  35000},
        {102, "Priya", 42000},
        {103, "Rahul", 38000}
    };

    /* Write all records */
    ssize_t bytes_written = write(fd, employees, sizeof(employees));
    if (bytes_written == -1) { perror("write"); close(fd); return 1; }
    printf("Employee records written successfully.\n");
    printf("Bytes written: %ld\n", (long)bytes_written);

    /* Update employee 102's salary: 42000 → 50000 */
    struct Employee updated = {102, "Priya", 50000};
    lseek(fd, 1 * sizeof(struct Employee), SEEK_SET);
    write(fd, &updated, sizeof(updated));
    printf("Employee 102 updated using lseek().\n");

    /* Read back employee 102 to verify */
    struct Employee retrieved;
    lseek(fd, 1 * sizeof(struct Employee), SEEK_SET);
    read(fd, &retrieved, sizeof(retrieved));

    printf("\nRetrieved employee record:\n");
    printf("ID: %d\n", retrieved.id);
    printf("Name: %s\n", retrieved.name);
    printf("Salary: %.2f\n", retrieved.salary);

    close(fd);
    printf("\nFile closed successfully.\n");
    return 0;
}
```

---

## 🔧 Commands Used

### 1. Verify environment and directory
```bash
cd /workspaces/cli-scripting-lab-2/Question-3
pwd
ls -la
gcc --version
```

### 2. Edit/view the source code
```bash
nano src/employee_records.c
```

### 3. Compile and run
```bash
gcc -Wall -Wextra src/employee_records.c -o employee_records
./employee_records
```

### 4. Verify the data file
```bash
ls -lh files/employees.dat
```

**Expected Output:**
```
File created successfully.
Employee records written successfully.
Bytes written: 120
Employee 102 updated using lseek().

Retrieved employee record:
ID: 102
Name: Priya
Salary: 50000.00

File closed successfully.
```

---

## 🔄 Program Flow

```
1. open("files/employees.dat", O_CREAT | O_RDWR | O_TRUNC, 0644)
      │
2. write() ── 3 Employee structs (120 bytes total)
      │         [101, Arun, 35000]  [102, Priya, 42000]  [103, Rahul, 38000]
      │
3. lseek(fd, 1 * sizeof(Employee), SEEK_SET)
      │         ↑ Jump to byte offset 40 (second record)
      │
4. write() ── Overwrite record 102 → salary = 50000
      │
5. lseek(fd, 1 * sizeof(Employee), SEEK_SET)
      │         ↑ Jump back to second record
      │
6. read()  ── Retrieve updated record 102
      │
7. close(fd)
```

---

## 📊 Data Layout in `employees.dat`

| Offset (bytes) | Field | Record |
|----------------|-------|--------|
| 0 – 39 | Employee 101 | `{101, "Arun", 35000}` |
| 40 – 79 | Employee 102 | `{102, "Priya", 50000}` ← updated |
| 80 – 119 | Employee 103 | `{103, "Rahul", 38000}` |

Each `struct Employee` = `4 (int) + 30 (char[]) + 4 (float)` + padding = **40 bytes**

---

## 📸 Screenshots

| Screenshot | Description |
|------------|-------------|
| Q3_1.png | Directory listing and GCC version check |
| Q3_2.png | Initial compile — file created but empty (0 bytes) |
| Q3_3.png | Compile & run — records written (120 bytes) |
| Q3_4.png | Updated version — employee 102 updated via `lseek()` |
| Q3_5.png | Full output — retrieved record showing updated salary (50000.00) |

---

## 💡 Key Concepts Demonstrated

| Concept | System Call |
|---------|------------|
| File creation with permissions | `open(path, O_CREAT \| O_RDWR \| O_TRUNC, 0644)` |
| Binary struct writing | `write(fd, &struct, sizeof(struct))` |
| Random access file seeking | `lseek(fd, offset, SEEK_SET)` |
| Binary struct reading | `read(fd, &struct, sizeof(struct))` |
| File descriptor cleanup | `close(fd)` |
| Error handling | `perror()` on failure |
