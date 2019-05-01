//Main Program
//including all the headers required for calculating minimum spanning tree(MST) 
#include <iostream>																
using namespace std;
#include<fstream>																	//for reading input graph file
#include<string>																	//line variable for reading lines out of text file
#include<time.h>																	//for calculation of execution time of "Prim's" & "Kruskal's" code
#include "graph.h"																	//including all graph implementation and related methods
#include "prims.h"																	//prim's adt implementation
#include "priorityQ.h"																//priority queue implementation and methods underlying that adt
#include "mfset.h"																	//tree implementation of merge-find set(MFSET)
#include "kruskal.h"																//Kruskal's adt implementation

int main() {																		//main program execution begins here
	string line;								
	int lines,edges=0;
	ifstream myfile;
	
	myfile.open("input.txt");														//opening the input text file
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
      		lines++;																//for calculating number of vertices
    	}
    	myfile.close();																//closing te input text file
  	}
	else
		cout << "Unable to open file";												//if error occurs while opening the input text file

	ifstream myfile1 ("input.txt");													//this is to save cost matrix in our graph object
	if(!myfile1.is_open())
		return -1;
	
	int **costm=new int*[lines];													//creating a cost matrix for storing weights of edges in a graph
	
	for(int x=0;x<lines;x++)
		costm[x]=new int[lines];
		
	for(int i=0; i < lines; i++)
    	for(int j=0; j< lines; j++)
        {
			myfile1 >> costm[i][j];													//inserting integer weights one by one into the cost matrix
			if(costm[i][j]!=0 && costm[i][j]!=-1 && i<j)							//condition to check the total weighted edges in the graph 
			{
				edges++;															//saving the total number of edges in the edges variable
			}
		}
	myfile1.close();																//closing the text file	
	
	priorityQ pq(edges);															//setting total number of edges by constructor
	
	graph g(lines);																	//making two graph objects "g" & "y" for prim's 
	graph y(lines);
	g.tedges(edges);																//setting total edges in the object by calling tedges() method
	y.tedges(edges);
		
    //edge e;
    for(int i=0; i < lines; i++)													//setting costmatrix in the graph object
    	for(int j=0; j< lines; j++)
        {
    		g.setcost(i,j,costm[i][j]);	
        }
	//Prim's
	clock_t start, end;																//initializing variables to note start and end clocks count
	start = clock();																//clock starts
	y=prims(g);																		//Sending graph object to Prim's implementation
	end = clock();																	//clock ends
	double duration_sec = double(end-start)/CLOCKS_PER_SEC;							//calculating duration of Prim's execution
	cout<<"Prim's algorithm MST (total cost: "<<y.mstcost()<<" ; runtime: "<<duration_sec*1000<<"ms)"<<endl;
	y.mstprint();																	//printing MST from prim's returned graph object
	
	//Kruskal's
	
	graph s(lines);																	//Making graph object for Kruskal's implementation
	s.tedges(edges);																//setting total edges in the object by calling tedges() method
	
	start = clock();																//clock starts
	s=kruskal(g);																	//Sending graph object to Kruskal's implementation
	end = clock();																	//clock ends
	duration_sec = double(end-start)/CLOCKS_PER_SEC;								//calculating duration
	cout<<"Kruskal's algorithm MST (total cost: "<<s.mstcost()<<" ; runtime: "<<duration_sec*1000<<"ms)"<<endl;
	s.mstprint();																	//printing MST from Kruskal's returned graph object
	return 0;																		//Main program's execution ends
}
