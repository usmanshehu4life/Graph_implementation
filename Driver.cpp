// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Vertex.h"
#include "Edge.h"
#include"Graph.h"

int main()
{
	cout << "YUL aiport map showing the distance from montreal to any major city in Canada\n";
	string s;
	cout << "Please input your destination city: \n";
	cin >> s;
	cout << "Please input the distance in kilometers between this two cities\n";
	int distance;
	cin >> distance;

	Vertex v("Montreal");
	cout << v.toString() << endl;
	Vertex v1(s);
	cout << v1.toString() << endl;
	Edge e(v, v1, distance);
	cout << e.toString() << endl;
	UGraph graph;
	//add vertex
	graph.addVertex(v);
	graph.addVertex(v1);
	//add edges
	graph.addEdge(e);
	graph++;
	graph.display();
	UGraph graph2;
	graph2 == graph;
	graph2.display();
	system("pause");
	
	return 0;


	
	



}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
