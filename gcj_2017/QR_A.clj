; Google Code Jam 2017 Qualification Round
; Problem A. Oversized Pancake Flipper

(use '[clojure.string :only (join split includes?)])

(defn rev[s]
  (map (fn[c] (if (= c \+) \- \+)) s))

(defn f[s k t]
  (cond
    (= (count s) 0) t
    (= (first s) \+) (f (rest s) k t)
    (< (count s) k) -1
    :else (f (concat (rev (take k s)) (drop k s)) k (+ 1 t))))

(defn solve[s k]
  (def ans (f s k 0))
  (if (< ans 0)
    "IMPOSSIBLE"
    ans))

(defn output-result[t ans]
  (println (str "Case #" t ": " ans)))

(def T (read-string (read-line)))
(loop [t 1]
  (when (<= t T)
    (def x (split (read-line) #" "))
    (output-result t (solve (first x) (read-string (last x))))
    (recur (inc t))))
