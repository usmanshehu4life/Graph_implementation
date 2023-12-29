#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Vertex
{
public:
	Vertex();
	Vertex(string);
	~Vertex();
	void set_ID(string);
	string get_ID();
	
	
	void Add_vertex(Vertex);
	virtual string toString();
	vector<Vertex> getNeighbors();

	bool operator==(Vertex&);
	


private:
	string ID;
	vector<Vertex> neighbors;


};












