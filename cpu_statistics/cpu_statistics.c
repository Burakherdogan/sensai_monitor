#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

#define MAX_LINE_LENGTH 256

/*
 * Function to retrieve the current clock speed of the CPU.
 * Reads the CPU clock speed in MHz from the /proc/cpuinfo file.
 * Returns the current CPU clock speed in MHz if successful,
 * or -1.0 if an error occurs or the clock speed cannot be retrieved.
 */
double show_clock_speed(){
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    double clock_speed = 0.0;
        
    // Open the /proc/cpuinfo file for reading
    fp = fopen("/proc/cpuinfo","r");
    if (fp == NULL){
        return -1.0; // Return -1.0 if the file cannot be opened
    }

    // Read each line of the file until the "cpu MHz" line is found
    while(fgets(line, sizeof(line), fp)){
        if(strstr(line, "cpu MHz")){
            sscanf(line, "cpu MHz\t: %lf", &clock_speed);
            break; // Stop reading after finding the clock speed
        }
    }
    
    // Close the file
    fclose(fp);
    
    // Return the current CPU clock speed in MHz
    return clock_speed;
}

/*
 * Function to retrieve the current CPU temperature.
 * Reads the temperature value from the file /sys/class/thermal/thermal_zone0/temp.
 * Returns the temperature in Celsius.
 * Returns -1 if the file cannot be opened or if reading fails.
 */
int show_temp(){
    FILE *fp;
    int temp = 0;
    
    // Open the /sys/class/thermal/thermal_zone0/temp file for reading
    fp = fopen("/sys/class/thermal/thermal_zone0/temp","r");
    if (fp == NULL){
        return -1; // Return -1 if the file cannot be opened
    }
    
    // Read the first two characters from the file as an integer
    if(fscanf(fp,"%2d", &temp)!=1){
        fclose(fp);
        return -1; // Return -1 if reading fails
    }
        
    // Close the file
    fclose(fp);

    // Return the current CPU tempature.
    return temp;
}

/*
 * Function to retrieve the current CPU voltage.
 * Reads the voltage value from the file /sys/class/hwmon/hwmon0/in0_input.
 * Returns the voltage in millivolts (mV).
 * Returns -1 if the file cannot be opened or if reading fails.
 */
int show_voltage(){
    FILE *fp;
    int voltage = 0;

    // Open the file for reading
    fp = fopen("/sys/class/hwmon/hwmon2/in0_input", "r"); // $ls /sys/class/hwmon/*/in0_input
    if(fp == NULL){
        return -1; // Return -1 if the file cannot be opened
    }
    // Read the voltage value from the file
    if(fscanf(fp, "%d", &voltage) != 1){
        fclose(fp);
        return -1; // Return -1 if reading fails
    }

    // Close the file
    fclose(fp);

    // Return the voltage in millivolts (mV)
    return voltage;
}

/*
 * Function to retrieve the current CPU usage rate.
 * Reads CPU statistics from the file /proc/stat and calculates the usage rate.
 * Returns the CPU usage rate as a percentage.
 * Returns -1 if the file cannot be opened or if reading fails.
 */
double show_usage_rate() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int user, nice, system, idle;
    double total_time, usage_rate;

    // Open the /proc/stat file for reading
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1; // Return -1 if the file cannot be opened
    }

    // Read each line of the file
    while (fgets(line, sizeof(line), fp)) {
        // Check if the line starts with "cpu"
        if (sscanf(line, "cpu %d %d %d %d", &user, &nice, &system, &idle) == 4) {
            // Calculate the total CPU time (excluding idle time)
            total_time = user + nice + system + idle;

            // Calculate the CPU usage rate as a percentage
            usage_rate = ((total_time - idle) * 100.0) / total_time;

            fclose(fp);
            return usage_rate;
        }
    }

    fclose(fp);
    return -1; // Return -1 if CPU usage rate cannot be determined
}

/*
 * Function to retrieve the total number of CPU cores in the system.
 * Reads the /proc/cpuinfo file to count the number of processors listed.
 * Returns the total number of CPU cores.
 * Returns -1 if the file cannot be opened.
 */
int show_cores() {
    FILE *fp;
    int cores = 0;
    char line[MAX_LINE_LENGTH];

    // Open the /proc/cpuinfo file for reading
    fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/cpuinfo");
        return -1;
    }

    // Iterate through each line and count the number of processors
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "processor")) {
            cores++;
        }
    }

    // Close the file
    fclose(fp);

    // Return the total number of CPU cores
    return cores;
}

/* Function to retrieve the current caches in the CPU
 *
 *
 *
 *
 */
int show_cache(){
   FILE *fp;
   int cache = 0;
   char line[MAX_LINE_LENGTH];

   fp = fopen("/proc/cpuinfo","r");
   if (fp == NULL) {
	   perror("Error opening /proc/cpuinfo");
	   return -1;
   }

   while (fgets(line, sizeof(line), fp)){
	   sscanf(line, "cache size	: %d", &cache);
   }
   fclose(fp);
		  	

    return cache;
}

int show_architecture(){
	struct utsname uname_data;
	if(uname(&uname_data) <  0){
		perror("uname");	
	}

	printf("%s",uname_data.machine);
	
	return 0;
}
char* show_model(){
	char* model;
	

	return model;
}
