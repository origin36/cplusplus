#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
        float totaltime, idletime, total_mem, free_mem; //creation of float variables
        string  name, kernel_version, time, date, waste; //creatin of string variables
        ifstream uptime, hostname, version, meminfo, rtc; //creation of file names

		//open uptime, save values totaltime and idletime, and close uptime
        uptime.open("/proc/uptime");
        uptime >> totaltime;
        uptime >> idletime;
        uptime.close();

		//convert times to hours
        totaltime = totaltime / 3600;
        idletime = idletime / 3600;

		//open hostname, save name, and close hostname
        hostname.open("/proc/sys/kernel/hostname");
        hostname >> name;
        hostname.close();

		//open version, save version, and close version
        version.open("/proc/version");
        version >> waste;
        version >> waste;
        version >> kernel_version;
        version.close();

		//open memory info, save total and free, and close memory
        meminfo.open("/proc/meminfo");
        meminfo >> waste;
        meminfo >> total_mem;
        meminfo >> waste;
        meminfo >> waste;
        meminfo >> free_mem;
        meminfo.close();

		//calculate the used memory
        int used_mem = total_mem - free_mem;

		//open rtc, save time and date, and close rtc
        rtc.open("/proc/driver/rtc");
        rtc >> waste;
        rtc >> waste;
        rtc >> time;
        rtc >> waste;
        rtc >> waste;
        rtc >> date;
        rtc.close();
		
		//formatted output
        cout << "Machine name: " << name << endl;
        cout << "System date: " << date << endl;
        cout << "System time: " << time << endl;
        cout << "Kernal version: " << kernel_version << endl;
        cout << "Used memory : " << used_mem << " kB" << endl;
        cout << "Free memory: " << free_mem << " kB" << endl;
        cout << "Duration of uptime: " << totaltime << " hours" << endl;
        cout << "Duration of idletime: " << idletime << " hours" << endl;

        return 0;
} //end main
