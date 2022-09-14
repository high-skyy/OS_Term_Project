#include "Job.h"

Job::Job(const int id, const int at, const int st, const int pr)
    :  processId(id), arrivalTime(at), serviceTime(st), priority(pr) {}

int Job::getArrivalTime() const {
    return this->arrivalTime;
}

int Job::getServiceTime() const {
    return this->serviceTime;
}

int Job::getPriority() const {
    return this->priority;
}

int Job::getProcessId() const {
    return this->processId;
}

void Job::updateArrivalTime(const int at) {
    this->arrivalTime = at;
}

void Job::updateServiceTime(const int st) {
    this->serviceTime = st;
}

void Job::updatePriority(const int pr) {
    this->priority = pr;
}

void Job::updateProcessId(const int id) {
    this->processId = id;
}
