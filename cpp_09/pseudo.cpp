



















/*




binsert ( target , S , L , R )
	IF ( L > R )
		return
	
	m <-- floor((L + R) / 2)

	IF ( target < S[m].major and m == 0 )
		S.push_front( target )
		return
	IF ( target > S[m].major and m == S.len() - 1 )
		S.push_back( target )
		return
	IF ( target < S[m - 1].major )
	IF ( S[m].major < target )
		L <-- m + 1
	IF ( S[m].major > target )
		R <-- m - 1

	binsert ( target , S , L , R )

insert ( container , S )
	S_copy <-- S
	k <-- 2
	prev_group_end <-- 1
	odd_container <-- container.len() % 2
	container_last <-- container[ container.len() - 1 ]

	LOOP
		b <-- compute_b ( k )
		b_copy <-- b
		
		IF ( b > S.len() )
			IF ( odd )
				binsert( container_last.n , S , 0 , S.len() - 1 )
			return

		WHILE ( b > prev_group_end )
			binsert ( S_copy[b].minor , S , 0 , S.len() - 1 )
			b--


		prev_group_end <-- b_copy
		k++
	

merge_insertion ( container , S )
	if (container.len() == 1)
		S.push( container[0] )
		return

	container_of_largest_in_pairs = get_from( &container )
	merge_insertion( &container_of_largest_in_pairs , S )
	S.push_front( S[0].minor )
	insert( &container , S )









*/


