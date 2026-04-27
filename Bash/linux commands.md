## Linux Basic commands

# Linux Bash

# Linux Command Reference Guide

## File System Navigation

- `pwd` - Print working directory (current location)
- `ls` - List files and directories
    - `ls -la` - List all files (including hidden) with detailed information
    - `ls | grep 'Documents'` - List files/directories matching 'Documents'
- `cd` - Change directory
    - `cd ..` - Move to parent directory
    - `cd ~` - Move to home directory
    - `cd /path/to/directory` - Move to specific path
- `find` - Search for files
    - `find . -name "filename"` - Find file by name in current directory and subdirectories
    - `find /path -type f -name "*.txt"` - Find all .txt files in specified path

## File Operations

- `touch` - Create empty file or update timestamp
    - `touch filename.txt` - Create new empty file
    - `touch -m filename.txt` - Update file modification time
- `mkdir` - Create new directory
    - `mkdir -p path/to/new/directory` - Create directory with parent directories if needed
- `cp` - Copy files or directories
    - `cp source destination` - Copy file
    - `cp -r source_dir destination_dir` - Copy directory recursively
- `mv` - Move or rename files
    - `mv oldname newname` - Rename file
    - `mv file /path/to/destination/` - Move file to new location
- `rm` - Remove files or directories
    - `rm filename` - Delete file
    - `rm -r directory` - Delete directory and contents recursively
    - `rm -f filename` - Force delete without confirmation

## File Content

- `cat` - Display file contents
- `head` - Display first few lines of file
    - `head -n 20 filename` - Show first 20 lines
- `tail` - Display last few lines of file
    - `tail -f logfile` - Follow log file in real-time
- `less` - View file contents with pagination
- `grep` - Search for patterns in files
    - `grep -r "pattern" directory` - Search recursively
    - `grep -i "pattern" file` - Case-insensitive search
    - `grep -n "pattern" file` - Show line numbers
    - `grep -v "pattern" file` - Show lines NOT matching pattern
    - `grep -l "ERROR" *.log` - List only filenames containing matches

## File Permissions & Ownership

- `chmod` - Change file permissions
    - `chmod 755 file` - Set rwx for owner, rx for group and others
    - `chmod +x filename` - Make file executable
    - `chmod u+w file` - Add write permission for owner
- `chown` - Change file owner and group
    - `chown user:group filename` - Change owner and group

### Permission Numeric Values

- 4 - Read (r)
- 2 - Write (w)
- 1 - Execute (x)
- Common combinations:
    - 700 - Owner: rwx, Group: ---, Others: ---
    - 755 - Owner: rwx, Group: r-x, Others: r-x
    - 644 - Owner: rw-, Group: r--, Others: r--
    - 777 - Owner: rwx, Group: rwx, Others: rwx (use with caution)

## Process Management

- `ps` - Show running processes
    - `ps -ef` - Show all processes in full format
    - `ps -u username` - Show processes for specific user
    - `ps aux` - Show all processes with detailed info
- `top` - Display and manage running processes interactively
- `htop` - Enhanced interactive process viewer (may need installation)
- `kill` - Terminate process by PID
    - `kill -9 PID` - Force kill process
- `pkill` - Kill process by name
    - `pkill -u username` - Kill all processes by user
- `pidof` - Find PID of a program
    - `pidof program_name` - Get PIDs for a program
- `bg` - Continue suspended jobs in background
- `fg` - Bring background jobs to foreground
- `jobs` - List background jobs

## System Information

- `df` - Disk free space
    - `df -h` - Human-readable format
- `du` - Disk usage
    - `du -sh directory` - Summarize directory size in human-readable format
- `free` - Display memory usage
    - `free -h` - Human-readable format
- `uname -a` - Show system information
- `lsb_release -a` - Display Linux distribution info
- `uptime` - Show how long system has been running

## Compression & Archives

- `tar` - Tape archive utility
    - `tar -cf archive.tar files` - Create archive
    - `tar -xf archive.tar` - Extract archive
    - `tar -czf archive.tar.gz files` - Create compressed gzip archive
    - `tar -xzf archive.tar.gz` - Extract gzip archive
    - `tar -xvf file.tgz` - Extract and show files being extracted

## Network

- `ping` - Test network connectivity
- `ssh` - Secure shell remote login
    - `ssh user@hostname` - Connect to remote system
    - `ssh -yc user@ipaddr` - Connect with compression enabled and X11 forwarding
- `scp` - Secure copy
    - `scp file user@server:/path/` - Copy file to remote server
    - `scp user@server:/path/file .` - Copy file from remote server to current directory
- `ifconfig` or `ip addr` - Display network interfaces
- `netstat` or `ss` - Display network connections and routing tables
- `wget` or `curl` - Download files from web

## Package Management

### Debian/Ubuntu

- `apt update` - Update package lists
- `apt install package` - Install package
- `apt remove package` - Remove package
- `apt upgrade` - Upgrade all packages

### Red Hat/CentOS/Fedora

- `yum update` - Update package lists
- `yum install package` - Install package
- `yum remove package` - Remove package

## Shell Shortcuts & Tips

- `history` - Show command history
- `!!` - Repeat last command
- `ctrl + c` - Cancel/interrupt current command
- `ctrl + z` - Suspend current process
- `command & disown` - Run command in background and detach from terminal
- `command > file` - Redirect stdout to file
- `command >> file` - Append stdout to file
- `command 2> file` - Redirect stderr to file
- `command > file 2>&1` - Redirect both stdout and stderr to file
- `command1 | command2` - Pipe output of command1 as input to command2
- `alias name='command'` - Create command alias

## Clipboard Operations

- `command | xclip -selection clipboard` - Copy command output to clipboard (Linux with X11)
- `command | clip` - Copy command output to clipboard (on some systems)
- `cat ~/.file.txt | clip` - Copy file contents to clipboard

## Useful Combinations

- `grep -rn -i "error" . > result.txt` - Search recursively for "error" and save results
- `find . -type f -exec grep "pattern" {} \; -print` - Find files containing pattern
- `ps -ef | grep username` - Find processes for specific user
- `sudo find / -name "filename" 2>/dev/null` - Search entire system for file, hiding errors

Here’s a handy **Ubuntu CLI (Command Line Interface) Cheatsheet** to boost your terminal skills! 🚀

---

### **Basic Commands**

- `pwd` – Show current directory
- `ls` – List files and directories
    - `ls -l` (long format)
    - `ls -a` (include hidden files)
- `cd <directory>` – Change directory
    - `cd ..` (go up one level)
    - `cd -` (switch to the previous directory)
- `mkdir <dir>` – Create a directory
- `rmdir <dir>` – Remove an empty directory
- `rm <file>` – Delete a file
    - `rm -r <dir>` (delete directory & contents)
- `cp <source> <destination>` – Copy files
- `mv <source> <destination>` – Move/rename files
- `touch <file>` – Create an empty file

---

### **File Viewing & Editing**

- `cat <file>` – View file contents
- `less <file>` – View large files (scroll)
- `nano <file>` – Edit file with Nano
- `vim <file>` – Edit file with Vim
- `head <file>` – Show first 10 lines
- `tail <file>` – Show last 10 lines
    - `tail -f <file>` (live updates, useful for logs)

---

### **User & Permissions**

- `whoami` – Show current user
- `who` – Show logged-in users
- `chmod <mode> <file>` – Change permissions
    - `chmod 755 <file>` (read/write/execute for owner, read/execute for others)
- `chown <user>:<group> <file>` – Change file ownership

---

### **Processes & System Info**

- `ps aux` – Show running processes
- `top` / `htop` – Monitor system processes
- `kill <PID>` – Kill process by ID
    - `kill -9 <PID>` (force kill)
- `pkill <name>` – Kill process by name
- `free -h` – Check RAM usage
- `df -h` – Check disk usage
- `du -sh <dir>` – Check directory size

---

### **Networking**

- `ip a` – Show network interfaces
- `ping <host>` – Test network connection
- `curl <URL>` – Fetch a web page
- `wget <URL>` – Download a file
- `netstat -tulnp` – Show open ports
- `ss -tulnp` – Alternative to netstat

---

### **Package Management**

- `apt update` – Refresh package list
- `apt upgrade` – Upgrade installed packages
- `apt install <package>` – Install a package
- `apt remove <package>` – Remove a package
- `dpkg -i <file>.deb` – Install a local `.deb` package

---

### **Archives & Compression**

- `tar -cvf archive.tar <files>` – Create tar archive
- `tar -xvf archive.tar` – Extract tar archive
- `tar -czvf archive.tar.gz <files>` – Create tar.gz archive
- `tar -xzvf archive.tar.gz` – Extract tar.gz archive
- `zip -r archive.zip <files>` – Create zip archive
- `unzip archive.zip` – Extract zip archive

---

### **Searching**

- `grep "text" <file>` – Search text in file
- `grep -r "text" <directory>` – Search recursively
- `find <dir> -name "<pattern>"` – Find files
- `locate <file>` – Quickly find file locations
- `which <command>` – Find command location

---

### **Shortcuts**

- `Ctrl + C` – Kill current process
- `Ctrl + Z` – Suspend process
- `Ctrl + A` – Move to beginning of line
- `Ctrl + E` – Move to end of line
- `Ctrl + R` – Search command history
- `!!` – Repeat last command
- `!<command>` – Repeat last command starting with `<command>`

---

```
### How to create a symlink to a file
ln [-sf] [source] [destination]
Example:
``` bash
ln -s test_file.txt link_file.txt
```

### PATH environment
In Linux, the PATH environment variable is a system-wide variable that specifies a list of directories where executable files and scripts are located. When you enter a command in the terminal, the system searches these directories for the corresponding executable.

Here's how to work with the PATH environment variable in Linux:

1. **Viewing the PATH Variable:**
   
   To view the current value of the PATH variable, you can use the `echo` command:
   
   ```bash
   echo $PATH
   ```

2. **Modifying the PATH Variable:**
   
   To add a directory to the PATH variable, you can modify your shell's configuration file, such as `.bashrc` for Bash or `.zshrc` for Zsh. Open the appropriate file in a text editor (e.g., `nano`, `vi`, `gedit`) and add the following line, replacing `/your/directory/path` with the actual directory you want to add:
   
   ```bash
   export PATH=$PATH:/your/directory/path
   ```

   After making the changes, save and exit the file. To apply the changes, either log out and log back in, or source the file:
   
   ```bash
   source ~/.bashrc   # For Bash
   source ~/.zshrc    # For Zsh
   ```

3. **Removing a Directory from the PATH Variable:**

   To remove a directory from the PATH variable, edit the shell configuration file and remove the corresponding line that sets the PATH.

4. **Temporary Modification:**

   If you want to temporarily modify the PATH for the current session, you can use the `export` command directly in the terminal:
   
   ```bash
   export PATH=$PATH:/your/temporary/directory
   ```

   This change will be effective for the current session only.

5. **Checking for Executables:**

   To check if a particular executable is in the PATH, you can use the `which` command. For example:
   
   ```bash
   which executable_name
   ```

   Replace `executable_name` with the actual name of the executable you're looking for.

Keep in mind that modifying the PATH variable should be done with caution to ensure that the system can locate essential executables and scripts needed for its normal operation.

## CMAKE BASICS 
```
cmake [options] -S <path-to-source> -B <path-to-build>
```
path-to-source - should have CMakeLists.txt

path-to-build - is usually under build folder.

```
cmake
cd build
cmake -s ../ -B . 
cd ..
CMakeLists.txt
```


# Google Unit Test 
Example: https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/ 

wget https://github.com/google/googletest/archive/release-1.8.0.tar.gz

tar xzf release-1.8.0.tar.gz

cd googletest-release-1.8.0

```
mkdir build && cd build
cmake ..
make -j
``` 

Now, copy the headers to a directory where compilers can find them:
sudo cp -r ../googletest/include /usr/local/include

copy static libraries: 
sudo cp -r ./googlemock/gtest/libgtest*.a /usr/local/lib/

Additionally, you can also add googlemock library (C++ framework for mocking objects):
sudo cp -r ./googlemock/libgmock*.a /usr/local/lib/


