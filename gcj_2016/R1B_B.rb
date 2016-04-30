#!/usr/bin/ruby

# Google Code Jam 2016 Round 1B
# Problem B. Close Match

def solve(c, j)
  ac = ''
  aj = ''
  mc = 10000
  len = c.length
  m = 10 ** c.length - 1
  u = {}
  (0..m).each do |a|
    x = sprintf("%03d", a).slice(3-len,len)
    (0..len-1).each do |i|
      x[i] = c[i] if c[i] != '?'
    end
    next if u[x]
    u[x] = 1
    (0..m).each do |b|
      y = sprintf("%03d", b).slice(3-len,len)
      (0..len-1).each do |i|
        y[i] = j[i] if j[i] != '?'
      end
      d = (x.to_i - y.to_i).abs
      if d < mc
        mc = d
        ac = x
        aj = y
      elsif d <= mc
        if x.to_i < ac.to_i
          ac = x
          aj = y
        elsif x.to_i <= ac.to_i
          aj = y if y.to_i < aj.to_i
        end
      end
    end
  end
  [ac, aj]
end

T = STDIN.gets.to_i
(1..T).each do |t|
  (c, j) = STDIN.gets.split(' ')
  ans = solve(c, j)
  puts "Case ##{t}: #{ans[0]} #{ans[1]}"
end
