#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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