<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<!-- PROJECT LOGO -->

# **<center>CPU Scheduling Simulator</center>**
## **<center>My First Project</center>**



<!-- TABLE OF CONTENTS -->
## Contents
<details>
  <summary>Table of Contents</summary>
  <ol>
  <li><a href="#brief-overview">Brief Overview</a></li>
  <li><a href="#built-with">Built With</a></li>
  <li><a href="#roadmap">Roadmap</a></li>
  <li><a href="#class-diagram">Class Diagram</a></li>
  <li><a href="#ui-&-functions">UI & Functions</a></li>
  <li><a href="#my-contribution">My Contribution</a></li>
  <li><a href="#what-i-learned">What I Learned</a></li>
  <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details


<!-- ABOUT THE PROJECT -->
## Brief Overview

**- CPU Scheduling Simulator (7 different types)**
  - FCFS, SJF, SRTF, RR, non preemptive priority, preemptive priority, non preemptive priority with RR  
  
**- Input**
  - Number of processes, Process ID, Arrival time, Service time, Priority, Time quantum(for RR)
  
**- Output**
  - Gantt Chart(Using GUI), Average waiting time and waiting time per process, Average return time and return time per process, Average response time and response time per process

<p align="right">(<a href="#readme-top">back to top</a>)</p>



## Built With

* <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C++&logoColor=white"/>
* <img src="https://img.shields.io/badge/Qt-41CD52?style=flat-square&logo=Qt&logoColor=white"/>

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [O] Skeleton code
- [O] Alogrithm implementation
    - [O] Algorithm TEST
- [O] UI Platform implementation
    - [O] UI TEST

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CLASS DIAGRAM -->
## Class Diagram
![함수 다이어그램](https://user-images.githubusercontent.com/105041834/190543107-1b40b57c-710f-46a4-8a92-1e74d87d6b56.jpg)


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- UI & FUNCTIONS -->
## UI
<img width="704" alt="GUI" src="https://user-images.githubusercontent.com/105041834/190588251-89d6ed99-f475-4e31-a5ef-08f89b6313cc.png">

## Functions
<ol>
<li>Scheduling algorithm selection</li>
<li>Process input</li>
<li>Input process list display</li>
<li>Quantum apply</li>
<li>Gantt chart display</li>
<li>display of average waiting time, return time, response time</li>
<li>display of waiting time, return time, response time for every process</li>
</ol>

<!-- MY CONTRIBUTIONS -->
## My Contribution
- Algorithm Implementation (SRTJ, SJF)
  - OS_Term_Project/source/Scheduler.cpp
- Algorithm debugging and testing (program's robustness)
  - OS_Term_Project/source/testing.cpp (annotation)
- Refactoring
  - Modularization for efficient debugging
<details>
<summary>Refactoring Details</summary>
  
**- Previous Design**
  
> Previously there was an object(Statistics) which stored the waiting time, return time, response time of a job. After the termination of the schedule algorithm function in Scheduler the Job object's Statistics(waitingTime, returnTime, responseTime) values were all updated and the schedule algorithm function returned the Gantt Chart(std::vector).

```
# deleted class
Statistics class {
Instance variable:
int waitingTime
int returnTime
int responseTime

Instance method:
Statistics ()
Statistics (const int, const int, const int)
void update (const Statistics)
int getWaitingTime() const
int getReturnTime() const
int getResponseTime() const
void updateResponseTime(int)
void updateReturnTime(int)
void updateResponseTime(int)
}

# Only the instance method below was deleted
Job class {
Instance variable:
int processID
int arrivalTime
int serviceTime
int priority
Statistics stat

Instance method:
...
void updateStat(const Statistics)
...
}
```

**- Refactored design**
  
> We deleted the Statistics class and all the methods related to it. The schedule algorithm function **only** returned the Gantt Chart(std::vector). We made additional functions(input : Gantt Chart) that calculated the waiting time, return time, response time per process in the StatisticsManager.
</details>
<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- WHAT I LEARNED -->
## What I learned
- **Programming skills**  
Because I had just started majoring in computer science, the project itself was quite challenging. The implementation of the skeleten code improved my skills to design objects and object methods. Furthermore, through peer code reviews I learned the importance of clean coding and methods to avoid when coding. One of my teammates taught me to always code in a way that the code is readible to other people without any annotations.

- **The importance of modularization**  
When testing the robustness of our simulator with many test cases the simulator frequently failed and had errors. Due to the complicated design of the objects it was hard to troubleshoot all the problems. By dividing the object methods into many functions that have a single role, we could efficiently debug and update the program.

- **The importance of communication when doing a team project**  
Due to the misleading variable name and design we had a misunderstanding of what kind of function we were making. This made our team waste a significant amount of time. After this instance I learned that for clarification annotations are not an option.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Sdlkfjv](https://github.com/Sdlkfjv)
* [JEONGSY99129](https://github.com/JEONGSY99129)
* [kimjg1119](https://github.com/kimjg1119)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
