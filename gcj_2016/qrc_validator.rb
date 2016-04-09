#!/usr/bin/ruby

u = {}

STDIN.gets
while true
  s = STDIN.gets
  break unless s
  puts s
  ds = s.split(' ')
  v = ds.shift
  if u[v]
    puts "ERROR: V=#{v}"
    exit
  end
  u[v] = 1
  ds.each_with_index do |d, i|
    x = v.to_i(i + 2)
    y = d.to_i
    if (x % y != 0 || y >= x)
      puts "ERROR: V=#{v}, R=#{i+2}, D=#{d}"
      exit
    end
  end
end
puts "DONE"
