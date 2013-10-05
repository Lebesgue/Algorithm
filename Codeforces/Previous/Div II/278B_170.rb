n = gets.to_i;
a = (0..n-1).inject([]) {|acc, y| 
  s = gets.chomp 
  b = (0..s.length-1).inject([]){ |ai, x|
    (x..s.length-1).inject(ai){ |aj, y|
      aj << s[x..y]
    }
  }
  acc + b
}.sort{ |x, y|  
  if x.size < y.size 
    -1
  elsif x.size > y.size
    1
  else
    if x <= y then -1 else 1 end
  end
}.uniq
ans="a"
a.each{|x| 
  break if x != ans
  ans.succ!
}
puts ans

