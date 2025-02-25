













/*









swap( &a , &b , pair_size )
	if (*a > *b)
		while (pair_size != 0)
			tmp = *a
			*a = *b
			*b = tmp
			&a--
			&b--
			pair_size--


main_chain_merge_sort( list , left , right , pair_size )
	if (pair_size == 0)
			swap(&list[0], &list[1], pair_size)
			return
	
	mid = left + (right - left) / 2
	main_chain_merge_sort(list, left, mid, pair_size / 2)
	main_chain_merge_sort(list, mid + 1, right, pair_size / 2)
	swap(&list[pair_size - 1], &list[2 * pair_size - 1], pair_size)
	

merge_insert( list )
	if (list.len() % 2 == 0)
		main_chain_merge_sort( list , 0, list.len() - 1 ,  list.len() / 2 )
	else
		main_chain_merge_sort( list , 0, list.len() - 2 ,  list.len() / 2 )
	insert_sort( list )


	
	









*/



