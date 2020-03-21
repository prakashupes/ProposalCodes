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

![download (3)](https://user-images.githubusercontent.com/44925217/77232179-77271200-6bc5-11ea-97f5-f372df77786f.gif)


#### 2. Two Graphs Common Spanning Trees:
![download (2)](https://user-images.githubusercontent.com/44925217/77232235-cec57d80-6bc5-11ea-809e-2b7ead970edf.gif)

