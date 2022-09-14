#include "StatisticsManager.h"
#include "Scheduler.h"

//StatisticsManager::StatisticsManager() {}

double StatisticsManager::getAverageReturnTime(const std::vector<Unit> result_vector) const {
    double sum = 0.0;
    int i = 0;

    for (i = 0; i < result_vector.size(); i++)
    {
        sum += result_vector[i].second;
    }

    return sum / (double)result_vector.size();
}

double StatisticsManager::getAverageWaitingTime(const std::vector<Unit> result_vector) const {
    double sum = 0.0;
    int i = 0;

    for (i = 0; i < result_vector.size(); i++)
    {
        sum += result_vector[i].second;
    }

    return sum / (double)result_vector.size();
}

//////// (SH) (Statistics spelling error)
double StatisticsManager::getAverageResponseTime(const std::vector<Unit> result_vector) const {
    double sum = 0.0;
    int i = 0;

    for (i = 0; i < result_vector.size(); i++)
    {
        sum += result_vector[i].second;
    }

    return sum / (double)result_vector.size();
}
//////// (SH) the jobs already has statistics updated correctly
std::vector<Unit> StatisticsManager::calculateWaitingTime(const std::vector<Unit> gant, const std::vector<Job> jobs) const {
    // Write your code here
    std::vector<Unit> result; //       
    int id;
    int current_time = 0;
    int return_time = 0;
    Unit temp_result;

    for (int i = 0; i < jobs.size(); i++)
    {
        // process_id     
        id = jobs[i].getProcessId();
        return_time = 0;
        current_time = 0;

        for (int j = 0; j < gant.size(); j++)
        {
            current_time = current_time + gant[j].second;
            if (id == gant[j].first)
            {
                return_time = current_time - jobs[i].getArrivalTime();
            }
        }
        result.emplace_back(id, return_time);
    }
    
    return result;
}

std::vector<Unit> StatisticsManager::calculateReturnTime(const std::vector<Unit> gant, const std::vector<Job> jobs) const {
    // Write your code here
    std::vector<Unit> result; //       
    int id;
    int current_time = 0;
    int return_time = 0;
    int waiting_time = 0;
    Unit temp_result;

    for (int i = 0; i < jobs.size(); i++)
    {
        // process_id     
        id = jobs[i].getProcessId();
        return_time = 0;
        waiting_time = 0;
        current_time = 0;

        for (int j = 0; j < gant.size(); j++)
        {
            current_time = current_time + gant[j].second;
            if (id == gant[j].first)
            {
                return_time = current_time - jobs[i].getArrivalTime();
            }
        }
        waiting_time = return_time - jobs[i].getServiceTime();
        result.emplace_back(id, waiting_time);
    }

    return result;
}

std::vector<Unit> StatisticsManager::calculateResponseTime(const std::vector<Unit> gant, const std::vector<Job> jobs) const {
    // Write your code here
    std::vector<Unit> result; //       
    int id;
    int current_time = 0;
    int response_time = 0;
    Unit temp_result;
    
    for (int i = 0; i < jobs.size(); i++)
    {
        // process_id     
        id = jobs[i].getProcessId();
        response_time = 0;
        current_time = 0;

        for (int j = 0; j < gant.size(); j++)
        {
            if (id == gant[j].first)
            {
                response_time = current_time - jobs[i].getArrivalTime();
                break;
            }

            current_time = current_time + gant[j].second;
        }
    result.emplace_back(id, response_time);
    }

    return result;
}


