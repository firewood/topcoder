#!/usr/bin/env ruby

require 'set'

def collect(rows)
  counts = rows.map do |row|
    count = [0] * 26
    row.each { |c| count[c] += 1 }
    count
  end
  kinds = counts.map do |row|
    row.count { |c| c > 0 }
  end
  [counts, kinds]
end

def check(kinds)
  (kinds.size).times.select { |r| kinds[r] == 1 }
end

def erase(chars, remain_rows, remain_columns, column_kinds, columns, row_index)
  remain_rows.delete(row_index)
  remain_columns.select do |column|
    char = chars[row_index][column]
    columns[column][char] -= 1
    if columns[column][char] == 0
      column_kinds[column] -= 1
      column_kinds[column] == 1
    end
  end
end

(h, w) = gets.split(' ').map(&:to_i)
c = []
h.times.each { |i| c << gets.chomp }

chars = c.map.each { |row| row.chars.map { |c| c.ord - 'a'.ord } }
rotated_chars = chars.transpose
(rows, row_kinds) = collect(chars)
(columns, column_kinds) = collect(rotated_chars)

row_q = check(row_kinds)
col_q = check(column_kinds)
remain_rows = Set.new(h.times)
remain_columns = Set.new(w.times)
while !row_q.empty? || !col_q.empty?
  col_s = row_q.map { |row| erase(chars, remain_rows, remain_columns, column_kinds, columns, row) }
  h -= row_q.size
  row_q = []
  col_q += col_s.flatten if h >= 2

  row_s = col_q.map { |column| erase(rotated_chars, remain_columns, remain_rows, row_kinds, rows, column) }
  w -= col_q.size
  col_q = []
  row_q = row_s.flatten if w >= 2
end

puts h * w
