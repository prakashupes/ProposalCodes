# ProposalCodes
This repository contains Example codes of GSoc proposal.
The project consists of the implementation of two algorithms:<br>
><b>1.Lengauer Tarjan Dominator Tree <br>
>2.Two Graphs Common Spanning Trees</b>

The algorithms are going to be taken from Boost Graph Library (BGL). The first part of this project is to provide support for Lengauer Tarjan Dominator Tree in pgRouting. Lengauer Tarjan Dominator Tree is applied in many routing applications, such as if the user wants to go from city A to city B and there are multiple routes but all the routes are diverting from city X then the user can find out city X by using this algorithm.
And the second part of this project is to provide support for Two Graphs Common Spanning Trees in pgRouting.  Mint, Read and Tarjan (MRT) algorithm is used to calculate Two Graphs Common Spanning Trees.



### Dependencies 
>1.Installed Boost Libraries <br>
>2. GNU G++ compiler

#### Steps of compilation:
```
 c++ -I path/to/boost_1_66_0 file_name.cpp -o file_name
```
```
 ./file_name
```
### Visualization:
#### 1. Lengauer Tarjan Dominator Tree:
Visualizaion:
![Alt Text](https://lh3.googleusercontent.com/8hZ2IcKZ0wvWKWJ9lc5VTEIRdc-LNzTijtWTXTSCcFIou5DYC1kSLbkR2-QLnNg3lCjdgZELZzPKQ88BnvqFWKtS9OjO_rfgX1T2rj3AD8YbGWRln3wZx-CFuEzyhtRNhBYCZgnHytzZAEx1cspfM8ihm9lbDZzOP65IEHzFIDEMnHQE1atA5TAy1tbBN8MmJ_4mmc8Q8Yh71s8Wy1gyyG4mwXeDEbR7DzCeSz66X1Utq25zyQ-BC1zfpO3ZPZcuEHn6N-RdPJOVJ4oXQq31xloHVnxUt0Tr_zAas5n8fCTgsvkaZZJ2zT2NypYj9MzRwywj0PH_85J0GUo9IvK7N9hwpWbNgnL6M4eD2MXbfSbZmq1YW7IBcXbskHBGiIVCEEp-obX5yoEfWPpp5kd0U50lUc9CixvMQK5ZOF7z0Lx84V3AJiSQMdw0Ga8kfS2tPvB_azUHmxY4-SGe8D9NqC0jyGFtsooacMSqjMm8wzkKhNqqVmrGZQQN76ODRG283m7UT9y9iTPdXOwuMVcvhtRAo_GvP51dOwW7YaV0joDSdH3_JBPC_DNB0aC-_VvmOPTPAYa5Yk9z5HkrlpFBZJnu61y9DtZNnvTzE369lWUbcVmMmrwXdjB3G4JHIIG4kFYVL-zPbsQxjFRnSc9BryjG1AU9pYy-LgcpQfL0P-6s_N5t6Xk3J-o3GNEZ=w720-h405-no)

