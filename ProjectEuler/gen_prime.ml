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

let y = gen_prime 10000000
