#pragma once
#ifndef __JOB_H__
#define __JOB_H__

#include <string>

class Statistics;

class Job {
private:

    int processId;
    int arrivalTime;
    int serviceTime;
    int priority;

public:
    Job(const int, const int, const int, const int);

    void updateProcessId(const int);
    int getProcessId() const;

    void updateArrivalTime(const int);
    int getArrivalTime() const;

    void updateServiceTime(const int);
    int getServiceTime() const;

    void updatePriority(const int);
    int getPriority() const;
};

#endif
