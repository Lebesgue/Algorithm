n = gets.to_i;
c = gets.split(' ').map(&:to_i);
idx = (0..n-1).to_a.sort{|x, y|
  c[x] <=> c[y]
}
a = Array.new(n); b = Array.new(n);
cnt = (n+2)/3;

n.times{|i|
  j = idx[i];
  if i < cnt
    a[j] = i; b[j] = c[j] - a[j];
  elsif i < 2*cnt
    b[j] = i; a[j] = c[j] - b[j];
  else
    b[j] = n - i - 1; a[j] = c[j] - b[j];
  end
}
puts "YES"
puts a.map(&:to_s).join(' ')
puts b.map(&:to_s).join(' ')
