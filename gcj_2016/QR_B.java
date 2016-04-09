// Google Code Jam 2016 Qualification Round
// Problem B. Revenge of the Pancakes

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class QR_B {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    String readLine() {
        String s = null;
        try {
            s = reader.readLine();
        } catch (Exception e) {
        }
        return s;
    }

    String rev(String s) {
        StringBuffer sb = new StringBuffer(s);
        sb.reverse();
        return sb.toString().replaceAll("\\+", "a").replaceAll("-", "+").replaceAll("a", "-");
    }

    int solve(String s) {
        int a = s.indexOf('-');
        int b = s.indexOf('+');
        if (a < 0) {
            return 0;
        } else if (b < 0) {
            return 1;
        }
        int m = Math.max(a, b);
        return 1 + solve(rev(s.substring(0, m)) + s.substring(m));
    }

    void solveAll() {
        int T = Integer.parseInt(readLine());
        for (int t = 1; t <= T; ++t) {
            System.out.println("Case #" + t + ": " + solve(readLine()));
        }
    }

    public static void main(String[] args) {
        new QR_B().solveAll();
    }
}
