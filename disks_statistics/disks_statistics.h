#ifndef __DISKS_STATISTICS__
#define __DISKS_STATISTICS__

// This function retrieves the temperature of the disk drive.
int show_disk_temp();
// This function retrieves the count of power cycles that the disk drive has experienced.
int show_power_cycle_count();
// This function calculates the disk usage percentage of the file system.
double show_disk_usage();

#endif // !__DISKS_STATISTICS__
