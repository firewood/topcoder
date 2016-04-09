// Google Code Jam 2016 Qualification Round
// Problem B. Revenge of the Pancakes

object Solver {
    def rev(s: String) :String = {
        s.reverse.replaceAll("\\+", "a").replaceAll("-", "+").replaceAll("a", "-")
    }

    def solve(s: String) :Int = {
        val a = s.indexOf('-')
        val b = s.indexOf('+')
        if (a < 0) {
            0
        } else if (b < 0) {
            1
        } else {
            val m = List(a, b).max
            1 + solve(rev(s.substring(0, m)) + s.substring(m))
        }
    }

    def main(args: Array[String]) :Unit = {
        val T = scala.io.StdIn.readLine.toInt
        (1 to T).foreach(t => {
            val ans = solve(scala.io.StdIn.readLine)
            println(s"Case #$t: $ans")
        })
    }
}
