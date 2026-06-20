func numberOfWays(numPeople int) int {
    cnt := make(map[int]int)
    cnt[0] = 1
    for i:=2; i<=numPeople; i+=2 {
        for j:=1; j<i; j+=2 {
            cnt[i] = (cnt[i] + cnt[j-1] * cnt[i-j-1]) % 1000000007
        }
    }
    return cnt[numPeople]
}
