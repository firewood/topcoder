; Google Code Jam 2016 Qualification Round
; Problem B. Revenge of the Pancakes

(use '[clojure.string :only (join split includes?)])

(defn iter[s c]
  (if (empty? s)
    0
    (+ (if (= (first s) c) 0 1) (iter (rest s) (first s)))))

(defn solve[s]
  (iter (seq (str s \+)) (first (str s))))

(defn output-result[t ans]
  (println (str "Case #" t ": " ans)))

(def T (read-string (read-line)))
(loop [t 1]
  (when (<= t T)
    (def s (read-string (read-line)))
    (output-result t (solve s))
    (recur (inc t))))
