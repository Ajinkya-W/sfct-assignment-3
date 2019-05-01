#ifndef MFSET_H_INCLUDED
#define MFSET_H_INCLUDED

class mfset{																		//merge-find set class begins
	int nametype;
	int elementtype;
	
	typedef struct name{
	int setname;																	//nametype
	int nextelement;
	}nam; 
	
	typedef struct setheader{
	int count;
	int firstelement;
	}sethead;
	
	nam* names;																		//dynamic array of structure name type
	sethead* setheaders;															//dynamic array of structure setheader type
	
	public:
	mfset(int n)																	//mfset constructor for allocating size to two dynamic arrays
	{
		names=new nam[n];
		setheaders=new sethead[n];		
	}
	
	int initial(int a,int x)														//initializing 'a' to a set containing x only
	{
		names[x].setname=a;		  													
		names[x].nextelement=0;   													
		setheaders[a].count=1;
		setheaders[a].firstelement=x;
		return 0;
	}
	int merge(int a,int b)															//merge A and B, calling the result A or B, arbitrarily
	{
		int i;														
		if(setheaders[a].count>setheaders[b].count)
		{																			// A is the larger set; merge B into A
																					//find end of B, changing set names to A as we go
			i=setheaders[b].firstelement;
			while(names[i].nextelement!=0)
			{
				names[i].setname=a;
				i=names[i].nextelement;
			}																		// append list A to the end of B and call the result A 
																					//now i is the index of the last member of B
			names[i].setname=a;
			names[i].nextelement=setheaders[a].firstelement;
			setheaders[a].firstelement=setheaders[b].firstelement;
			setheaders[a].count=setheaders[a].count+setheaders[b].count;
		}
		else																		//B is at least as large as A
		{
																					//find end of B, changing set names to A as we go
			i=setheaders[a].firstelement;
			while(names[i].nextelement!=0)
			{
				names[i].setname=b;
				i=names[i].nextelement;
			}																		// append list A to the end of B and call the result A 
																					//now i is the index of the last member of B
			names[i].setname=b;
			names[i].nextelement=setheaders[b].firstelement;
			setheaders[b].firstelement=setheaders[a].firstelement;
			setheaders[b].count=setheaders[b].count+setheaders[a].count;
		}
	}
	int find(int x)																	//returns the name of the set of which x is a member
	{
		return names[x].setname;
	}
};
#endif
    
	  
		  	

