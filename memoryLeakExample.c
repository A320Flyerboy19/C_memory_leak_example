// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                          ⚠️  CRITICAL WARNING ⚠️                           ║
// ║                                                                            ║
// ║  THIS PROGRAM INTENTIONALLY CREATES A SEVERE MEMORY LEAK                   ║
// ║                                                                            ║
// ║  DANGER:                                                                   ║
// ║  • Allocates 10 MB of RAM per second WITHOUT FREEING IT                    ║
// ║  • Will consume ALL available system memory if left running                ║
// ║  • May cause system instability, freezing, or crashes                      ║
// ║  • May cause data loss in other running applications                       ║
// ║  • Could trigger OS emergency memory management (swap thrashing)           ║
// ║                                                                            ║
// ║  BEFORE RUNNING:                                                           ║
// ║  • Save ALL work in other applications                                     ║
// ║  • Close unnecessary programs                                              ║
// ║  • Know your system's RAM capacity                                         ║
// ║  • DO NOT exceed 50% of your total RAM                                     ║
// ║  • Keep Activity Monitor/Task Manager open and visible                     ║
// ║                                                                            ║
// ║  RECOMMENDED LIMITS:                                                       ║
// ║  • 8 GB RAM system:  Stop at 2-3 GB leaked                                 ║
// ║  • 16 GB RAM system: Stop at 5-7 GB leaked                                 ║
// ║  • 32 GB RAM system: Stop at 10-15 GB leaked                               ║
// ║                                                                            ║
// ║  TO STOP THE PROGRAM:                                                      ║
// ║  • Press Ctrl+C immediately in the terminal                                ║
// ║  • If system freezes: Force quit via Activity Monitor/Task Manager         ║
// ║  • Worst case: Hard reboot your machine (LAST RESORT)                      ║
// ║                                                                            ║
// ║  FOR EDUCATIONAL PURPOSES ONLY - USE AT YOUR OWN RISK                      ║
// ╚════════════════════════════════════════════════════════════════════════════╝

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep()
#include <signal.h> // for signal handling

// Signal handler for clean exit
void handle_signal(int sig)
{
    printf("\n\n🛑 Program interrupted! Exiting immediately...\n");
    printf("Note: Memory will be freed by the operating system.\n");
    exit(0);
}

int main(void)
{
    // Register signal handler for Ctrl+C
    signal(SIGINT, handle_signal);

    printf("Creating memory leak...\n");
    printf("Watch your system monitor (Task Manager/Activity Monitor)\n");
    printf("⚠️  Press Ctrl+C at ANY TIME to stop and exit!\n\n");

    int total_mb = 0;

    // ═══════════════════════════════════════════════════════════════════════════
    // OPTION 1: SLOW LEAK - 10 MB per second (600 MB per minute)
    // ═══════════════════════════════════════════════════════════════════════════
    for (int i = 0; i < 999999; i++) // Run forever (or until system runs out of memory)
    {
        // Allocate 10 MB and never free it
        char *leak = malloc(10 * 1024 * 1024);

        if (leak == NULL)
        {
            printf("Allocation failed at iteration %d\n", i);
            break;
        }

        // Write to it so OS actually allocates the memory
        for (int j = 0; j < 10 * 1024 * 1024; j += 4096)
        {
            leak[j] = 'A';
        }

        total_mb += 10;
        printf("Leaked %.2f GB so far... (Press Ctrl+C to stop)\n", total_mb / 1000.0);

        // Check for milestones every 500 MB
        for (int milestone = 500; milestone <= 100000; milestone += 500)
        {
            if (total_mb == milestone)
            {
                printf("⚠️  WARNING: %.1f GB leaked!\n", milestone / 1000.0);
                break; // Exit milestone check once we find a match
            }
        }

        sleep(1); // Pause so you can watch
    }

    // ═══════════════════════════════════════════════════════════════════════════
    // OPTION 2: MEDIUM LEAK - 1 GB per 10 seconds (6 GB per minute)
    // Comment out OPTION 1 above and uncomment this section to use
    // ═══════════════════════════════════════════════════════════════════════════
    /*
    for (int i = 0; i < 999999; i++) // Run forever (or until system runs out of memory)
    {
        // Allocate 100 MB and never free it
        char *leak = malloc(100 * 1024 * 1024);

        if (leak == NULL)
        {
            printf("Allocation failed at iteration %d\n", i);
            break;
        }

        // Write to it so OS actually allocates the memory
        for (int j = 0; j < 100 * 1024 * 1024; j += 4096)
        {
            leak[j] = 'A';
        }

        total_mb += 100;
        printf("Leaked %.2f GB so far... (Press Ctrl+C to stop)\n", total_mb / 1000.0);

        // Check for milestones every 500 MB
        for (int milestone = 500; milestone <= 100000; milestone += 500)
        {
            if (total_mb == milestone)
            {
                printf("⚠️  WARNING: %.1f GB leaked!\n", milestone / 1000.0);
                break; // Exit milestone check once we find a match
            }
        }

        sleep(1); // Pause 1 second between 100 MB allocations (= 1 GB per 10 seconds)
    }
    */

    // ═══════════════════════════════════════════════════════════════════════════
    // ⚠️⚠️⚠️ OPTION 3: EXTREME DANGER - 5 GB PER 30 SECONDS (10 GB PER MINUTE) ⚠️⚠️⚠️
    // ═══════════════════════════════════════════════════════════════════════════
    //
    //
    // ⚠️  EXTREME WARNING - READ BEFORE UNCOMMENTING ⚠️
    //
    // This option is EXTREMELY AGGRESSIVE and HIGHLY DANGEROUS:
    // • Leaks 166 MB per second (5 GB in 30 seconds, 10 GB per minute)
    // • Will exhaust 16 GB of RAM in approximately 90 seconds
    // • VERY HIGH probability of system freeze/crash
    // • May not give you time to react before system becomes unresponsive
    // • Could cause immediate kernel panic or blue screen
    // • GUARANTEED data loss risk in other applications
    //
    // DO NOT USE THIS OPTION UNLESS:
    // ✓ You have 32+ GB of RAM
    // ✓ ALL other applications are closed and work is saved
    // ✓ You are prepared to hard reboot your machine
    // ✓ You have your finger on Ctrl+C BEFORE running
    // ✓ You understand the severe risks involved
    //
    // ═══════════════════════════════════════════════════════════════════════════
    // TESTED ON: 128 GB RAM System (macOS)
    // Initial State: 42.22 GB used, 85.78 GB available
    //
    // Expected Timeline from Initial State:
    // • 1 min:  52 GB total (10 GB leaked)   ✅ Safe
    // • 2 min:  62 GB total (20 GB leaked)   ✅ Safe
    // • 3 min:  72 GB total (30 GB leaked)   ⚠️  Getting high
    // • 4 min:  82 GB total (40 GB leaked)   ⚠️  Caution zone
    // • 5 min:  92 GB total (50 GB leaked)   🚨 Danger zone
    // • 6 min: 102 GB total (60 GB leaked)   💀 System stress
    // • 7 min: 112 GB total (70 GB leaked)   ☠️  Very risky
    // • 12.8 min: 128 GB exhausted (complete system failure likely)
    //
    // RECOMMENDED SAFE STOP POINTS FOR 128 GB SYSTEM:
    // • Conservative: Stop at 70-75 GB total (~28-33 GB leaked) = 2.8-3.3 minutes
    // • Moderate: Stop at 90 GB total (~48 GB leaked) = 4.8 minutes
    // • Aggressive: Stop at 110 GB total (~68 GB leaked) = 6.8 minutes
    //
    // WATCH YOUR MEMORY PRESSURE IN ACTIVITY MONITOR!
    // If the graph turns YELLOW or RED, stop IMMEDIATELY!
    // ═══════════════════════════════════════════════════════════════════════════
    //
    // SERIOUSLY - This is like playing with fire. Option 1 or 2 is sufficient
    // for learning about memory leaks. This option exists only to demonstrate
    // catastrophic memory exhaustion.
    //
    // YOU HAVE BEEN WARNED. 💀
    // ═══════════════════════════════════════════════════════════════════════════
    /*
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║  ☠️  EXTREME MODE ACTIVATED - 5 GB PER 30 SECONDS  ☠️        ║\n");
    printf("║  YOUR SYSTEM MAY BECOME UNRESPONSIVE VERY QUICKLY!          ║\n");
    printf("║  KEEP YOUR FINGER ON Ctrl+C!                                ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("\n");

    for (int i = 0; i < 999999; i++) // Run forever (or until system runs out of memory)
    {
        // Allocate 166 MB and never free it (5000 MB / 30 iterations ≈ 166 MB per iteration)
        char *leak = malloc(166 * 1024 * 1024);

        if (leak == NULL)
        {
            printf("Allocation failed at iteration %d\n", i);
            break;
        }

        // Write to it so OS actually allocates the memory
        for (int j = 0; j < 166 * 1024 * 1024; j += 4096)
        {
            leak[j] = 'A';
        }

        total_mb += 166;
        printf("☠️  LEAKED %.2f GB - DANGER ZONE! (Press Ctrl+C NOW!)\n", total_mb / 1000.0);

        // Check for milestones every 500 MB
        for (int milestone = 500; milestone <= 100000; milestone += 500)
        {
            if (total_mb >= milestone && total_mb < milestone + 166)
            {
                printf("🚨🚨🚨 CRITICAL: %.1f GB LEAKED! STOP NOW! 🚨🚨🚨\n", milestone / 1000.0);
                break;
            }
        }

        sleep(1); // 1 second between 166 MB allocations = 5 GB per 30 seconds
    }
    */

    printf("Press Enter to exit and release all memory...\n");
    getchar();

    return 0;
}