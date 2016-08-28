#ifndef astar_h
#define astar_h
using namespace std;

class Astar {
public:
	int search( int, int, char**, pair<int,int>, pair<int,int> ); 
	// A * search for shortest path between two points

private:
	int** allocateCostMap(int, int);
	void deleteCostMap(int**,int);
	struct node {
		int x, y;
		int cost;
		int f;
	}; // node for A* search
	struct compare  
	{  
		bool operator()(const node l, const node r)  {  return l.f > r.f;  }  
	};
};

#endif
