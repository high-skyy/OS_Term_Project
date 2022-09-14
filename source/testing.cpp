// /* main �Լ� made by SH*/


// #include "Job.h"
// #include "Scheduler.h"
// #include "Statistics.h"
// #include "StatisticsManager.h"
// #include <string>
// #include <vector>
// #include <algorithm>


// int main()
// {
//     //test process produced (ppt ch5-part2-5.34)
//     //name      processID   arrivalTime     serviceTime     priority
//     //process1  1           0               10              3
//     //process2  2           1               28              2
//     //process3  3           2               6               4
//     //process4  4           3               4               1
//     //process5  5           4               14              2
//     std::vector<Job> test;
//     //Job::Job(const std::string& str, const int id, const int at, const int st, const int pr)
//     test.push_back(Job("process1", 1, 0, 10, 3));
//     test.push_back(Job("process2", 2, 1, 28, 2));
//     test.push_back(Job("process3", 3, 2, 6, 4));
//     test.push_back(Job("process4", 4, 3, 4, 1));
//     test.push_back(Job("process5", 5, 4, 14, 2));

//     //test process produced (assignment 5.5)
//     //name      processID   arrivalTime     serviceTime     priority
//     //process1  1           0               20              40
//     //process2  2           25              25              30
//     //process3  3           30              25               30
//     //process4  4           60              15               35
//     //process5  5           100             10              5
//     //process6  6           105             10              10

//     std::vector<Job>test_2;
//     test_2.push_back(Job("process1", 1, 0, 20, 40));
//     test_2.push_back(Job("process2", 2, 25, 25, 30));
//     test_2.push_back(Job("process3", 3, 30, 25, 30));
//     test_2.push_back(Job("process4", 4, 60, 15, 35));
//     test_2.push_back(Job("process5", 5, 100, 10, 5));
//     test_2.push_back(Job("process6", 6, 105, 10, 10));
    

//     int time_quantum = 2;
//     int time_quantum_2 = 10;
//     // Job print
//     int i;
//     for (i = 0; i < 5; i++)
//     {
//         printf("name: %s, ID: %d, AT: %d, ST: %d, PR: %d\n", test[i].getName(), test[i].getProcessId(), test[i].getArrivalTime(), test[i].getServiceTime(), test[i].getPriority());
//     }

//     for (i = 0; i < 5; i++)
//     {
//         printf("name: %s, ID: %d, AT: %d, ST: %d, PR: %d\n", test_2[i].getName(), test_2[i].getProcessId(), test_2[i].getArrivalTime(), test_2[i].getServiceTime(), test_2[i].getPriority());
//     }

//     std::vector<Unit> result;
//     std::vector<int> waiting_time;
//     std::vector<int> response_time;
//     std::vector<int> return_time;
//     Scheduler temp_scheduler;
//     StatisticsManager Stat_manager = StatisticsManager();
    
//     printf("FirstComeFirstServe_first_sample\n\n");
    
//     result = temp_scheduler.FirstComeFirstServe(test);

//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }

//     printf("ShortestJobFisrt_first_sample\n\n");

//     result = temp_scheduler.ShortestJobFirst(test);


//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }

//     printf("ShortestRemainingTimeFirst_first_sample \n\n");
//     result = temp_scheduler.ShortestRemainingTimeFirst(test);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
    
//     printf("RoundRobin_first_sample \n\n");
//     result = temp_scheduler.RoundRobin(test, time_quantum);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
    

//     /*
//     printf("PreemptivePrior \n\n");
//     result = temp_scheduler.PreemptivePrior(test);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
//     */
//     /*
//     printf("NonpreemptivePrior_first_sample\n\n");
//     result = temp_scheduler.NonpreemptivePrior(test);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
//     */

//     printf("\n\n*************************second test***********************\n\n");
    
//     printf("FirstComeFirstServe_second_sample\n\n");
    
//     result = temp_scheduler.FirstComeFirstServe(test_2);

//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
    
//     printf("ShortestJobFisrt_second_sample\n\n");

//     result = temp_scheduler.ShortestJobFirst(test_2);


//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
    


    
//     printf("ShortestRemainingTimeFirst_second_sample \n\n");
//     result = temp_scheduler.ShortestRemainingTimeFirst(test_2);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
    
//     printf("RoundRobin_second_sample \n\n");
//     result = temp_scheduler.RoundRobin(test_2, time_quantum_2);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
    
//     /*
//     printf("PreemptivePrior_second_sample \n\n");
//     result = temp_scheduler.PreemptivePrior(test);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
    
    
//     printf("NonpreemptivePrior_second_sample\n\n");
//     result = temp_scheduler.NonpreemptivePrior(test_2);
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("pid : %d     processed time : %d\n", result[i].first, result[i].second);
//         //printf("")
//     }
//     */

//     /*
//     for (i = 0; i < result.size(); i++)
//     {
//         printf("process id : %d\n", test[i].getProcessId());
//         printf("%d" test.)
//     }*/
// }


