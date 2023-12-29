#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<sstream>
#include "Vertex.h"
#include "Edge.h"
using namespace std;
class Graph :public Edge
{
public:
	Graph() {
	
	
	
	};
	//virtual ~Graph() = 0;
	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(Vertex& v) = 0;
	//Bonus question: add in a set of vertices; bool retruns if it is added successfully
	//virtual bool addVertices(Vertex* vArray) = 0;
	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex(Vertex& v) = 0;
	//remove a edge; as a result, some node may remain as orphan.
	virtual bool addEdge(Edge& e) = 0;
	//Bonus question : remove a set of edge; as a result, some node may remain as orphan.
	//virtual bool addEdges(Edge* eArray) = 0;
	// remove the edge
	virtual bool remove(Edge& e) = 0;
	// return bool if a vertex exists in a graph;
	virtual bool searchVertex(const Vertex& v) = 0;
	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(const Edge& e) = 0;
	// display the path that contains the vertex;
	virtual void display(Vertex& v) const = 0;
	// display the path that contains the edge;
	virtual void display(Edge& e) const = 0;
	// display the whole graph with your own defined format
	virtual void display() = 0;
	// convert the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
	// define your own format of a string representation of the graph.
	virtual string toString() const = 0;
	//remove all the vertices and edges;
	virtual bool clean() = 0;
};
class UGraph : public Graph
{
	vector<Vertex> vertices;
	int V, E;
	vector<Edge> edges;
public:
	UGraph() :Graph()
	{
		V = 0;
		E = 0;
	}
	bool operator==(UGraph& G) {
		for (int i = 0; i < V;i++) {
			if (this->vertices[i] == G.vertices[i])
				return true;
		}
		for (int i = 0; i < E; i++) {
			if (this->edges[i] == G.edges[i])
				return true;
		}



		
		return false;


	}

	UGraph& operator=(UGraph& g) {
		for (int i = 0; i < V;i++)
			this->vertices[i] = g.vertices[i];
		for (int i = 0; i < E; i++)
			this->edges[i] = edges[i];

		this->V = g.V;
		this->E = g.E;



		return (*this);

	}



	UGraph& operator++() {
		for (int i = 0; i < E; i++)
		edges[i].increment_weight();
		return (*this);

	}

	
	



	bool addVertex(Vertex& ver)
	{
		vertices.push_back(ver);
		V++;
		return true;
	}
	//Bonus question: add in a set of vertices; bool retruns if it is added successfully
	bool addVertices(Vertex* vArray)
	{
		int size = sizeof(vArray);
		for (int i = 0; i < size; i++)
			if (!addVertex(vArray[i]))
				return false;
		return true;
	}
	//the edges that has connection with this vertex need to be removed;
	bool removeVertex(Vertex& v)
	{
		vertices.pop_back();
		vector<Vertex> list = v.getNeighbors();
		for (Vertex vt : vertices)
		{
			Edge e(v, vt, 0);
			if (!remove(e))
				return false;
		}
		return true;
	}
	//remove a edge; as a result, some node may remain as orphan.
	bool addEdge(Edge& e)
	{
		edges.push_back(e);
		E++;
		return true;
	}
	//Bonus question : remove a set of edge; as a result, some node may remain as orphan.
	bool addEdges(Edge* eArray)
	{
		int size = sizeof(eArray);
		for (int i = 0; i < size; i++)
			if (!addEdge(eArray[i]))
				return false;
		return true;
	}
	// remove the edge
	bool remove(Edge& e)
	{
		vector<Edge>::iterator it;
		Edge et = e;
		//int i = 0;
		for (it = edges.begin(); it != edges.end(); it++) {
			// found nth element..print and break.
			if (et.get_start().get_ID() == (*it).get_start().get_ID())
			{
				if (et.get_end().get_ID() == (*it).get_end().get_ID())
				{
					edges.erase(it);
					return true;
				}
			}
		}
		return false;
	}
	// return bool if a vertex exists in a graph;
	bool searchVertex(const Vertex& v)
	{
		vector<Vertex>::iterator it;
		Vertex t = v;
		for (it = vertices.begin(); it != vertices.end(); it++) {
			// found nth element..print and break.
			if (t.get_ID() == (*it).get_ID()) {
				return true;
			}
		}
		return false;
	}
	// return bool if a Edge exists in a graph;
	bool searchEdge(const Edge& e)
	{
		vector<Edge>::iterator it;
		Edge et = e;
		for (it = edges.begin(); it != edges.end(); it++) {
			// found nth element..print and break.
			if (et.get_start().get_ID() == (*it).get_start().get_ID())
			{
				if (et.get_end().get_ID() == (*it).get_end().get_ID())
					return true;
			}
		}
		return false;
	}
	// utility function to check if current
	// vertex is already present in path
	bool isNotVisited(Vertex x, vector<Vertex> path)const
	{
		int size = path.size();
		for (int i = 0; i < size; i++)
			if (path[i].get_ID() == x.get_ID())
				return false;
		return true;
	}
	// display the path that contains the vertex;
	void display(Vertex& v) const
	{
		// create a queue which stores
		// the paths
		Vertex s = vertices[0];
		Vertex d = vertices[V - 1];
		queue<vector<Vertex> > q;
		// path vector to store the current path
		vector<Vertex> path;
		path.push_back(s);
		q.push(path);
		while (!q.empty()) {
			path = q.front();
			q.pop();
			Vertex last = path[path.size() - 1];
			// if last vertex is the desired destination
			// then print the path
			if (last.get_ID() == d.get_ID())
			{
				//print path
				int size = path.size();
				int f = 0;
				for (int i = 0; i < size; i++)
					if (path[i].get_ID() == v.get_ID())
						f = 1;
				if (f == 1)
				{
					for (int i = 0; i < size; i++)
						cout << path[i].get_ID() << " ";
					cout << endl;
					return;
				}
			}

			// traverse to all the nodes connected to
			// current vertex and push new path to queue
			vector<Vertex> adj = s.getNeighbors();
			vector<Vertex>::iterator it;

			for (it = adj.begin(); it != adj.end(); it++)
			{
				Vertex vert = (*it);
				// found nth element..print and break.
				if (isNotVisited(vert, path) == true)
				{
					vector<Vertex> newpath(path);
					newpath.push_back((*it));
					q.push(newpath);
				}
			}
		}
	}
	// display the path that contains the edge;
	void display(Edge& e) const
	{
	}
	// display the whole graph with your own defined format
	void display()
	{
		vector<Edge>::iterator it;
		for (it = edges.begin(); it != edges.end(); it++) {
			cout << " source: " << (*it).get_start().get_ID();
			cout << " end: " << (*it).get_end().get_ID();
			cout << " distance in km: " << (*it).get_weight();
			cout << endl;
		}
	}
	// convert the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
	// define your own format of a string representation of the graph.
	string toString() const
	{
		stringstream ss;

		// create a queue which stores
		// the paths
		Vertex s = vertices[0];
		Vertex d = vertices[V - 1];
		queue<vector<Vertex> > q;
		// path vector to store the current path
		vector<Vertex> path;
		path.push_back(s);
		q.push(path);
		while (!q.empty()) {
			path = q.front();
			q.pop();
			Vertex last = path[path.size() - 1];
			// if last vertex is the desired destination
			// then print the path
			if (last.get_ID() == d.get_ID())
			{
				//print path
				int size = path.size();
				int f = 0;
				for (int i = 0; i < size; i++)
				{
					for (int i = 0; i < size; i++)
						ss << path[i].get_ID() << "-";
					ss << "; ";
				}
			}
			// traverse to all the nodes connected to
			// current vertex and push new path to queue
			vector<Vertex> adj = s.getNeighbors();
			vector<Vertex>::iterator it;
			for (it = adj.begin(); it != adj.end(); it++)
			{
				Vertex vert = (*it);
				// found nth element..print and break.
				if (isNotVisited(vert, path) == true)
				{
					vector<Vertex> newpath(path);
					newpath.push_back((*it));
					q.push(newpath);
				}
			}
		}
		return ss.str();
	}
	//remove all the vertices and edges;
	bool clean()
	{
		vertices.clear();
		edges.clear();
		return true;
	}
};

