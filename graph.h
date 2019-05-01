#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

class graph{																		//Graph Class begins																							
	int **cm;																		//Cost matrix
	int node;																		//total number of vertices
	int ne;																			//total number of edges

	public:
	graph(int n)																	//graph's constructor
	{
		node=n;
		int v=n;
		cm= new int* [v];

		for(int i=0;i<v;i++)
		{
			cm[i]=new int[v];
		}
		for(int i=0;i<v;i++)														
		{
			for(int j=0;j<v;j++)
			{
				cm[i][j]=0;															//initialising cost matrix's all weights as 0(zero)
			}
		}
	}
	int nodeval()																	//function returning total vertices of the graph
	{
		return node;
	}

	int tedges(int ed)																//function setting total edges of the graph in no. of edges variable
	{
		ne=ed;
		return 0;
	}
	
	int noedges()																	//function returning total edges of the graph
	{
		return ne;
	}
	
	int setcost(int i,int j,int w)													//function setting weights of the graph into the cost matrix
	{
		cm[i][j]=w;
		return 0;
	}

	int getcost(int i,int j)														//function to retrieve weights of the graph from the cost matrix
	{
		return cm[i][j];
	}

	int mstprint()																	//function to print MST of the graph
	{	int n=nodeval();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(getcost(i,j)!=0 && i<j)
				{
					cout<<"("<<i+1<<"-"<<j+1<<")"<<endl;							//printing edges in required output pattern
				}
			}
		}
	}

	int mstcost()																	//function calculating total cost of the MSt
	{	int n=nodeval();
		int tc=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(getcost(i,j)!=0 && i<j)
				{
					tc+=getcost(i,j);
				}
			}
		}
		return tc;																	//returning the total cost of MST 
	}
};

#endif
