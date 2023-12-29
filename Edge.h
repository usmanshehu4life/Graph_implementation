#pragma once
#include"Vertex.h"



class Edge: public Vertex
{
public:
	Edge();
	~Edge();
	Edge(Vertex& s, Vertex& e, int w);
	int increment_weight();
	
	void set_start(Vertex);
	void set_end(Vertex);
	Vertex get_start();
	Vertex get_end();
	void set_weight(int);
	int get_weight();
	string toString();
	bool operator==(Edge&);
	



private:
	Vertex start;
	Vertex end;
	int weight;
	

	

};


