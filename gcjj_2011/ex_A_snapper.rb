#!/usr/bin/ruby

def solve(n, k)
  b = (2 ** n)
  (k % b) == (b - 1)
end

T = STDIN.gets.to_i
(1..T).each do |t|
  (n, k) = STDIN.gets.split(' ').map { |v| v.to_i }
  answer = solve(n, k) ? "ON" : "OFF"
  puts "Case ##{t}: #{answer}"
end
