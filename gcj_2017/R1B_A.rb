#!/usr/bin/ruby

# Google Code Jam 2017 Round 1B
# Problem A. Steed 2: Cruise Control

T = STDIN.gets.to_i
(1..T).each do |tt|
  (d, n) = STDIN.gets.split(' ').map { |x| x.to_i }
  h = []
  (1..n).each do |i|
    h.push(STDIN.gets.split(' ').map { |x| x.to_i })
  end

  h = h.sort{|a,b| b[0]-a[0]}
  arr = 0
  v = 0
  h.each do |x|
    r = d - x[0]
    s = 1.0 * x[1]
    t = 1.0 * r / s
    if t > arr
      arr = t
    end
  end
  ans = 1.0 * d / arr

  puts sprintf("Case #%d: %.7f", tt, ans)
end
