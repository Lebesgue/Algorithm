let get_seq n = 
  let rec aux acc n = 
	if n = 0 then acc
	else aux (n :: acc) (n - 1)
  in
  aux [] n


let gen_prime n = 
  let update x step lst = 
	let rec aux acc cur y = 
	  match y with
		| [] -> List.rev acc
		| h :: hs -> begin
		  if cur < h then aux acc (cur + step) y
		  else if h < cur then aux (h :: acc) cur hs else aux acc (cur + step) hs
		end 
	in
	aux [] x lst
  in

  let rec aux acc lst = 
	match lst with
	  | [] -> List.rev acc
	  | x :: xs -> begin
		if x * x > n then aux (x :: acc) xs
		else aux (x :: acc) (update (x*x) x xs)
	  end
  in
  aux [] (List.tl (get_seq n))

(* n must be less than the size of x *)
let rec get_nth n x = 
  if n > List.length x then raise (Failure "n must not be larger than the length")
  else   if n = 1 then List.hd x else get_nth (n - 1) (List.tl x)


let p_list = gen_prime 1000000
(* let ans = get_nth 10001 (gen_prime 1000000); *)


