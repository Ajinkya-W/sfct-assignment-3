#ifndef PRIMS_H_INCLUDED
#define PRIMS_H_INCLUDED

graph prims(graph h)																//Prim's function begins with a graph object as an input
{
	const int INF=99999;
	const int LIN=999;																//assigning for those who dont have direct edge
	int n=h.nodeval();
	int i,j,k,tc=0,min,closest[n];													//index of closest vertex in terms of cost between those verticees which are traversed till then
	int lc[n];																		//cost of edge between 'i' & closest[i] 
	int z[n][n],c[n][n];															//c[][] is cost matrices & z[][] will have MST stored in it till we save MSt to graph object
	
	lc[0]=0,closest[0]=0;															//for first vertex closet vertex will be itself & hence cost will be 0(no self loops present in graph)
	
	for(i=0;i<n;i++)															
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=h.getcost(i,j);													//getting cost of edges into cost matrix c[][]
			
			if(i==j);																//also assigning z[][] zero for diagonal of matrix in MSt matrix
				z[i][j]=0;
				
			if(c[i][j]==-1)															//changing '-1' weight to some [big value< infinity] to simplify computation 
				c[i][j]=LIN;
		}
	}

	for(i=1;i<n;i++)
	{
		lc[i]=c[0][i];																//initializing lowcost[] and closet[] considering 1st vertex as start point 
		closest[i]=0;
	}
	
	for(i=1;i<n;i++)
	{
		min=lc[1];
		k=1;

		for(j=2;j<n;j++)
		{
			if( lc[j]!=0 && lc[j]<min && lc[j]!=-1)									//finding closest vertex from start vertex
			{
				min=lc[j];
				k=j;
			}
		}
		z[closest[k]][k]=c[closest[k]][k];											//adding that edge to MST
		z[k][closest[k]]=c[closest[k]][k];

		lc[k]=INF;																	//setting to INF to not let same edge to come under consideration in subsequent steps
	
		for(j=1;j<n;j++)
		{
			if(c[k][j]<lc[j] && c[k][j]!=0 && lc[j]!=INF)							//updating lowcost[] and closest[] according to new added edge 
			{
				lc[j]=c[k][j];
				closest[j]=k;
			}
		}
	}
	graph y(n);																		//instantiating a graph instance with size n named 'y' which would seerve as an MST

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			y.setcost(i,j,z[i][j]);													//setting the cost into MST
		}
	}
	return y;																		//returning the object to the top level program
}


#endif
