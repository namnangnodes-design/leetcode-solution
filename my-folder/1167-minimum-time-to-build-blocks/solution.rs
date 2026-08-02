use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn min_build_time(blocks: Vec<i32>, split: i32) -> i32 {
        let mut h: BinaryHeap<_> = blocks.into_iter().map(Reverse).collect();

        while h.len() > 1 {
            h.pop();
            match h.pop() {
                Some(Reverse(b)) => h.push(Reverse(b + split)),
                _ => println!("error: should always have a value"),
            }
        }

        if let Some(Reverse(b)) = h.pop() { return b; }
        return 0;
    }
}
