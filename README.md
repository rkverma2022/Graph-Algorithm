# Graph-Algorithm
Graph Algorithm 

**A. Graph Representation** 
1. Adjacency Matrix

      Space Complexity = O(n^2)


2. Adjacency List
   

      Space Complexity for undirected = 2 * E

   
      Space Complexity for directed = E


**B. Graph Traversal**

1. BFS

         visit the 0 - level, --> 1 - level --> 2 - level ...
2. DFS
3.
4. <img>https://github.com/rkverma2022/Graph-Algorithm/assets/112231455/219574ee-9678-4391-83e7-ebf3d3f9d757 </img>

5. cycle detection

         5A. BFS
         5B. DFS
6. Min Distance in given grid

         https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1 

7. Bipartite Graph

         https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

8. Cycle in Directed Graph

         https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

9. Topological Sort (only work for DAG (Directed Acyclic Graph) )

          https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

10. Kahn Topological Sort (BFS)


           step 1. find the indegree of each vertex put in a list
           step 2. put the nodes into a queue whose indegree = 0
           step 3. do bfs untill the queue get empty
              step 3.1 take the front node from queue and push into ans
                  step 3.2 go through all the child of node and decrease their indegree
                      step 3.3 push the child node into queue when indegree = 0
