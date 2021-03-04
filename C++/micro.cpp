
class min_heap
{
	int max_size=1e5;
	
	int size=0;
	
	int arr[max_size];
	
	void insert(int val)
	{
		arr[size]=val;
		size++;
		
		perculate_up(size-1); // size-1 is index of newly inserted element
	}
	
	void perculate_up(int ind)
	{
		if(ind==0)
		{
			return;
		}
		
		int par=ind/2;
		
		if(arr[ind]<arr[par])
		{
			swap(arr[ind],arr[par]);
			perculate_up(par);
		}
	}
	
	void perculate_down(int ind)
	{
		if(ind>=size)
		{
			return;
		}
		
		int left_child=2*ind+1;
		int right_child=2*ind+2;
		
		int min_ele=min(arr[left_child],arr[right_child]);
		
		if(min_ele>arr[ind])
		{
			if(arr[left_child]<arr[right_child])
			{
				swap(arr[ind],arr[left_child]);
				perculate_down(left_child);
			}
			else
			{
				swap(arr[ind],arr[right_child]);
				perculate_down(right_child);
			}
		}
	}
	
	void del_min(int val)
	{
		swap(arr[size-1],arr[0]);
		size--;
		
		perculate_down(0);	
	}
	
	int get_min()
	{
		if(size==0)
		{
			throw exception("Size of the heap is zero");
		}
		
		return arr[0];
	}
}

class largest_k
{
	min_heap heap;
	int k;
	
	largest_k(int k)
	{
		this->k=k;
		heap=min_heap();
	}
	
	void insert_element(int val)
	{
		if(heap.size()<k)
		{
			insert(val);	
		}
		else if(heap.get_min()<val)
		{	
			heap.insert(val);
			
			if(heap.size>k)
				heap.del_min();
		}
	}
	
	int get_kth_largest()
	{
		if(heap.size<k)
		{
			throw exception("Number of elements < k");
		}
		
		return heap.get_min();
	}
}

