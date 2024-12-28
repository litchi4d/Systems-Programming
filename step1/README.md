# Step 1: learning Basic Linux Commands

### `cd`
**Change Directory**
- Use this command to navigate between directories.

**Usage:**
```bash
cd [directory_path]
```
**Example:**
```bash
cd /home/user/Documents
```
---

### `ls`
**List Files and Directories**
- Displays the contents of the current directory.

**Usage:**
```bash
ls [options]
```
**Example:**
```bash
ls -l   # Lists files in a detailed view
ls -a   # Includes hidden files
```
---

### `mkdir`
**Make Directory**
- Creates a new directory.

**Usage:**
```bash
mkdir [directory_name]
```
**Example:**
```bash
mkdir new_project
```
---

### `cp`
**Copy Files or Directories**
- Copies files or directories from one location to another.

**Usage:**
```bash
cp [source] [destination]
```
**Example:**
```bash
cp file.txt /home/user/Backup/
```
---

### `mv`
**Move or Rename Files**
- Moves files from one location to another or renames them.

**Usage:**
```bash
mv [source] [destination]
```
**Example:**
```bash
mv old_name.txt new_name.txt  # Rename a file
mv file.txt /home/user/Documents/  # Move a file
```
---

### `chmod`
**Change File Permissions**
- Modifies the access permissions of files and directories.

**File Permissions:**
1. **Read (r):** Value = 4
2. **Write (w):** Value = 2
3. **Execute (x):** Value = 1

**Groups:**
1. **User (u):** The owner of the file.
2. **Group (g):** Other users in the owner’s group.
3. **Others (o):** All other users.

**Usage:**
```bash
chmod [permissions] [file_name]
```
**Examples:**
```bash
chmod u+x script.sh  # Add execute permission to the user.
chmod 766 file.txt   # Assign rwx to user, rw to group and others.
```
---

### `grep`
**Search for Patterns in Files**
- Searches for specific substrings or patterns within files.

**Usage:**
```bash
grep [pattern] [file]
```
**Examples:**
```bash
grep "error" log.txt        # Find lines containing 'error' in log.txt
grep -r "TODO" ./project     # Recursively search for 'TODO' in the project directory
```
---

### `find`
**Search for Files and Directories**
- Finds files or directories based on name, type, or other attributes.

**Usage:**
```bash
find [path] [criteria]
```
**Examples:**
```bash
find /home/user -name "*.txt"    # Find all .txt files in the user's home directory
find . -type d                  # Find all directories in the current location
```
---