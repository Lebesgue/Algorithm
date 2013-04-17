open Hashtbl

let range ?(x = 1) ?(inc = 1) n = 
  let rec aux acc x = 
	if x > n then acc else aux (x :: acc) (x + inc)
  in
  List.rev (aux [] x)

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
  aux [] (List.tl (range n))


let pm_list = gen_prime 100000
let pm_tb = Hashtbl.create (List.length pm_list) 
let () = List.iter (fun x -> Hashtbl.add pm_tb x true) pm_list

let ( |> ) v f = f v
let ( <| ) f v = f v
let foi = float_of_int
let iof = int_of_float
