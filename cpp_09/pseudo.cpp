













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


INSERT ( target , S )
	end <-- S.len() - 1
	binsert ( target , S , 0 , end , end )

pair_chain_lookup ( atom , R )
	ptr <-- &atom
	i <-- 0
	WHILE ( i < R )
		ptr <-- ptr->pair_chain
		i++
	return *ptr

insert ( container , &S , R )
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
				INSERT ( container_last , S )
			b = S.len() - 1
			pairing <-- pair_chain_lookup ( main_chain[b] , R )
			WHILE ( b > prev_group_end )
				INSERT  ( pairing , S )
				b--
			RETURN

		pairing <-- pair_chain_lookup ( main_chain[b] , R )
		WHILE ( b > prev_group_end )
			INSERT  ( pairing , S )
			b--


		prev_group_end <-- b_copy
		k++
	

pairwise_reduce ( container )
	i <-- 0
	reduced <-- NOTHING
	smaller <-- NEW ATOM

	WHILE ( i + 1 < container.len() )
		IF ( container[i].integer < container[i + 1].integer )
			larger <-- container[i + 1]
			*smaller <-- container[i]
		ELSE
			larger <-- container[i]
			*smaller <-- container[i + 1]
		smaller->pair_chain = NULL
		ptr <-- &larger
		WHILE ( ptr->pair_chain != NULL )
			ptr <-- ptr->pair_chain
		ptr->pair_chain <-- smaller
		i += 2

merge_insertion ( container , &S , R )
	if (container.len() == 1)
		S.push( container[0] )
		return

	container_of_largest_in_pairs = pairwise_reduce ( &container )
	merge_insertion( &container_of_largest_in_pairs , &S , R + 1 )
	S.insert ( 0 , pair_chain_lookup ( S[0] , R ) )
	insert( &container , &S , R )










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




