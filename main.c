#include "cpu_statistics/cpu_statistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
//CPU FEATURES
while (1) {
        int clock_speed = show_clock_speed();
        int temp = show_temp();
	int voltage = show_voltage();
	double usage_rate = show_usage_rate();
	int cores = show_cores();
	int cache = show_cache();
	printf("\033[H\033[J");
	printf("   ____  ____   _   _   _____  _____     _   _____  _   _  ____   _____  ____ \n");
	printf("  / ___||  _ \\ | | | | |  ___|| ____|   / \\ |_   _|| | | ||  _ \\ | ____|/ ___| \n");
	printf(" | |    | |_) || | | | | |_   |  _|    / _ \\  | |  | | | || |_) ||  _|  \\___ \\ \n");
	printf(" | |___ |  __/ | |_| | |  _|  | |___  / ___ \\ | |  | |_| ||  _ < | |___  ___) | \n");
	printf("  \\____||_|     \\___/  |_|    |_____|/_/   \\_\\|_|   \\___/ |_| \\_\\|_____||____/ \n");
        printf("|-----------------------------|");
	printf("|-----------------------------|");
	printf("|-----------------------------|");
	printf("|-----------------------------|\n");	
        if(clock_speed<1000){
	printf("| Clock Speed is: %d MHz     |", clock_speed);
	}
	else{
	printf("| Clock Speed is: %d MHz    |", clock_speed);
	}
	printf("| Temperature : %d            |",temp);
	printf("| Voltage : %d mV          |",voltage);
	printf("| Cores Count: %d             |\n",cores);
	printf("|-----------------------------|");
        printf("|-----------------------------|");
        printf("|-----------------------------|");
        printf("|-----------------------------|\n");
	printf("| Cache :    %d MB         |", cache);
	printf("| Architecture:         ");
	show_architecture();
	printf("|| Usage rate :    %lf  %     |\n",usage_rate);
	printf("|-----------------------------|");
        sleep(1); 
    }
return 0;
}

