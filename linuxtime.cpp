#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <unistd.h>
using namespace std;

void work();

int main()
{
        double begin_total_time, begin_idle_time, end_total_time, end_idle_time;
        ifstream uptime;

        uptime.open("/proc/uptime");
        uptime >> begin_total_time;
        uptime >> begin_idle_time;
        uptime.close();

        work();

        uptime.open("/proc/uptime");
        uptime >> end_total_time;
        uptime >> end_idle_time;
        uptime.close();

        double prog_total = end_total_time - begin_total_time;
        double prog_idle = end_idle_time - begin_idle_time;
        double prog_work = prog_total - prog_idle;
        double work_percent = (prog_work / prog_total) * 100;

        cout << "Total program time: " << prog_total << " seconds." << endl;
        cout << "Total idle time: " << prog_idle << " seconds." << endl;
        cout << "Total work time: " << prog_work << " seconds." << endl;
        cout << "Percent of work time: " << work_percent << "%." << endl;

        return 0;
} //end main

void work()
{
        double y;
        double x = 3.0;
        double e = 2.0;
        int i, j;
        for (i = 0; i < 5; i++)
        {
                for (j = 0; j < 400000; j++)
                {
                        y = pow(x, e);
                } //end for
                cout << "Loop " << (i + 1) << " of work cycle." << endl;
                sleep(1);
        } //end for
} //end work
