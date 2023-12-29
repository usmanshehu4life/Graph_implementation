#include "Vertex.h"

Vertex::Vertex()
{
	ID = " ";
	


}

Vertex::Vertex(string Id)
{
	ID = Id;
	
	
}

Vertex::~Vertex()
{
	
}

void Vertex::set_ID(string i) {
	ID =i;

}

string Vertex::get_ID() {
	return ID;
}


void Vertex::Add_vertex(Vertex v)
{
	neighbors.push_back(v);
}

 string Vertex::toString()
{
	stringstream s;
	s << "V(" << ID << ")";
	return s.str();
}

 vector<Vertex> Vertex::getNeighbors()
{
	return neighbors;
}

 

 bool Vertex::operator==(Vertex& v)
 {
	 if(this->ID != v.ID)
	 return false;



	 return true;
 }
 