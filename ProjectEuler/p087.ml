open Hashtbl

let get_seq ?(x = 1) ?(inc = 1) n = 
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
  aux [] (List.tl (get_seq n))


let pm_list = gen_prime 10000
let tb = Hashtbl.create 5000011
let arr_2 = Array.of_list (List.filter (fun x -> x * x <= 50000000) pm_list)
let arr_3 = Array.of_list (List.filter (fun x -> x * x * x <= 50000000) pm_list)
let arr_4 = Array.of_list (List.filter (fun x -> x * x * x * x <= 50000000) pm_list)
let n2 = Array.length arr_2
let n3 = Array.length arr_3
let n4 = Array.length arr_4


for i = 0 to n2-1 do
  for j = 0 to n3-1 do
	for k = 0 to n4-1 do
	  Hashtbl.add tb (arr.(i) * arr.(i) + arr.(j) * arr.(j) * arr.(j) 
		+ arr.(k) * arr.(k) * arr.(k) * arr.(k)) true
	done;
  done;
done
  
let ans = List.fold_left (fun acc x -> if Hashtbl.mem tb x then 1 + acc else acc) 
  0 (get_seq 50000000)
