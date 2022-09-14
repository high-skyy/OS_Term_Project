/* main ÇÔ¼ö made by SH*/


#include "Job.h"
#include "Scheduler.h"
#include "Statistics.h"
#include "StatisticsManager.h"
#include <string>
#include <vector>
#include <algorithm>


int main()
{
    //test process produced (ppt ch5-part2-5.34)
    //name      processID   arrivalTime     serviceTime     priority
    //process1  1           0               10              3
    //process2  2           1               28              2
    //process3  3           2               6               4
    //process4  4           3               4               1
    //process5  5           4               14              2
    std::vector<Job> test;
    //Job::Job(const std::string& str, const int id, const int at, const int st, const int pr)
    test.push_back(Job( 1, 0, 10, 3));
    test.push_back(Job( 2, 1, 28, 2));
    test.push_back(Job( 3, 2, 6, 4));
    test.push_back(Job( 4, 3, 4, 1));
    test.push_back(Job( 5, 4, 14, 2));

    //test process produced (assignment 5.5)
    //name      processID   arrivalTime     serviceTime     priority
    //process1  1           0               20              40
    //process2  2           25              25              30
    //process3  3           30              25               30
    //process4  4           60              15               35
    //process5  5           100             10              5
    //process6  6           105             10              10

    std::vector<Job>test_2;
    test_2.push_back(Job( 1, 0, 20, 40));
    test_2.push_back(Job( 2, 25, 25, 30));
    test_2.push_back(Job( 3, 30, 25, 30));
    test_2.push_back(Job( 4, 60, 15, 35));
    test_2.push_back(Job( 5, 100, 10, 5));
    test_2.push_back(Job( 6, 105, 10, 10));
    

    int time_quantum = 2;
    int time_quantum_2 = 10;
    // Job print
    int i;


    printf("\n\n**********************first_test_sample**********************\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("ID: %d, AT: %d, ST: %d, PR: %d\n",  test[i].getProcessId(), test[i].getArrivalTime(), test[i].getServiceTime(), test[i].getPriority());
    }


    printf("\n\n**********************second_test_sample**********************\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("ID: %d, AT: %d, ST: %d, PR: %d\n",  test_2[i].getProcessId(), test_2[i].getArrivalTime(), test_2[i].getServiceTime(), test_2[i].getPriority());
    }

    printf("\n\n");

    std::vector<Unit> result;
    std::vector<Unit> waiting_time;
    std::vector<Unit> response_time;
    std::vector<Unit> return_time;
    double average_waiting_time=0;
    double average_response_time=0;
    double average_return_time=0;
    Scheduler temp_scheduler;
    StatisticsManager Stat_manager = StatisticsManager();

    printf("\n\n*************************first test***********************\n\n");
    
    printf("\n\nFirstComeFirstServe_first_sample\n\n");
    
    result = temp_scheduler.FirstComeFirstServe(test);

    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }
    printf("\n");

    waiting_time = Stat_manager.calculateWaitingTime(result, test);
    response_time = Stat_manager.calculateResponseTime(result, test);
    return_time = Stat_manager.calculateReturnTime(result,test);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);
        
    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);

    
    printf("\n\nShortestJobFisrt_first_sample\n\n");

    result = temp_scheduler.ShortestJobFirst(test);

    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test);
    response_time = Stat_manager.calculateResponseTime(result, test);
    return_time = Stat_manager.calculateReturnTime(result, test);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);

    
    printf("\n\nShortestRemainingTimeFirst_first_sample \n\n");
    result = temp_scheduler.ShortestRemainingTimeFirst(test);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test);
    response_time = Stat_manager.calculateResponseTime(result, test);
    return_time = Stat_manager.calculateReturnTime(result, test);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);
    
    printf("\n\nRoundRobin_first_sample \n\n");
    result = temp_scheduler.RoundRobin(test, time_quantum);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }
    
    waiting_time = Stat_manager.calculateWaitingTime(result, test);
    response_time = Stat_manager.calculateResponseTime(result, test);
    return_time = Stat_manager.calculateReturnTime(result, test);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);
    
    printf("\n\nPreemptivePrior \n\n");
    result = temp_scheduler.PreemptivePrior(test);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test);
    response_time = Stat_manager.calculateResponseTime(result, test);
    return_time = Stat_manager.calculateReturnTime(result, test);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);
    
    printf("\n\nNonpreemptivePrior_first_sample\n\n");
    result = temp_scheduler.NonpreemptivePrior(test);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }
    
    waiting_time = Stat_manager.calculateWaitingTime(result, test);
    response_time = Stat_manager.calculateResponseTime(result, test);
    return_time = Stat_manager.calculateReturnTime(result, test);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);




    
    printf("\n\n*************************second test***********************\n\n");
    



    printf("\n\nFirstComeFirstServe_second_sample\n\n");
    
    result = temp_scheduler.FirstComeFirstServe(test_2);

    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test_2);
    response_time = Stat_manager.calculateResponseTime(result, test_2);
    return_time = Stat_manager.calculateReturnTime(result, test_2);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);

    


    printf("\n\nShortestJobFisrt_second_sample\n\n");

    result = temp_scheduler.ShortestJobFirst(test_2);


    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }
    

    waiting_time = Stat_manager.calculateWaitingTime(result, test_2);
    response_time = Stat_manager.calculateResponseTime(result, test_2);
    return_time = Stat_manager.calculateReturnTime(result, test_2);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);


    
    printf("\n\nShortestRemainingTimeFirst_second_sample \n\n");
    result = temp_scheduler.ShortestRemainingTimeFirst(test_2);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test_2);
    response_time = Stat_manager.calculateResponseTime(result, test_2);
    return_time = Stat_manager.calculateReturnTime(result, test_2);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);

    
    printf("\n\nRoundRobin_second_sample \n\n");
    result = temp_scheduler.RoundRobin(test_2, time_quantum_2);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test_2);
    response_time = Stat_manager.calculateResponseTime(result, test_2);
    return_time = Stat_manager.calculateReturnTime(result, test_2);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);
    
    
    printf("\n\nPreemptivePrior_second_sample \n\n");
    result = temp_scheduler.PreemptivePrior(test_2);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test_2);
    response_time = Stat_manager.calculateResponseTime(result, test_2);
    return_time = Stat_manager.calculateReturnTime(result, test_2);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);


    
    
    printf("\n\nNonpreemptivePrior_second_sample\n\n");
    result = temp_scheduler.NonpreemptivePrior(test_2);
    for (i = 0; i < result.size(); i++)
    {
        printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
        //printf("")
    }

    waiting_time = Stat_manager.calculateWaitingTime(result, test_2);
    response_time = Stat_manager.calculateResponseTime(result, test_2);
    return_time = Stat_manager.calculateReturnTime(result, test_2);
    average_waiting_time = Stat_manager.getAverageWaitingTime(waiting_time);
    average_response_time = Stat_manager.getAverageResponseTime(response_time);
    average_return_time = Stat_manager.getAverageReturnTime(return_time);

    for (i = 0; i < waiting_time.size(); i++)
    {
        printf("pid : %d     waiting time : %d\n", waiting_time[i].first, waiting_time[i].second);

    }
    printf("\n");
    for (i = 0; i < response_time.size(); i++)
    {
        printf("pid : %d     response time : %d\n", response_time[i].first, response_time[i].second);
        //printf("")
    }
    printf("\n");
    for (i = 0; i < return_time.size(); i++)
    {
        printf("pid : %d     return time : %d\n", return_time[i].first, return_time[i].second);
        //printf("")
    }
    printf("\n");
    printf("average_waiting_time = %f, average_response_time = %f, average_return_time = %f", average_waiting_time, average_response_time, average_return_time);



    
    
}


