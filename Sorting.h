template <class gtype>
class Sorting
{
protected:
    gtype *array;
	long int length;
	int partition(long int,long int);
	int quick(long int low,long int high);
public:
    inline sorting(long int initialLength);
    inline void input();
    inline void showElements();
    void bubbleSort();
    void quickSort(long int ,long int);
    void insertionSort();
    void mergeSort();
    void bucketSort();
    void selectionSort();
    void countingSort(sorting &count,long int n,long int k);


};





     sorting(long int initialLength);
    {
        length=initialLength;
        array=new T[length];

    }

template <class T>
int Sorting::partition(long int low,long int  high)
	{
		long int left,right,pivelmt;
		left=low;
		right=high;
		pivelmt=array[low];
		if(low > high)
		return 0;
		while(left<right)
		{
			while(array[left] <= pivelmt)
			left++;
            while(array[right]> pivelmt)
			right--;
            if(left<right)
			{
				gtype temp=array[left];
				array[left]=array[right];
				array[right]=temp;
			}
		}
		array[low]=array[right];
		array[right]=pivelmt;
		return right;

	}
template <class T>
int quick(long int low,long int high)
	{
         long int comp;
		if(low < high)
		{
		   int	pivot=partition(low,high);
			quick(low,pivot-1);
			quick(pivot+1,high);
		}
	}

	template<class T>
    void counting(sorting &count,long int n,long int k)
	{
		  	gtype c[k];
		  	for(long int i=0;i<k;i++)
		  	c[i]=0;

		  	for(long int i=0;i<n;i++)
		  	c[array[i]]=c[array[i]]+1;

		  	for(long int i=1;i<k;i++)
		  	c[i]=c[i-1] + c[i];

		  	for(long int j=n-1;j>=0;j--)
		  	{

		  	  count.array[c[array[j]-1]]=array[j];
		  	  c[array[j]]=c[array[j]]-1;
		    }
		    cout<<endl<<" complexity : O(n)";
		  }
