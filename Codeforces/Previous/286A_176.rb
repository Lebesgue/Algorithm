n = gets.to_i;

if n % 4 > 1 
  puts "-1"
else
  a = Array.new(n);
  (1..(n/4)).each{|i|
    j = (i-1)*2 + 1;
    a[j-1] = j+1;
    a[j] = n - j + 1;
    a[n-j] = n - j;
    a[n-j-1] = j;
  }
  a[n/2] = n/2+1 if n % 4 ==1
  puts a.join(' ');
end
