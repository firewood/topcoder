(use '[clojure.string :only (join split)])

(defn solve[t]
  (def input (split (read-line) #"\s"))
  (def n (read-string (first input)))
  (def s (map read-string (split (second input) #"")))
  (defn add[level n sum s]
    (def p (max 0 (- level n)))
    (if (empty? s)
      sum
      (add (+ level 1) (+ n (first s) p) (+ sum p) (rest s))))
  (add 0 0 0 s))

(defn output-result[t ans] (println (format "Case #%d: %d" t ans)))
(def T (read-string (read-line)))
(doall (map (fn[t] (output-result (+ t 1) (solve t))) (range 0 T)))
