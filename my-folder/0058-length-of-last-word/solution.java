class Solution {
    public int lengthOfLastWord(String s) {
        String[] wordsArr = s.split(" ");
        return wordsArr[wordsArr.length - 1].length();
    }
}
