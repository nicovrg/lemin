# Lem-in

Lem-in is an initiation to graph theory. Students are asked to work on an algorithm to optimize flow of ants through a maze composed of rooms linked between each others.
It's an opportunity to work on graph traversal algorithm such as dfs/bfs (deepth & breath first search), flow optimisation algorithms such as Ford-Fulkerson or 
edmond karp


## Input format

Here is a map example:
![simple](img/lemin_subject_example.png)

```
Ant: a unit of flow
Room: node
Link: edge
```

At the begining of the game, all ants are packed in start. 
Each turn ants can move, but they can't be multiple ants in a room or a link (except start and end rooms).

In this project we seek to optimized the number of turns we need to move all ants from start to end as well as the time needed to run the algorithm.

## Project

The first part of the project consist to parse all data on stdin and store them under a data structure that represent our graph.
The second part is the algorithm that compute the best combinaison of moves
The thrid part is the solution output that print on stdin the list of moves to do
The fourth and optionnal part is a visualisator that read the algorithm output and create a graphic display of it.


## Parsing

We read stdin to get all infos (number of ants, all rooms, all links between rooms ...)

We use mainly list because they are easy to use and allow us to manipulate and record data with a lot of freedom. We could have use a hash table, a binary tree or a table of list but we didn't spend time implementing this because we under estimate the time parsing would take. 

At the end of the project, we figured out parsing was taking as much as three quater of the total run time, but reworking the data structure would mean making tremendous changes to the project so we just took some time to optimised our list manipulation, and it was sufficient to be under the 3 sec, so we can get all points here.

## Algorithm

bfs
edmond karp

## Output format

Once we now witch configuration is the best, we put it in a buffer and print it when it's full or when there is nothing left to add in it. This output will be use by the graphic display.


## Graphic display

The visual mode for this project requires networkX and matplotlib. To install them: 

* [NetworkX](https://networkx.github.io/) - Used to generate the nodes, connections and node placement in the visualizer
* [Matplotlib](https://matplotlib.org/) - Plot the colorful dots represe

```
pip3 install netowrkX
pip3 install matplotlib
```


Usage:
![simple](img/lemin_visu_usage.png)

Simple graph:
![simple](img/lemin_visu_one.mov)

Medium graph:
![simple](img/lemin_visu_two.png)

Big graph:
![simple](img/lemin_visu_four.png)
