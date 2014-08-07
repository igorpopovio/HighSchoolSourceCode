int prim(unsigned n)
{if (n%2==0) return 0;
	else
    	{for (unsigned i=3;i<n/2;i++,i++)
        	if (n%i==0) return 0;
        return 1;}
}