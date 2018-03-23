int Fibonacci_Search(int *a,int n,int key)
{
	
	int low,high,mid,i,k;
	low = 1;
	high = n;
	k=0;
	for(i=0;i<13;i++)
	{
		if(i<2)
			F[i]=i;
		else
			F[i]=F[i-1]+F[i-2];	
	}
	while(n>F[k]-1)
		k++;
	for(i=n;i<F[k]-1;i++)
	{
		a[i]=a[n];
	}
	
	while(low<=high)
	{
		mid = low + F[k-1]-1;
		if(key<a[mid])
		{
			high = mid - 1;
			k--;
		}
		else if(k>a[mid])
		{
			low = mid + 1;
			k=k-2;
		}
		else 
		{
			if(mid<=n)
				return mid;
			else 
				return n;
		}
	}
	return 0;
}
