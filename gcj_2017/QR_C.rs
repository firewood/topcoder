// Google Code Jam 2017 Qualification Round
// Problem C. Bathroom Stalls

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

fn solve(t: i64, n: i64, k: i64) {
    let mut r: i64 = n;
    let mut d: i64 = 1;
    let mut rk: i64 = k;
    while rk > d {
        rk -= d;
        r -= d;
        d *= 2;
    }
    let mut sz = r / d - 1;
    if rk <= (r % d) {
        sz += 1;
    }
    println!("Case #{}: {} {}", t + 1, sz / 2 + (sz % 2), sz / 2);
}

fn main() {
    for t in 0..get() {
        let n: i64 = get();
        let k: i64 = get();
        solve(t, n, k);
    }
}
