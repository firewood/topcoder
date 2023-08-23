#!/usr/bin/env ruby

require 'set'

def collect(rows)
  counts = rows.map do |chars|
    count = Array.new(26, 0)
    chars.each { |c| count[c] += 1 }
    count
  end
  kinds = counts.map do |row|
    row.count { |c| c > 0 }
  end
  [counts, kinds]
end

def get_erasable_rows(kinds)
  (kinds.size).times.select { |r| kinds[r] == 1 }
end

def erase(chars, remain_rows, remain_columns, column_counts, column_kinds, r)
  remain_rows.delete(r)
  remain_columns.select do |c|
    if (column_counts[c][chars[r][c]] -= 1) == 0
      (column_kinds[c] -= 1) == 1
    end
  end
end

(h, w) = gets.split(' ').map(&:to_i)
row_chars = h.times.map { |_| gets.chomp.bytes.map { |b| b - 'a'.ord } }
(row_counts, row_kinds) = collect(row_chars)
column_chars = row_chars.transpose
(column_counts, column_kinds) = collect(column_chars)

rows_to_erase = get_erasable_rows(row_kinds)
cols_to_erase = get_erasable_rows(column_kinds)
remain_rows = Set.new(h.times)
remain_columns = Set.new(w.times)
while !rows_to_erase.empty? || !cols_to_erase.empty?
  next_cols_to_erase = rows_to_erase.map { |r| erase(row_chars, remain_rows, remain_columns, column_counts, column_kinds, r) }
  h -= rows_to_erase.size
  rows_to_erase = []
  cols_to_erase += next_cols_to_erase.flatten if h >= 2

  next_rows_to_erase = cols_to_erase.map { |c| erase(column_chars, remain_columns, remain_rows, row_counts, row_kinds, c) }
  w -= cols_to_erase.size
  cols_to_erase = []
  rows_to_erase = next_rows_to_erase.flatten if w >= 2
end

puts h * w
