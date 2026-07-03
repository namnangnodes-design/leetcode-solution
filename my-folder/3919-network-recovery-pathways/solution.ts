function findMaxPathScore(
    edges: number[][],
    online: boolean[],
    k: number,
): number {
    const n = online.length;
    const g: [number, number][][] = Array.from({ length: n }, () => []);

    let l = Infinity;
    let r = 0;

    for (const edge of edges) {
        const u = edge[0];
        const v = edge[1];
        const w = edge[2];

        if (!online[u] || !online[v]) {
            continue;
        }
        g[u].push([v, w]);
        l = Math.min(l, w);
        r = Math.max(r, w);
    }

    if (!check(l, k, g, n)) {
        return -1;
    }

    while (l <= r) {
        const mid = (l + r) >> 1;
        if (check(mid, k, g, n)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return r;
}

function check(
    mid: number,
    k: number,
    g: [number, number][][],
    n: number,
): boolean {
    const dis = new Array<number>(n).fill(Infinity);
    const pq = new PriorityQueue<[number, number]>((a, b) => a[0] - b[0]);

    dis[0] = 0;
    pq.enqueue([0, 0]);

    while (!pq.isEmpty()) {
        const [d, u] = pq.dequeue()!;

        if (d > k) {
            return false;
        }
        if (u === n - 1) {
            return true;
        }
        if (d !== dis[u]) {
            continue;
        }

        for (const [v, w] of g[u]) {
            if (w < mid) {
                continue;
            }
            const nd = d + w;
            if (nd < dis[v]) {
                dis[v] = nd;
                pq.enqueue([nd, v]);
            }
        }
    }

    return false;
}
