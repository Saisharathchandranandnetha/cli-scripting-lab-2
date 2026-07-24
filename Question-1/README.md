# Question 1 — File Management & Duplicate Detection

## 📝 Problem Statement

Simulate a student assignment submission system using Linux CLI commands. The task involves managing student submission files, detecting duplicate submissions using SHA-256 checksums, backing up unique files, generating a summary report, and handling errors with I/O redirection.

---

## 🎯 Objectives

- Navigate directories and list files with detailed metadata
- View file contents using `cat`
- Compute SHA-256 checksums to detect duplicate submissions
- Copy only unique files to a backup directory
- Generate a processing report with file counts
- Redirect errors to a log file using `2>`

---

## 📂 Directory Structure

```
Question-1/
├── README.md
├── files/                  ← Student submission files
│   ├── student1.txt        → "Student A Assignment"
│   ├── student2.txt        → "Student B Assignment"
│   ├── student3.txt        → "Student A Assignment"  (duplicate of student1)
│   ├── student4.txt        → "Student C Assignment"
│   └── student5.txt        → "Student B Assignment"  (duplicate of student2)
├── backup/                 ← Only unique files backed up here
│   ├── student1.txt        → "Student A Assignment"
│   ├── student2.txt        → "Student B Assignment"
│   └── student4.txt        → "Student C Assignment"
├── report.txt              ← Summary report
├── errors.log              ← Redirected stderr
├── commands.txt
├── output.txt
├── src/
└── screenshots/            ← Q1_1 through Q1_7
```

---

## 🔧 Commands Used

### 1. Navigate and list files
```bash
cd /workspaces/cli-scripting-lab-2/Question-1
pwd
ls -la
ls -l files/
```

### 2. View file contents
```bash
cat files/student1.txt
cat files/student2.txt
cat files/student3.txt
cat files/student4.txt
cat files/student5.txt
```

### 3. Detect duplicates with SHA-256 checksums
```bash
sha256sum files/*.txt | sort
```

**Output** — identical hashes reveal duplicates:
```
194efa60bdb089996c62b7957e2f833b...  files/student1.txt
194efa60bdb089996c62b7957e2f833b...  files/student3.txt   ← duplicate
59073f202ea676fa373f7815dc7ab861...  files/student2.txt
59073f202ea676fa373f7815dc7ab861...  files/student5.txt   ← duplicate
a7f90f73af9a13fbe3ea03dd48b4f47b...  files/student4.txt   ← unique
```

### 4. Back up unique files
```bash
cp files/student1.txt backup/
cp files/student2.txt backup/
cp files/student4.txt backup/
```

### 5. Verify backup
```bash
ls -l backup/
cat backup/student1.txt
cat backup/student2.txt
cat backup/student4.txt
```

### 6. Generate processing report
```bash
echo "Total files processed:"
find files -type f | wc -l

echo "Unique files backed up:"
find backup -type f | wc -l

echo "Duplicate files:"
echo 2
```

### 7. Write report to file & view
```bash
cat report.txt
```

**Report content:**
```
Submission Processing Report
Files processed: 5
Duplicate files: 2
Files backed up: 3
```

### 8. Error redirection
```bash
ls files/nonexistent.txt 2> errors.log
cat errors.log
```

**errors.log content:**
```
ls: cannot access 'files/nonexistent.txt': No such file or directory
```

---

## 📸 Screenshots

| Screenshot | Description |
|------------|-------------|
| Q1_1.png | Directory listing (`ls -la`) |
| Q1_2.png | File contents and listing of `files/` |
| Q1_3.png | SHA-256 checksums sorted to reveal duplicates |
| Q1_4.png | Backup directory contents verification |
| Q1_5.png | File count summary (processed / backed up / duplicates) |
| Q1_6.png | Report file content and metadata |
| Q1_7.png | Error log content and metadata |

---

## 💡 Key Concepts Demonstrated

| Concept | Commands |
|---------|----------|
| File listing with metadata | `ls -la`, `ls -l` |
| File content viewing | `cat` |
| Checksum-based duplicate detection | `sha256sum`, `sort` |
| File copying | `cp` |
| Counting files | `find -type f \| wc -l` |
| Standard error redirection | `2>` |
| Report generation | `echo`, output redirection |
