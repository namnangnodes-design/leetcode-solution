type pos struct { x,y int }
const (
    up,right,down,left = 1,2,4,8
)
func numberOfCleanRooms(room [][]int) int {
    n,m,cnt := len(room), len(room[0]), 0
    seen := make(map[pos]int)
    // start at {0,0} facing right
    p,d,t := pos{0,0},2,0
    for s := seen[p]; s & d == 0; s=seen[p] {
        // new space found
        if s == 0 { cnt++ }
        //fmt.Println(p,d,seen,s,cnt)
        // mark room for current direction
        seen[p] |= d
        // continue moving if possible, othewise turn clockwise
        turn := false
        switch d {
            case 1: if p.x > 0 && room[p.x-1][p.y] == 0 { p.x-- } else { turn = true }
            case 2: if p.y < m-1 && room[p.x][p.y+1] == 0 { p.y++ } else { turn = true }
            case 4: if p.x < n-1 && room[p.x+1][p.y] == 0 { p.x++ } else { turn = true }
            case 8: if p.y > 0 && room[p.x][p.y-1] == 0 { p.y-- } else { turn = true }
        }
        if turn {
            // stop turning after 2 attempts (in case of 1x1 room)
            t++
            if t > 2 { return cnt }
            d = d * 2 % 15
        } else {
            // moving straight, reset turn counter
            t = 0
        }
    }
    return cnt
}
