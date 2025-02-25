













/*







swap( container , a_idx , b_idx , pair_size )
	if (container[a_idx] > container[b_idx])
		while (pair_size != 0)
			tmp = container[a_idx]
			container[a_idx] = container[b_idx]
			container[b_idx] = tmp
			a_idx--;
			b_idx--;
			pair_size--


main_chain_merge_sort( container , left , right , pair_size )
	if (pair_size == 0)
			swap(&container[0], &container[1], pair_size)
			return
	
	mid = left + (right - left) / 2
	main_chain_merge_sort(container, left, mid, pair_size / 2)
	main_chain_merge_sort(container, mid + 1, right, pair_size / 2)
	swap(container, [pair_size - 1, 2 * pair_size - 1, pair_size)
	

merge_insert( container )
	if (container.len() % 2 == 0)
		main_chain_merge_sort( container , 0, container.len() - 1 ,  container.len() / 2 )
	else
		main_chain_merge_sort( container , 0, container.len() - 2 ,  container.len() / 2 )
	insert_sort( container )


	
	









*/



