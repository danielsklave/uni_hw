/*
 * http://olimps.lio.lv/rezultati_sikak.php?queue_id=58625
*/
#include <iostream>
#include <fstream>
using namespace std;

class Graph {

   int size;
   int **matrix;
   bool checkCycle(int v, bool *checked, bool *recur);

   public:
      Graph(int s);
      ~Graph();
      void addEdge(int v, int w);
      bool isCyclic();
      int getRoot();
      int getHeight(int root);
};

Graph::Graph(int s) {

   size = s;
   matrix = new int*[size];

   for(int i = 0; i < size; ++i) 
   {
      matrix[i] = new int[size]; 
      for(int j = 0; j < size; ++j)
         matrix[i][j] = 0;
   }
}

Graph::~Graph() {
   for (int i = 0; i < size; i++)
      delete[] matrix[i];
   delete[] matrix;
}

void Graph::addEdge(int v, int u) {
   matrix[v][u] = 1;
   matrix[u][v] = -1;
}

bool Graph::checkCycle(int v, bool *checked, bool *recur) {

	if (!checked[v]) 
   {
		checked[v] = recur[v] = true;
      for (int i = 0; i < size; i++) 
      {
         if (matrix[v][i] != 1) continue;
			if (!checked[i] && checkCycle(i, checked, recur))
				return true;
			if (recur[i]) return true;
		}
	}
	recur[v] = false;
	return false;
}

bool Graph::isCyclic() {

	bool *checked = new bool[size], *recur = new bool[size];

	for (int i = 0; i < size; i++)
		if (checkCycle(i, checked, recur)) 
      {
         delete[] checked;
         delete[] recur;
			return true;
      }
   delete[] checked;
   delete[] recur;
	return false;
}

int Graph::getRoot() {

   int root = -1;
   for(int i = 0; i < size; i++) 
   {
      int inPoints = 0;
      for(int j = 0; j < size; j++)
         if(matrix[i][j] == -1) inPoints++;

      if(inPoints > 1) return -1;
      if(inPoints == 0) root = i;
   }
   return root;
}

int Graph::getHeight(int root) {

   int height = 0;
   for(int i = 0; i < size; i++) 
   {
      if(matrix[root][i] == 1) 
      {
         int h = getHeight(i);
         if (h > height) height = h;
      }
   }
   return height + 1;
}

int main() {

   ifstream input("koks.dat"); 
   int left, right;

	input >> left >> right;
   Graph graph(left);

   while(input >> left >> right) graph.addEdge(--left, --right);

	input.close();

	ofstream output("koks.rez");

   int root = graph.getRoot();

   if (root > -1 && !graph.isCyclic()) 
      output << root + 1 << ' ' << graph.getHeight(root) - 1;
   else
      output << "0 0"; 

	output.close();
}
