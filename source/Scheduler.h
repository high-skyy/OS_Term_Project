#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include <vector>
#include <algorithm>

#include "Scheduler.h"
#include "Job.h"

using pid_type = int;
using time_type = int;
using Unit = std::pair<pid_type, time_type>;
using Process = std::pair<Job, int>;

class Scheduler {
public:
    std::vector<Unit> FirstComeFirstServe(const std::vector<Job>) const;
    // (SH) deleted const in the argument to update statistics in job
    std::vector<Unit> ShortestJobFirst(std::vector<Job>) const;
    // (SH) deleted const in the argument to update statistics in job
    std::vector<Unit> ShortestRemainingTimeFirst(std::vector<Job>) const;
    std::vector<Unit> RoundRobin(const std::vector<Job>, const int) const;
    std::vector<Unit> PreemptivePrior(const std::vector<Job>) const;
    std::vector<Unit> NonpreemptivePrior(const std::vector<Job>) const;
    std::vector<Unit> NonpreemptivePriorRR(const std::vector<Job>, const int) const;
};

#endif // _SCHEDULER_H_
