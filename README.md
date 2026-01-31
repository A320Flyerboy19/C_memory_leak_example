# C Memory Leak Demonstration Program

⚠️ **EDUCATIONAL PROJECT - DANGEROUS IF MISUSED** ⚠️

A C program designed to demonstrate memory leaks and their effects on system resources. This program **intentionally** creates severe memory leaks to help students understand memory management concepts and the consequences of improper memory handling.

## 🎓 Educational Purpose

This program was created as a learning tool for:

- Understanding what memory leaks are and how they occur
- Visualizing real-time memory consumption
- Learning proper memory management practices (by seeing what NOT to do)
- Understanding system resource limitations
- Practicing safe C programming habits

## 🚀 Getting Started

### Prerequisites

- GCC compiler (or any C compiler)
- Terminal/Command Prompt access
- **8+ GB RAM recommended**
- System monitor access (Activity Monitor/Task Manager)

### Clone the Repository

```bash
# Clone the repository
git clone https://github.com/A320Flyerboy19/C_memory_leak_example.git

# Navigate into the directory
cd C_memory_leak_example
```

### Compile the Program

```bash
# Basic compilation
gcc -o memory_leak memory_leak.c

# Or with warnings (recommended for learning)
gcc -Wall -Wextra -o memory_leak memory_leak.c

# With debugging symbols (for use with Valgrind)
gcc -g -o memory_leak memory_leak.c
```

### Your First Run (Safe Mode)

⚠️ **Before running, read the safety warnings below!**

```bash
# 1. Open your system monitor FIRST
#    macOS: Activity Monitor (Applications → Utilities)
#    Windows: Task Manager (Ctrl+Shift+Esc)
#    Linux: System Monitor or run 'htop'

# 2. Run the program (Option 1 is default - safest)
./memory_leak

# 3. Watch memory usage climb in your system monitor

# 4. Press Ctrl+C to stop when you've seen enough
```

### Expected Output

```
Creating memory leak...
Watch your system monitor (Task Manager/Activity Monitor)
⚠️  Press Ctrl+C at ANY TIME to stop and exit!

Leaked 0.01 GB so far... (Press Ctrl+C to stop)
Leaked 0.02 GB so far... (Press Ctrl+C to stop)
Leaked 0.03 GB so far... (Press Ctrl+C to stop)
...
⚠️  WARNING: 0.5 GB leaked!
Leaked 0.51 GB so far... (Press Ctrl+C to stop)
...
⚠️  WARNING: 1.0 GB leaked!
...

[Press Ctrl+C here]

🛑 Program interrupted! Exiting immediately...
Note: Memory will be freed by the operating system.
```

## ⚠️ CRITICAL SAFETY WARNING

### **THIS PROGRAM IS DANGEROUS**

This is **NOT** a normal program. It is specifically designed to consume system memory aggressively and can cause:

- ❌ System crashes and freezes
- ❌ Data loss in other running applications
- ❌ Forced system reboots
- ❌ Disk thrashing (excessive swap usage)
- ❌ Temporary system unresponsiveness
- ❌ Potential corruption of unsaved work

**DO NOT RUN THIS PROGRAM** unless you:

1. ✅ Fully understand the risks
2. ✅ Have saved ALL work in other applications
3. ✅ Have closed unnecessary programs
4. ✅ Are monitoring system memory usage
5. ✅ Are prepared to force-quit or reboot if necessary

## 🚨 Before Running - Required Precautions

### Mandatory Steps

1. **Save Everything**: Save all open documents, code, and work
2. **Close Applications**: Close browsers, IDEs, and memory-intensive apps
3. **Open System Monitor**:
   - **macOS**: Activity Monitor (Applications → Utilities)
   - **Windows**: Task Manager (Ctrl+Shift+Esc)
   - **Linux**: System Monitor or `htop`
4. **Know Your RAM**: Check your system's total RAM capacity
5. **Read Instructions**: Understand how to stop the program (Ctrl+C)

### System Requirements

- **Minimum**: 8 GB RAM (use only Option 1)
- **Recommended**: 16+ GB RAM
- **For Option 3**: 32+ GB RAM (NOT recommended for learning)

## 🎮 Usage Options

The program has **THREE** modes of operation. Only one can be active at a time.

### Option 1: Slow Leak (DEFAULT - RECOMMENDED) ✅

**Rate**: 10 MB per second (600 MB per minute)

```bash
# Already active by default - just compile and run
./memory_leak
```

**Safe for learning** - Gives you plenty of time to observe and stop.

**Recommended stop points**:

- **8 GB system**: Stop at 2-3 GB leaked (~3-5 minutes)
- **16 GB system**: Stop at 5-7 GB leaked (~8-12 minutes)
- **32 GB system**: Stop at 10-15 GB leaked (~17-25 minutes)

---

### Option 2: Medium Leak (ADVANCED) ⚠️

**Rate**: 100 MB per second (6 GB per minute)

**To activate Option 2:**

1. Open `memory_leak.c` in a text editor
2. **Comment out** the Option 1 loop (lines 60-88):

```c
   /*
   for (int i = 0; i < 999999; i++)
   {
       // ... Option 1 code ...
   }
   */
```

3. **Uncomment** the Option 2 loop (lines 95-118)
4. Recompile: `gcc -o memory_leak memory_leak.c`
5. Run: `./memory_leak`

⚠️ **More aggressive** - Less reaction time available. System can fill up in minutes.

---

### Option 3: Extreme Leak (DANGEROUS - NOT RECOMMENDED) 🚨💀

**Rate**: 166 MB per second (10 GB per minute)

### **🚨 EXTREME DANGER - READ CAREFULLY 🚨**

This option is **highly dangerous** and can crash your system in minutes.

**DO NOT USE unless:**

- You have 32+ GB RAM
- All work is saved and apps are closed
- You are an advanced user who understands the risks
- You have a specific reason to test extreme memory exhaustion

**To activate Option 3:**

1. Comment out Option 1
2. Uncomment Option 3 loop (lines 198-229)
3. **READ ALL WARNINGS IN THE CODE**
4. Recompile and run **at your own risk**

**Timeline for 16 GB system**:

```
Time        Leaked    Status
30 sec      5 GB      ⚠️  Warning
60 sec      10 GB     🚨 Critical
90 sec      15 GB     ☠️  SYSTEM FAILURE LIKELY
```

**Seriously, stick with Option 1 for learning!**

## 🛑 How to Stop the Program

### Normal Exit (Recommended)

Press **Ctrl+C** in the terminal at any time. The program will catch the signal and exit gracefully.

```bash
# You'll see this output:
🛑 Program interrupted! Exiting immediately...
Note: Memory will be freed by the operating system.
```

### Emergency Stop (If System Freezes)

**macOS**:

1. Open Activity Monitor
2. Find the process name `memory_leak`
3. Click the X button (top left)
4. Click "Force Quit"

**Windows**:

1. Open Task Manager (Ctrl+Shift+Esc)
2. Find `memory_leak.exe` in the Processes tab
3. Right-click → "End Task"

**Linux**:

```bash
# Find the process ID
ps aux | grep memory_leak

# Kill the process (replace [PID] with actual process ID)
kill -9 [PID]

# Or use pkill
pkill memory_leak
```

### Last Resort: Hard Reboot

If your system becomes completely unresponsive:

- Hold the power button for 5-10 seconds until the system shuts down
- Wait a few seconds, then power back on
- **This should be your LAST option as it may cause data loss**

## 📊 Monitoring Memory Usage

### What to Watch

**Memory Pressure** (macOS Activity Monitor):

- 🟢 **Green**: Safe - system has plenty of free memory
- 🟡 **Yellow**: Warning - consider stopping soon
- 🔴 **Red**: DANGER - stop immediately!

**Memory Used** (Windows Task Manager):

- Monitor the "Memory" column percentage
- If it exceeds 80%, **stop the program**

**Available Memory**:

- Keep at least 20-30% of total RAM free
- If available memory drops below 2 GB, **STOP**

**Swap Usage**:

- If swap/page file starts being used heavily, **STOP**
- Excessive swapping = severe performance degradation
- Your system will become very slow

### Warning Signs to Stop Immediately

- 🚨 System becomes noticeably slow
- 🚨 Mouse/cursor starts lagging
- 🚨 Other applications freeze or crash
- 🚨 Memory pressure turns yellow or red
- 🚨 Available memory drops below 2-3 GB
- 🚨 Swap usage spikes significantly

## 🧪 Testing Information

This program was tested on:

- **System**: macOS with 128 GB RAM
- **Initial State**: 42.22 GB used, 85.78 GB available
- **Test Duration**: Up to 7 minutes (70 GB leaked)
- **Result**: System remained stable but memory pressure increased significantly

### Option 3 Timeline (128 GB System - For Reference Only)

```
Time     Total Used    Leaked    Status
------   ----------    ------    ------
1 min    52 GB        10 GB     ✅ Safe
2 min    62 GB        20 GB     ✅ Safe
3 min    72 GB        30 GB     ⚠️  Getting high
4 min    82 GB        40 GB     ⚠️  Caution zone
5 min    92 GB        50 GB     🚨 Danger zone
6 min    102 GB       60 GB     💀 System stress
7 min    112 GB       70 GB     ☠️  Very risky
12.8min  128 GB       86 GB     ⚡ SYSTEM FAILURE
```

**Note**: Your system will likely fail much sooner if you have less RAM!

## 🐛 Detecting Memory Leaks with Valgrind

To properly analyze memory leaks using professional tools:

```bash
# 1. Compile with debug symbols
gcc -g -o memory_leak memory_leak.c

# 2. Run with Valgrind (Linux/macOS only)
valgrind --leak-check=full --show-leak-kinds=all ./memory_leak

# 3. Let it run for 10-20 seconds, then stop with Ctrl+C

# 4. Valgrind will show a detailed leak report
```

**Sample Valgrind Output:**

```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 104,857,600 bytes in 10 blocks
==12345==   total heap usage: 10 allocs, 0 frees, 104,857,600 bytes allocated
==12345==
==12345== 104,857,600 bytes in 10 blocks are definitely lost
```

This shows exactly how much memory was leaked and where!

## 📚 Learning Outcomes

After using this program, you should understand:

1. **What memory leaks are**: Memory allocated with `malloc()` but never freed with `free()`
2. **Impact on systems**: How leaked memory affects system performance and stability
3. **Proper memory management**: The critical importance of freeing allocated memory
4. **System limits**: Understanding RAM capacity constraints and swap behavior
5. **Debugging tools**: Using Valgrind and system monitors to detect leaks
6. **Real-world implications**: Why memory leaks in production software are serious bugs

### Key Takeaways

✅ **Always `free()` what you `malloc()`**  
✅ **Monitor memory usage during development**  
✅ **Use tools like Valgrind to catch leaks early**  
✅ **Understand your system's resource limitations**  
✅ **Memory leaks compound over time** (especially in long-running applications)

## 🔧 Troubleshooting

### "Command not found: gcc"

**macOS:**

```bash
xcode-select --install
```

**Linux (Ubuntu/Debian):**

```bash
sudo apt update
sudo apt install build-essential
```

**Windows:**

- Install MinGW or use WSL (Windows Subsystem for Linux)

### "Permission denied" when running

```bash
# Make the file executable
chmod +x memory_leak

# Then run
./memory_leak
```

### Program won't stop with Ctrl+C

- Try pressing Ctrl+C multiple times
- Use the Emergency Stop methods listed above
- Force quit from Task Manager/Activity Monitor

### System became slow after running

- The OS will eventually free the memory
- Wait a few minutes for memory to be reclaimed
- If needed, restart your computer to fully clear memory

## ⚖️ License

MIT License - See [LICENSE](LICENSE) file for details.

## ⚠️ Disclaimer

```
THIS SOFTWARE IS PROVIDED FOR EDUCATIONAL PURPOSES ONLY.

THE AUTHORS ARE NOT RESPONSIBLE FOR:
- System crashes or data loss
- Hardware damage or failure
- Corrupted files or applications
- Loss of unsaved work
- Any other consequences from running this program

BY USING THIS SOFTWARE, YOU ACKNOWLEDGE THESE RISKS AND AGREE
THAT THE AUTHORS BEAR NO RESPONSIBILITY FOR ANY CONSEQUENCES.

THIS PROGRAM INTENTIONALLY CREATES DANGEROUS CONDITIONS.
USE AT YOUR OWN RISK.
```

## 🤝 Contributing

This is an educational project. Contributions are welcome for:

- Improved safety warnings
- Better documentation
- Additional educational features
- Bug fixes
- Platform-specific instructions

**To contribute:**

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -m 'Add some improvement'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Open a Pull Request

## 📧 About

**Created by**: Wyatt (A320Flyerboy19)  
**Purpose**: Educational demonstration of memory leaks and proper memory management

**Repository**: https://github.com/A320Flyerboy19/C_memory_leak_example

---

## 🎯 Complete Quick Start Guide

### For Complete Beginners

```bash
# Step 1: Clone the repository
git clone https://github.com/A320Flyerboy19/C_memory_leak_example.git
cd C_memory_leak_example

# Step 2: Open your system monitor
# macOS: Applications → Utilities → Activity Monitor
# Windows: Press Ctrl+Shift+Esc
# Linux: Run 'gnome-system-monitor' or 'htop'

# Step 3: Compile the program
gcc -o memory_leak memory_leak.c

# Step 4: Run it (Option 1 is safest)
./memory_leak

# Step 5: Watch your memory usage climb in the system monitor

# Step 6: After 1-2 GB leaked, press Ctrl+C to stop
```

### One-Line Quick Test

```bash
git clone https://github.com/A320Flyerboy19/C_memory_leak_example.git && cd C_memory_leak_example && gcc -o memory_leak memory_leak.c && ./memory_leak
```

**Remember**:

- ✅ Option 1 is perfectly sufficient for learning
- ✅ You don't need Options 2 or 3 unless you have a specific reason
- ✅ Always keep Ctrl+C ready to stop the program
- ✅ Watch your system monitor closely

---

**Stay safe and happy learning! 🎓💻**

_"The best way to learn is by doing - but in this case, learn what NOT to do!"_
