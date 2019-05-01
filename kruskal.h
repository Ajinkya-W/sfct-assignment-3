#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

graph kruskal(graph h)
{																					// V: SET of vertex;	E: SET of edges;	var T: SET of edges
	
	int c=h.nodeval();																//total components equals total vertices
	int next=1,V=c;		
	priorityQ Q(h.noedges());														//sending edges into the priority queue
	mfset M(c);																		//C sized mfset

	int cu,cv;																		//component names
	graph T(c);
	
	for(int v=0;v<V;v++)															//initializing mfset M
	{
		M.initial(next,v);
		next++;
	}
	
	edge e;
	for(int i=0; i < V; i++)														//inserting the edges into the Priority queue
    {
		for(int j=i; j< V; j++)
        {
			if(h.getcost(i,j)!=-1 && i!=j)
			{
				e.weight=h.getcost(i,j);
				e.start=i;
				e.end=j;
				Q.insert(e);
			}
		}
	}
		
	while(c>1)		
	{
		e=Q.deletemin();
		cu=M.find(e.start);
		cv=M.find(e.end);
			
		if(cu!=cv)																	//if true then adding that edge to the MST
		{
			M.merge(cu,cv);
			c=c-1;
			T.setcost(e.start,e.end,e.weight);
			T.setcost(e.end,e.start,e.weight);
		}	
	}
	return T;
}
#endif
