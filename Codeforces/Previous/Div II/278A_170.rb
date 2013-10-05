n = gets.to_i;
a = gets.split.map(& :to_i);
sum = a.inject(:+);
acc = 0;
d = [0].concat(a.map {|x| acc += x})
s, t = gets.split.map(&:to_i);
s, t = t, s if t < s
p ([d[t-1]-d[s-1], sum - d[t-1] + d[s-1]].min)
