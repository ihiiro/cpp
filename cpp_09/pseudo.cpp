



















/*




bsearch ( target , S , L , R  )
	IF ( L > R )
		return
	
	m <-- floor((L + R) / 2)

	IF ( S[m].major < target )
		L <-- m + 1
	IF ( S[m].major > target )
		R <-- m - 1

	IF ( m == 0 AND S[m].major > target )
		S.insert ( m , target )

	IF ( m == S.len() - 1 AND S[m].major < target)
		S.push_back( target )

	IF ( S[m - 1].major < target AND S[m + 1] > target )
		S.insert ( m + 1 , target )

	IF ( S[m].major < target )




	bsearch ( target , S , L , R )


binsert ( target , S )


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
				binsert( container_last.n , S )
			return

		WHILE ( b > prev_group_end )
			binsert ( S_copy[b].minor , S )
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


