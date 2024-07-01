### Mini Tutorial for the Graph class

    1. graph<T> -- unweighted graph
    2. weighted_graph<T> -- weighted graph
graph class algorithms:
    - dfs
    - bfs
    - connected_components
    - cycle
    - topological_sort
    - bipartite
    - bridge
    - connected
    - visualize

weighted_graph class algorithms:
    - dfs
    - bfs
    - shortest_path
    - connected_components
    - cycle
    - topological_sort
    - prim
    - bipartite
    - bridge
    - connected
    - visualize

There are also some functions for both classes like **has_edge(u, v)** that checks if an edge exists from node u to node v, **size()** that returns the number of elements in the graph, **empty()** that checks if a graph is empty and **empty()** that empties the graph.You can see more about graph algorithms [here](https://github.com/nikolasfil/AlgoDay/tree/main/AlgoDay-1/Spiros).
### **DFS**:
```cpp
#include <graph.h>
graph<int> g("directed");
g.add_edge(1, 2);
g.add_edge(4, 5);
g.add_edge(5 , 6);
g.add_edge(2, 4);

//returns the path of the dfs.
std::vector<T> dfs = g.dfs();
```

### **BFS**:
```cpp
#include <graph.h>
graph<int> g("directed");
g.add_edge(1, 2);
g.add_edge(4, 5);
g.add_edge(5 , 6);
g.add_edge(2, 4);

//returns the path of the bfs.
std::vector<T> bfs = g.bfs();
```

### **connected_components**:
```cpp
#include <graph.h>
graph<char> g("undirected");
g.add_edge('a', 'b');
g.add_edge('b','c');
g.add_edge('g','h');
//returns the number of connected components(islands)
std::cout << g.connected_components() << '\n';
```

### **cycle**:
```cpp
#include <graph.h>
#include <string>
graph<std::string> g("undirected");
g.add_edge("hello", "world");
g.add_edge("hello", "mars");
g.add_edge("mars", "world"); 
//checks if a cycle exist in the graph.
if(g.cycle()){
    std::cout << "cycle detected" << '\n'
}
```

### **topological_sort**:
```cpp
#include <graph.h>
graph<int> g("undirected");
g.add_edge(1, 4);
g.add_edge(4, 5);
g.add_edge(5, 2);
g.add_edge(2, 8);

//returns the topological order of the elements.
std::vector<int> topo = g.topological_sort();
```

### **bipartite**:
```cpp
#include <graph.h>
graph<int> g("undirected");
g.add_edge(1, 4);
g.add_edge(4, 5);
g.add_edge(5, 2);
g.add_edge(2, 8);

//checks if a graph is bipartite.
if(g.bipartite()){
    std::cout << "graph is bipartite" << '\n'
}
```

### **bridge**:
```cpp
#include <graph.h>
graph<int> g("undirected");
g.add_edge(1, 4);
g.add_edge(4, 5);
g.add_edge(5, 2);
g.add_edge(2, 8);

//returns the bridges of the graph(works with weighted graph as well).
std::vector<std::vector<int>> bridges = g.bridge(1);
```

### **visualize**:
```cpp
#include <graph.h>
graph<int> g("undirected");
g.add_edge(1, 4);
g.add_edge(4, 5);
g.add_edge(5, 2);
g.add_edge(2, 8);

// returns a .dot file that automatically opens
// using graphviz plugins on vscode(or locally with 
// command lines).
g.visualize();
```

### **shortest_path**:
```cpp
#include <weighted_graph.h>
weighted_graph<int> g("undirected");
g.add_edge(1, 4, 2);
g.add_edge(4, 5, 6);
g.add_edge(5, 2, 9);
g.add_edge(2, 8, 10);

// returns the shortest path from 1 to 2.
std::cout << g.shortest_path(1, 2) << '\n';
```

### **prim**:
```cpp
#include <weighted_graph.h>
weighted_graph<std::string> g("undirected");
g.add_edge("Athens", "Thessaloniki", 15);
g.add_edge("Patras", "Lamia", 50);
g.add_edge("Athens", "Lamia", 10);
g.add_edge("Kozani", "Thessaloniki", 13);
g.add_edge("Athens", "Kozani", 100);

// returns the minimum spanning tree starting 
// from the node Athens.
std::cout << g.prim("Athens") << '\n';
```

### **connected**:

```cpp
#include <graph.h>
graph<std::string> g("undirected");
g.add_edge("hello", "world");
g.add_edge("world", "universe");
g.add_edge("hello", "universe");

// return true if graph is connected 
if(g.connected()){
    std::cout << "graph is connected" << '\n';
}
```

### **topological_sort**:
```cpp
#include <weighted_graph.h>
weighted_graph<int> g("undirected");
g.add_edge(1, 2, -6);
g.add_edge(2, 3, 5);
g.add_edge(3, 1, -2);

// returns the shortest paths from starting point 1 using an unordered_map
// bellman ford algorithm is capable of detecting negative cycles
// so bell_ford[2] = -INF, bell_ford[3] = -INF, etc...
std::unordered_map<std::string, double> bell_ford = g.bellman_ford(1);
```