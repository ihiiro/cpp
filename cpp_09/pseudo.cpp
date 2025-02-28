













struct atom
{
	int major;
	int minor;
	struct atom *ptr;
};


struct atom *A;
struct atom *ptr;

while (i < 1)
{
	ptr = A;
	ptr = A.ptr;
}

/*


binsert ( target , S , L , R , end )
	IF ( L > end )
		S.push_back ( target )
		return
	IF ( L > R )
		S.insert ( L , target )
		return

	m <-- (L + R) / 2

	IF ( S[m] < target.major )
		binsert ( target , S , m + 1 , R , end )
	ELSE
		binsert ( target , S , L , m - 1 , end )


insert ( target , S )
	end <-- S.len() - 1
	binsert ( target , S , 0 , end , end )

insert ( &container , &S )  <============================ INSERT
	main_chain <-- S <===== main_chain should not contain elements of S with a NULL pair_chain
	k <-- 2
	prev_group_end <-- 0
	odd_container <-- container.len() % 2
	container_last <-- container[ container.len() - 1 ]

	LOOP
		b <-- compute_b ( k ) - 1
		b_copy <-- b

		IF ( b > S.len() - 1 )
			IF ( odd )
				insert( container_last , S )
			b = S.len - 1
			WHILE ( b > prev_group_end )
				insert ( main_chain[b].minor , S )
				b--
			RETURN

		WHILE ( b > prev_group_end )
			insert ( main_chain[b].minor , S )
			b--


		prev_group_end <-- b_copy
		k++
	

merge_insertion ( container , &S , R )
	if (container.len() == 1)
		S.push( container[0] )
		return

	container_of_largest_in_pairs = get_from( &container )
	merge_insertion( &container_of_largest_in_pairs , &S , R + 1 )
	
	i <-- 0
	ptr <-- &S[0]
	IF ( R == 0 )
		R <-- 1
	WHILE ( i < R )
		ptr <-- ptr->pair_chain
		i++

	S.insert ( 0 , *ptr )
	insert( &container , &S )










NOTE TO SELF
	I'm not absolutely certain that a configuration will never have a bi > floor(n/2) + 1
	when computing bi in INSERT, but I am assuming so, and therefore, INSERT always 
	subtracts 1 from bi that is larger than S.len() - 1 after inserting it in to S
	then b(i - 1) and b(i - 2) ... are inserted.
	If the assumption is false, a segmentation fault could occur, in all cases do check what bi is in 
	the odd case inside INSERT.
CORRECTION
	A configuration can absolutely have a bi > floor(n/2) + 1 because the insertion ordering follows a jacobsthal series
	whose values are independent of n.



*/




