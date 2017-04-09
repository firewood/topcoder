// Google Code Jam 2017 Qualification Round
// Problem A. Oversized Pancake Flipper

#[allow(unused_imports)]
use std::cmp::*;
use std::io::*;

#[allow(dead_code)]
fn get_line() -> String {
    let mut ret: String = String::new();
    std::io::stdin().read_line(&mut ret).ok();
    return ret;
}

#[allow(dead_code)]
fn get_word() -> String {
    let mut stdin: Stdin = std::io::stdin();
    let mut u8b: [u8; 1] = [0];
    loop {
        let mut buf: Vec<u8> = Vec::with_capacity(16);
        loop {
            let res = stdin.read(&mut u8b);
            if res.is_err() || u8b[0] <= ' ' as u8 {
                break;
            } else {
                buf.push(u8b[0]);
            }
        }
        if buf.len() >= 1 {
            let ret = std::string::String::from_utf8(buf).unwrap();
            return ret;
        }
    }
}

#[allow(dead_code)]
fn parse<T: std::str::FromStr>(s: &str) -> T {
     return s.parse::<T>().ok().unwrap();
}

#[allow(dead_code)]
fn get<T: std::str::FromStr>() -> T {
    parse(&get_word())
}

fn reverse(c: char) -> char {
    match c {
        '-' => '+',
        _ => '-',
    }
}

fn solve(s: String, k: usize, t: i64) -> i64 {
    if s.len() == 0 {
        return t;
    }
    if s.chars().next() == Some('+') {
        return solve(format!("{}", &s[1..]), k, t);
    }
    if s.len() < k {
        return -1;
    }
    let a: String = s.chars().take(k).map(reverse).collect();
    let b: String = s.chars().skip(k).collect();
    return solve(format!("{}{}", a, b), k, 1 + t);
}

fn main() {
    for t in 0..get() {
        let s: String = get_word();
        let k: usize = get();
        let ans: i64 = solve(s, k, 0);
        if ans < 0 {
            println!("Case #{}: IMPOSSIBLE", t + 1);
        } else {
            println!("Case #{}: {}", t + 1, ans);
        }
    }
}
