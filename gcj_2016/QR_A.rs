// Google Code Jam 2016 Qualification Round
// Problem A. Counting Sheep

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

fn find_first(d: i64, n: i64) -> i64 {
    let ds: String = format!("{}", d);
    let mut x = n;
    loop {
        let s: String = format!("{}", x);
        if s.contains(&ds) {
            return x;
        }
        x = x + n;
    }
}

fn solve(n: i64) -> String {
    if n <= 0 {
        return String::from("INSOMNIA");
    }
    let ans: i64 = (0..10).collect::<Vec<i64>>().iter().map(|&d| find_first(d, n) ).max().unwrap();
    return format!("{}", ans);
}

fn main() {
    for t in 0..get() {
        let n: i64 = get();
        println!("Case #{}: {}", t + 1, solve(n));
    }
}
