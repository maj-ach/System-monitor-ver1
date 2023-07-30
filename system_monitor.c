#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/statvfs.h>

/*
 * Die
 * @param const char *const string
 * @return void
 *
 * */
void die(const char *const string)
{
    perror(string);
    exit(EXIT_FAILURE);
}

/*
 * Get disk info
 * @param void
 * @return void
 *
 * */
void get_disk_info(void)
{
    struct statvfs disk_info;
    int result = statvfs("/home/", &disk_info);
    if (result == -1)
        die("statvfs failed");

    printf("\n[*] Total physical memory (/home): %llu bytes\n", (unsigned long long int)(disk_info.f_frsize) * disk_info.f_blocks);
    printf("\n[*] Available disk space (/home): %llu bytes\n", (unsigned long long int)(disk_info.f_frsize) * disk_info.f_bfree);
}

/*
 * Get system info
 * @param void
 * @return void
 *
 * */
void get_system_info(void)
{
    struct utsname system_info;
    int result = uname(&system_info);
    if (result == -1) 
        die("uname failed");

    printf("\n[*] CPU model: %s\n", system_info.machine);
}

int main(void)
{
    get_system_info();
    get_disk_info();

    return EXIT_SUCCESS;
}
