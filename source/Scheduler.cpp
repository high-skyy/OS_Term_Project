#include "Scheduler.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#include <tuple>



std::vector<std::tuple<int, int, int>> new_sort(std::vector<Job> job) {
    std::vector <std::tuple<int, int, int>> v; //pid, at, index 넣어줌

    for (int i = 0; i < job.size(); i++) {
        v.push_back(std::make_tuple(job[i].getProcessId(), job[i].getArrivalTime(), i));
    }


    for (int i = 0; i < job.size() - 1; i++) { //ArrivalTime 기준으로 순서 정렬
        int tmp = i;
        for (int j = i + 1; j < job.size(); j++) {
            if (std::get<1>(v[tmp]) > std::get<1>(v[j])) tmp = j;
        }
        if (tmp != i) swap(v[i], v[tmp]);
    }

    return v;
}


std::vector<Unit> Scheduler::FirstComeFirstServe(const std::vector<Job> job) const {
    std::vector<std::tuple<int, int, int>> sort;
    std::vector<Unit> gantt; //gantt 차트
    int time = 0;

    if (job.size() > 1)
    {
        sort = new_sort(job); //arrivalTime을 기준으로 프로세스 실행 순서 결정

        for (int i = 0; i < sort.size(); i++) {
            int pid = std::get<0>(sort[i]);
            int at = std::get<1>(sort[i]);
            int index = std::get<2>(sort[i]);

            if (job[index].getArrivalTime() > time) { //프로세스가 지금보다 나중에 들어오면
                gantt.push_back(std::make_pair(0, at - time)); //들어오기전까지는 idle로 상태 저장
                time =  at; //idle만큼 시간 추가
            }
            gantt.push_back(std::make_pair(pid, job[index].getServiceTime())); //끝난 프로세스는 간트차트로
            time += job[index].getServiceTime();
        }
    }
    else if (job.size() == 1)
    {
        if (job[0].getArrivalTime() > time) {
            gantt.push_back(std::make_pair(0, job[0].getArrivalTime() - time));
            time = job[0].getArrivalTime();
            time += job[0].getServiceTime();
            gantt.push_back(std::make_pair(job[0].getProcessId(), job[0].getServiceTime())); //끝난 프로세스는 간트차트로
        }
    }
    return gantt;
}

std::vector<Unit> Scheduler::ShortestJobFirst(const std::vector<Job> job) const {
	// your code here


	if (job.size() == 0)
		printf("The job list is empty \n");

	std::vector<Unit> result;
	Unit temp_result;
	std::vector<int> vec_burst_time; // process burst time;
	std::vector<int> vec_waiting_time; // process waiting time;
	std::vector<int> vec_response_time_parity; // check response time
	std::vector<int> vec_return_time; // process terminated time - process arrival time
	std::vector<int> vec_response_time; // process response time
	std::vector<int> vec_end_time; // process terminated time
	std::vector<int> vec_processed_time; // processed time 
	int i = 0;
	int current_time = 0; // current time
	int end_time; // process terminated time
	int num_finished_process = 0; // number of finished process - 1
	int index_min = job.size(); // index of most small burst time job.size() just for first loop
	int waitingT;
	int returnT;
	int responseT;
	int previous_idle = 1;
	int first_time = 1;

	//initialize response_time, processedtime, parity bit 
	for (i = 0; i < job.size(); i++)
	{
		vec_burst_time.push_back(job[i].getServiceTime());
		vec_waiting_time.push_back(0);
		vec_response_time_parity.push_back(0);
		vec_return_time.push_back(0);
		vec_response_time.push_back(0);
		vec_end_time.push_back(0);
		vec_processed_time.push_back(0);

	}


	vec_processed_time.push_back(0); // for CPU idle state add one more entity vec_processed_time[job.size()] = 0

	vec_burst_time.push_back(999); // parameter until the first time of process

	// increase current time and check if all processes are finished
	while (num_finished_process < job.size())
	{
		index_min = job.size();                                          // index_min initialization

		// find the index of the process that has the smallest burst_time
		for (i = 0; i < job.size(); i++)
		{
			// check arrival time                       &  check if it is smallest burst time               & if the burst time is not 0
			if (job[i].getArrivalTime() <= current_time && vec_burst_time[i] < vec_burst_time[index_min] && vec_burst_time[i]>0)
			{
				// process a different process
				index_min = i;
			}
		}

		// index_min has the index of the smallest burst_time process

		if (index_min == job.size()) // no process to work with (the CPU is IDLE)
		{
			previous_idle = 1; // change to idle state
			vec_processed_time[job.size()] = vec_processed_time[job.size()] + 1;
			current_time = current_time + 1;
		}

		else // there is a process to work with
		{
			if (previous_idle == 1) // idle to new process
			{
				if (first_time != 1)
				{
					temp_result.first = 0; // idle pid is 0
					temp_result.second = vec_processed_time[job.size()];
					result.push_back(temp_result);
					vec_processed_time[job.size()] = 0; // initialize idle processed_time to 0
					previous_idle = 0; // change to busy
				}
			}

			previous_idle = 0; // change to busy just in case

			// handling response time
			if (vec_response_time_parity[index_min] == 0) // if the response_time wasn't handled
			{
				vec_response_time_parity[index_min] = 1;
				vec_response_time[index_min] = current_time; // put the current time in the response_time vector
			}

			vec_processed_time[index_min] = job[index_min].getServiceTime();
			vec_burst_time[index_min] = 0; // process is finished

			num_finished_process = num_finished_process + 1;
			end_time = current_time + job[index_min].getServiceTime();
			vec_end_time[index_min] = end_time; //save the time when the process was terminated
			// handling waiting_time
			vec_waiting_time[index_min] = current_time - job[index_min].getArrivalTime();
			// handling return_time
			vec_return_time[index_min] = end_time - job[index_min].getArrivalTime();

			temp_result.first = job[index_min].getProcessId();
			temp_result.second = vec_processed_time[index_min];
			result.push_back(temp_result);
			vec_processed_time[index_min] = 0; // initialize the processed time to 0

			current_time = current_time + job[index_min].getServiceTime();
		}
		first_time = 0;
	}


	return result;
}

std::vector<Unit> Scheduler::ShortestRemainingTimeFirst(const std::vector<Job> job) const {
	// your code here
	if (job.size() == 0)
		printf("The job list is empty \n");

	std::vector<Unit> result;
	Unit temp_result;
	//std::vector<Job> result_job;
	std::vector<int> vec_burst_time; // process burst time;
	std::vector<int> vec_waiting_time; // process waiting time;
	std::vector<int> vec_response_time_parity; // check response time
	std::vector<int> vec_return_time; // process terminated time - process arrival time
	std::vector<int> vec_response_time; // process response time
	std::vector<int> vec_end_time; // process terminated time
	std::vector<int> vec_processed_time; // processed time (�𸣰���)
	int i;
	int current_time; // current time
	int end_time; // process terminated time
	int num_finished_process = 0; // number of finished process - 1
	int index_min = job.size(); // index of most small burst time job.size() just for first loop
	int waitingT;
	int returnT;
	int responseT;
	int previous_idle = 1;
	int previous_index;
	int first_time = 1;

	//initialize response_time, processedtime, parity bit 
	for (i = 0; i < job.size(); i++)
	{
		vec_burst_time.push_back(job[i].getServiceTime());
		vec_waiting_time.push_back(0);
		vec_response_time_parity.push_back(0);
		vec_response_time.push_back(0);
		vec_return_time.push_back(0);
		vec_end_time.push_back(0);
		vec_processed_time.push_back(0);
	}


	vec_processed_time.push_back(0); // for CPU idle state add one more entity vec_processed_time[job.size()] = 0

	vec_burst_time.push_back(999); // parameter until the first time of process

	// increase current time and check if all processes are finished
	for (current_time = 0; num_finished_process < job.size(); current_time++)
	{
		previous_index = index_min; // get previous processes's index
		index_min = job.size();                                          // index_min initialization

		// find the index of the process that has the smallest burst_time
		for (i = 0; i < job.size(); i++)
		{
			// check arrival time                       &  check if it is smallest burst time               & if the burst time is not 0
			if (job[i].getArrivalTime() <= current_time && vec_burst_time[i] < vec_burst_time[index_min] && vec_burst_time[i]>0)
			{
				// process a different process
				index_min = i;
			}
		}
		// index_min has the index of the smallest burst_time process


		if (previous_index != index_min && vec_burst_time[previous_index] != 0 && vec_burst_time[previous_index] != 999) // preempted
		{
			temp_result.first = job[previous_index].getProcessId();
			temp_result.second = vec_processed_time[previous_index];
			result.push_back(temp_result);
			vec_processed_time[previous_index] = 0; // initialize the processed time to 0
		}


		if (index_min == job.size()) // no process to work with (the CPU is IDLE)
		{
			previous_idle = 1; // change to idle state
			vec_processed_time[job.size()] = vec_processed_time[job.size()] + 1;
		}

		else // there is a process to work with
		{
			if (previous_idle == 1) // idle to new process
			{
				if (first_time != 1)
				{
					temp_result.first = 0; // idle pid is 0
					temp_result.second = vec_processed_time[job.size()];
					result.push_back(temp_result);
					vec_processed_time[job.size()] = 0; // initialize idle processed_time to 0
					previous_idle = 0; // change to busy
				}
			}

			previous_idle = 0; // change to busy just in case

			// handling response time
			if (vec_response_time_parity[index_min] == 0) // if the response_time wasn't handled
			{
				vec_response_time_parity[index_min] = 1;
				vec_response_time[index_min] = current_time; // put the current time int the response_time vector
			}

			vec_processed_time[index_min] = vec_processed_time[index_min] + 1;
			vec_burst_time[index_min] = vec_burst_time[index_min] - 1; // if processed for one unit time

			if (vec_burst_time[index_min] == 0) // finished process
			{
				num_finished_process = num_finished_process + 1;
				end_time = current_time + 1;
				vec_end_time[index_min] = end_time; //save the time when the process was terminated
				// handling waiting_time
				vec_waiting_time[index_min] = end_time - job[index_min].getArrivalTime() - job[index_min].getServiceTime();
				// handling return_time
				vec_return_time[index_min] = end_time - job[index_min].getArrivalTime();

				temp_result.first = job[index_min].getProcessId();
				temp_result.second = vec_processed_time[index_min];
				result.push_back(temp_result);
				vec_processed_time[index_min] = 0; // initialize the processed time to 0
			}

		}
		first_time = 0;
	}

	return result;
}

std::vector<Unit> Scheduler::RoundRobin(const std::vector<Job> job, const time_type quantum) const {
    std::vector<std::tuple<int, int, int>> sort;
    std::queue<Unit> ReadyQueue; //(ProcessId, RemainingTime)
    std::vector<Unit> gantt;
    int time = 0;
    int process_exit = 0; //종료된 프로세스 count
    int next;


    if (job.size() > 1) {
        sort = new_sort(job);

        for (int i = 0; i < sort.size(); i++) { //0초에 도착한 프로세스있으면 Queue에 넣기
            int pid = std::get<0>(sort[i]);
            int at = std::get<1>(sort[i]);
            int index = std::get<2>(sort[i]);

            if (at == 0) {
                ReadyQueue.push(std::make_pair(pid, job[index].getServiceTime())); //0초에 도착한 것이 있으면 queue에 바로 넣어줌
            }
            else {
                next = i;
                break; //at이 0이 아니면 for문 벗어남
            }
        }

        while (process_exit != sort.size()) { //모든 프로세스가 종료될때까지 while문 실행

            if (ReadyQueue.empty()) { //Queue가 비어있으면
                gantt.push_back(std::make_pair(0, std::get<1>(sort[next]) - time)); //다음 프로세스가 실행될때까지 idle
                ReadyQueue.push(std::make_pair(std::get<0>(sort[next]), job[std::get<2>(sort[next])].getServiceTime())); //다음 프로세스 Queue에 넣기
                time = std::get<1>(sort[next]); //idle만큼 시간 추가
                next++; //Queue에 넣을 다음 프로세스 가리키기 위해 next 변경
            }

            int currentprocess = ReadyQueue.front().first; //현재 실행할 프로세스아이디 전달
            int remainingtime = ReadyQueue.front().second; //현재 실행한 프로세스 ST 전달

            if (remainingtime <= quantum) { //quantum보다 남은 시간이 더 적으면 그만큼만 실행
                gantt.push_back(std::make_pair(currentprocess, remainingtime));
                time += remainingtime;

                for (int i = next; i < sort.size(); i++) {//남은 프로세스들 중에 2초 지난 time 전에 들어온 프로세스를 queue에 넣어주기
                    if (std::get<1>(sort[i]) <= time) {
                        ReadyQueue.push(std::make_pair(std::get<0>(sort[i]), job[std::get<2>(sort[i])].getServiceTime())); //다음 프로세스 Queue에 넣기

                        if (i == sort.size() - 1) next = sort.size();
                    }
                    else { //남은 프로세스들이 현재 시간보다 뒤에 들어오면 next 값만 변경해주기
                        next = i;
                        break;
                    }
                }
                process_exit++; //종료된 프로세스 카운트
                ReadyQueue.pop(); //실행한 프로세스를 큐에서 제거
                continue;
            }
            else {
                time += quantum; //진행시간 늘리고
                remainingtime -= quantum; //남은 시간 줄이고
                gantt.push_back(std::make_pair(currentprocess, quantum));
            }



            for (int i = next; i < sort.size(); i++) {//남은 프로세스들 중에 2초 지난 time 전에 들어온 프로세스를 queue에 넣어주기
                if (std::get<1>(sort[i])<=time){
                    ReadyQueue.push(std::make_pair(std::get<0>(sort[i]), job[std::get<2>(sort[i])].getServiceTime())); //다음 프로세스 Queue에 넣기

                    if (i == sort.size() - 1) next = sort.size();
                }
                else { //남은 프로세스들이 현재 시간보다 뒤에 들어오면 next 값만 변경해주기
                    next = i;
                    break;
                }
            }
            ReadyQueue.push(std::make_pair(currentprocess, remainingtime)); //queue의 끝에 넣기
            ReadyQueue.pop(); //실행한 프로세스를 큐에서 제거
        }
    }
    else if (job.size() == 1) {
        int pid = job[0].getProcessId();
        int remainingtime = job[0].getServiceTime();
        int time = 0;

        if (job[0].getArrivalTime() > time) {
            gantt.push_back(std::make_pair(0, job[0].getArrivalTime() - time));
            time = job[0].getArrivalTime();
        }

        while (!(remainingtime <= 0)) {
            if (remainingtime < quantum)
                gantt.push_back(std::make_pair(pid, remainingtime));
            else
                gantt.push_back(std::make_pair(pid, quantum));


            remainingtime -= quantum;
            time += quantum;

        }
    }

    return gantt;
}

std::vector<Unit> Scheduler::NonpreemptivePrior(const std::vector<Job> job) const {
	std::vector<Unit> res;
	time_type current_time = 0;

	std::vector<Job> sorted_job = job;
	sort(sorted_job.begin(), sorted_job.end(), [](Job& a, Job& b) {
		return a.getArrivalTime() < b.getArrivalTime();
		});

	auto prior_comp = [](Job& a, Job& b) {
		if (a.getPriority() == b.getPriority()) return a.getServiceTime() > b.getServiceTime();
		return a.getPriority() > b.getPriority();
	};
	std::priority_queue<Job, std::vector<Job>, decltype(prior_comp)> pq(prior_comp);

	unsigned int cleared_job = 0, last_job = 0;
	while (cleared_job < sorted_job.size()) {
		while (last_job < sorted_job.size() && sorted_job[last_job].getArrivalTime() <= current_time) {
			pq.push(sorted_job[last_job]);
			last_job++;
		}
		if (pq.empty()) {
			assert(last_job < sorted_job.size());
			time_type next_time = sorted_job[last_job].getArrivalTime();
			res.emplace_back(0, next_time - current_time);
			current_time = next_time;
		}
		else {
			Job j = pq.top();
			pq.pop();
			time_type runtime;

			runtime = j.getServiceTime();

			res.emplace_back(j.getProcessId(), runtime);
			current_time += runtime;
			cleared_job++;
		}
	}

	return res;
}

std::vector<Unit> Scheduler::PreemptivePrior(const std::vector<Job> job) const {
	std::vector<Unit> res;
	time_type current_time = 0;

	std::vector<Job> sorted_job = job;
	sort(sorted_job.begin(), sorted_job.end(), [](Job& a, Job& b) {
		return a.getArrivalTime() < b.getArrivalTime();
		});

	auto prior_comp = [](Job& a, Job& b) {
		if (a.getPriority() == b.getPriority()) return a.getServiceTime() > b.getServiceTime();
		return a.getPriority() > b.getPriority();
	};
	std::priority_queue<Job, std::vector<Job>, decltype(prior_comp)> pq(prior_comp);

	unsigned int cleared_job = 0, last_job = 0;
	while (cleared_job < sorted_job.size()) {
		while (last_job < sorted_job.size() && sorted_job[last_job].getArrivalTime() <= current_time) {
			pq.push(sorted_job[last_job]);
			last_job++;
		}
		if (pq.empty()) {
			assert(last_job < sorted_job.size());
			time_type next_time = sorted_job[last_job].getArrivalTime();
			res.emplace_back(0, next_time - current_time);
			current_time = next_time;
		}
		else {
			Job j = pq.top();
			pq.pop();
			time_type next_job_start, runtime;

			if (last_job < sorted_job.size()) {
				next_job_start = sorted_job[last_job].getArrivalTime();
				runtime = std::min(j.getServiceTime(), next_job_start - current_time);
			}
			else runtime = j.getServiceTime();

			if (res.empty() || res.back().first != j.getProcessId()) res.emplace_back(j.getProcessId(), runtime);
			else res.back().second += runtime;
			current_time += runtime;

			time_type new_service_time = j.getServiceTime() - runtime;
			if (new_service_time > 0) {
				j.updateServiceTime(new_service_time);
				pq.push(j);
			}
			else cleared_job++;
		}
	}

	return res;
}
std::vector<Unit> Scheduler::NonpreemptivePriorRR(const std::vector<Job> job, const int quantum) const {
	std::vector<Unit> res;
	time_type current_time = 0;

	std::vector<Job> sorted_job = job;
	sort(sorted_job.begin(), sorted_job.end(), [](Job& a, Job& b) {
		return a.getArrivalTime() < b.getArrivalTime();
		});

	auto prior_comp = [](Job& a, Job& b) {
		if (a.getPriority() == b.getPriority()) return a.getServiceTime() > b.getServiceTime();
		return a.getPriority() > b.getPriority();
	};
	std::priority_queue<Job, std::vector<Job>, decltype(prior_comp)> pq(prior_comp);

	unsigned int cleared_job = 0, last_job = 0;
	while (cleared_job < sorted_job.size()) {
		while (last_job < sorted_job.size() && sorted_job[last_job].getArrivalTime() <= current_time) {
			pq.push(sorted_job[last_job]);
			last_job++;
		}
		if (pq.empty()) {
			assert(last_job < sorted_job.size());
			time_type next_time = sorted_job[last_job].getArrivalTime();
			res.emplace_back(0, next_time - current_time);
			current_time = next_time;
		}
		else {
			Job j = pq.top();
			pq.pop();
			time_type next_job_start, runtime;

			runtime = std::min(j.getServiceTime(), quantum);

			res.emplace_back(j.getProcessId(), runtime);
			current_time += runtime;

			time_type new_service_time = j.getServiceTime() - runtime;
			if (new_service_time > 0) {
				j.updateServiceTime(new_service_time);
				pq.push(j);
			}
			else cleared_job++;
		}
	}

	return res;
}
