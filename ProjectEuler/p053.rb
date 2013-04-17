ans = 0;
c = Array.new(101) {Array.new(101)}
c[0][0] = 1;
(1..100).each{|i| 
  c[i][0] = 1; c[i][i] = 1;
  (1..i-1).each {|j|
    if c[i-1][j-1] == -1 || c[i-1][j] == -1 || c[i-1][j-1] + c[i-1][j] > 1000000 
      c[i][j] = -1;
      ans += 1;
    else
      c[i][j] = c[i-1][j-1] + c[i-1][j]
    end
  }
}
p ans

