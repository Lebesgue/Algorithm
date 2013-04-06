$md = 1000000007;
def pow(x, y)
  if y == 0 
    1
  else
    t = pow(x, y/2);
    t = (t * t) % $md;
    if y % 2 == 1 then (x * t) % $md else t end
  end
end

n, k = gets.split.map(& :to_i)
p pow(k, k - 1) * pow(n - k, n - k) % $md

