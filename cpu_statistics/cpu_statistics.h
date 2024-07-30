#ifndef __CPU_STATISTICS__
#define __CPU_STATISTICS__


// Function to retrieve the current clock speed of the CPU.
double show_clock_speed();
// Function to retrieve the current temperature of the CPU.
int show_temp();
// Function to retrieve the current voltage of the CPU.
int show_voltage();
// Function to retrieve the current CPU usage rate.
double show_usage_rate();
// Function to retrieve the number of cores in the CPU.
int show_cores();
// Function to retrieve information about CPU cache. 
int show_cache();
// Function to retrieve the architecture of the CPU.
int show_architecture();
// Function to show detailed information about the CPU model.
char* show_model();

#endif // !__CPU_STATISTICS__
