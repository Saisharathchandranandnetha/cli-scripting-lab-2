# Question 4 — Log Analysis & I/O Redirection

## 📝 Problem Statement

Perform server log analysis using Linux CLI tools. The task involves creating a log file using here-documents, filtering error entries with `grep`, redirecting filtered output to a report file, using pipes to combine commands, checking exit codes, and monitoring log files in real-time with `tail -f`.

---

## 🎯 Objectives

- Create files using here-documents (`cat > file << 'EOF'`)
- Filter log entries by severity level using `grep`
- Redirect output to files with `>` (overwrite)
- Append data to files with `>>` (append)
- Combine commands using pipes (`|`)
- Check command exit codes with `echo $?`
- Monitor files in real-time with `tail -f`

---

## 📂 Directory Structure

```
Question-4/
├── README.md
├── files/
│   ├── server.log              ← Server log with mixed severity levels
│   └── error_report.txt        ← Filtered ERROR entries
├── commands.txt
├── output.txt
└── screenshots/                ← Q4_1 through Q4_4B
```

---

## 📄 File Contents

### `files/server.log`
```
INFO Server started
INFO User logged in
ERROR Database connection failed
INFO Request processed
WARNING High memory usage
ERROR Authentication failed
ERROR Live server failure detected
```

### `files/error_report.txt` (generated)
```
ERROR Database connection failed
ERROR Authentication failed
```

---

## 🔧 Commands Used

### 1. Navigate and set up
```bash
cd /workspaces/cli-scripting-lab-2/Question-4
pwd
ls -la
```

### 2. Create the log file using here-document
```bash
cat > files/server.log << 'EOF'
INFO Server started
INFO User logged in
ERROR Database connection failed
INFO Request processed
WARNING High memory usage
ERROR Authentication failed
EOF
```

### 3. View the log file
```bash
cat files/server.log
```

### 4. Filter ERROR entries with grep
```bash
grep "ERROR" files/server.log
```

**Output:**
```
ERROR Database connection failed
ERROR Authentication failed
```

### 5. Redirect filtered output to report file
```bash
grep "ERROR" files/server.log > files/error_report.txt
cat files/error_report.txt
ls -l files/error_report.txt
```

### 6. Pipe: combine cat with grep
```bash
cat files/server.log | grep "ERROR"
```

### 7. Redirect grep output to /dev/null and check exit code
```bash
grep "ERROR" files/server.log > /dev/null
echo $?
```

**Output:** `0` (errors found — success exit code)

### 8. Append new entry to log file
```bash
echo "ERROR Live server failure detected" >> files/server.log
```

### 9. Monitor log file in real-time
```bash
tail -f files/server.log
```

---

## 🔄 I/O Redirection Summary

| Operator | Meaning | Example |
|----------|---------|---------|
| `>` | Redirect stdout (overwrite) | `grep "ERROR" log > report.txt` |
| `>>` | Redirect stdout (append) | `echo "new entry" >> log` |
| `2>` | Redirect stderr | `command 2> errors.log` |
| `\|` | Pipe stdout → stdin | `cat log \| grep "ERROR"` |
| `/dev/null` | Discard output | `grep "x" file > /dev/null` |
| `$?` | Last command exit code | `echo $?` → `0` (success) |

---

## 📸 Screenshots

| Screenshot | Description |
|------------|-------------|
| Q4_1.png | Directory setup, here-document creation, log file content |
| Q4_2.png | `grep "ERROR"`, redirection to `error_report.txt`, file verification |
| Q4_3.png | Pipe (`cat \| grep`), `/dev/null` redirection, exit code check |
| Q4_4A.png | `tail -f` monitoring the log file in real-time |
| Q4_4B.png | Appending a new error entry with `>>` |

---

## 💡 Key Concepts Demonstrated

| Concept | Tool / Technique |
|---------|------------------|
| File creation | Here-document (`<< 'EOF'`) |
| Pattern searching | `grep "PATTERN" file` |
| Output redirection | `>` (overwrite), `>>` (append) |
| Command piping | `cmd1 \| cmd2` |
| Exit code inspection | `$?` |
| Real-time file monitoring | `tail -f` |
| Output suppression | Redirect to `/dev/null` |
