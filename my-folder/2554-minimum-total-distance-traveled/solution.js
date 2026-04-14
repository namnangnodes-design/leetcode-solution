var minimumTotalDistance = function(robot, factory) {
    robot.sort((a,b)=>a-b);
    factory.sort((a,b)=>a[0]-b[0]);

    let n = robot.length;
    let m = factory.length;
    let INF = 1e18;

    let dp = Array.from({length:n+1}, ()=>Array(m+1).fill(INF));

    for(let j=0;j<=m;j++) dp[0][j]=0;

    for(let j=1;j<=m;j++){
        let [pos, limit] = factory[j-1];

        for(let i=0;i<=n;i++){
            dp[i][j]=dp[i][j-1];

            let dist=0;

            for(let k=1;k<=limit && i-k>=0;k++){
                dist += Math.abs(robot[i-k]-pos);
                dp[i][j]=Math.min(dp[i][j], dp[i-k][j-1]+dist);
            }
        }
    }

    return dp[n][m];
};
