#ifndef __MODE_STATISTICS__
#define __MODE_STATISTICS__

// Enum to represent different performance modes
typedef enum {
    NORMAL_MODE, // Normal operating mode
    SILENT_MODE, // Silent or low-power mode
    TURBO_MODE   // Turbo or high-performance mode
} PerformanceMode;
// Function to retrieve the current performance mode of the system
PerformanceMode show_performance_mode();

#endif // !__MODE_STATISTICS__
