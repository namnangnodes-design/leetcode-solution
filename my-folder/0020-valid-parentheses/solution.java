class Solution {
    public boolean isValid(String s) {
        Stack<Character> parent = new Stack<Character>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{' || s.charAt(i) == '<') {
				parent.push(s.charAt(i));
			} else {
				if (parent.empty()) {
					return false;
				} else if ((parent.peek() == '(' && s.charAt(i) != ')') || (parent.peek() == '[' && s.charAt(i) != ']')
						|| (parent.peek() == '{' && s.charAt(i) != '}')
						|| (parent.peek() == '<' && s.charAt(i) != '>')) {
					return false;
				} else {
					parent.pop();
				}
			}
		}
		if (!parent.empty()) {
			return false;
		}
		return true;
    }
}
