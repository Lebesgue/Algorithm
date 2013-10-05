def f n
  cur = 1
  while cur <= n
    cur = cur * 2
  end
  cur /= 2
  i = cur
  cur -= 1
  while i <= n && cur >= 0
    $a[cur] = i
    $a[i] = cur
    $ans += 2 * (cur ^ i)
    i += 1
    cur -= 1
  end
  if cur >= 1 
    f cur 
  end
end

n = gets.to_i
$ans = 0
$a = Array.new(n + 1, 0)
f n
p $ans
puts $a.join(' ')
