function findSafeWalk(grid: number[][], health: number): boolean {
    const m = grid.length,
        n = grid[0].length;
    const dis: number[][] = Array.from({ length: m }, () =>
        new Array(n).fill(-1),
    );
    const dirs: [number, number][] = [
        [0, 1],
        [1, 0],
        [-1, 0],
        [0, -1],
    ];

    const pq = new MinPriorityQueue<[number, number, number]>({
        compare: (
            a: [number, number, number],
            b: [number, number, number],
        ): number => a[0] - b[0],
    });
    pq.enqueue([grid[0][0], 0, 0]);

    while (!pq.isEmpty()) {
        const element = pq.dequeue();
        const [val, cx, cy] = element;
        if (dis[cx][cy] >= 0) {
            continue;
        }
        dis[cx][cy] = val;

        for (const [dx, dy] of dirs) {
            const nx = cx + dx;
            const ny = cy + dy;

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || dis[nx][ny] >= 0) {
                continue;
            }

            pq.enqueue([val + grid[nx][ny], nx, ny]);
        }
    }

    return dis[m - 1][n - 1] < health;
}
