#pragma once
#ifndef _STATISTICS_MANAGER_H_
#define _STATISTICS_MANAGER_H_

#include <vector>
#include "Job.h"
#include "Scheduler.h"

class StatisticsManager {
private:

public:
    std::vector<Unit> calculateWaitingTime(const std::vector<Unit>, const std::vector<Job>) const;
    std::vector<Unit> calculateReturnTime(const std::vector<Unit>, const std::vector<Job>) const;
    std::vector<Unit> calculateResponseTime(const std::vector<Unit>, const std::vector<Job>) const;
    double getAverageWaitingTime(const std::vector<Unit>) const;
    double getAverageReturnTime(const std::vector<Unit>) const;
    double getAverageResponseTime(const std::vector<Unit>) const;
};

#endif // _STATISTICS_MANAGER_H_
// (SH) due to error erased _STATISTICS_MANAGER_H_