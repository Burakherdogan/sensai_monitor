#ifndef __CPU_STATISTICS__
#define __CPU_STATISTICS__

// CPUModel: Structure representing the processor model and its specifications.
typedef struct {
    const char* manufacturer; // Manufacturer of the processor
    const char* name; // Name of the processor model
    const char* version; // Version of the processor
    int year;  // Year of manufacture of the processor
} CPUModel;

// Architecture: Enumeration representing the processor architecture.
typedef enum {
    X86, // Intel x86 architecture
    ARM, // ARM architecture
    RISC_V, // RISC-V architecture
} Architecture;

// Function to retrieve the current clock speed of the CPU.
int show_clock_speed();
// Function to retrieve the current temperature of the CPU.
int show_temp();
// Function to retrieve the current voltage of the CPU.
int show_voltage();
// Function to retrieve the current CPU usage rate.
int show_usage_rate();
// Function to retrieve the number of threads in the CPU.
int show_thread();
// Function to retrieve information about CPU cache. 
int show_cache();
// Function to retrieve the architecture of the CPU.
Architecture show_architecture();
// Function to retrieve the model information of the CPU
char* get_model();
// Function to show detailed information about the CPU model.
CPUModel show_model();

#endif // !__CPU_STATISTICS__
