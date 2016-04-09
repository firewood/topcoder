; Google Code Jam 2016 Qualification Round
; Problem A. Counting Sheep

(use '[clojure.string :only (join split)])

(defn gen[n] (iterate (fn[x] (+ x n)) n))

(defn check[d n]
  (some (fn[x] (= x d)) (map read-string (split (str n) #""))))

(defn findFirst[d n] (first (filter (fn[x] (check d x)) (gen n))))

(defn solve[]
  (def n (read-string (read-line)))
  (if (= n 0)
    "INSOMNIA"
    (str (apply max (map (fn[d] (findFirst d n)) (range 0 10))))))

(defn output-result[t ans] (println (format "Case #%d: %s" t ans)))
(def T (read-string (read-line)))
(doall (map (fn[t] (output-result (+ t 1) (solve))) (range 0 T)))
