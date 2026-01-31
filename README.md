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

## 🚨 Before Running

### Required Precautions

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

## 🔧 Compilation

```bash
# Standard compilation
gcc -o memory_leak memory_leak.c

# With warnings enabled (recommended)
gcc -Wall -Wextra -o memory_leak memory_leak.c

# With debugging symbols (for Valgrind)
gcc -g -o memory_leak memory_leak.c
```

## 🎮 Usage Options

The program has **THREE** modes of operation. Only one can be active at a time.

### Option 1: Slow Leak (DEFAULT - RECOMMENDED)

**Rate**: 10 MB per second (600 MB per minute)

```bash
./memory_leak
```

**Safe for learning** - Gives you plenty of time to observe and stop.

**Recommended stop points**:

- 8 GB system: Stop at 2-3 GB leaked
- 16 GB system: Stop at 5-7 GB leaked
- 32 GB system: Stop at 10-15 GB leaked

---

### Option 2: Medium Leak (ADVANCED)

**Rate**: 100 MB per second (6 GB per minute)

To use Option 2:

1. Comment out the Option 1 loop (lines 60-88)
2. Uncomment the Option 2 loop (lines 95-118)
3. Recompile and run

⚠️ **More aggressive** - Less reaction time available.

---

### Option 3: Extreme Leak (DANGEROUS - NOT RECOMMENDED)

**Rate**: 166 MB per second (10 GB per minute)

**🚨 EXTREME DANGER 🚨**

This option is **highly dangerous** and can crash your system in minutes.

To use Option 3:

1. Comment out Option 1
2. Uncomment Option 3 loop (lines 198-229)
3. **READ ALL WARNINGS IN THE CODE**
4. Recompile and run **at your own risk**

**Timeline for 16 GB system**:

- 30 seconds: 5 GB leaked
- 60 seconds: 10 GB leaked
- 90 seconds: 15 GB leaked (SYSTEM FAILURE LIKELY)

## 🛑 How to Stop the Program

### Normal Exit

Press **Ctrl+C** in the terminal at any time. The program will catch the signal and exit gracefully.

```bash
# Terminal will show:
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
2. Find `memory_leak.exe`
3. Right-click → "End Task"

**Linux**:

1. Open System Monitor or run `top`/`htop`
2. Find the `memory_leak` process
3. Send SIGKILL: `kill -9 [PID]`

### Last Resort

If your system becomes completely unresponsive, you may need to perform a hard reboot:

- Hold the power button for 5-10 seconds
- **This should be your LAST option**

## 📊 Monitoring Memory Usage

### What to Watch

**Memory Pressure** (macOS Activity Monitor):

- 🟢 **Green**: Safe
- 🟡 **Yellow**: Warning - consider stopping
- 🔴 **Red**: DANGER - stop immediately!

**Available Memory**:

- Keep at least 20-30% of total RAM free
- If available memory drops below 2 GB, **STOP**

**Swap Usage**:

- If swap starts being used heavily, **STOP**
- Excessive swapping = severe performance degradation

## 🧪 Testing Information

This program was tested on:

- **System**: macOS with 128 GB RAM
- **Initial State**: 42.22 GB used, 85.78 GB available
- **Test Duration**: Up to 7 minutes (70 GB leaked)
- **Result**: System remained stable but memory pressure increased significantly

### Option 3 Timeline (128 GB System)

```
Time    Total Used    Leaked    Status
1 min   52 GB        10 GB     ✅ Safe
2 min   62 GB        20 GB     ✅ Safe
3 min   72 GB        30 GB     ⚠️  Getting high
4 min   82 GB        40 GB     ⚠️  Caution
5 min   92 GB        50 GB     🚨 Danger
6 min   102 GB       60 GB     💀 System stress
7 min   112 GB       70 GB     ☠️  Very risky
12.8min 128 GB       86 GB     ⚡ SYSTEM FAILURE
```

## 🐛 Detecting Memory Leaks with Valgrind

To properly analyze memory leaks (without the intentional ones):

```bash
# Compile with debug symbols
gcc -g -o memory_leak memory_leak.c

# Run with Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./memory_leak

# Stop the program quickly (Ctrl+C) to see leak report
```

## 📚 Learning Outcomes

After using this program, you should understand:

1. **What memory leaks are**: Memory allocated but never freed
2. **Impact on systems**: How leaked memory affects system performance
3. **Proper memory management**: Always `free()` what you `malloc()`
4. **System limits**: Understanding RAM capacity constraints
5. **Debugging tools**: Using Valgrind and system monitors

## ⚖️ License

MIT License - See [LICENSE](LICENSE) file for details.

## ⚠️ Disclaimer

```
THIS SOFTWARE IS PROVIDED FOR EDUCATIONAL PURPOSES ONLY.

THE AUTHORS ARE NOT RESPONSIBLE FOR:
- System crashes or data loss
- Hardware damage
- Corrupted files or applications
- Any other consequences from running this program

BY USING THIS SOFTWARE, YOU ACKNOWLEDGE THESE RISKS AND AGREE
THAT THE AUTHORS BEAR NO RESPONSIBILITY FOR ANY CONSEQUENCES.

USE AT YOUR OWN RISK.
```

## 🤝 Contributing

This is an educational project. If you have suggestions for:

- Improved safety warnings
- Better documentation
- Additional educational features
- Bug fixes

Please open an issue or submit a pull request!

## 📧 Contact

Created by: A320Flyerboy19
Purpose: Educational demonstration of memory leaks

---

## 🎯 Quick Start (Safe Mode)

```bash
# 1. Compile
gcc -o memory_leak memory_leak.c

# 2. Run (Option 1 is default - safest)
./memory_leak

# 3. Watch Activity Monitor / Task Manager

# 4. Stop when you've seen enough (Ctrl+C)
```

**Remember**: Option 1 is perfectly sufficient for learning about memory leaks. You don't need to use Options 2 or 3 unless you have a specific reason and understand the risks.

---

**Stay safe and happy learning! 🎓**
