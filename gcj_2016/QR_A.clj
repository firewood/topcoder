; Google Code Jam 2016 Qualification Round
; Problem A. Counting Sheep

(use '[clojure.string :only (join split includes?)])

; generates [N N*2 N*3, ...]
(defn gen[n]
  (iterate (fn[x] (+ x n)) n))

; check if digit D is in N
(defn check[d n]
  (includes? (str n) (str d)))

; first N contains digit D
(defn find-first[d n]
  (first
    (filter (fn[x] (check d x)) (gen n))))

(defn solve[n]
  (if (= n 0)
    "INSOMNIA"
    (apply max (map (fn[d] (find-first d n)) (range 0 10)))))

(defn output-result[t ans]
  (println (str "Case #" t ": " ans)))

(def T (read-string (read-line)))
(loop [t 1]
  (when (<= t T)
    (def n (read-string (read-line)))
    (output-result t (solve n))
    (recur (inc t))))
