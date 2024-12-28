# File Operations in C Using System Calls

This program demonstrates file operations in C using low-level system calls like `open`, `read`, `write`, `close`, and `creat`. It explores file descriptors, file flags, and permissions.

---

## Key Concepts

### 1. **Kernel and File Descriptors**
- The kernel is an interface between hardware and software.
- The kernel maintains a list of open files using integers called file descriptors:
  - `stdin`: 0
  - `stdout`: 1
  - `stderr`: 2

### 2. **`open()` System Call**
- A lower-level alternative to `fopen`.
- Returns a file descriptor (an integer) instead of a `FILE*` pointer.
- Often used for unbuffered I/O or when interacting with devices like pipes or serial ports.
- Accepts **flags**:
  - `O_RDONLY`: Open in read-only mode.
  - `O_WRONLY`: Open in write-only mode.
  - `O_RDWR`: Open in read-write mode.

### 3. **File Permissions**
- Permissions are set using `mode_t`, a bitmask.
  - Example: `S_IRUSR | S_IWUSR | S_IXUSR` (Read + Write + Execute for user).
  - Alternatively, use octal values: `0744`.

---