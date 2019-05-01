#ifndef PRIORITYQ_H_INCLUDED
#define PRIORITYQ_H_INCLUDED

typedef struct e{																	//Structure to store edge 
	int start,end,weight;
	}edge;
	
class priorityQ{																	//priorityQ is the priority queue for heap and its underlying necessary operation
	int edges;
	int last;

	edge* pqueue;																	//for array of edge type
	
	public:
	priorityQ(int n)																//constructor
	{
		edges=n;
		int v=n;
		pqueue=new edge[n+1];
	}

	edge deletemin()																//function to delete root and then heapify
	{
		int i,j;
		edge temp;
		edge min;
		if(last==0)																	//last is the variable depicting no. of edges entered in priority queue
			cout<<"priority queue is empty";
		else
		{
			min=pqueue[1];															// we'll start pqueue from index 1
			pqueue[1]=pqueue[last];
			last=last-1;															//moving the last element to the beginning
			i=1;																	//i is the current position of the old last element	
			while(i<=(last/2))
			{																		
				if((pqueue[2*i].weight<pqueue[2*i+1].weight)||(2*i==last))			//checking left and right child
					j=2*i;
				else
					j=2*i+1;														//j will be the child of i having the smaller priority                         
																					//or if 2*i = A.last, then j is the only child of i
				if(pqueue[i].weight>pqueue[j].weight)
				{																	//swap old last element with low priority child
					temp=pqueue[i];
					pqueue[i]=pqueue[j];
					pqueue[j]=temp;
					i=j;
				}
				else
					return min; 													//can't push further
			}
			return min;																//pushed all the way to a leaf
		}	
	}
	
	int insert(edge x)
	{
		int i;
		edge temp;
		{	
			++last;
			pqueue[last].end =x.end;
			pqueue[last].start =x.start;
			pqueue[last].weight =x.weight;
			i = last; 																//{ i is index of current position of x } 
		
			while( (i >1) && (x.weight)< (pqueue[i/2 ].weight))						//comparing with root and swaping if current weight's less than root
			    {
			        temp = pqueue[i];                
		  			pqueue [i] = pqueue [i/2];
				    pqueue [i/2] = temp;
		            i = i/2 ;
				}
		} 
		return 0;
	}
/*	
	int printQ()
	{
		for(int i=1;i<=edges;i++)
			cout<<pqueue[i].weight;
		return 0;
	}
*/
};
#endif
