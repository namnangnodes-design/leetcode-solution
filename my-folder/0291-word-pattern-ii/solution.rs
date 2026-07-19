use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn word_pattern_match(pattern: String, s: String) -> bool {
        fn backtrack(pat: &str, s: &str, char_to_substr: &mut HashMap<char, String>, used_substrings: &mut HashSet<String>) -> bool {
            if pat.is_empty() {
                return s.is_empty();
            }
            if s.is_empty() {
                return false;
            }

            let current_char = pat.chars().next().unwrap();
            let remaining_pattern = &pat[1..];

            if let Some(mapped_substr) = char_to_substr.get(&current_char) {
                if s.starts_with(mapped_substr) {
                    return backtrack(remaining_pattern, &s[mapped_substr.len()..], char_to_substr, used_substrings);
                } else {
                    return false;
                }
            }
            for i in 1..=s.len() {
                let substr = s[..i].to_string();

                if used_substrings.contains(&substr) {
                    continue;
                }

                char_to_substr.insert(current_char, substr.clone());
                used_substrings.insert(substr.clone());

                if backtrack(remaining_pattern, &s[i..], char_to_substr, used_substrings) {
                    return true;
                }

                // Backtrack
                char_to_substr.remove(&current_char);
                used_substrings.remove(&substr);
            }

            false
        }

        let mut char_to_substr = HashMap::new();
        let mut used_substrings = HashSet::new();
        backtrack(&pattern, &s, &mut char_to_substr, &mut used_substrings)
    }
}
