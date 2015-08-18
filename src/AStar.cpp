// Astar.cpp
// http://en.wikipedia.org/wiki/A*
// Compiler: Dev-C++ 4.9.9.2
// FB - 201012256

#include "AStar.h"
using namespace std;

const int n=60; // horizontal size of the map
const int m=60; // vertical size size of the map
static int map[n][m];
static int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
static int open_nodes_map[n][m]; // map of open (not-yet-tried) nodes
static int dir_map[n][m]; // map of directions
const int dir=4; // number of possible directions to go at any position
// if dir==4
static int dx[dir]={1, 0, -1, 0};
static int dy[dir]={0, 1, 0, -1};
// if dir==8
//static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
//static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};

AStar::AStar(){

    // create empty map
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++) map[x][y]=0;
    }

    // fillout the map matrix with a '+' pattern
    for(int x=n/8;x<n*7/8;x++)
    {
        map[x][m/2]=1;
    }
    for(int y=m/8;y<m*7/8;y++)
    {
        map[n/2][y]=1;
    }

}

AStar::~AStar(){

}

class node
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

    public:
        node(int xp, int yp, int d, int p)
            {xPos=xp; yPos=yp; level=d; priority=p;}

        int getxPos() const {return xPos;}
        int getyPos() const {return yPos;}
        int getLevel() const {return level;}
        int getPriority() const {return priority;}

        void updatePriority(const int & xDest, const int & yDest)
        {
             priority=level+estimate(xDest, yDest)*10; //A*
        }

        // give better priority to going strait instead of diagonally
        void nextLevel(const int & i) // i: direction
        {
             level+=(dir==8?(i%2==0?10:14):10);
        }

        // Estimation function for the remaining distance to the goal.
        const int & estimate(const int & xDest, const int & yDest) const
        {
            static int xd, yd, d;
            xd=xDest-xPos;
            yd=yDest-yPos;

            // Euclidian Distance
            d=static_cast<int>(sqrt(xd*xd+yd*yd));

            // Manhattan distance
            //d=abs(xd)+abs(yd);

            // Chebyshev distance
            //d=max(abs(xd), abs(yd));

            return(d);
        }
};

// Determine priority (in the priority queue)
bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
}

// A-star algorithm.
// The route returned is a string of direction digits.
string AStar::pathFind( const int & xStart, const int & yStart,
                 const int & xFinish, const int & yFinish )
{
    static priority_queue<node> pq[2]; // list of open (not-yet-tried) nodes
    static int pqi; // pq index
    static node* n0;
    static node* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi=0;

    // reset the node maps
    for(y=0;y<m;y++)
    {
        for(x=0;x<n;x++)
        {
            closed_nodes_map[x][y]=0;
            open_nodes_map[x][y]=0;
        }
    }

    // create the start node and push into list of open nodes
    n0=new node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    open_nodes_map[x][y]=n0->getPriority(); // mark it on the open nodes map

    // A* search
    while(!pq[pqi].empty())
    {
        // get the current node w/ the highest priority
        // from the list of open nodes
        n0=new node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pqi].pop(); // remove the node from the open list
        open_nodes_map[x][y]=0;
        // mark it on the closed nodes map
        closed_nodes_map[x][y]=1;

        // quit searching when the goal state is reached
        //if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==xFinish && y==yFinish)
        {
            // generate the path from finish to start
            // by following the directions
            path="";
            while(!(x==xStart && y==yStart))
            {
                j=dir_map[x][y];
                c='0'+(j+dir/2)%dir;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }

            // garbage collection
            delete n0;
            // empty the leftover nodes
            while(!pq[pqi].empty()) pq[pqi].pop();
            return path;
        }

        // generate moves (child nodes) in all possible directions
        for(i=0;i<dir;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];

            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || map[xdx][ydy]==1
                || closed_nodes_map[xdx][ydy]==1))
            {
                // generate a child node
                m0=new node( xdx, ydy, n0->getLevel(),
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);

                // if it is not in the open list then add into that
                if(open_nodes_map[xdx][ydy]==0)
                {
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    pq[pqi].push(*m0);
                    // mark its parent node direction
                    dir_map[xdx][ydy]=(i+dir/2)%dir;
                }
                else if(open_nodes_map[xdx][ydy]>m0->getPriority())
                {
                    // update the priority info
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    // update the parent direction info
                    dir_map[xdx][ydy]=(i+dir/2)%dir;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].top().getxPos()==xdx &&
                           pq[pqi].top().getyPos()==ydy))
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pq[pqi].pop(); // remove the wanted node

                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    return ""; // no route found
}

void AStar::main(DataKeeper &dataKeeper)
{

    srand(time(NULL));

    // randomly select start and finish locations
/*    switch(switchVal)
    {
        case 0: startX=0;startY=0;endX=n-1;endY=m-1; break;
        case 1: startX=0;startY=m-1;endX=n-1;endY=0; break;
        case 2: startX=n/2-1;startY=m/2-1;endX=n/2+1;endY=m/2+1; break;
        case 3: startX=n/2-1;startY=m/2+1;endX=n/2+1;endY=m/2-1; break;
        case 4: startX=n/2-1;startY=0;endX=n/2+1;endY=m-1; break;
        case 5: startX=n/2+1;startY=m-1;endX=n/2-1;endY=0; break;
        case 6: startX=0;startY=m/2-1;endX=n-1;endY=m/2+1; break;
        case 7: startX=n-1;startY=m/2+1;endX=0;endY=m/2-1; break;
    }*/

    setStartDest(dataKeeper);

    cout<<"Map Size (X,Y): "<<n<<","<<m<<endl;
    cout<<"Start: "<<startX<<","<<startY<<endl;
    cout<<"Finish: "<<endX<<","<<endY<<endl;
    // get the route
    clock_t start = clock();
	pathFind(startX, startY, endX, endY);
    if(path=="") cout<<"An empty route generated!"<<endl;
    clock_t end = clock();
    double time_elapsed = double(end - start);
    cout<<"Time to calculate the route (ms): "<<time_elapsed<<endl;
    cout<<"Route:"<<endl;
    cout<<path<<endl<<endl;
    dataKeeper.setPath(path);

}

void AStar::newObstacle(int xObj, int yObj){
	map[xObj][yObj] = 1;
}

void AStar::newPath(DataKeeper &dataKeeper){
	cout << "I'm here 2" << endl;
	this->path=dataKeeper.getPath();
}

void AStar::setStartDest(DataKeeper &dataKeeper){
    this->startX=dataKeeper.getCurrentX();
    this->startY=dataKeeper.getCurrentY();
    this->endX=dataKeeper.getDestX();
    this->endY=dataKeeper.getDestY();
}

void AStar::displayMap(){
	cout << "I'm here 4" << endl;
    // follow the route on the map and display it
	if(path.length()>0)
	{
		int j; char c;
		int x=startX;
		int y=startY;
		map[x][y]=2;
		for(int i=0;i<path.length();i++)
		{
			c =path.at(i);
			j=atoi(&c);
			cout << "test" << endl;
			x=x+dx[j];
			y=y+dy[j];
			map[x][y]=3;
		}
		map[x][y]=4;

	}
	cout << "I'm here 5" << endl;
	// display the map with the route
	for(int y=0;y<m;y++)
	{
		for(int x=0;x<n;x++)
			if(map[x][y]==0)
				cout<<".";
			else if(map[x][y]==1)
				cout<<"O"; //obstacle
			else if(map[x][y]==2){
				cout<<"S"; //start
				map[x][y] = 0;
			}
			else if(map[x][y]==3){
				cout<<"R"; //route
				map[x][y] = 0;
			}
			else if(map[x][y]==4){
				cout<<"F"; //finish
				map[x][y] = 0;
			}
		cout<<endl;
	}
	cout << "I'm here 6" << endl;
}
