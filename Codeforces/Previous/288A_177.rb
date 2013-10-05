n, m = gets.split.map(& :to_i)

if m == 1 && n != 1 || m > n
  ans = "-1"
elsif m == 1
  ans = "a"
else
  L = n - (m - 2);
  ans = "ab" * (L/2);
  if L % 2 == 1
    ans += "a"
  end
  ans += ('c'..(m + 96).chr).to_a.join('');
end
puts ans
