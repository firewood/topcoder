#!/usr/bin/ruby

# Google Code Jam 2016 Round 1A
# Problem C. BFFs

T = STDIN.gets.to_i
(1..T).each do |t|
  n = STDIN.gets.to_i
  f = STDIN.gets.split(' ').map { |x| x.to_i - 1 }
  s = []
  (1..n-1).each do |i|
    s << i
  end
  ans = 0
  s.permutation(n-1) do |q|
    if f[0] == q[0] || f[0] == q[q.length - 1]
      x = [0, *q, 0]
      if (1..n-1).all? { |i| f[i] == x[i-1] || f[i] == x[i+1] }
        ans = n
        break
      end
    end
  end
  if ans < n
    s = []
    (0..n).each do |i|
      s << i
    end
    l = n - 1
    while l >= 2
#    (2..n-1).each do |l|
      s.permutation(l) do |q|
        if f[q[0]] == q[1] || f[q[0]] == q[q.length - 1]
          x = [*q, q[0]]
          if (1..l-1).all? { |i| f[q[i]] == x[i-1] || f[q[i]] == x[i+1] }
            ans = l
            break
          end
        end
      end
      l -= 1
      break if ans > 0
    end
  end
  puts "Case ##{t}: #{ans}"
end
