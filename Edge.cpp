#include "Edge.h"
Edge::Edge()
{
	weight = 0;
}



Edge::~Edge()
{
	
}

Edge::Edge(Vertex& s, Vertex& e, int w)
{
	start = s;
	end = e;
	weight = w;
}

int Edge::increment_weight()
{
	return weight++;
}

void Edge::set_start(Vertex s)
{
	start = s;

}

 void Edge::set_end(Vertex e)
{
	end = e;
}

Vertex Edge::get_start()
{
	return start;
}

Vertex Edge::get_end()
{
	return end;
}

void Edge::set_weight(int w)
{
	weight = w;
}

int Edge::get_weight()
{
	return weight;
}

string Edge::toString()
{
	stringstream s;
	s << start.toString() << "--" << weight << "-->" << end.toString();
	s << endl;
	return s.str();
}



bool Edge::operator==(Edge& e)
{
	if((this->start == e.start) && (this->end == e.end) && (this->weight == e.weight))
	return true;

	else
		return false;




}
