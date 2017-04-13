#!/usr/bin/ruby

# Google Code Jam 2017 Qualification Round
# Problem B. Tidy Numbers

T = STDIN.gets.to_i
(1..T).each do |t|
  n = STDIN.gets.to_i
  ans = 1
  (1..n).each do |i|
    ans = i if i.to_s.split('').sort.join('').to_i == i
  end
  puts "Case ##{t}: #{ans}"
end
