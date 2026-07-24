# Question 5 — Vim Editor & Configuration Files

## 📝 Problem Statement

Demonstrate proficiency with the **Vim text editor** by creating and editing a server configuration file. The exercise covers file creation with `echo`, editing with Vim in different modes, understanding Vim swap (`.swp`) files, and verifying file contents.

---

## 🎯 Objectives

- Create configuration files using `echo` and `>` / `>>`
- Verify Vim installation and version
- Understand Vim's three main modes (Normal, Insert, Command-Line)
- Edit files using Vim
- Understand and identify Vim swap files (`.swp`, `.swo`, `.swn`)
- List hidden files with `ls -la`

---

## 📂 Directory Structure

```
Question-5/
├── README.md
├── files/
│   ├── server.conf             ← Configuration file
│   ├── .server.conf.swp        ← Vim swap file
│   ├── .server.conf.swo        ← Additional swap file
│   ├── .server.conf.swn        ← Additional swap file
│   └── .server.conf.swm        ← Additional swap file
├── commands.txt
├── output.txt
└── screenshots/                ← Q5_1 through Q5_4
```

---

## 📄 File Contents

### `files/server.conf`
```
server_port=8080
database=production
```

---

## 🔧 Commands Used

### 1. Navigate and verify Vim installation
```bash
cd /workspaces/cli-scripting-lab-2/Question-5
pwd
ls -la
vim --version | head
```

**Vim version:** VIM - Vi IMproved 9.1 (2024 Jan 02)

### 2. Create the configuration file
```bash
echo "server_port=8080" > files/server.conf
echo "database=production" >> files/server.conf
cat files/server.conf
```

**Output:**
```
server_port=8080
database=production
```

### 3. Edit with Vim
```bash
vim files/server.conf
```

### 4. List files including hidden swap files
```bash
ls -la files/
```

**Output shows swap files created by Vim:**
```
-rw-r--r--  1 codespace codespace 12288 .server.conf.swm
-rw-r--r--  1 codespace codespace 12288 .server.conf.swn
-rw-r--r--  1 codespace codespace 12288 .server.conf.swo
-rw-r--r--  1 codespace codespace 12288 .server.conf.swp
-rw-rw-rw-  1 codespace codespace    37 server.conf
```

---

## 📖 Vim Modes Reference

| Mode | How to Enter | Purpose |
|------|-------------|---------|
| **Normal** | `Esc` | Navigate, delete, copy, paste |
| **Insert** | `i`, `a`, `o` | Type and edit text |
| **Command-Line** | `:` | Save (`:w`), quit (`:q`), save & quit (`:wq`) |
| **Visual** | `v` | Select text for operations |

### Common Vim Commands

| Command | Action |
|---------|--------|
| `:w` | Save file |
| `:q` | Quit |
| `:wq` | Save and quit |
| `:q!` | Quit without saving |
| `i` | Enter insert mode at cursor |
| `a` | Enter insert mode after cursor |
| `o` | Open new line below and enter insert mode |
| `dd` | Delete current line |
| `yy` | Copy current line |
| `p` | Paste |
| `/pattern` | Search forward |
| `u` | Undo |

---

## 🔒 Vim Swap Files Explained

When Vim opens a file, it creates a **swap file** (`.swp`) to:

1. **Prevent concurrent editing** — warns if another Vim instance has the file open
2. **Enable crash recovery** — unsaved changes can be recovered from the swap file
3. **Track modifications** — records edit history for the session

| Swap File | Purpose |
|-----------|---------|
| `.server.conf.swp` | Primary swap file |
| `.server.conf.swo` | Created when `.swp` already exists (2nd session) |
| `.server.conf.swn` | Created when `.swo` already exists (3rd session) |
| `.server.conf.swm` | Created when `.swn` already exists (4th session) |

> **Note:** Multiple swap files indicate that Vim was opened multiple times without properly closing previous sessions. Recovery can be done with `vim -r filename`.

---

## 📸 Screenshots

| Screenshot | Description |
|------------|-------------|
| Q5_1.png | Directory listing, Vim version check, hidden files shown |
| Q5_2.png | File creation with `echo` and content verification |
| Q5_3.png | `ls -la files/` showing swap files alongside `server.conf` |
| Q5_4.png | Vim swap file recovery prompt showing multiple swap files |

---

## 💡 Key Concepts Demonstrated

| Concept | Tool / Technique |
|---------|------------------|
| File creation | `echo "content" > file` |
| File appending | `echo "content" >> file` |
| Text editing | `vim` (Normal, Insert, Command-Line modes) |
| Hidden file listing | `ls -la` |
| Swap file management | `.swp`, `.swo`, `.swn` files |
| Version checking | `vim --version \| head` |
| Crash recovery | `vim -r filename` |
