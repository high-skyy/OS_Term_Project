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
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#brief-overview">Brief Overview</a></li>
    <li><a href="#built-with">Built With</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#class-diagram">Class Diagram</a><li>
    <li><a href="#my-contribution">My Contribution</a></li>
    <li><a href="#what-i-learned">What I Learned</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## Brief Overview

**- 7가지 CPU Scheduling Simulator 개발**
  - FCFS, SJF, SRTF, RR, 비선점 Priority, 선점 Priority, 비선점 Priority with RR  
  
**- Input**
  - (프로세스 수), 프로세스ID, 도착시간, 서비스시간, 우선순위, 시간할당량  
  
**- Output**
  - gantt chart, 각 프로세스 별 대기시간 및 평균 대기시간, 각 프로세스 별 반환시간 및 평균 반환시간, 각 프로세스 별 응답시간 및 평균 응답시간

<p align="right">(<a href="#readme-top">back to top</a>)</p>



## Built With

* <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C++&logoColor=white"/>
* <img src="https://img.shields.io/badge/Qt-41CD52?style=flat-square&logo=Qt&logoColor=white"/>

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [O] Skeleton code
- [O] 7 Alogrithm implementation
    - [O] Algorithm TEST
- [O] UI Platform implementation
    - [O] UI TEST

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CLASS DIAGRAM -->
## Class Diagram
![함수 다이어그램](https://user-images.githubusercontent.com/105041834/190543107-1b40b57c-710f-46a4-8a92-1e74d87d6b56.jpg)


<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MY CONTRIBUTION -->
## My Contribution
- Algorithm Implementation (SRTJ, SJF)
- Algorithm debugging and testing (program's robustness)
- Refactoring
  - Modularization for efficient debugging

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- WHAT I LEARNED -->
## What I Learned
- **프로그래밍 능력**  
스켈레톤 코드를 직접 고민해서 구현하고 수정해 나가면서 C와 C++ 코딩 능력뿐만이 아닌 프로그램을 구현함에 있어 Class의 설계부터 Method의 구현까지 전체적인 흐름을 알게 되었다.
- **Modularization의 중요성**  
여러 테스트 케이스를 통해 프로그램의 robustness를 측정하는데 fail이 일어날 때마다 디버깅을 하기가 힘들었는데 여러 역할을 하는 함수를 분해하고 modularization을 시킴으로서 효율적으로 디버깅 및 버전 업데이트를 할 수 있게 되었다.
- **Communication의 중요성**  
팀 별로 프로젝트가 진행될 때 다른 팀원들과 각 변수가 갖는 logical meaning에 대한 오해가 있어 문제가 발생하였으며 이는 추후에 주석을 자세하게 달아줌으로서 해결.

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
