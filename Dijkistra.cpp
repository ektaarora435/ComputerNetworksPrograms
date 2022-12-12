#include <iostream>
 #include <iomanip>
 #define MAX_NODES 20

using namespace std;


class Set
{

public:
int edge;
int vertex;
int path[MAX_NODES];
int dist[MAX_NODES];
int adjMatrix[MAX_NODES][MAX_NODES];


void input(int v, int e)
{
edge = e; vertex = v;
for (int i = 0; i < v; i++)// initializing the adjacency matrix
for (int j = 0; j < v; j++) adjMatrix[i][j] = 0;
int src, dest, weight;
for (int i = 0; i < edge; i++)
{
cout << "\nEDGE " << (i + 1)
<< "\n	\n";
cout << "Enter Source: "; cin >> src;
cout << "Enter Destination: "; cin >> dest;
cout << "Enter Weight: "; cin >> weight;
adjMatrix[src - 1][dest - 1] = weight; adjMatrix[dest - 1][src - 1] = weight;
}

}


void display()
{
for (int i = 0; i < vertex; i++)
{
for (int j = 0; j < vertex; j++)
cout << setw(5) << adjMatrix[i][j] << " "; cout <<"\n";
}
}


void dijkstra(int src)
{
bool visited[MAX_NODES];


for (int i = 0; i < vertex; i++)
{
visited[i] = false; dist[i] = INT_MAX;
}
path[src] = -1;//source node dist[src] = 0;
for (int i = 0; i < vertex- 1; i++)
{
int u = minDist(visited);//nearest node visited[u] = true;
for (int v = 0; v < vertex; v++)

if (visited[v] == false && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v])
{
path[v] = u;
dist[v] = dist[u] + adjMatrix[u][v];
}
}
cout << "\nDestn Node \t Distance \t Shortest Path";//displaying

cout << "\n	\t\t";

for (int i = 0; i < vertex; i++)
{
cout <<"\n"<< (i + 1)<< " \t\t " << dist[i]<< " \t\t " << (src + 1);
printShortestPath(i);
}
}


int minDist(bool *visited)
{
int min = INT_MAX, min_index; for (int v = 0; v < vertex; v++)
if (visited[v] == false && dist[v] <= min)
{
min = dist[v]; min_index = v;
}
return min_index;
}

void printShortestPath(int node)
{
if (path[node] == -1) return;
printShortestPath(path[node]); cout << " -> " << (node + 1);
}
};


int main()
{
int ver, ed; Set s;

cout << "Enter total number of Nodes: "; cin >> ver;
cout << "Enter number of Edges: "; cin >> ed;
s.input(ver, ed); cout<<"\nGRAPH\n"; cout<<"	\n";
s.display(); cout <<"\n";
cout << "Enter Source Node: "; cin >> ver;
s.dijkstra(ver - 1);
return 0;
}
