



















/*


binsert ( target , S , L , R , end )
	IF ( L > end )
		S.push_back ( target )
		return
	IF ( L > R )
		S.insert ( L , target )
		return

	m = (L + R) / 2

	IF ( S[m] < target.major )
		binsert ( target , S , m + 1 , R , end )
	ELSE
		binsert ( target , S , L , m - 1 , end )


insert ( target , S )
	end = S.len() - 1
	binsert ( target , S , 0 , end , end )

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
				insert( container_last.minor , S )
			return

		WHILE ( b > prev_group_end )
			insert ( S_copy[b].minor , S )
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


