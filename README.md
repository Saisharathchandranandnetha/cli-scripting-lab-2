# CLI Scripting Lab 2

A collection of five hands-on exercises demonstrating essential **Linux CLI**, **shell scripting**, and **systems programming** concepts. Each question is self-contained in its own directory with source code, sample data files, command references, output logs, and terminal screenshots.

---

## 📋 Table of Contents

| # | Topic | Key Concepts |
|---|-------|--------------|
| [Question 1](Question-1/) | File Management & Duplicate Detection | `ls`, `cat`, `sha256sum`, `cp`, file comparison, I/O redirection, report generation |
| [Question 2](Question-2/) | Process Management — Web Server Monitor | `fork()`, `waitpid()`, `kill()`, `SIGTERM`, zombie process prevention, GCC compilation |
| [Question 3](Question-3/) | Low-Level File I/O — Employee Records | `open()`, `read()`, `write()`, `lseek()`, `close()`, binary struct I/O, file descriptors |
| [Question 4](Question-4/) | Log Analysis & I/O Redirection | `grep`, `cat`, `tail -f`, `echo`, `>`, `>>`, pipe (`\|`), exit codes, here-documents |
| [Question 5](Question-5/) | Vim Editor & Configuration Files | `vim`, insert/command/last-line modes, `.swp` swap files, `echo`, file creation |

---

## 🗂️ Project Structure

```
cli-scripting-lab-2/
├── README.md               ← You are here
├── Question-1/             ← File management & duplicate detection
│   ├── src/                ← (scripts, if any)
│   ├── files/              ← Student submission files
│   ├── backup/             ← Unique files backed up here
│   ├── errors.log          ← Redirected stderr output
│   ├── report.txt          ← Processing summary report
│   ├── screenshots/        ← Terminal screenshots (Q1_1 – Q1_7)
│   └── README.md
├── Question-2/             ← Process monitoring (C program)
│   ├── src/                ← process_monitor.c
│   ├── process_monitor     ← Compiled binary
│   ├── screenshots/        ← Terminal screenshots (Q2_1 – Q2_5)
│   └── README.md
├── Question-3/             ← Employee records (C program)
│   ├── src/                ← employee_records.c
│   ├── files/              ← employees.dat (binary data file)
│   ├── employee_records    ← Compiled binary
│   ├── screenshots/        ← Terminal screenshots (Q3_1 – Q3_5)
│   └── README.md
├── Question-4/             ← Log analysis & I/O redirection
│   ├── files/              ← server.log, error_report.txt
│   ├── screenshots/        ← Terminal screenshots (Q4_1 – Q4_4B)
│   └── README.md
└── Question-5/             ← Vim editor & config files
    ├── files/              ← server.conf, .swp files
    ├── screenshots/        ← Terminal screenshots (Q5_1 – Q5_4)
    └── README.md
```

---

## 🛠️ Prerequisites

- **Linux / macOS** terminal (or WSL on Windows)
- **GCC** compiler (`gcc --version` ≥ 13.x recommended)
- **Vim** editor (`vim --version`)
- Standard POSIX utilities: `ls`, `cat`, `grep`, `sha256sum`, `find`, `wc`, `tail`, `cp`, `echo`

---

## 🚀 How to Use

1. **Clone the repository**
   ```bash
   git clone https://github.com/Saisharathchandranandnetha/cli-scripting-lab-2.git
   cd cli-scripting-lab-2
   ```

2. **Navigate to any question**
   ```bash
   cd Question-1   # or Question-2, Question-3, etc.
   ```

3. **Read the question-level README** for detailed instructions, commands used, and expected output.

4. **For C programs (Q2 & Q3)**, compile and run:
   ```bash
   gcc -Wall -Wextra src/<source_file>.c -o <output_binary>
   ./<output_binary>
   ```

---

## 📸 Screenshots

Each question directory contains a `screenshots/` folder with annotated terminal captures showing every step of the exercise execution.

---

## 👤 Author

**Saisharathchandranandnetha**

---

## 📄 License

This project is for educational purposes as part of a CLI Scripting Lab assignment.