let range ?(x = 1) ?(inc = 1) n = 
  let rec aux acc x = 
	if x > n then acc else aux (x :: acc) (x + inc)
  in
  List.rev (aux [] x)

	
let g acc x = 
  List.fold_left (fun acc y ->
	let cnt = x * (x - 1) * y * (y - 1) / 4 in
	let diff = abs (cnt - 2000000) in
	if diff < (List.hd acc) then 
	  [diff; x; y]
	else
	  acc)
	acc (range ~x:x 100)
	
let ret = List.fold_left g [100000; 0; 0] (range ~x:2 100) in
(List.hd (List.rev ret) - 1) * (List.hd (List.tl ret) - 1)

